#include <eigen3/Eigen/Dense>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include "Particle.h"

namespace ParticleSystem {
    class RadialPS {
        private:
            std::vector<Particle> particles;
            double duration;
            timeval time;
            int nParticles;
            Eigen::Vector2d pos;
        public:
            RadialPS(double duration, Eigen::Vector2d pos);
            ~RadialPS();
            void run(double deltaTime);
            std::vector<Particle> getParticles();
    };
};