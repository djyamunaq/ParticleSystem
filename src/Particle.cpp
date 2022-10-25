#include "Particle.h"

Particle::Particle() {}

Particle::Particle(Eigen::Vector2d pos, Eigen::Vector2d vel) {
    this->pos = pos;
    this->vel = vel;
    this->lifeSpan = 255;
}

Particle::~Particle() {
}

bool Particle::isDead() {
    return this->lifeSpan == 0;
}

void Particle::update(double deltaTime) {
    this->lifeSpan--;

    this->vel += this->acc;
    this->pos += this->vel;
}

void Particle::setPos(Eigen::Vector2d newPos) {
    this->pos = newPos;
}

Eigen::Vector2d Particle::getPos() {
    return this->pos;
}

void Particle::setVel(Eigen::Vector2d newVel) {
    this->vel = newVel;
}

Eigen::Vector2d Particle::getVel() {
    return this->vel;
}

void Particle::setAcc(Eigen::Vector2d newAcc) {
    this->acc = newAcc;
}

Eigen::Vector2d Particle::getAcc() {
    return this->acc;
}

int Particle::getLifeSpan() {
    return this->lifeSpan;
}

void Particle::setLifeSpan(int lifeSpan) {
    this->lifeSpan = lifeSpan;
}