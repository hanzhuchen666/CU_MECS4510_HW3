#include "SimulatorBase.hpp"

int Robot::getIndex(int i, int j){
    if(i>j){
        return i*(i-1)/2 + j;
    }else if(i==j){
        return -1;
    }else{
        return j*(j-1)/2 + i;
    }
};

void Simulator::update(){
    for(int i =0 ; i< this->robots.size(); ++i){
        this->robots[i]->update(this->dt);
    }
    return;
}


Simulator::Simulator(double dt, int step){
    this->dt = dt;
    this->step = step;
};

Simulator::~Simulator(){
    for(int i = 0; i< this->robots.size(); ++i){
        delete this->robots[i];
    }
};



void Robot::addSprings(){
    this->springs.push_back(100.0);
    this->springs.push_back(0.0);
    this->springs.push_back(0.0);
    this->springs.push_back(1.5);
};

void Robot::addDots(double m){
    this->dots.push_back(m);
    for(int i = 0; i < 3; ++i){
        this->PVA.push_back(rand());
    }
    for(int i = 0; i< 6; ++i){
        this->PVA.push_back(0.0);
    }
    for(int i  =0; i< this->dots.size()-1; ++i){
        addSprings();
    }
    return;
};

void Robot::addDots(double m, double x, double y, double z){
    this->dots.push_back(m);
    this->PVA.push_back(x);
    this->PVA.push_back(y);
    this->PVA.push_back(z);
    for(int i = 0; i< 6; ++i){
        this->PVA.push_back(0.0);
    }
    for(int i  =0; i< this->dots.size()-1; ++i){
        addSprings();
    }
    return;
};

void Robot::randomGenerate(int n){
    // for(int i = 0; i< n; ++i){
    //     this->addDots()
    // }
};

void Robot::update(double dt){
    for(int i = 0; i<this->dots.size(); ++i){
        this->PVA[9*i+6] = 0;
        this->PVA[9*i+7] = 0;
        this->PVA[9*i+8] = 0;
    }

    for(int i = 0; i<this->dots.size()-1; ++i){
        for(int j = i+1; j<this->dots.size(); ++j){
            //interact
            int index = this->getIndex(i, j);
            double dx = this->PVA[9*i+0] - this->PVA[9*j+0];
            double dy = this->PVA[9*i+1] - this->PVA[9*j+1];
            double dz = this->PVA[9*i+2] - this->PVA[9*j+2];
            double length= std::sqrt(dx*dx + dy*dy + dz*dz);
            double ex = dx/length;
            double ey = dy/length;
            double ez = dz/length;
            double l0 = this->springs[index*4+1]* sin(this->springs[index*4+2]) + this->springs[index*4+3];
            double fint = this->springs[index*4+0]*(length - l0);
            
            this->PVA[9*i+6] -= ex * fint/this->dots[i]*dt;
            this->PVA[9*i+7] -= ey * fint/this->dots[i]*dt;
            this->PVA[9*i+8] -= ez * fint/this->dots[i]*dt;
            this->PVA[9*j+6] += ex * fint/this->dots[j]*dt;
            this->PVA[9*j+7] += ey * fint/this->dots[j]*dt;
            this->PVA[9*j+8] += ez * fint/this->dots[j]*dt;

        }
    }
    
    for(int i = 0; i<this->dots.size(); ++i){
        //integrate
        this->PVA[9*i+3] += this->PVA[9*i+6]*dt;
        this->PVA[9*i+4] += this->PVA[9*i+7]*dt;
        this->PVA[9*i+5] += this->PVA[9*i+8]*dt;
        this->PVA[9*i+0] += this->PVA[9*i+3]*dt;
        this->PVA[9*i+1] += this->PVA[9*i+4]*dt;
        this->PVA[9*i+2] += this->PVA[9*i+5]*dt;
        
    }
};

BoxRobot::BoxRobot(){
    this->addDots(1,0,0,0);
    this->addDots(1,1,0,0);
    this->addDots(1,0,1,0);
    this->addDots(1,0,0,1);
    this->addDots(1,1,1,0);
    this->addDots(1,0,1,1);
    this->addDots(1,1,0,1);
    this->addDots(1,1,1,1);
};

TwoPoints::TwoPoints(){
    this->addDots(1,0,0,0);
    this->addDots(1,1,0,0);
}


