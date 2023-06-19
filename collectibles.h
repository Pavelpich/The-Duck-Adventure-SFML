#pragma once
#include "static.h"
class Collectibles : public Static{
	void Init(std::string textureName, sf::Vector2f position);
};
class Carrot : public Collectibles {
	void Init(std::string textureName, sf::Vector2f position);
};
class Strawberry : public Collectibles {
	void Init(std::string textureName, sf::Vector2f position);
};
class Key : public Collectibles {
	void Init(std::string textureName, sf::Vector2f position);
};