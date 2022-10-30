#include "SimulatorBase.hpp"
#include <iomanip>
#include <glad/glad.h>
#include <Visualize.hpp>

int main(){
    int step = 10000;
    double dt = 0.001;

    // BouncingBoxSim sim = BouncingBoxSim(dt, step);
    // for(int i =0 ; i<sim.step; ++i){
    //     sim.update();
    //     if(i%100==0){
    //         std::cout<<robots[0]->PVA[6*9+0]
    //         <<" "<<robots[0]->PVA[6*9+1]<<
    //         " "<<robots[0]->PVA[6*9+2]<<
    //         "   "<<robots[0]->PVA[7*9+0]
    //         <<" "<<robots[0]->PVA[7*9+1]<<
    //         " "<<robots[0]->PVA[7*9+2]
    //         <<std::endl;
    //     }

    // }
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
        vis.input(vertices,indices);
        vis.inloop();
    }
    return 0;
    
}
