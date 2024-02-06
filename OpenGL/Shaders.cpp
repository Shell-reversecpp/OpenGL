//
// Created by snake0x8 on 2/2/24.
//

#include "Shaders.h"



CShader::CShader()
{
    m_bLoaded = false;
}

bool CShader::LoadShader(string sFile, int iType)
{
    vector<string> sLines;

    if (!GetLinesFromFile(sFile, false, &sLines))
    {
        char message[1024];
        snprintf(message, sizeof(message), "Cannot load shader\n%s\n", sFile.c_str());
        // Заменено MessageBox на std::cerr
        std::cerr << "Error: " << message << std::endl;
        return false;
    }

    const char** sProgram = new const char*[(int)sLines.size()];
    for (int i = 0; i < (int)sLines.size(); i++)
        sProgram[i] = sLines[i].c_str();

    m_uiShader = glCreateShader(iType);

    glShaderSource(m_uiShader, (int)sLines.size(), sProgram, NULL);
    glCompileShader(m_uiShader);

    delete[] sProgram;

    int iCompilationStatus;
    glGetShaderiv(m_uiShader, GL_COMPILE_STATUS, &iCompilationStatus);

    if (iCompilationStatus == GL_FALSE)
    {
        char sInfoLog[1024];
        char sFinalMessage[1536];
        int iLogLength;
        glGetShaderInfoLog(m_uiShader, 1024, &iLogLength, sInfoLog);
        char sShaderType[64];
        if (iType == GL_VERTEX_SHADER)
            snprintf(sShaderType, sizeof(sShaderType), "vertex shader");
        else if (iType == GL_FRAGMENT_SHADER)
            snprintf(sShaderType, sizeof(sShaderType), "fragment shader");
        else if (iType == GL_GEOMETRY_SHADER)
            snprintf(sShaderType, sizeof(sShaderType), "geometry shader");
        else
            snprintf(sShaderType, sizeof(sShaderType), "unknown shader type");

        snprintf(sFinalMessage, sizeof(sFinalMessage), "Error in %s!\n%s\nShader file not compiled.  The compiler returned:\n\n%s", sShaderType, sFile.c_str(), sInfoLog);

        // Заменено MessageBox на std::cerr
        std::cerr << "Error: " << sFinalMessage << std::endl;
        return false;
    }
    m_iType = iType;
    m_bLoaded = true;

    return true;
}

bool CShader::GetLinesFromFile(string sFile, bool bIncludePart, vector<string>* vResult)
{
    FILE* fp = fopen(sFile.c_str(), "rt");
    if (!fp)
        return false;

    string sDirectory;
    int slashIndex = -1;

    for (int i = (int)sFile.size() - 1; i == 0; i--)
    {
        if (sFile[i] == '\\' || sFile[i] == '/')
        {
            slashIndex = i;
            break;
        }
    }

    sDirectory = sFile.substr(0, slashIndex + 1);

    char sLine[255];

    bool bInIncludePart = false;

    while (fgets(sLine, 255, fp))
    {
        stringstream ss(sLine);
        string sFirst;
        ss >> sFirst;
        if (sFirst == "#include")
        {
            string sFileName;
            ss >> sFileName;
            if ((int)sFileName.size() > 0 && sFileName[0] == '\"' && sFileName[(int)sFileName.size() - 1] == '\"')
            {
                sFileName = sFileName.substr(1, (int)sFileName.size() - 2);
                GetLinesFromFile(sDirectory + sFileName, true, vResult);
            }
        }
        else if (sFirst == "#include_part")
            bInIncludePart = true;
        else if (sFirst == "#definition_part")
            bInIncludePart = false;
        else if (!bIncludePart || (bIncludePart && bInIncludePart))
            vResult->push_back(sLine);
    }
    fclose(fp);

    return true;
}

bool CShader::IsLoaded()
{
    return m_bLoaded;
}

GLuint CShader::GetShaderID()
{
    return m_uiShader;
}

void CShader::DeleteShader()
{
    if (!IsLoaded())
        return;
    m_bLoaded = false;
    glDeleteShader(m_uiShader);
}

CShaderProgram::CShaderProgram()
{
    m_bLinked = false;
}

void CShaderProgram::CreateProgram()
{
    m_uiProgram = glCreateProgram();
}

bool CShaderProgram::AddShaderToProgram(CShader* shShader)
{
    if (!shShader->IsLoaded())
        return false;

    glAttachShader(m_uiProgram, shShader->GetShaderID());

    return true;
}

bool CShaderProgram::LinkProgram()
{
    glLinkProgram(m_uiProgram);
    int iLinkStatus;
    glGetProgramiv(m_uiProgram, GL_LINK_STATUS, &iLinkStatus);

    if (iLinkStatus == GL_FALSE)
    {
        char sInfoLog[1024];
        char sFinalMessage[1536];
        int iLogLength;
        glGetProgramInfoLog(m_uiProgram, 1024, &iLogLength, sInfoLog);
        snprintf(sFinalMessage, sizeof(sFinalMessage), "Error! Shader program wasn't linked! The linker returned:\n\n%s", sInfoLog);
        // Заменено MessageBox на std::cerr
        std::cerr << "Error: " << sFinalMessage << std::endl;
        return false;
    }

    m_bLinked = iLinkStatus == GL_TRUE;
    return m_bLinked;
}

void CShaderProgram::DeleteProgram()
{
    if (!m_bLinked)
        return;
    m_bLinked = false;
    glDeleteProgram(m_uiProgram);
}

void CShaderProgram::UseProgram()
{
    if (m_bLinked)
        glUseProgram(m_uiProgram);
}

GLuint CShaderProgram::GetProgramID()
{
    return m_uiProgram;
}

void CShaderProgram::SetUniform(string sName, float* fValues, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform1fv(iLoc, iCount, fValues);
}

void CShaderProgram::SetUniform(string sName, const float fValue)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform1fv(iLoc, 1, &fValue);
}

void CShaderProgram::SetUniform(string sName, glm::vec2* vVectors, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());

    glUniform2fv(iLoc, iCount, &vVectors[0].x);
}

void CShaderProgram::SetUniform(string sName, const glm::vec2 vVector)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform2fv(iLoc, 1, &vVector.x);
}

void CShaderProgram::SetUniform(string sName, glm::vec3* vVectors, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform3fv(iLoc, iCount, &vVectors[0].x);
}

void CShaderProgram::SetUniform(string sName, const glm::vec3 vVector)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform3fv(iLoc, 1, &vVector.x);
}

void CShaderProgram::SetUniform(string sName, glm::vec4* vVectors, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform4fv(iLoc, iCount, &vVectors[0].x);
}

void CShaderProgram::SetUniform(string sName, const glm::vec4 vVector)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform4fv(iLoc, 1, &vVector.x);
}

void CShaderProgram::SetUniform(string sName, glm::mat3* mMatrices, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniformMatrix3fv(iLoc, iCount, GL_FALSE, &(*mMatrices)[0][0]);
}

void CShaderProgram::SetUniform(string sName, const glm::mat3 mMatrix)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniformMatrix3fv(iLoc, 1, GL_FALSE, &mMatrix[0][0]);
}

void CShaderProgram::SetUniform(string sName, glm::mat4* mMatrices, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniformMatrix4fv(iLoc, iCount, GL_FALSE, &(*mMatrices)[0][0]);
}

void CShaderProgram::SetUniform(string sName, const glm::mat4 mMatrix)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniformMatrix4fv(iLoc, 1, GL_FALSE, &mMatrix[0][0]);
}

void CShaderProgram::SetUniform(string sName, int* iValues, int iCount)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform1iv(iLoc, iCount, iValues);
}

void CShaderProgram::SetUniform(string sName, const int iValue)
{
    int iLoc = glGetUniformLocation(m_uiProgram, sName.c_str());
    glUniform1i(iLoc, iValue);
}