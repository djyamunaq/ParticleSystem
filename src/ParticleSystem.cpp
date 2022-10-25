#include "ParticleSystem.h"


ParticleSystem::RadialPS::RadialPS(double duration, Eigen::Vector2d pos) {
    this->pos = pos;
    this->duration = duration;
    this->nParticles = ceil(duration)/10;
    
    gettimeofday(&this->time, 0);

    for(int i=0; i<nParticles; i++) {
        double speed = 3*((double) rand()/RAND_MAX);
        double theta = -(4*(M_PI/6)*((double) rand()/RAND_MAX) + M_PI/6);
        // double theta = 2*M_PI*((double) random()/RAND_MAX);
        Eigen::Vector2d randVel = {speed*cos(theta), speed*sin(theta)};
        
        Particle particle(pos, randVel);
        particle.setVel(randVel);

        particles.push_back(particle);
    }
}

ParticleSystem::RadialPS::~RadialPS() {}

void ParticleSystem::RadialPS::run(double deltaTime) {
    std::vector<Particle>::iterator it = this->particles.begin();
    
    while(it != this->particles.end() && this->particles.size() != 0) {
        (*it).update(deltaTime);

        if((*it).getPos()(1) >= this->pos(1)) {
            Eigen::Vector2d pos = {(*it).getPos()(0), this->pos(1)};
            (*it).setPos(pos);
        }
        
        timeval t_now;
        gettimeofday(&t_now, 0);

        double elapsedTime = 1e3*(t_now.tv_sec - this->time.tv_sec) + 1e-3*(t_now.tv_usec - this->time.tv_usec);

        double lifePercentage = 1 - (elapsedTime/this->duration);

        if(elapsedTime > this->duration) 
            (*it).setLifeSpan(0);
        else
            (*it).setLifeSpan(255*lifePercentage);

        if((*it).isDead()) {
            this->particles.erase(it);

            if(this->particles.size() == 0) break;
        } 

        it++;
    }
}

std::vector<Particle> ParticleSystem::RadialPS::getParticles() {
    return this->particles;
}
