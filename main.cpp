#include "SimulatorBase.hpp"

int main(){
    int step = 10000;
    double dt = 0.001;

    // BouncingBoxSim sim = BouncingBoxSim(dt, step);
    Simulator sim = Simulator(0.001, 10000000);
    
    auto& robots = (sim.robots);
    robots.push_back(new BoxRobot());
    robots.push_back(new TwoPoints());
    for(int i =0 ; i<sim.step; ++i){
        sim.update();
        if(i%100==0){
            std::cout<<robots[1]->PVA[0]
            <<" "<<robots[1]->PVA[1]<<
            " "<<robots[1]->PVA[2]<<
            "   "<<robots[1]->PVA[9]
            <<std::endl;
        }

    }
    return 0;
    
}
