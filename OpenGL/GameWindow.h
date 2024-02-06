//
// Created by snake0x8 on 2/2/24.
//





#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "common.h"
#include <string>

class GameWindow {
public:
    static GameWindow& GetInstance();
    GameWindow();

    enum {
        SCREEN_WIDTH = 800,
        SCREEN_HEIGHT = 600,
    };

    GLFWwindow* Init();
    void Deinit();

    void SetDimensions(GLFWwindow* window);
    GLFWwindow* GetWindow() const { return m_window; }

private:
    GameWindow(const GameWindow&);
    void operator=(const GameWindow&);

    void CreateGameWindow(std::string title);
    void InitOpenGL();
    void RegisterSimpleOpenGLClass();

    bool  m_bFullscreen;

    GLFWwindow* m_window;
    std::string m_sAppName;

    int m_width;
    int m_height;
};

#endif // GAME_WINDOW_H

