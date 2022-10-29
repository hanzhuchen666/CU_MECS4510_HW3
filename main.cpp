#include "SimulatorBase.hpp"

int main(){
    int step = 10000;
    double dt = 0.001;

    // BouncingBoxSim sim = BouncingBoxSim(dt, step);
    Simulator sim = Simulator(0.001, 10000000);
    BoxRobot* robot = new BoxRobot();
    sim.robots.push_back(robot);
    sim.robots.push_back(new TwoPoints());
    std::cout<<robot->dots.size()
    <<" "<<robot->springs.size()<<" "<<
    robot->PVA.size()<<std::endl;
    for(int i =0 ; i<sim.step; ++i){
        sim.update();
        if(i%100==0){
            std::cout<<sim.robots[1]->PVA[0]
            <<" "<<sim.robots[1]->PVA[1]<<
            " "<<sim.robots[1]->PVA[2]<<
            "   "<<sim.robots[1]->PVA[9]
            <<std::endl;
        }

    }
    return 0;
    
}
