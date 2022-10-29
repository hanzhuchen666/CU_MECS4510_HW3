#include "SimulatorBase.hpp"

int main(){
    


    int step = 10000;
    double dt = 0.001;

    // BouncingBoxSim sim = BouncingBoxSim(dt, step);
    Simulator sim = Simulator(0.001, 10000);
    
    for(int i =0; i< sim.step; ++i){
        sim.update();
        // std::cout<<sim.dots[0]->pos[0];
    }
    return 0;
    
}
