#include "SimulatorBase.hpp"
#include <iostream>
#include <cstring>


int main(){

    int n_dot = 8;
    int n_spring = n_dot * (n_dot - 1)/2;

    Simulator sim = Simulator(0.001, 1000000);
    
    sim.addDot(1.0 ,0,0,0);
    sim.addDot(1,1,0,0);
    sim.addDot(1,0,1,0);
    sim.addDot(1,1,1,0);
    sim.addDot(1,0,0,1);
    sim.addDot(1,0,1,1);
    sim.addDot(1,1,0,1);
    sim.addDot(1,1,1,1);
    
    for(int i =0; i< n_spring; ++i){
        sim.addSpring(1.0 ,1.0 );
        sim.deltaPos.push_back(new double[4]);
    }

    
}