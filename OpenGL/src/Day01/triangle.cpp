#include"triangle.h"

float vertices[]{
	-0.5f,-0.5f,0.0f,
	0.5f,-0.5f,0.0f,
	0.0f,0.5f,0.0f,
};


void testTriangle()
{
	// ���㻺������,����һ�����㻺�����ID
	unsigned int VBO;
	glGenBuffers(1, &VBO);


	// ���㻺�������� GL_ARRAY_BUFFER, ����󶨶�����壬ֻҪ�ǲ�ͬ�Ļ�������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);




}
