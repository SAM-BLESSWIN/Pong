#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_position;
	RectangleShape m_shape;
	float m_speed = 1000.0f;
	float m_directionX = 0.2f;
	float m_directionY = 0.2f;

public:
	Ball(float startX,float startY);
	FloatRect getPosition(); 
	RectangleShape getShape();
	float getXVelocity(); 
	float GetSpeed();
	void SetSpeed(float speed);
	void reboundSides(); 
	void reboundBatOrTop(); 
	void reboundBottom(); 
	void update(Time deltatime);

};