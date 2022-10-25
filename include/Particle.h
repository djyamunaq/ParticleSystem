#include <eigen3/Eigen/Dense>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>

class Particle {
    private:
        Eigen::Vector2d pos;
        Eigen::Vector2d vel;
        Eigen::Vector2d acc;
        double angle;
        int lifeSpan;
    public:
        Particle();
        Particle(Eigen::Vector2d pos, Eigen::Vector2d vel);
        ~Particle();
        bool isDead();
        void update(double deltaTime);
        void setPos(Eigen::Vector2d newPos);
        Eigen::Vector2d getPos();
        void setVel(Eigen::Vector2d newVel);
        Eigen::Vector2d getVel();
        void setAcc(Eigen::Vector2d newAcc);
        Eigen::Vector2d getAcc();
        int getLifeSpan();
        void setLifeSpan(int lifeSpan);
};