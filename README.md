This project is a modern C++ template for developing OpenGL applications with a wxWidgets GUI on Linux. It's designed to serve as a robust starting point for interactive 3D applications, visual tools, or graphical editors.
✅ wxWidgets + OpenGL Integration
✅ GLAD Loader
✅ Shader Management
✅ Vertex Buffer Objects (VBO)
✅ Vertex Array Objects (VAO)

🛠️ Building a C++ OpenGL + wxWidgets Project on Linux (Debian/Ubuntu)

This guide provides step-by-step instructions to install dependencies, configure the build system, and run a modern OpenGL project with a wxWidgets GUI and STB image support. The project uses:

    CMake for build configuration

    GLAD as the OpenGL loader

    STB for texture/image handling

📁 Project Structure Overview

Your project directory should look like this:

OpenGlWithWx/
├── CMakeLists.txt              # CMake configuration file
├── stb/                        # Contains stb_image.h
│   └── stb_image.h
├── glad/                       # GLAD source + its own CMakeLists.txt
├── resources/
│   └── shaders/
│       ├── shader.frag
│       └── shader.vert
├── *.cpp / *.h                 # Your source and header files

✅ Install Required Dependencies

Install all necessary packages on any Debian-based system (Ubuntu, Mint, Pop!_OS, etc.):

sudo apt update && sudo apt install -y \
    cmake \
    build-essential \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libwxgtk3.2-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxinerama-dev \
    libxcursor-dev

🔧 Building and Running the Project

Follow these steps to build and run the application:

    1. Create a build directory and generate Makefiles:

mkdir build && cd build
cmake ..

2. Compile the project:

make -j$(nproc)

3. Run the executable:

./OpenGl
