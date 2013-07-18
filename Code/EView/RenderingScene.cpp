//
//  RenderingScene.cpp
//  HomewardJourney
//
//  Created by apple on 13-7-17.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#include "RenderingScene.h"
#include "render_data.h"
#include "Global.h"

RenderingScene::RenderingScene()
{}

RenderingScene::~RenderingScene()
{}

void RenderingScene::Initialize()
{
    ShaderManager *sob =  new ShaderManager();
    shader = sob->LoadShader("Directional.es2");
    
    g_view_matrix = GutMatrixLookAtRH(g_eye, g_lookat, g_up);
    g_projection_matrix = GutMatrixPerspectiveRH_OpenGL(g_fFovW, g_fAspect, g_fart, g_near);
    
}



void RenderingScene::Render()
{
    // 清除画面
    GLuint program = shader->program;
    
	// 清除画面
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	// 把正向和反向的面都画出来
	glDisable(GL_CULL_FACE);
    
    glUseProgram(program);
    
    glVertexAttribPointer(shader->m_attributes.VPosition, 3, GL_FLOAT, 0, sizeof(Vertex_VC), &g_vertices[0].m_Position);
    glEnableVertexAttribArray( shader->m_attributes.VPosition );
    glVertexAttribPointer(shader->m_attributes.VColor, 4, GL_UNSIGNED_BYTE, 1, sizeof(Vertex_VC), &g_vertices[0].m_RGBA);
    glEnableVertexAttribArray(shader->m_attributes.VColor);
    
    
    glUniformMatrix4fv(shader->m_uniforms.Projection4x4, 1, 0, (float *)&g_projection_matrix);
    glUniformMatrix4fv(shader->m_uniforms.ViewMatrix4x4, 1, 0, (float *) &g_view_matrix);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, g_indices);
}
















































































