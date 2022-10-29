#include "SimulatorBase.hpp"


Dot::Dot(){};
Dot::Dot(double m, double x, double y, double z){
    this->m = m;
    this->pos[0] = x;
    this->pos[1] = y;
    this->pos[2] = z;
};

Spring::Spring(double k, double l0){
    this->k = k;
    this->l0 = l0;
};
    
void Simulator::distance(int dot1, int dot2){
    int index = this->getIndex(dot1, dot2);
    
    double dx = this->dots[dot1]->pos[0] - this->dots[dot2]->pos[0];
    double dy = this->dots[dot1]->pos[1] - this->dots[dot2]->pos[1];
    double dz = this->dots[dot1]->pos[2] - this->dots[dot2]->pos[2];
    double length= std::sqrt(dx*dx + dy*dy + dz*dz);
    this->deltaPos[index][0] = length;
    this->deltaPos[index][1] = dx/length;
    this->deltaPos[index][2] = dy/length;
    this->deltaPos[index][3] = dz/length;
};
void Simulator::addDot(Dot* d){
    this->dots.push_back(d);
    this->Fint.push_back(new double[4]);
};

void Simulator::addDot(double m, double x, double y, double z){
    this->dots.push_back(new Dot(m, x, y, z));
    this->Fint.push_back(new double[4]);
};

void Simulator::addSpring(Spring* s, int index1, int index2){

};

void Simulator::addSpring(double k, double l0){
    this->springs.push_back(new Spring(k, l0));
};

int Simulator::getIndex(int i, int j){
    if(i<j){
        return i*(this->dots.size()-1)-i*(i -1)/2 +j - i -1;
    }else if(i==j){
        return -1;
    }else{
        return j*(this->dots.size()-1)-j*(j -1)/2 +i - j -1;
    }
};

void Simulator::update(){
    this->interact();
    this->integrate();
    this->t+=1;
};

void Simulator::interact(){
    //get the distance to deltaPos
    for(int i = 0; i < this->dots.size() - 1; ++i){
        for(int j = i+1; j< this->dots.size(); ++j){
            this->distance(i,j);
        }
    }
    //get the Fint
    for(int i = 0; i< this->Fint.size(); ++i){
        memset(this->Fint[i],0,sizeof(this->Fint[i]));
    }
    for(int i = 0; i< this->dots.size()-1; ++i){
        for(int j = i+ 1; j< this->dots.size(); ++j){
            int index = this->getIndex(i,j);
            double Force = this->springs[index]->k* (this->deltaPos[index][0]- this->springs[index]->l0);
            this->Fint[i][0] -= this->deltaPos[index][1]*Force;
            this->Fint[i][1] -= this->deltaPos[index][2]*Force;
            this->Fint[i][2] -= this->deltaPos[index][3]*Force;
            this->Fint[j][0] += this->deltaPos[index][1]*Force;
            this->Fint[j][1] += this->deltaPos[index][2]*Force;
            this->Fint[j][2] += this->deltaPos[index][3]*Force;
        }
    }
};

void Simulator::integrate(){
    for(int i = 0; i<this->dots.size(); ++i){
        this->dots[i]->acc[0] = this->Fint[i][0]/ this->dots[i]->m;
        this->dots[i]->acc[1] = this->Fint[i][1]/ this->dots[i]->m;
        this->dots[i]->acc[2] = this->Fint[i][2]/ this->dots[i]->m;

        this->dots[i]->vel[0] += this->dots[i]->acc[0]*this->dt;
        this->dots[i]->vel[1] += this->dots[i]->acc[1]*this->dt;
        this->dots[i]->vel[2] += this->dots[i]->acc[2]*this->dt;

        this->dots[i]->pos[0] += this->dots[i]->vel[0]*this->dt;
        this->dots[i]->pos[1] += this->dots[i]->vel[1]*this->dt;
        this->dots[i]->pos[2] += this->dots[i]->vel[2]*this->dt;
    }
};

Simulator::Simulator(double dt, int step){
    this->dt = dt;
    this->step = step;
};

Simulator::~Simulator(){
    for(int i = 0; i< this->dots.size(); ++i){
        delete(this->dots[i]);
    }
    for(int i = 0; i< this->springs.size(); ++i){
        delete(this->springs[i]);
    }
    for(int i = 0; i< this->Fext.size(); ++i){
        delete[] (this->Fext[i]);
    }
    for(int i = 0; i< this->Fint.size(); ++i){
        delete[] (this->Fint[i]);
    }
    for(int i = 0; i< this->deltaPos.size(); ++i){
        delete[] (this->deltaPos[i]);
    }
};

BouncingBoxSim::BouncingBoxSim(double dt, int step):Simulator(dt, step){
    int n_dot = 8;
    int n_spring = n_dot * (n_dot -1)/2;
    
    this->addDot(1,0,0,0);
    this->addDot(1,1,0,0);
    this->addDot(1,0,1,0);
    this->addDot(1,1,1,0);
    this->addDot(1,0,0,1);
    this->addDot(1,0,1,1);
    this->addDot(1,1,0,1);
    this->addDot(1,1,1,1);

    for(int i =0; i< n_spring; ++i){
        this->addSpring(0.5 ,0.5);
        this->deltaPos.push_back(new double[4]);
    }
};

TwoDotsSim::TwoDotsSim(double dt, int step):Simulator(dt, step){
    int n_dot = 2;
    int n_spring = n_dot * (n_dot -1)/2;

    this->addDot(1,0,0,0);
    this->addDot(1,1,0,0);
    for(int i =0; i< n_spring; ++i){
        this->addSpring(0.5 ,0.5);
        this->deltaPos.push_back(new double[4]);
    }
};

void Robot::addSprings(){
    this->springs.push_back(1.0);
    this->springs.push_back(0.0);
    this->springs.push_back(0.0);
    this->springs.push_back(0.5);
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
}

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
}


