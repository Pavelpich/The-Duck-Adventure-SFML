#pragma once
#include "static.h"
class Obstacles : public Static {
public:
	void Init(std::string textureName, sf::Vector2f position);

	//virtual void onTouch();
};
class Spike : public Obstacles {
public:
	void Init(std::string textureName, sf::Vector2f position);
};
class Fire : public Obstacles {};