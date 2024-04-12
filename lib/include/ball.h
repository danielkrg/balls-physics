#pragma once
#include <SFML/Graphics.hpp> 



struct Ball {
    sf::Vector2f currentPosition;
    sf::Vector2f lastPosition;
    sf::Vector2f acceleration;
    float radius;
    sf::Color color = sf::Color::White;

    Ball() = default;
    Ball(sf::Vector2f pos, float rad)
        : currentPosition{pos}
        , lastPosition{pos}
        , acceleration{0.0f, 0.0f}
        , radius{rad}
    {}
        
    void update(float dt) {
        sf::Vector2f disp = currentPosition - lastPosition;
        lastPosition = currentPosition;
        currentPosition = currentPosition + disp + acceleration * (dt * dt);
        acceleration = {};
    }

    void accelerate(sf::Vector2f a) {
        acceleration += a;
    }

    void setVelocity(sf::Vector2f vel, float dt) {
        lastPosition = currentPosition - vel * dt;
    }

    void incVelocity(sf::Vector2f vel, float dt) {
        lastPosition -= vel * dt;
    }
};

class Handler {
    public: 
        Handler() = default;
        Handler(float winX, float winY, int nBalls)
            : windowX{winX}
            , windowY{winY}
            , numBalls{nBalls}
        {}

        void update() {
            time += frame_dt;
            int num_steps = 2;
            for (int i = 0; i < num_steps; i++) {
                applyGravity();
                checkCollisions();
                checkBoundaries(frame_dt / num_steps);
                updateBalls(frame_dt / num_steps);
            }
        }

        Ball& addNewBall(sf::Vector2f pos, float rad) {
            return balls.emplace_back(pos, rad);
        }

        std::vector<Ball>& getBalls() {
            return balls;
        }

        int getNumBalls() {
            return balls.size();
        }

        void setFrameDt(float framerate) {
            frame_dt = 1.0f / framerate;
        }

        float getFrameDt() {
            return frame_dt;
        }

        float getTime() {
            return time;
        }

    private:
        sf::Vector2f gravity = {0.0f, 981.0f};
        std::vector<Ball> balls;
        float windowX;
        float windowY;
        int numBalls;
        float time = 0.0f;
        float frame_dt = 0.0f;


        void applyGravity() {
            for (auto& ball : balls) {
                ball.accelerate(gravity);
            }
        }
        
        void updateBalls(float dt) {
            for (auto& ball : balls) {
                ball.update(dt);
            }
        }
        
        void checkCollisions() {
            float dampC = 0.75f;
            for (auto& ball_1 : balls) {
                for (auto& ball_2 : balls) {
                    if (&ball_1 != &ball_2) {
                        sf::Vector2f v = ball_1.currentPosition - ball_2.currentPosition;
                        float dist = sqrt(v.x * v.x + v.y * v.y);
                        float minDist = ball_1.radius + ball_2.radius;
                        if (dist < minDist) {
                            sf::Vector2f n;
                            if (dist == 0) {
                                n = {1, 1};
                            } else {
                                n = v / dist;
                            }
                            float delta = 0.5f * dampC * (dist - minDist);
                            ball_1.currentPosition -= 0.5f * delta * n;
                            ball_2.currentPosition += 0.5f * delta * n;
                        }
                    }
                }
            }
        }
        void checkBoundaries(float dt) {
            for (auto& ball : balls) {
                sf::Vector2f pos = ball.currentPosition;
                sf::Vector2f lastPos = ball.lastPosition;
                sf::Vector2f vel = dt * (pos - lastPos);
                float dampC = 0.75f;
                float moveX = 0.0f;
                float moveY = 0.0f;
                if (pos.y + 2 * ball.radius > windowY) {
                    moveY = -2 * ball.radius + windowY - pos.y;
                    ball.lastPosition = {lastPos.x, pos.y + dampC * vel.y};
                    if (vel.y < 0.01f) {
                        ball.lastPosition = {lastPos.x + dampC * vel.x, pos.y + moveY};
                    }
                }
                if (pos.x < 0.0f) {
                    moveX = -pos.x;
                    ball.lastPosition = {pos.x + vel.x, lastPos.y};
                }
                else if (pos.x + 2 * ball.radius > windowX) {
                    moveX = -2 * ball.radius + windowX - pos.x;
                    ball.lastPosition = {pos.x + vel.x, lastPos.y};
                }
                ball.currentPosition += {moveX, moveY};
            }
        }
};