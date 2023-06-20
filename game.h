#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"
#include "collectibles.h"

class Game {
private:
	Hero * goose;
	sf::RenderWindow * window;
	Key* key;
	Platform* exit_door;
	sf::Vector2f playerPosition;

	float currentTime;
	float prevTime = 0.0f;

	bool playerMoving;
	bool inverse;

	bool key_collected = false;


	std::vector<Platform*> platforms;
	std::vector<Spike*> spikes;
	//std::vector<Fire*> fires;
	std::vector<Strawberry*> strawberries;
	std::vector<Carrot*> carrots;
	std::vector<Static*> hearts;

	//private methods game
	void UpdateInput();
	void draw(sf::RenderWindow& window);
	void drawFull();
	void update(float dt, bool playerMoving, bool inverse, float min_y);
	/*bool isKeyCollected();
	void TakeKey();*/
public:
	void InitGame();
	int StartGame();
};