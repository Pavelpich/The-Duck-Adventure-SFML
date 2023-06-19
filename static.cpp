#include "static.h"

Static:: Static() {}

Static::~Static() {}

void Static::Init(std::string textureName, sf::Vector2f position) {

	m_position = position;

	m_texture.loadFromFile(textureName.c_str());

	//shape.setTexture(&m_texture);
	m_sprite_size = sf::Vector2i(80, 16);

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
}

sf::Sprite Static::getSprite()
{
	return m_sprite;
}

void Static::Draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
};