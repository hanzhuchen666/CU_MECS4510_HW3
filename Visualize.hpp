#include <glad/glad.h>
#include <GLFW/glfw3.h>
#ifndef _VISUALIZE_H
#define _VISUALIZE_H


class Visualizer{
    public:
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow *window);
    int blankWindow();
};

#endif
