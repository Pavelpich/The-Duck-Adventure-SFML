#pragma once
#include <SFML/Graphics.hpp>
#include "platform.h"

// Header File is Required to easily manage functions use them

class Hero {
private:

	int jumpCount = 0;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	float m_mass;
	float m_velocity;
	const float m_gravity = 9.80f;
	bool m_grounded;
	sf::Vector2f original_pos;

	int m_frameCount;
	float m_animDuration;
	float m_elapsedTime=0.0;
	sf::Vector2i m_spriteSize;
	int health_points;

public:

	// Constructor || Destructor // 
	Hero();
	~Hero();

	// initialise goose
	void init(std::string textureName,int frameCount, float animDuration, sf::Vector2f position, float mass);

	// update position
	void update(float dt, bool playermoving, bool inverse, float min_y, bool is_key_collected);

	// jump
	void jump(float velocity);

	//move if get damage
	void jumpFromDamage();

	// Get Sprite 
	sf::Sprite getSprite();

	// Get position 
	float getX();
	float getY();
	sf::Vector2f getPosition();

	// Set position
	void setPosition(float x, float y);
	void setPositionX(float x);
	void setPositionY(float y);

	//collision with objects
	bool isCollidingWith(sf::Sprite obj);
	
	//collision with platform
	bool jumps_on(sf::Sprite platform);
	void standOnPlatform(sf::Sprite platform);
	bool hitsHeadWith(sf::Sprite platform);
	void fallDown();

	//all health methods for our duck
	int getHealth();
	void increaseHealth(int health);
	void takeDamage(int dmg);
	bool isDead();

	bool stands_on_Floor(Floor * floor);

	void standOnFloor(sf::Sprite floor);

	void pickUpKey();

	void restart();
};