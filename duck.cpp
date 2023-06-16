#include <SFML/Graphics.hpp>
#include "duck.h"


Hero::Hero() {}


Hero::~Hero() {}

void Hero::init(std::string textureName, int frameCount, float
	animDuration, sf::Vector2f position, float mass) {

	m_position = position;
	m_mass = mass;

	m_grounded = false;

	m_frameCount = frameCount;

	m_animDuration = animDuration;

	

	// Load a Texture
	m_texture.loadFromFile(textureName.c_str());


	// Sprite size
	m_spriteSize = sf::Vector2i(80, 80);

	// Create Sprite and Attach a Texture
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_spriteSize.x / 2, m_spriteSize.y / 2);

	// Used for animation
	m_sprite.setTextureRect(sf::IntRect(0, 0, m_spriteSize.x, m_spriteSize.y));
}


///  I have idea to create separate SpreadSheets to animate goosy
///  but maybe it is better to have everything in one?
///  but How?
/// 
/// breath animation -> while static
/// walk animation if moving.



void Hero::update(float dt, bool playermoving, bool inverse, float min_y) {

	// Animate Sprite
	

	// Jump
	m_velocity -= m_mass * m_gravity * dt;

	m_position.y -= m_velocity * dt;

	m_sprite.setPosition(m_position);


	if (m_position.y >= min_y) {

		m_position.y = min_y;
		m_velocity = 0;
		m_grounded = true;
		jumpCount = 0;
	}

	if (playermoving && !inverse) 
	{
		m_position.x += 2.8;
		// moving animation
		m_elapsedTime += dt;
		int animFrame = static_cast<int> ((m_elapsedTime / m_animDuration) * m_frameCount) % m_frameCount;
		m_sprite.setTextureRect(sf::IntRect(animFrame * m_spriteSize.x, 80, m_spriteSize.x, m_spriteSize.y));
		
	}
	else if (playermoving && inverse)
	{
		m_position.x -= 2.8;
		m_elapsedTime += dt;
		int animFrame = static_cast<int> ((m_elapsedTime / m_animDuration) * m_frameCount) % m_frameCount;
		m_sprite.setTextureRect(sf::IntRect(animFrame * m_spriteSize.x, 160, m_spriteSize.x, m_spriteSize.y));
	}
	else 
	{
		// breath animation
		m_elapsedTime += dt;
		int animFrame = static_cast<int> ((m_elapsedTime / m_animDuration) * m_frameCount) % m_frameCount;
		m_sprite.setTextureRect(sf::IntRect(animFrame * m_spriteSize.x, 0, m_spriteSize.x, m_spriteSize.y));

	}


	// -40 to make equal as texture
	if (m_position.x >= 1500-40)
	{
		m_position.x = 1500-40;
	}
	else if (m_position.x <= 40)
	{
		m_position.x = 40;
	}

}

void Hero::jump(float velocity) {

	if (jumpCount < 2) {
		jumpCount++;

		m_velocity = velocity;
		m_grounded = false;
	}

}

sf::Sprite Hero::getSprite()
{
	return m_sprite;
}

float Hero::getX() { return m_position.x; }
float Hero::getY() { return m_position.y; }

sf::Vector2f Hero::getPosition() { return m_position; }

void Hero::setPosition(float x, float y) { m_position.y = y; m_position.x = x; }

void Hero::setPositionY(float y) { m_position.y = y; }
void Hero::setPositionX(float x) { m_position.y = x; }

bool Hero::jumps_on(sf::Sprite platform) {

	if ((platform.getGlobalBounds().intersects(m_sprite.getGlobalBounds()))) {
		return true;
	}

	return false;
}

void Hero::standOnPlatform(sf::Sprite platform) {
	m_position.y = platform.getPosition().y - 40;
	m_velocity = 0;
	m_grounded = true;
	jumpCount = 0;
}

bool Hero::hitsHeadWith(sf::Sprite platform) {
	if ((m_position.x > platform.getPosition().x && m_position.x < platform.getPosition().x + 80)&&(m_position.y <= platform.getPosition().y + 40 + 32)) {
		return true;
	}

	return false;
};
void Hero::fallDown() {
	m_velocity = 0;
};