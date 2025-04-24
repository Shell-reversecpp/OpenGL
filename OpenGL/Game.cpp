//
// Created by snake0x8 on 2/2/24.
//

#include "Game.h"
#include "Shaders.h"
#include "GLCanvas.h"
#include "UIButton.h"


Game::Game(GLCanvas* canvas)
    : m_pShaderProgram(nullptr),
      m_pUpdateTimer(new wxTimer()),
      m_pViewMatrix(new glm::mat4(1)),
      m_pProjectionMatrix(new glm::mat4(1)),
      m_uiVAO(0),
      m_cubeVAO(0),
      m_glCanvas(canvas),
      m_ui(nullptr),
      m_controlPanel(nullptr),
      m_showPanel(false),
      m_deltaTime(0.0f)
{
    m_pUpdateTimer->Bind(wxEVT_TIMER, &Game::OnTimer, this);
    m_pUpdateTimer->Start(16);
    m_lastFrameTime = wxDateTime::Now();
}



Game::~Game() {
    delete m_pShaderProgram;
    delete m_pUpdateTimer;
   // delete m_pModelMatrix;
    delete m_pViewMatrix;
    delete m_pProjectionMatrix;
    delete m_controlPanel;
    delete m_glCanvas;
    delete m_ui;

    if(m_uiVAO) glDeleteVertexArrays(1, &m_uiVAO);
    if(m_cubeVAO) glDeleteVertexArrays(1, &m_cubeVAO);
    glDeleteBuffers(2, m_cubeVBO);

}

bool Game::Initialise() {
    if (!m_glCanvas->IsGLInitialized()) {
        wxLogError("OpenGL context not initialized!");
        return false;
    }

    m_glCanvas->SetCurrent();

    // Инициализация шейдеров
    m_pShaderProgram = new CShaderProgram;
    CShader shVertex, shFragment;

    if (!shVertex.LoadShader("resources/shaders/shader.vert", GL_VERTEX_SHADER) ||
        !shFragment.LoadShader("resources/shaders/shader.frag", GL_FRAGMENT_SHADER)) {
        wxLogError("Failed to load shaders!");
        return false;
    }

    m_pShaderProgram->CreateProgram();
    m_pShaderProgram->AddShaderToProgram(&shVertex);
    m_pShaderProgram->AddShaderToProgram(&shFragment);

    if (!m_pShaderProgram->LinkProgram()) {
        wxLogError("Failed to link shader program!");
        return false;
    }

    // UI
    m_ui = new UI();

    m_controlPanel = new ControlPanel(m_glCanvas->GetParent());
    m_ui->AddElement(m_controlPanel);

    UIButton* button = new UIButton(10, 10, 64, 64, "resources/Textures/showForm.png");
    button->SetOnClick([this]() {
        m_showPanel = !m_showPanel;
        m_controlPanel->Show(m_showPanel);
    });
    m_ui->AddElement(button);

    // Матрицы камеры
    glm::vec3 vEye(0.0f, 0.0f, 10.0f);
    glm::vec3 vView(0.0f, 0.0f, 0.0f);
    glm::vec3 vUp(0.0f, 1.0f, 0.0f);
    *m_pViewMatrix = glm::lookAt(vEye, vView, vUp);

    int w, h;
    m_glCanvas->GetSize(&w, &h);
    this->UpdateProjectionMatrix(w, h);

    // --- ПИРАМИДА ---
    GLuint uiVBO[2];

    float fPyramidPositions[] = {
        // Основание
        -1.0f, 0.0f, -1.0f,
         1.0f, 0.0f, -1.0f,
         0.0f, 0.0f,  1.0f,

        // Грань 1
        -1.0f, 0.0f, -1.0f,
         1.0f, 0.0f, -1.0f,
         0.0f, 1.5f,  0.0f,

        // Грань 2
         1.0f, 0.0f, -1.0f,
         0.0f, 0.0f,  1.0f,
         0.0f, 1.5f,  0.0f,

        // Грань 3
         0.0f, 0.0f,  1.0f,
        -1.0f, 0.0f, -1.0f,
         0.0f, 1.5f,  0.0f
    };

    float fPyramidColor[] = {
        0.8f, 0.8f, 0.8f,  0.8f, 0.8f, 0.8f,  0.8f, 0.8f, 0.8f,
        1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &m_uiVAO);
    glBindVertexArray(m_uiVAO);

    glGenBuffers(2, uiVBO);

    glBindBuffer(GL_ARRAY_BUFFER, uiVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fPyramidPositions), fPyramidPositions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, uiVBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fPyramidColor), fPyramidColor, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    // CUBE INIT
    float fCubeVertices[] = {

        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,


        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f
    };

    GLuint fCubeIndices[] = {

        0, 1, 2,  2, 3, 0,

        3, 2, 6,  6, 5, 3,

        5, 6, 7,  7, 4, 5,

        4, 7, 1,  1, 0, 4,

        4, 0, 3,  3, 5, 4,

        1, 7, 6,  6, 2, 1
    };

    float fCubeColor[] = {
        1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 1, 0,
        1, 0, 1,  0, 1, 1,  1, 1, 1,  0, 0, 0
    };

    glGenVertexArrays(1, &m_cubeVAO);
    glBindVertexArray(m_cubeVAO);

    GLuint vboCube[2], eboCube;
    glGenBuffers(2, vboCube);
    glGenBuffers(1, &eboCube);

    glBindBuffer(GL_ARRAY_BUFFER, vboCube[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fCubeVertices), fCubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, vboCube[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(fCubeColor), fCubeColor, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboCube);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(fCubeIndices), fCubeIndices, GL_STATIC_DRAW);


    m_pShaderProgram->UseProgram();
    m_pShaderProgram->SetUniform("viewMatrix", m_pViewMatrix);
    m_pShaderProgram->SetUniform("projectionMatrix", m_pProjectionMatrix);



    return true;
}



void Game::OnMouseClick(wxMouseEvent& event) {
    if (m_ui)
        m_ui->HandleMouse(event);
}

void Game::UpdateProjectionMatrix(int width, int height) const {
    if(height == 0) height = 1;
    *m_pProjectionMatrix = glm::perspective(
        glm::radians(45.0f),
        (float)width/(float)height,
        0.1f,
        100.0f
    );
}

void Game::OnTimer(wxTimerEvent& event) {
    wxDateTime currentTime = wxDateTime::Now();
    wxTimeSpan timeDiff = currentTime - m_lastFrameTime;
    m_lastFrameTime = currentTime;

    m_deltaTime = static_cast<float>(timeDiff.GetMilliseconds().ToDouble() / 1000.0);
    m_elapsedTime += m_deltaTime;

    m_glCanvas->Bind(wxEVT_LEFT_DOWN, &Game::OnMouseClick, this);
    m_glCanvas->Refresh();
}

void Game::Render() {
    if (!m_glCanvas || !m_glCanvas->IsGLInitialized()) return;

    wxGLContext* glContext = m_glCanvas->GetContext();
    if (!glContext) return;




    while (glGetError() != GL_NO_ERROR);

    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);




    m_pShaderProgram->UseProgram();

    m_pShaderProgram->SetUniform("viewMatrix", *m_pViewMatrix);
    m_pShaderProgram->SetUniform("projectionMatrix", *m_pProjectionMatrix);

    m_pShaderProgram->SetUniform("t", m_elapsedTime);

    if (m_controlPanel) {
        bool drawPyramid = m_controlPanel->GetCheckBoxValueShowPyramid();
        bool drawCube = m_controlPanel->GetCheckBoxValueShowCube();

        if (drawPyramid && !drawCube) {
            DrawPyramid(glm::vec3(0, 0, 0),  m_deltaTime);
        } else if (drawCube && !drawPyramid) {
            DrawCube(glm::vec3(0, 0, 0),  m_deltaTime);
        }
    }



    glUseProgram(0);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    int w, h;
    m_glCanvas->GetSize(&w, &h);
    glOrtho(0, w, h, 0, -1, 1); // 2D UI

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST); // UI

    if (m_ui) {
        m_ui->Render();
    }


    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);


    m_glCanvas->SwapBuffers();
}

void Game::Update() {
    static wxDateTime lastUpdateTime = wxDateTime::Now();
    wxTimeSpan span = wxDateTime::Now() - lastUpdateTime;
    lastUpdateTime = wxDateTime::Now();
    float deltaTime = span.GetMilliseconds().ToDouble() / 1000.0f;

    m_lastDeltaTime = deltaTime;
}

void Game::DrawPyramid(glm::vec3 t, float deltaTime)
{
    static float pyramidAngle = 0.0f;
    pyramidAngle += deltaTime * glm::radians(60.0f);
    pyramidAngle = fmod(pyramidAngle, glm::two_pi<float>());

    float angleX = pyramidAngle * 0.7f;
    float angleY = pyramidAngle;
    float angleZ = pyramidAngle * 1.3f;

    glm::vec3 pivotOffset(0.0f, 0.75f, 0.0f);
    glm::mat4 model = glm::translate(glm::mat4(1.0f), t);

    model = glm::translate(model, pivotOffset);
    model = glm::rotate(model, angleX, glm::vec3(1, 0, 0));
    model = glm::rotate(model, angleY, glm::vec3(0, 1, 0));
    model = glm::rotate(model, angleZ, glm::vec3(0, 0, 1));
    model = glm::translate(model, -pivotOffset);

    m_pShaderProgram->SetUniform("modelMatrix", model);
    glBindVertexArray(m_uiVAO);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glBindVertexArray(0);
}


void Game::DrawCube(glm::vec3 pos, float deltaTime)
{
    static float cubeAngle = 0.0f;
    cubeAngle += deltaTime * glm::radians(60.0f);
    cubeAngle = fmod(cubeAngle, glm::two_pi<float>());

    glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
    model = glm::rotate(model, cubeAngle, glm::vec3(1.0f, 1.0f, 0.0f));

    m_pShaderProgram->SetUniform("modelMatrix", model);
    glBindVertexArray(m_cubeVAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}