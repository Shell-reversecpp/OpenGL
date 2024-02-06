//
// Created by snake0x8 on 2/2/24.
//

#include "Game.h"
#include "Shaders.h"

Game& Game::GetInstance() {
    static Game instance;
    return instance;
}


Game::Game() : m_pShaderProgram(nullptr), m_pTimer(nullptr), m_pModelMatrix(nullptr),
               m_pViewMatrix(nullptr), m_pProjectionMatrix(nullptr), m_uiVAO(0), m_window(nullptr) {

    // Создать окно GLFW
    m_window = GameWindow::GetInstance().Init();
    glfwSetWindowUserPointer(m_window, this);
    // Проверить на ошибки при создании окна
    if (!m_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }
}


void Game::SetGLFWWindow(GLFWwindow* window){
    m_window = window;
    glfwSetKeyCallback(m_window, KeyCallback);
}

int Game::Execute() {
    //this->SetGLFWWindow(m_window);
    if (!m_window) {
        return -1;
    }

    Initialise();
    GameLoop();

    return 0;
}

void Game::Initialise() {
    m_pShaderProgram = new CShaderProgram;
    m_pTimer = new CHighResolutionTimer;
    m_pModelMatrix = new glm::mat4(1);
    m_pViewMatrix = new glm::mat4(1);
    m_pProjectionMatrix = new glm::mat4(1);

    this->m_spacing = 0.5f;

    glfwSetKeyCallback(m_window, KeyCallback);
   // m_window = GameWindow::GetInstance().Init();

    if (!m_window) {
        // Обработка ошибки создания окна
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }

    GLuint uiVBO[2];  // Two vertex buffer objects

    float fTrianglePositions[9];  // An array to store triangle vertex positions
    float fTriangleColor[9];      // An array to store triangle vertex colours

    // This sets the position, viewpoint, and up vector of the camera
    glm::vec3 vEye(10, 10, 10);
    glm::vec3 vView(0, 0, 0);
    glm::vec3 vUp(0, 1, 0);
    *m_pViewMatrix = glm::lookAt(vEye, vView, vUp);

    // This creates a view frustum
    *m_pProjectionMatrix = glm::perspective(45.0f, 1.333f, 1.0f, 150.0f);

    // This sets the background colour
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Setup triangle vertex positions
    fTrianglePositions[0] = -1.0f; fTrianglePositions[1] = 0.0f; fTrianglePositions[2] = 0.0f;
    fTrianglePositions[3] = 1.0f; fTrianglePositions[4] = 0.0f; fTrianglePositions[5] = 0.0f;
    fTrianglePositions[6] = 0.0f; fTrianglePositions[7] = 1.0f; fTrianglePositions[8] = 0.0f;

    // Setup triangle vertex colours
    fTriangleColor[0] = 0.0f; fTriangleColor[1] = 1.0f; fTriangleColor[2] = 0.0f;
    fTriangleColor[3] = 0.0f; fTriangleColor[4] = 0.0f; fTriangleColor[5] = 1.0f;
    fTriangleColor[6] = 1.0f; fTriangleColor[7] = 0.0f; fTriangleColor[8] = 0.0f;

    // Generate a VAO and two VBOs
    glGenVertexArrays(1, &m_uiVAO);
    glGenBuffers(2, &uiVBO[0]);

    // Create the VAO for the triangle
    glBindVertexArray(m_uiVAO);

    // Create a VBO for the triangle vertices
    glBindBuffer(GL_ARRAY_BUFFER, uiVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), fTrianglePositions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // Create a VBO for the triangle colours
    glBindBuffer(GL_ARRAY_BUFFER, uiVBO[1]);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), fTriangleColor, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // Load and compile shaders
     CShader shVertex, shFragment;
     shVertex.LoadShader("resources/shaders/shader.vert", GL_VERTEX_SHADER);
     shFragment.LoadShader("resources/shaders/shader.frag", GL_FRAGMENT_SHADER);
// Load and compile shaders

    // Create shader program and add shaders
    m_pShaderProgram->CreateProgram();
    m_pShaderProgram->AddShaderToProgram(&shVertex);
    m_pShaderProgram->AddShaderToProgram(&shFragment);

    // Link and use the program
    m_pShaderProgram->LinkProgram();
    m_pShaderProgram->UseProgram();

    // Set the modeling, viewing, and projection matrices in the shader
    m_pShaderProgram->SetUniform("viewMatrix", m_pViewMatrix);
    m_pShaderProgram->SetUniform("projectionMatrix", m_pProjectionMatrix);

    m_pTimer->Start();
    glEnable(GL_DEPTH_TEST);
}

void Game::Update() {
    // TODO: Add your game update logic here
}

void Game::DrawTriangle(glm::vec3 t) {
    // Set the modeling matrix
    *m_pModelMatrix = glm::translate(glm::mat4(1), glm::vec3(t.x, t.y, t.z));
    m_pShaderProgram->SetUniform("modelMatrix", m_pModelMatrix);
    m_pShaderProgram->SetUniform("t", static_cast<float>(m_pTimer->Elapsed()));

    // Render the triangle consisting of 3 vertices
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Game::DrawTriangleStack(glm::vec3 s) {
    for (int i = 0; i < 10; ++i)
    {

        this->DrawTriangle(glm::vec3(s.x, s.y , s.z + i * this->m_spacing));
    }
}

void Game::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // TODO: Handle key events
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    if (game == nullptr) return;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if(key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        game->m_spacing += 0.05f;
    }
    else if(key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
        game->m_spacing -= 0.05;
    }

}




void Game::Render() {
    // Clear the buffer for rendering a new frame
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind the VAO
    glBindVertexArray(m_uiVAO);

    this->DrawTriangleStack(glm::vec3 (0, 5 ,  0));
    this->DrawTriangleStack(glm::vec3 (2, 5 , -1));
    this->DrawTriangleStack(glm::vec3 (4, 5 , -3));


    // Swap buffers to show the rendered image
    glfwSwapBuffers(m_window);
}

void Game::GameLoop() {
    while (!glfwWindowShouldClose(m_window)) {
        // Update
        Update();

        // Render
        Render();

        // Poll for and process events
        glfwPollEvents();
    }
}


Game::~Game() {
    delete m_pShaderProgram;
    delete m_pTimer;
    delete m_pModelMatrix;
    delete m_pViewMatrix;
    delete m_pProjectionMatrix;

    // Завершение работы GLFW
    glfwTerminate();
}


