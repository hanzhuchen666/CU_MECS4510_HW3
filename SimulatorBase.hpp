class Dot{
    public:
    double m;
    double pos[3];
    double vel[3];
    double acc[3];
    Dot();
    Dot(double m);
    ~Dot();
};

class Spring{
    public:
    double k;
    double l0;
};

class Simulator{
    public:
    std::vector<Dot> dots;
    std::vector<Spring> springs;   

}