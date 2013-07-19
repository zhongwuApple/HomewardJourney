//
//  ShaderManager.cpp
//  MiniDota
//
//  Created by apple on 12-12-11.
//  Copyright (c) 2012年 apple. All rights reserved.
//

#include "ShaderManager.h"
#include <fstream>
#include <stdio.h>
#include "Global.h"


//这里的宏对应 shader里面的 名称

#define V_Position          "VPosition"
#define V_Color             "VColor"

#define U_WorldMatrix4x4    "WorldMatrix4x4"
#define U_ViewMatrix4x4     "ViewMatrix4x4"
#define U_Projection4x4     "Projection4x4"





int ShaderManager::ShaderSize(const string &name)
{
    ifstream objFile(name.c_str());
    objFile.seekg(0,ios::end);
    int length = objFile.tellg();
    return length;
}


void ShaderManager::ReadShader(char *rs, const string& name, int len)
{
    ifstream objFile(name.c_str());
    int cout = 0;
    while (cout<len)
    {
            char c = objFile.get();
            rs[cout] = c;
        cout++;
    }
    rs[len] = '\0';
}






ShaderObject* ShaderManager::LoadShader(const string &vertName, const string &fragName)
{
        const string& vName = resourcesPath + vertName;
        const string& fName = resourcesPath + fragName;
    
    
        int vLen = ShaderSize(vName);
        int fLen = ShaderSize(fName);
        char vertexShaderSource[vLen];
        char fragmentShaderSource[fLen];
        ReadShader(vertexShaderSource,vName, vLen);
        ReadShader(fragmentShaderSource,fName, fLen);
    
    
        GLuint programID = BuildProgram(vertexShaderSource, fragmentShaderSource);
    
        //绑定Shader
        ShaderObject *newObj = (ShaderObject *)malloc(sizeof(ShaderObject));
        newObj->programID = programID;
        BingShaderObject(newObj);
        return newObj;
}






#pragma mark shader 流程处理
GLuint ShaderManager::BuildProgram(const char* vShader, const char* fShader) const
{
    GLuint vertexShader = BuildShader(vShader, GL_VERTEX_SHADER);
    GLuint fragmentShader = BuildShader(fShader, GL_FRAGMENT_SHADER);
    
    GLuint programHandle = glCreateProgram();
    glAttachShader(programHandle, vertexShader);
    glAttachShader(programHandle, fragmentShader);
    glLinkProgram(programHandle);
    
    GLint linkSuccess;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &linkSuccess);
    if (linkSuccess == GL_FALSE)
    {
        GLchar messages[256];
        glGetProgramInfoLog(programHandle, sizeof(messages), 0, &messages[0]);
        cout << messages;
        exit(1);
    }
    return programHandle;
}


GLuint ShaderManager::BuildShader(const char* source, GLenum shaderType) const
{
    GLuint shaderHandle = glCreateShader(shaderType);
    glShaderSource(shaderHandle, 1, &source, 0);
    glCompileShader(shaderHandle);
    
    GLint compileSuccess;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
    if (compileSuccess == GL_FALSE)
    {
        GLchar messages[256];
        glGetShaderInfoLog(shaderHandle, sizeof(messages), 0, &messages[0]);
        cout << messages;
        exit(1);
    }
    return shaderHandle;
}





/*
 *      @brief   将变量名称于  shader 里面的变量绑定
 */
void ShaderManager::BingShaderObject(ShaderObject *obj)
{
    GLuint program = obj->programID;
    glUseProgram(program);
    
    //attribute 变量
    obj->m_attributes.VPosition = glGetAttribLocation(program, V_Position);
    obj->m_attributes.VColor = glGetAttribLocation(program, V_Color);

    //uniform   变量
    obj->m_uniforms.WorldMatrix4x4 = glGetUniformLocation(program, U_WorldMatrix4x4);
    obj->m_uniforms.ViewMatrix4x4 = glGetUniformLocation(program, U_ViewMatrix4x4);
    obj->m_uniforms.Projection4x4 = glGetUniformLocation(program, U_Projection4x4);

}





































