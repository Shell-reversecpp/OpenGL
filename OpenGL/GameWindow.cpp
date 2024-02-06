//
// Created by snake0x8 on 2/2/24.
//

#include "GameWindow.h"

GameWindow::GameWindow() : m_bFullscreen(false), m_window(nullptr) {

    // Инициализация GLFW в конструкторе GameWindow
    if (!glfwInit()) {
        // Обработка ошибки инициализации GLFW
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    // Переместите создание окна в метод InitOpenGL
    InitOpenGL();
}


GameWindow& GameWindow::GetInstance() {
    static GameWindow instance;
    return instance;
}

void GameWindow::SetDimensions(GLFWwindow* window) {
    glfwGetFramebufferSize(window, &m_width, &m_height);
}

GLFWwindow* GameWindow::Init() {


    //CreateGameWindow("Lab 1");

    if (!m_window) {
        // Обработка ошибки создания окна
        return nullptr;
    }

    InitOpenGL();

    return m_window;
}

void GameWindow::Deinit() {
    if (m_window) {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }

    glfwTerminate();
}


void GameWindow::CreateGameWindow(std::string title) {
    // Инициализация GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title.c_str(), nullptr, nullptr);

    if (!m_window) {
        // Обработка ошибки создания окна
        return;
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1); // Включение вертикальной синхронизации

    SetDimensions(m_window);
}

void GameWindow::InitOpenGL() {
    // Устанавливаем требуемую версию OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Создание окна GLFW
    /*
    m_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lab 1", nullptr, nullptr);
    if (!m_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
*/

    if (!m_window) {
        m_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lab 1", nullptr, nullptr);

        if (!m_window) {
            // Обработка ошибки создания окна
            return;
        }

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(1); // Включение вертикальной синхронизации

        SetDimensions(m_window);
    }
    // Инициализация контекста OpenGL в созданном окне
    glfwMakeContextCurrent(m_window);

    // Инициализация GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwDestroyWindow(m_window);
        glfwTerminate();
        return;
    }

    // Дополнительные настройки OpenGL, если необходимо
}


