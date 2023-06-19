#include <SFML/Graphics.hpp>
#include "obstacles.h"

//Obstacles section init and funcs
void Obstacles::Init(std::string textureName, sf::Vector2f position)
{
	Static::Init(textureName, position);

};
//Obstacles section init and funcs

//Spike section init and funcs
void Spike::Init(std::string textureName, sf::Vector2f position)
{
	Obstacles::Init(textureName, position);

};
//Spike section init and funcs


