#include "SimulatorBase.hpp"
#include <iomanip>
#include <glad/glad.h>
#include <Visualize.hpp>

int main(){
    int step = 10000;
    double dt = 0.001;

    Visualizer vis = Visualizer();
    vis.initWindow();
    vis.initShader();
    float vertices[] = {
    // positions         // colors
    0.0f, 0.0f, 0.0f,  0.2f, 0.5f, 1.0f,  // bottom right
    0.5f, 0.0f, 0.0f,  0.2f, 0.5f, 1.0f,  // bottom left
    0.0f, 0.5f, 0.0f,  0.2f, 0.5f, 1.0f,   // top
    0.5f, 0.5f, 0.0f,  0.2f, 0.5f, 1.0f,   //
    
    0.0f, 0.0f, 0.5f,  0.2f, 0.5f, 1.0f,  // front
    0.5f, 0.0f, 0.5f,  0.2f, 0.5f, 1.0f,  // bottom left
    0.0f, 0.5f, 0.5f,  0.2f, 0.5f, 1.0f,   // top
    0.5f, 0.5f, 0.5f,  0.2f, 0.5f, 1.0f   //
    
    };
    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 2,  // back
            1, 2, 3,   //
            4, 6, 7,   // front
            4, 5, 7,
            2, 0, 4,  // left
            2, 6, 4,  //
            1, 3, 7,  //right
            1, 5, 7,  //
            2, 6, 7,  //up
            2, 3, 7,
            0, 1, 5,  //bottom
            0, 4, 5
        };
    while(!glfwWindowShouldClose(vis.window)){
        
        vis.inloop1();
        vis.input(vertices, sizeof(vertices),indices,sizeof(indices));
        vis.inloop2();
    }
    return 0;
    
}
