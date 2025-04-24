cmake_minimum_required(VERSION 3.15)
project(OpenGlWithWx)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS core base gl)

include(${wxWidgets_USE_FILE})

add_subdirectory(glad)



configure_file(resources/shaders/shader.frag resources/shaders/shader.frag COPYONLY)
configure_file(resources/shaders/shader.vert resources/shaders/shader.vert COPYONLY)

set(SOURCES
        common.h
        Shaders.cpp Shaders.h
        GameWindow.cpp GameWindow.h
        Game.cpp Game.h
        WidgetWindow.cpp WidgetWindow.h
        GLCanvas.cpp GLCanvas.h
        UIElement.cpp UIElement.h
        UI.cpp UI.h
        UIButton.cpp UIButton.h
        IButtonListener.cpp
        IButtonListener.h
        ControlPanel.cpp
        ControlPanel.h
)

add_executable(OpenGl ${SOURCES})

target_include_directories(OpenGl PRIVATE
        ${CMAKE_SOURCE_DIR}/stb
)

target_link_libraries(OpenGl PRIVATE
        ${wxWidgets_LIBRARIES}
        ${OPENGL_LIBRARIES}
        GLAD
)

add_custom_command(TARGET OpenGl PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
)
