#pragma once
#include<SFML/Graphics.hpp> 
#include <cmath> 
#include <time.h>

class Ball {
    public:

        Ball(double initVY, double vX, double rad, double startX, double startY) {
            initVelY = initVY;
            velY = initVY;
            velX = vX;
            time = 0;
            sf::CircleShape shape(rad);
            shape.setFillColor(sf::Color::White);
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
        
        bool checkGround(int winY) {
            return (getPos().y + getRad() >= winY);
        }

        bool checkLeftWall() {
            return (getPos().x <= 0);
        }

        bool checkRightWall(int winX) {
            return (getPos().x + getRad() >= winX);
        }

        void move(double g, int winX, int winY) {
            time += 0.001;
            velY = initVelY + g*time;

            if (checkGround(winY)) {
                initVelY = -0.8*velY;
                velY = initVelY;
                time = 0;
                // drawing.setPosition(getPos().x, getPos().y - getRad());
                velX *= 0.9995;
            }

            if (checkLeftWall() || checkRightWall(winX)) {
                velX *= -1;
            }
            drawing.move(velX, velY);
        }
    
    private:
        double initVelY;
        double velY;
        double velX;
        double time;

        sf::CircleShape drawing;
};