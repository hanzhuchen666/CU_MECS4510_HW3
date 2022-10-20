#include "SimulatorBase.hpp"
#include <iostream>


int main(){
    Dot* dot =new Dot(3,1,2,3);
    std::cout<<dot<<std::endl;
    Simulator sim = Simulator();
    sim.addDot(dot);
    std::cout<<(sim.dots[0]);
    std::cout<<sim.dots[0]->m;
    return 0;
}