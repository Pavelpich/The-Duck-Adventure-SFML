#include <SFML/Graphics.hpp>
#include "obstacles.h"

//Obstacles section init and funcs
void Obstacles::Init(std::string textureName, sf::Vector2f position)
{
	Static::Init(textureName, position);
	int GetDamage();
};
//Obstacles section init and funcs

//Spike section init and funcs
void Spike::Init(std::string textureName, sf::Vector2f position)
{
	Obstacles::Init(textureName, position);

};

int Spike::GetDamage() {
	return -1;
}
//Spike section init and funcs

//Fire section init and funcs
void Fire::Init(std::string textureName, sf::Vector2f position)
{
	Obstacles::Init(textureName, position);

};

int Fire::GetDamage() {
	return -3;
}
//Fire section init and funcs