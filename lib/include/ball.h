#pragma once
#include<SFML/Graphics.hpp> 
#include <cmath> 
#include <time.h>

class Ball {
    public:
        Ball(float initVY, float vX, float rad, float startX, float startY) {
            initVelY = initVY;
            velY = initVY;
            velX = vX;
            time = 0;
            sf::CircleShape shape(rad);
            shape.setFillColor(sf::Color::White);
            shape.setPosition(startX, startY);
            drawing = shape;
        }
        
        sf::Vector2f getPos() {
            return drawing.getPosition() + sf::Vector2f(getRad(), getRad());
        }

        void setPos(float x, float y) {
            drawing.setPosition(x, y);
        }

        sf::Vector2f getVel() {
            return sf::Vector2f(velX, velY);
        }

        void setVel(float vX, float vY) {
            velX = vX;
            velY = vY;
        }

        float getRad() {
            return drawing.getRadius();
        } 

        float getInitVelY() {
            return initVelY;
        }

        void setInitVelY(float initvY) {
            initVelY = initvY;
        }

        float getT() {
            return time;
        }

        void setT(float t) {
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

        void move(float g, int winX, int winY) {
            drawing.move(velX, velY);
            time += 0.001;
            velY = initVelY + g*time;

            if (checkGround(winY)) {
                initVelY = -0.80*velY;
                velY = initVelY;
                time = 0;
                sf::Vector2f pos = getPos();
                drawing.setPosition(getPos().x, getPos().y - getRad());
                velX *= 0.9995;
            }

            if (checkLeftWall() || checkRightWall(winX)) {
                velX *= -1;
            }
        }
    
    private:
        float initVelY;
        float velY;
        float velX;
        float time;
        sf::CircleShape drawing;
};