//
//  render_data.h
//  Perspective
//
//  Created by  on 12-9-28.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//


#ifndef _render_data_h
#define _render_data_h



#include "MatrixCustom.h"
#include "VectorCustom.h"


struct Vertex_VC
{
	float m_Position[3];
	unsigned char m_RGBA[4];
};


//常量
const float g_fFovW = 90.0f;
const float g_fAspect = 480/320.0f;
const float g_fart = 0.1f;
const float g_near = 100.0f;


// 矩形
// 镜头位置
extern Vector3 g_eye;
// 镜头对准的点
extern Vector3 g_lookat;
// 镜头正上方的方向
extern Vector3 g_up;


// 镜头转换矩阵
extern Matrix4x4 g_view_matrix;
// 对象旋转矩阵
extern Matrix4x4 g_world_matrix;

extern Matrix4x4 g_projection_matrix;

extern Vertex_VC g_vertices[5];
extern unsigned short g_indices[18];



#endif


































































