#pragma once
#include "static.h"
class Obstacles : public Static {
public:
	void Init(std::string textureName, sf::Vector2f position);

	virtual int GetDamage() = 0; //virt func for getting dmg
};
class Spike : public Obstacles {
public:
	void Init(std::string textureName, sf::Vector2f position);

	 int GetDamage();
};
//class Fire : public Obstacles {
//public:
//	void Init(std::string textureName, sf::Vector2f position);
//
//	 int GetDamage();
//};