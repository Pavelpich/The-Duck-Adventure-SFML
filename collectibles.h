#pragma once
#include "static.h"
class Collectibles : public Static{
protected:
	bool picked_up = false;
public:
	void Init(std::string textureName, sf::Vector2f position);
	virtual int onCollect() = 0;
	bool isNotPickedUp();
};
class Carrot : public Collectibles {
public:
	void Init(std::string textureName, sf::Vector2f position);
	int onCollect();
};
class Strawberry : public Collectibles {
public:
	void Init(std::string textureName, sf::Vector2f position);
	int onCollect();
};
class Key : public Collectibles {
public:
	void Init(std::string textureName, sf::Vector2f position);
	int onCollect();
};