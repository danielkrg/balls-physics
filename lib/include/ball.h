#pragma once
#include<SFML/Graphics.hpp> 
#include <cmath> 
#include <time.h>
#include<random>



class Ball {
    public:

        Ball(double initVY, double vX, double rad, double startX, double startY) {
            initVelY = initVY;
            velY = initVY;
            velX = vX;
            time = 0;
            sf::CircleShape shape(rad);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0,255);
            shape.setFillColor(sf::Color(dis(gen),dis(gen),dis(gen)));
            // shape.setFillColor(sf::Color::White);
            shape.setOrigin(shape.getRadius(),shape.getRadius());
            shape.setPosition(startX, startY);
            drawing = shape;
        }
        
        sf::Vector2f getPos() {
            return drawing.getPosition();// + sf::Vector2f(getRad(), getRad());
        }

        void setPos(double x, double y) {
            drawing.setPosition(x, y);
        }

        sf::Vector2f getVel() {
            return sf::Vector2f(velX, velY);
        }

        void setVel(double vX, double vY) {
            velX = vX;
            velY = vY;
        }

        double getRad() {
            return drawing.getRadius();
        } 

        double getInitVelY() {
            return initVelY;
        }

        void setInitVelY(double initvY) {
            initVelY = initvY;
        }

        double getT() {
            return time;
        }

        void setT(double t) {
            time = t;
        }

        sf::CircleShape getDrawing() {
            return drawing;
        }

        void moveDrawing(double x, double y) {
            drawing.move(x, y);
        }
        

        // bool checkGround(int winY) {
        double checkGround(int winY) {
            // return (getPos().y + getRad() >= winY);
            return (winY - (getPos().y + getRad()));
        }

        // bool checkLeftWall() {
        double checkLeftWall() {
            // return (getPos().x <= 0);
            return (getPos().x - getRad());
        }

        // bool checkRightWall(int winX) {
        double checkRightWall(int winX) {
            // return (getPos().x + getRad() >= winX);
            return (winX - (getPos().x + getRad()));

        }

        void move(double g, int winX, int winY) {
            time += 0.001;
            velY = initVelY + g*time;
            float moveX = velX;
            float moveY = velY;

            if (checkGround(winY) < 0) {
                initVelY = -0.8*abs(velY);
                velY = initVelY + checkGround(winY);
                time = 0;
                // drawing.setPosition(getPos().x, winY - getRad());
                moveY = winY - getPos().y - getRad();
                velX *= 0.995;
            }

            if (checkLeftWall() < 0) {
                // drawing.setPosition(getRad(), getPos().y);
                moveX = getPos().x;
                velX *= -0.95;

            }

            if (checkRightWall(winX) < 0) {
                // drawing.setPosition(winX - getRad(), getPos().y);
                moveX = winX - getPos().x - getRad();
                velX *= -0.95;
            }

            drawing.move(moveX, moveY);
        }
    
    private:
        double initVelY;
        double velY;
        double velX;
        double time;

        sf::CircleShape drawing;
};