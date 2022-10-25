#include <eigen3/Eigen/Dense>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>
#include <opencv2/viz.hpp>
#include <opencv2/viz/vizcore.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/eigen.hpp>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include "ParticleSystem.h"

#define WHITE cv::Scalar(255, 255, 255)
#define BLACK cv::Scalar(0, 0, 0)
#define GREEN cv::Scalar(255, 255, 0)
#define BLUE cv::Scalar(255, 0, 0)
#define RED cv::Scalar(0, 0, 255)

int main() {
    int w, h;
    w = 1000;
    h = 1000;

    Eigen::Vector2d gravity = Eigen::Vector2d(0, 1e-2);

    Eigen::Vector2d emitterOrigin = Eigen::Vector2d(w/2, h/2);

    ParticleSystem::RadialPS ps(10000, emitterOrigin);

    std::time_t deltaTime = 0;

    while(1) {
        std::time_t time0 = std::time(nullptr);

        ps.run(deltaTime);

        std::vector<Particle> particles = ps.getParticles();

        cv::Mat img = cv::Mat::zeros(h, w, CV_8UC3);
        double alpha0 = 0;
        double alpha1 = 0;
        
        for(int i=0; i<particles.size(); i++) {
            Particle particle = particles.at(i);

            /* Draw semi-transparent circle */
            Eigen::Vector2d pos = {particle.getPos()(0), particle.getPos()(1)};
            double distance = (emitterOrigin - pos).norm();
            double refDistance = 200;

            alpha0 = distance/refDistance;
            alpha1 = particle.getLifeSpan();

            // std::cout << alpha0 << " " << alpha1 << std::endl;
            
            double alpha = 255*(0.6*(alpha1/255) + 0.4*(1-alpha0));
            cv::Scalar color = cv::Scalar(alpha, alpha, alpha);

            std::cout << alpha << std::endl;

            cv::circle(img, cv::Point2d(pos(0), pos(1)), 5, color, CV_FILLED);
        }

        cv::imshow("Particle System", img);
        cv::waitKey(10);

        std::time_t time = std::time(nullptr);
        deltaTime = time - time0;
    }

    return 0;
}