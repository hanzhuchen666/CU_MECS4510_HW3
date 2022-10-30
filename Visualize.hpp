#include <glad/glad.h>
#include <GLFW/glfw3.h>



class Visualizer{
    public:
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow *window);
    int blankWindow();
};

