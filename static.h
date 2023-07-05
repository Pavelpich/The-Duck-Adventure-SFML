#pragma once
#include <SFML/Graphics.hpp>

class Static {
protected:
	sf::Texture m_texture; //texture
	sf::Sprite m_sprite; //sprite
	sf::Vector2f m_position; //pos
	sf::Vector2i m_sprite_size; //size

public:
	Static();
	~Static();
	void Init(std::string textureName, sf::Vector2f position);
	sf::Sprite getSprite(); // getter for sprite
};