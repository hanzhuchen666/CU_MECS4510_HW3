#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

#ifndef _SIMULATORBASE_H
#define _SIMULATORBASE_H

class Dot{
    public:
    double m;
    double pos[3];
    double vel[3]{0.0, 0.0, 0.0};
    double acc[3]{0.0, 0.0, 0.0};
    Dot();
    Dot(double m, double x, double y, double z);

};


class Spring{
    public:
    double k;
    double l0;
    double a;
    double b;
    double c;
    Spring(double k, double l0);
};

class Simulator{
    public:
    std::vector<Dot*> dots;
    std::vector<Spring*> springs;
    double dt= 0.001;
    int t = 0;
    double step;
    std::vector<double*> Fint;
    std::vector<double*> Fext;
    std::vector<double*> deltaPos;
    void distance(int dot1, int dot2);
    int getIndex(int i, int j);
    void addDot(Dot* d);
    void addDot(double m, double x, double y, double z);
    void addSpring(Spring* s, int index1, int index2);
    void addSpring(double k, double l0);
    void interact();
    void integrate();
    void update();
    Simulator(double dt, int step);
    ~Simulator();
    void run();
    

};

class BouncingBoxSim: public Simulator{
    public:
    BouncingBoxSim(double dt, int step);
};

class TwoDotsSim: public Simulator{
    public:
    TwoDotsSim(double dt, int step);
};

#endif

