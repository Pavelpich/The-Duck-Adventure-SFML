#include <SFML/Graphics.hpp>
#include "duck.h"
#include "platform.h"
#include "exception.h"


Hero::Hero() {}
Hero::~Hero() {}

void Hero::init(std::string textureName, int frameCount, float
	animDuration, sf::Vector2f position, float mass) {

	m_position = position;
	m_mass = mass;

	m_grounded = false;

	m_frameCount = frameCount;

	m_animDuration = animDuration;

	original_pos = m_position;

	// Load a Texture
	if (!m_texture.loadFromFile(textureName.c_str())) {
		throw new Exception("Image for duck was not loaded! Check the file!");
	};


	// Sprite size
	m_spriteSize = sf::Vector2i(80, 80);

	// Create Sprite and Attach a Texture
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_spriteSize.x / 2, m_spriteSize.y / 2);

	// Used for animation
	m_sprite.setTextureRect(sf::IntRect(0, 0, m_spriteSize.x, m_spriteSize.y));
	
	//Add health points when creating duck;
	health_points = 3;
}


///  I have idea to create separate SpreadSheets to animate goosy
///  but maybe it is better to have everything in one?
///  but How?
/// 
/// breath animation -> while static
/// walk animation if moving.



void Hero::update(float dt, bool playermoving, bool inverse, float min_y, bool is_key_collected) {

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
	if (m_position.x >= 1550 && !is_key_collected)
	{
		m_position.x = 1550;
	}
	if (m_position.y>=20 && m_position.x >= 1550 && is_key_collected) {
		m_position.x = 1550;
	}
	if (m_position.x <= 40)
	{
		m_position.x = 40;
	}

}

void Hero::jump(float velocity) {

	if (jumpCount < 3) {
		jumpCount++;

		m_velocity = velocity;
		m_grounded = false;
	}

}

//void Hero::jumpFromDamage() {
//	Hero::jump(700.0f);
//}

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

	if ((m_position.x > platform.getPosition().x && m_position.x < platform.getPosition().x + 80) && (m_position.y + 40 >= platform.getPosition().y && m_position.y <= platform.getPosition().y + 16)) {
		return true;
	}

	return false;
}

bool Hero::isCollidingWith(sf::Sprite obj) {
	if ((m_position.x > obj.getPosition().x && m_position.x < obj.getPosition().x + 30) && (m_position.y + 40 >= obj.getPosition().y && m_position.y <= obj.getPosition().y + 16)) {
		//return false;
		return true;
	}

	return false;
};

void Hero::standOnPlatform(sf::Sprite platform) {
	m_position.y = platform.getPosition().y - 40;
	m_velocity = 0;
	m_grounded = true;
	jumpCount = 0;
}

//bool Hero::hitsHeadWith(sf::Sprite platform) {
//	if ((m_position.x > platform.getPosition().x && m_position.x < platform.getPosition().x + 80)&&(m_position.y >= platform.getPosition().y - 40 && m_position.y <= platform.getPosition().y + 40 + 32)) {
//		return true;
//	}
//
//	return false;
//};


bool Hero::hitsHeadWith(sf::Sprite platform) {
	if ((m_position.x > platform.getPosition().x && m_position.x < platform.getPosition().x + 80)&&(m_position.y >= platform.getPosition().y - 40 && m_position.y <= platform.getPosition().y + 40 + 32)) {
		return true;
	}

	return false;
};


void Hero::fallDown() {
	m_velocity = 0;
};

int Hero::getHealth() {
	return health_points;
}

//void Hero::decreaseHealth() {
//	health_points--;
//};

//void Hero::die() {
//	health_points=0;
//};

//bool Hero::stands_on_first_floor(sf::Sprite floor) {
//	
//}
//bool Hero::stands_on_second_floor(sf::Sprite floor) {}
//bool Hero::stands_on_third_floor(sf::Sprite floor) {}

bool Hero::stands_on_Floor(Floor * floor) {
	if ((m_position.x > floor->getSprite().getPosition().x && m_position.x < (floor->getSprite().getPosition().x) + (floor->getHeight())) && (m_position.y + 40 >= floor->getSprite().getPosition().y && m_position.y <= floor->getSprite().getPosition().y + 16))
		return true;
	else return false;
}

void Hero::standOnFloor(sf::Sprite floor){
	m_position.y = floor.getPosition().y - 40;
	m_velocity = 0;
	m_grounded = true;
	jumpCount = 0;
}

//void standOnFirstFloor(sf::Sprite floor) {};
//void standOnSecondFloor(sf::Sprite floor) {};
//void standOnThirdFloor(sf::Sprite floor) {};

void Hero::takeDamage(int dmg) {
	health_points +=dmg;
}

void Hero::increaseHealth(int hp) {
	if (health_points<3)
		health_points+= hp;
};

bool Hero::isDead() {
	if (health_points <= 0) return true;

	return false;
};

void Hero::restart() { m_position = original_pos; }