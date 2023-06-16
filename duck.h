#pragma once
#include <SFML/Graphics.hpp>

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

	int m_frameCount;
	float m_animDuration;
	float m_elapsedTime;;
	sf::Vector2i m_spriteSize;

public:

	// Constructor || Destructor // 
	Hero();
	~Hero();

	// initialise goose
	void init(std::string textureName,int frameCount, float animDuration, sf::Vector2f position, float mass);

	// update position
	void update(float dt, bool playermoving, bool inverse, float min_y);

	// jump
	void jump(float velocity);

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

	bool jumps_on(sf::Sprite platform);
	void standOnPlatform(sf::Sprite platform);

	bool hitsHeadWith(sf::Sprite platform);
	void fallDown();
};