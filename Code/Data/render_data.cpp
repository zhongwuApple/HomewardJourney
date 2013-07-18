
#include "render_data.h"




// 镜头转换矩阵
Matrix4x4 g_view_matrix;
// 对象旋转矩阵
Matrix4x4 g_world_matrix;

Matrix4x4 g_projection_matrix;




Vertex_VC g_vertices[5] =
{
	{
		{0.0f, 0.0f, 2.0f}, // top
		{255, 0, 0, 255},
	},
	{
		{-1.0f,-1.0f, 0.0f},
		{0, 255, 0, 255},
	},
	{
		{1.0f,-1.0f, 0.0f},
		{0, 0, 255, 255},
	},
	{
		{1.0f, 1.0f, 0.0f},
		{255, 255, 0, 255},
	},
	{
		{-1.0f, 1.0f, 0.0f},
		{0, 255, 255, 255},
	},
};


unsigned short g_indices[18] =
{
	0, 1, 2, // triangle 1°°
	0, 2, 3, // triangle 2
	0, 3, 4, // triangle 3
	0, 4, 1, // triangle 4
	1, 4, 2, // triangle 5
	2, 4, 3, // triangle 6
};


Vector3 g_eye(0.0f, 4.0f, 1.0f);

Vector3 g_lookat(0.0f, 0.0f, 1.0f);

Vector3 g_up(0.0f, 0.0f, 1.0f);
































