#include"createwindow.h"
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// ���봦��
void processInput(GLFWwindow* window)
{
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int testWindow()
{
    if (NULL == glfwInit())
    {
        // ��ʼ��GLFWʧ��

        return -1;
    }

    // �����ĵ�һ����������ѡ������ƣ����ǿ��ԴӺܶ���GLFW_��ͷ��ö��ֵ��ѡ�񣻵ڶ�����������һ�����ͣ������������ѡ���ֵ��
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);          // MACƽ̨

    // ��������
    GLFWwindow* window = glfwCreateWindow(800, 600, "demo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // GLAD����������OpenGL����ָ�룬�ڵ����κε�OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // �ӿ�
    // ���� ǰ�������ƴ��ڵ����½ǣ������������Ŵ��ڵĿ�͸�
    glViewport(0, 0, 800, 600);

    //���û��ı䴰�ڵĴ�С��ʱ���ӿ�ҲӦ�ñ�������
    //���ǿ��ԶԴ���ע��һ���ص�����(Callback Function)��
    //������ÿ�δ��ڴ�С��������ʱ�򱻵��á�
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    

    // ���ϻ���ͼ��
    while (!glfwWindowShouldClose(window))
    {
        // ������
        processInput(window);

        // ������ɫ
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // ����
        glClear(GL_COLOR_BUFFER_BIT);                       


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ��������
    glfwTerminate();

    return 0;
}
