#pragma once
#include <SFML/Graphics.hpp>
#include "duck.h"
class Static {
public:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	//sf::Vector2i m_spriteSize; //defined in children
	//sf::Vector2f m_size; //defined in children

	sf::RectangleShape rectangle;

	//virtual void collide(Hero hero) {};

};