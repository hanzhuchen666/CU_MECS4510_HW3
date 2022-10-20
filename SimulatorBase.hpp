#include <vector>

class Dot{
    public:
    double m;
    double pos[3];
    double vel[3];
    double acc[3];
};

class Spring{
    public:
    double k;
    double l0;
    double a;
    double b;
    double c;
};

class Simulator{
    public:
    std::vector<Dot> dots;
    std::vector<Spring> springs;
    double dt;


    addDot(Dot& d);
    addSpring(Spring& s, int index1, int index2);
    interact();
    integrate();

};