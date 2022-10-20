#include <vector>

class Dot{
    public:
    double m;
    double pos[3];
    double vel[3];
    double acc[3];
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
};

class Simulator{
    public:
    std::vector<Dot*> dots;
    std::vector<Spring*> springs;
    double dt;


    void addDot(Dot* d);
    void addDot(double m, double x, double y, double z);
    void addSpring(Spring& s, int index1, int index2);
    void interact();
    void integrate();
    ~Simulator();

};