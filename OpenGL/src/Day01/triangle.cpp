#include"triangle.h"

float vertices[]{
	-0.5f,-0.5f,0.0f,
	0.5f,-0.5f,0.0f,
	0.0f,0.5f,0.0f,
};


void testTriangle()
{
	// 顶点缓存类型,生成一个顶点缓存对象ID
	unsigned int VBO;
	glGenBuffers(1, &VBO);


	// 顶点缓冲类型型 GL_ARRAY_BUFFER, 允许绑定多个缓冲，只要是不同的缓冲类型
	glBindBuffer(GL_ARRAY_BUFFER, VBO);




}
