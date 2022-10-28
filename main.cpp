#include "SimulatorBase.hpp"



int main(){

    int n_dot = 2;
    int n_spring = n_dot * (n_dot - 1)/2;
    int step = 10000;

    Simulator sim = Simulator(0.001, step);
    Buffer buff = Buffer(n_dot,step);
    
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
    std::cout<<sim.dots[0]->pos[0]<<std::endl;
    
    for(int i =0; i< sim.step; ++i){
        sim.update();
        for(int j = 0; j<sim.dots.size(); ++j){
            buff.posBuffer[][i] = ;
            buff.posBuffer[][i] = ;
        }
        sim.buffer[i][] = sim.dots[0]->pos[0];
    }
    std::string file = "data/2_test_x.txt";
    buff.saveFile(file,buff.posBuffer,sim.step);
    buff.uploadFile(file);
    return 0;

    
}