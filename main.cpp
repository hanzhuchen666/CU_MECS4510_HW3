#include "SimulatorBase.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
    glfwTerminate();
    std::cout<<"finished";


    int n_dot = 2;
    int n_spring = n_dot * (n_dot - 1)/2;
    int step = 10000;

    Simulator sim = Simulator(0.001, step);
    
    sim.addDot(1 ,0,0,0);
    sim.addDot(1,1,0,0);
    // sim.addDot(1,0,1,0);
    // sim.addDot(1,1,1,0);
    // sim.addDot(1,0,0,1);
    // sim.addDot(1,0,1,1);
    // sim.addDot(1,1,0,1);
    // sim.addDot(1,1,1,1);
    
    for(int i =0; i< n_spring; ++i){
        sim.addSpring(0.5 ,0.5);
        sim.deltaPos.push_back(new double[4]);
    }
    
    for(int i =0; i< sim.step; ++i){
        sim.update();
        // sim.buffer[i] = sim.dots[0]->pos[0];
        // std::cout<<sim.dots[0]->pos[0];
    }
    return 0;
    
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}