





attribute vec4 VPosition;
attribute vec4 VColor;

uniform mat4 Projection4x4;
uniform mat4 ViewMatrix4x4;

varying vec4 colorVarying;
void main()
{
	gl_Position =  Projection4x4 * ViewMatrix4x4 * VPosition;    
	colorVarying = VColor;
}





























































