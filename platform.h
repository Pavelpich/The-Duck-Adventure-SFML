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

	void Init(std::string textureName, sf::Vector2f position);

	float getY();

	float getX();

	bool Detect(float x, float y);
};
class Floor : public Platform {
private:
	int height; // private mem height for collision
public:
	Floor(); //def constructor
	~Floor();
	//Init for floor, accepts height as one more param
	void Init(std::string textureName, sf::Vector2f position, int height);
	int getHeight();//getter for height
};
class Wall : public Platform {};