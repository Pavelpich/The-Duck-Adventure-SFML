#pragma once
#include "static.h"
#include <SFML/Graphics.hpp>

class Platform : public Static {
private:
	//sf::Vector2f m_position;
	sf::Vector2f m_size;
public:
	Platform();
	~Platform();

	void Init(std::string textureName, sf::Vector2f position, sf::Vector2f size);

	float getY();

	float getX();

	bool Detect(float x, float y);
};
class Floor : public Platform {};
class Wall : public Platform {};