cmake_minimum_required(VERSION 3.15)
project(OpenGl)

set(CMAKE_CXX_STANDARD 11)

#find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

configure_file(resources/shaders/shader.frag resources/shaders/shader.frag COPYONLY)
configure_file(resources/shaders/shader.vert resources/shaders/shader.vert COPYONLY)

# Добавьте подкаталог glad
add_subdirectory(glad)


# Укажите исходные файлы вашего проекта
set(SOURCES
        main.cpp
        common.h
        Shaders.cpp
        Shaders.h
        HighResolutionTimer.cpp
        HighResolutionTimer.h
        GameWindow.cpp
        GameWindow.h
        Game.cpp
        Game.h
)

# Создайте исполняемый файл
add_executable(OpenGl ${SOURCES})

# Укажите пути к заголовочным файлам
target_include_directories(OpenGl PRIVATE ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Линковка с библиотекой GLAD
target_link_libraries(OpenGl PRIVATE ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} GLEW::GLEW glfw GLAD)

target_link_libraries(OpenGl PRIVATE GLAD)
