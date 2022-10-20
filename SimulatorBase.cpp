#include "SimulatorBase.hpp"

Dot::Dot(){};

Dot::Dot(double m, double x, double y, double z){
    this->m = m;
    this->pos[0] = x;
    this->pos[1] = y;
    this->pos[2] = z;
};

void Simulator::addDot(Dot* d){

    this->dots.push_back(d);
};

void Simulator::addDot(double m, double x, double y, double z){
    this->dots.push_back(new Dot(m, x, y, z));
}

void Simulator::addSpring(Spring& s, int index1, int index2){

};

void Simulator::interact(){

};

void Simulator::integrate(){

};

Simulator::~Simulator(){
    for(int i = 0; i< this->dots.size(); ++i){
        delete(this->dots[i]);
    }
    for(int i = 0; i< this->springs.size(); ++i){
        delete(this->springs[i]);
    }
}





