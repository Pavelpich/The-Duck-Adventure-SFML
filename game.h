#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"

class Game {
private:
	Hero * goose;
	sf::RenderWindow * window;

	sf::Vector2f playerPosition;

	float currentTime;
	float prevTime = 0.0f;

	bool playerMoving;
	bool inverse;

	std::vector<Platform*> platforms;
	std::vector<Spike*> spikes;

	//private methods game
	void UpdateInput();
	void draw(sf::RenderWindow& window);
	void drawFull();
	void update(float dt, bool playerMoving, bool inverse, float min_y);
public:
	void InitGame();
	int StartGame();
};