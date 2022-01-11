#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	m_position.x = startX;
	m_position.y = startY;
	m_shape.setSize(sf::Vector2f(75, 5));
	m_shape.setPosition(m_position);
}

FloatRect Bat::GetPosition()
{
	return m_shape.getGlobalBounds();
}

RectangleShape Bat::GetShape()
{
	return m_shape;
}

void Bat::MoveLeft()
{
	m_movingLeft = true;
}

void Bat::StopLeft()
{
	m_movingLeft = false;
}

void Bat::MoveRight()
{
	m_MovingRight = true;
}

void Bat::StopRight()
{
	m_MovingRight = false;
}

void Bat::Update(Time deltatime)
{
	if (m_movingLeft)
	{
		m_position.x -= m_speed * deltatime.asSeconds();
	}

	if (m_MovingRight)
	{
		m_position.x += m_speed * deltatime.asSeconds();
	}

	m_shape.setPosition(m_position);
}