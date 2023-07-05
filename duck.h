#pragma once
#include <SFML/Graphics.hpp>
#include "platform.h"

// Header File is Required to easily manage functions use them

class Hero {
private:

	int jumpCount = 0; //jump count for duck
	sf::Texture m_texture; //duck texture
	sf::Sprite m_sprite; //sprite of duck
	sf::Vector2f m_position; //vector position for duck
	float m_mass; //mass of duck for jumping
	float m_velocity; //velocity for jumping
	const float m_gravity = 9.80f; // g constant for jump
	bool m_grounded; // true if is on solid ground
	sf::Vector2f original_pos; //position of start

	int m_frameCount; //fps counter for animation
	float m_animDuration; //duration for animation
	float m_elapsedTime=0.0;//time passed
	sf::Vector2i m_spriteSize; //prite size
	int health_points; //hearts

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
	
	// true if standing on floor
	bool stands_on_Floor(Floor * floor);
	
	// stay on floor
	void standOnFloor(sf::Sprite floor);

	//move to starting position
	void restart();
};