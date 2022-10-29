#include "SimulatorBase.hpp"

int main(){
    


    int step = 10000;
    double dt = 0.001;

    // BouncingBoxSim sim = BouncingBoxSim(dt, step);
    TwoDotsSim sim = TwoDotsSim(dt, step);
    
    for(int i =0; i< sim.step; ++i){
        sim.update();
        // std::cout<<sim.dots[0]->pos[0];
    }
    return 0;
    
}
