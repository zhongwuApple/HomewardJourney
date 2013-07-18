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

using namespace std;





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






ShaderObject* ShaderManager::LoadShader(const string &shaderName)
{
        const string resourcesPath = "/Users/apple/Library/Application Support/iPhone Simulator/6.1/Applications/48C896EB-B795-48B8-8F90-912ABDD8AB08/HomewardJourney.app/";
        const string& vName = resourcesPath + shaderName + ".vert";
        const string& fName = resourcesPath + shaderName + ".frag";
    
    
    
        int vLen = ShaderSize(vName);
        int fLen = ShaderSize(fName);
        char vertexShaderSource[vLen];
        char fragmentShaderSource[fLen];
        ReadShader(vertexShaderSource,vName, vLen);
        ReadShader(fragmentShaderSource,fName, fLen);
    
    
    
    
    std::cout<<"vLen si "<<vLen <<" fLen is "<<fLen<<endl;
    
        GLuint program = BuildProgram(vertexShaderSource, fragmentShaderSource);
    
        ShaderObject *newObj = (ShaderObject *)malloc(sizeof(ShaderObject));
        newObj->program = program;
        UseShader(newObj);
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





void ShaderManager::UseShader(ShaderObject *obj)
{
    GLuint program = obj->program;
    glUseProgram(program);
    obj->m_attributes.VPosition = glGetAttribLocation(program, "VPosition");
    obj->m_attributes.VColor = glGetAttribLocation(program, "VColor");

    obj->m_uniforms.WorldMatrix4x4 = glGetUniformLocation(program, "WorldMatrix4x4");
    obj->m_uniforms.ViewMatrix4x4 = glGetUniformLocation(program, "ViewMatrix4x4");
    obj->m_uniforms.Projection4x4 = glGetUniformLocation(program, "Projection4x4");
    

    

    

    
    
}





































