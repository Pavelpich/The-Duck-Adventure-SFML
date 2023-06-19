#pragma once
#include <SFML/Graphics.hpp>

class Static {
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	//sf::Vector2i m_spriteSize; //defined in children
	//sf::Vector2f m_size; //defined in children

	//sf::RectangleShape shape;

	//bool collide(Hero hero) {};

	sf::Vector2i m_sprite_size;

public:
	Static();
	~Static();
	void Init(std::string textureName, sf::Vector2f position);
	//sf::RectangleShape getShape();
	sf::Sprite getSprite();
	void Draw(sf::RenderWindow& window);
};