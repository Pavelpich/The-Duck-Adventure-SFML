#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"
#include "collectibles.h"

class Game {
private:
	Hero * goose; // our main goose instance, player
	sf::RenderWindow * window; // creating window instance
	Key* key; //key instance to open gate
	Platform* exit_door; //door instance
	sf::Vector2f playerPosition; //vector of player position

	Static * background; //our main background, like river, grass etc.

	float currentTime; // time var
	float prevTime = 0.0f; 

	bool playerMoving; //true if player if moving
	bool inverse;//true if movement is inverse

	bool key_collected = false; //bool if key is picked up 


	std::vector<Platform*> platforms; // vector with all platform objects
	std::vector<Spike*> spikes; //vector with all spike objects
	std::vector<Strawberry*> strawberries; // vector with all strawberry objects
	std::vector<Carrot*> carrots; // vector with all carrot objects
	std::vector<Static*> hearts; // vector with all heart objects

	Wall* First_Wall; // wall object
	Wall* Second_Wall; // another wall object
	Wall* Third_Wall; // and another wall object

	/*Floor* First_Floor;
	Floor* Second_Floor;
	Floor* Third_Floor;*/
	std::vector <Floor*> floors; //vector with all floors objects

	//private methods game
	void UpdateInput(); //update position of goose if pressed
	void draw(sf::RenderWindow& window); //draw all objects on screen
	void drawFull(); // func that clears screen and includes draw()
	void update(float dt, bool playerMoving, bool inverse, float min_y, bool is_key_collected);//call update of goose object
	void InitGame(); //init all instances and objects
public:
	int StartGame();// main method to start the game
};