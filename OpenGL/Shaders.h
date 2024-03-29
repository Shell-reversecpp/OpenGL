//
// Created by snake0x8 on 2/2/24.
//

#ifndef OPENGL_SHADERS_H
#define OPENGL_SHADERS_H

#include "common.h"
#include <cstdint>

// A class that provides a wrapper around an OpenGL shader
class CShader
{
public:
    CShader();

    bool LoadShader(string sFile, int iType);
    void DeleteShader();

    bool GetLinesFromFile(string sFile, bool bIncludePart, vector<string>* vResult);

    bool IsLoaded();
    GLuint GetShaderID();

private:
    GLuint m_uiShader; // ID of shader
    int m_iType;        // GL_VERTEX_SHADER, GL_FRAGMENT_SHADER...
    bool m_bLoaded;     // Whether shader was loaded and compiled
};

// A class that provides a wrapper around an OpenGL shader program
class CShaderProgram
{
public:
    CShaderProgram();

    void CreateProgram();
    void DeleteProgram();

    bool AddShaderToProgram(CShader* shShader);
    bool LinkProgram();

    void UseProgram();

    GLuint GetProgramID();

    // Setting vectors
    void SetUniform(string sName, glm::vec2* vVectors, int iCount = 1);
    void SetUniform(string sName, const glm::vec2 vVector);
    void SetUniform(string sName, glm::vec3* vVectors, int iCount = 1);
    void SetUniform(string sName, const glm::vec3 vVector);
    void SetUniform(string sName, glm::vec4* vVectors, int iCount = 1);
    void SetUniform(string sName, const glm::vec4 vVector);

    // Setting floats
    void SetUniform(string sName, float* fValues, int iCount = 1);
    void SetUniform(string sName, const float fValue);

    // Setting 3x3 matrices
    void SetUniform(string sName, glm::mat3* mMatrices, int iCount = 1);
    void SetUniform(string sName, const glm::mat3 mMatrix);

    // Setting 4x4 matrices
    void SetUniform(string sName, glm::mat4* mMatrices, int iCount = 1);
    void SetUniform(string sName, const glm::mat4 mMatrix);

    // Setting integers
    void SetUniform(string sName, int* iValues, int iCount = 1);
    void SetUniform(string sName, const int iValue);

private:
    GLuint m_uiProgram; // ID of program
    bool m_bLinked;      // Whether program was linked and is ready to use
};




#endif //OPENGL_SHADERS_H
