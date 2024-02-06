//
// Created by snake0x8 on 2/2/24.
//

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include "common.h"
#include "GameWindow.h"
#include "HighResolutionTimer.h"

// Classes used in game
class CShader;
class CShaderProgram;
class CHighResolutionTimer;

class Game {
private:
    CShaderProgram* m_pShaderProgram;
    CHighResolutionTimer* m_pTimer;
    glm::mat4* m_pModelMatrix;
    glm::mat4* m_pViewMatrix;
    glm::mat4* m_pProjectionMatrix;
    GLuint m_uiVAO;  // A vertex array object (to wrap VBOs)
    GLFWwindow* m_window;

public:
    Game();
    ~Game();
    static Game& GetInstance();
    void SetGLFWWindow(GLFWwindow* window);
    int Execute();

private:
    float m_spacing;

    void DrawTriangle(glm::vec3 t);
    void DrawTriangleStack(glm::vec3 s);


    void Initialise();
    void Update();
    void Render();
    void GameLoop();
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};


#endif //OPENGL_GAME_H
