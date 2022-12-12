#include"createwindow.h"
#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// 输入处理
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
        // 初始化GLFW失败

        return -1;
    }

    // 函数的第一个参数代表选项的名称，我们可以从很多以GLFW_开头的枚举值中选择；第二个参数接受一个整型，用来设置这个选项的值。
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);          // MAC平台

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "demo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // GLAD是用来管理OpenGL函数指针，在调用任何的OpenGL的函数之前我们需要初始化GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 视口
    // 参数 前两个控制窗口的左下角，后两个代表着窗口的宽和高
    glViewport(0, 0, 800, 600);

    //当用户改变窗口的大小的时候，视口也应该被调整。
    //我们可以对窗口注册一个回调函数(Callback Function)，
    //它会在每次窗口大小被调整的时候被调用。
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    

    // 不断绘制图形
    while (!glfwWindowShouldClose(window))
    {
        // 输入检测
        processInput(window);

        // 清屏颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // 清屏
        glClear(GL_COLOR_BUFFER_BIT);                       


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 结束程序
    glfwTerminate();

    return 0;
}
