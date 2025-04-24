//
// Created by snake0x8 on 2/2/24.
//

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include "ControlPanel.h"
#include "UI.h"


class CShader;
class CShaderProgram;
class GLCanvas;

class Game {
private:
    CShaderProgram* m_pShaderProgram;
    wxTimer* m_pUpdateTimer;
    glm::mat4* m_pModelMatrix;
    glm::mat4* m_pViewMatrix;
    glm::mat4* m_pProjectionMatrix;
    GLuint m_uiVAO;
    GLuint m_cubeVAO{};
    GLuint m_cubeVBO[2]{};
    GLCanvas* m_glCanvas;
    float m_spacing{};
    wxDateTime m_startTime;
    UI* m_ui{};
    ControlPanel* m_controlPanel{};

    void OnKeyPress(wxKeyEvent& event);
    void OnMouseClick(wxMouseEvent& event);

    bool m_showPanel;

public:
    Game(GLCanvas* canvas);
    ~Game();

    bool Initialise();
    void Render();
    void Update();
    void UpdateProjectionMatrix(int width, int height) const;
    void OnTimer(wxTimerEvent& event);


private:
    void DrawPyramid(glm::vec3 t, float deltaTime);
    void DrawCube(glm::vec3 pos, float deltaTime);
    void DrawTriangleStack(glm::vec3 s);
    wxDateTime m_lastUpdateTime;
    wxDateTime m_lastFrameTime;
    float m_lastDeltaTime = 0.0f;

    wxTimer m_updateTimer;

    float m_rotationAngleCube = 0.0f;
    float m_rotationAngle = 0.0f;
    wxStopWatch m_frameTimer;
    float m_elapsedTime = 0.0f;
    float m_deltaTime = 0.0f;
};

#endif // OPENGL_GAME_H