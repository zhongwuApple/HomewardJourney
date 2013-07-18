//
//  ShaderManager.h
//  MiniDota
//
//  Created by apple on 12-12-11.
//  Copyright (c) 2012年 apple. All rights reserved.
//



#ifndef _ShaderManager_h
#define _ShaderManager_h

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <iostream>
#include <string>



/*
    V开头表示是一个Vector
    F开头表是一个 Float
 */
struct UniformHandles
{
    GLint WorldMatrix4x4;         //世界坐标
    GLint ViewMatrix4x4;          //视图坐标 即 lookat
    GLint Projection4x4;          //投影
    GLint NormalMatrix3x3;

};

struct AttributeHandles
{
    GLint VPosition;             //顶点位置(x,y,z)
    GLint VColor;                //顶点颜色(r,g,b,a)
    GLint VNormal;               //法线
};



struct ShaderObject
{
    UniformHandles      m_uniforms;
    AttributeHandles    m_attributes;
    GLuint              program;
};




class ShaderManager 
{
    

public:
    
    GLuint BuildProgram(const char* vShader, const char* fShader) const;
    GLuint BuildShader(const char* source, GLenum shaderType) const;
    void   UseShader(ShaderObject *obj);

    void ReadShader(char *rs,const std::string &name, int len);                     //将shader 内容读到一个char数组中
    ShaderObject* LoadShader(const std::string &shaderName);        //加载shader
    int ShaderSize(const std::string& name);                                        //计算单个shader里面内容的大小
    
    ShaderObject* GetShaderObject( const std::string& name );
    
private:
    ~ShaderManager()
    {
    }
    
};


















































#endif /* defined(__MiniDota__ShaderManager__) */



























































