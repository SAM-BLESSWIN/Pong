#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_position;

	//A rectangular object
	RectangleShape m_shape;

	float m_speed = 1000.0f;
	bool m_MovingRight = false;
	bool m_movingLeft = false;

public:
	Bat(float startX, float startY);
	FloatRect GetPosition();
	RectangleShape GetShape();
	void MoveLeft();
	void MoveRight();
	void StopLeft();
	void StopRight();
	void Update(Time deltatime);
};
