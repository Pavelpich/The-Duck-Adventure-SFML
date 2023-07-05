#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"
#include "game.h"
#include "collectibles.h"
#include "exception.h"

void Game::InitGame() {
	sf::Vector2f viewSize(1600, 900); //create window with view
	sf::VideoMode vm(viewSize.x, viewSize.y); //create videomode on x and y size
	window = new sf::RenderWindow(vm, "Jumping Duck", sf::Style::Default); //assign window member on videomode

	sf::Vector2f playerPosition; //create player position vector

	playerMoving = false; // default value for playermoving in init is false
	inverse = false; // as upper is default val is false


	float currentTime; //variable for time
	float prevTime = 0.0f; //to track time last sec

	/// GOOSE SIZE 80x80
	//Create all platform objects
	Platform* platform = new Platform();
	Platform* platform2 = new Platform();
	Platform* platform3 = new Platform();
	Platform* platform4 = new Platform();
	Platform* platform5 = new Platform();
	Platform* platform6 = new Platform();
	Platform* platform7 = new Platform();
	Platform* platform8 = new Platform();
	Platform* platform9 = new Platform();
	Platform* platform10 = new Platform();
	Platform* platform11 = new Platform();
	Platform* platform12 = new Platform();
	Platform* platform13 = new Platform();
	Platform* platform14 = new Platform();
	//Create all spike objects
	Spike* Spike1 = new Spike();
	Spike* Spike2 = new Spike();
	Spike* Spike3 = new Spike();
	Spike* Spike4 = new Spike();
	Spike* Spike5 = new Spike();
	Spike* Spike6 = new Spike();
	Spike* Spike7 = new Spike();
	Spike* Spike8 = new Spike();
	Spike* Spike9 = new Spike();
	Spike* Spike10 = new Spike();
	Spike* Spike11 = new Spike();
	Spike* Spike12 = new Spike();
	Spike* Spike13 = new Spike();
	Spike* Spike14 = new Spike();
	Spike* Spike15 = new Spike();
	Spike* Spike16 = new Spike();
	Spike* Spike17 = new Spike();
	Spike* Spike18 = new Spike();
	Spike* Spike19 = new Spike();
	Spike* Spike20 = new Spike();
	Spike* Spike21 = new Spike();
	Spike* Spike22 = new Spike();
	Spike* Spike23 = new Spike();

	//Create all floors objects
	Floor* First_Floor = new Floor();
	Floor* Second_Floor = new Floor();
	Floor* Third_Floor = new Floor();

	//Create all walls objects and assign them to static members of game
	First_Wall = new Wall();
	Second_Wall = new Wall();
	Third_Wall = new Wall();
	
	//create carrot
	Carrot* carrot = new Carrot();
	
	//create strawberry
	Strawberry* strawberry = new Strawberry();

	//create hearts to track health of duck
	Static* Heart1 = new Static();
	Static* Heart2 = new Static();
	Static* Heart3 = new Static();

	//create exit door
	exit_door = new Platform();

	//create pickable key to open door
	key = new Key();

	//create our goose
	goose = new Hero();

	//create static background with grass etc
	background = new Static();

	//init goose with mass, coordinates 
	goose->init("Assets/fanim.png", 6, 0.75f, sf::Vector2f(0 + 40, 870 - 40), 177);
	srand((int)time(0)); //initialize time

	//init door
	exit_door->Init("Assets/door.png", sf::Vector2f(0+1530, 10));

	//initialize all platforms
	platform2->Init("Assets/platform.png", sf::Vector2f(1590 - 100, 900 - 90 - 26));
	platform->Init("Assets/platform.png", sf::Vector2f(1456, 900 - 330 - 26));
	platform4->Init("Assets/platform.png", sf::Vector2f(1590 - 100, 900 - 230 - 26));
	platform5->Init("Assets/platform.png", sf::Vector2f(1590 - 100, 900 - 420 - 26));
	platform3->Init("Assets/platform.png", sf::Vector2f(800 + 32, 315 - 26));
	platform6->Init("Assets/platform.png", sf::Vector2f(930 + 32, 240 - 26));
	platform7->Init("Assets/platform.png", sf::Vector2f(1040 + 32, 167 - 26));
	platform8->Init("Assets/platform.png", sf::Vector2f(1190 + 32, 140 - 26));
	platform9->Init("Assets/platform.png", sf::Vector2f(1190 + 132, 140 - 26));
	platform10->Init("Assets/platform.png", sf::Vector2f(1190 + 232, 140 - 26));
	platform11->Init("Assets/platform.png", sf::Vector2f(384 + 32, 704 - 87));
	platform12->Init("Assets/platform.png", sf::Vector2f(384 + 32, 544 - 90));
	platform13->Init("Assets/platform.png", sf::Vector2f(384 + 202, 544 - 170));
	platform14->Init("Assets/platform.png", sf::Vector2f(1190 + 232, 140 - 26));

	//place all platforms in vector
	platforms.push_back(platform);
	platforms.push_back(platform2);
	platforms.push_back(platform3);
	platforms.push_back(platform4);
	platforms.push_back(platform5);
	platforms.push_back(platform6);
	platforms.push_back(platform7);
	platforms.push_back(platform8);
	platforms.push_back(platform9);
	platforms.push_back(platform10);
	platforms.push_back(platform11);
	platforms.push_back(platform12);
	platforms.push_back(platform13);
	platforms.push_back(platform14);
// Spikes
	/// Zero Floor
	//init all spikes
	Spike1->Init("Assets/spike.png", sf::Vector2f(500, 830));
	Spike2->Init("Assets/spike.png", sf::Vector2f(519, 830));
	Spike4->Init("Assets/spike.png", sf::Vector2f(681, 830));
	Spike5->Init("Assets/spike.png", sf::Vector2f(1044, 830));

	/// On Platform
	Spike3->Init("Assets/spike.png", sf::Vector2f(1349, 85));

	/// First Floor
	Spike6->Init("Assets/spike.png", sf::Vector2f(1357, 674));
	Spike7->Init("Assets/spike.png", sf::Vector2f(1250, 674));
	Spike8->Init("Assets/spike.png", sf::Vector2f(1027, 674));
	Spike9->Init("Assets/spike.png", sf::Vector2f(827, 674));
	Spike10->Init("Assets/spike.png", sf::Vector2f(610, 674));
	Spike11->Init("Assets/spike.png", sf::Vector2f(629, 674));
	Spike12->Init("Assets/spike.png", sf::Vector2f(648, 674));
	Spike13->Init("Assets/spike.png", sf::Vector2f(667, 674));

	/// Second Floor
	Spike14->Init("Assets/spike.png", sf::Vector2f(576, 514));
	Spike15->Init("Assets/spike.png", sf::Vector2f(629, 514));
	Spike16->Init("Assets/spike.png", sf::Vector2f(648, 514));
	Spike17->Init("Assets/spike.png", sf::Vector2f(667, 514));
	Spike18->Init("Assets/spike.png", sf::Vector2f(610, 514));
	Spike19->Init("Assets/spike.png", sf::Vector2f(710, 514));
	Spike20->Init("Assets/spike.png", sf::Vector2f(863, 514));
	Spike21->Init("Assets/spike.png", sf::Vector2f(882, 514));
	Spike22->Init("Assets/spike.png", sf::Vector2f(1000, 514));
	Spike23->Init("Assets/spike.png", sf::Vector2f(1050, 514));

	//place all spikes into vector
	spikes.push_back(Spike1);
	spikes.push_back(Spike2);
	spikes.push_back(Spike3);
	spikes.push_back(Spike4);
	spikes.push_back(Spike5);
	spikes.push_back(Spike6);
	spikes.push_back(Spike7);
	spikes.push_back(Spike8);
	spikes.push_back(Spike9);
	spikes.push_back(Spike10);
	spikes.push_back(Spike11);
	spikes.push_back(Spike12);
	spikes.push_back(Spike13);
	spikes.push_back(Spike14);
	spikes.push_back(Spike15);
	spikes.push_back(Spike16);
	spikes.push_back(Spike17);
	spikes.push_back(Spike18);
	spikes.push_back(Spike19);
	spikes.push_back(Spike20);
	spikes.push_back(Spike21);
	spikes.push_back(Spike22);
	spikes.push_back(Spike23);

	//init carrot to restore health
	carrot->Init("Assets/carrot.png", sf::Vector2f(1129, 340));

	//place carrot into vector
	carrots.push_back(carrot);

	//create strawberry
	strawberry->Init("Assets/strawberry.png", sf::Vector2f(1300, 820));
	//strawberry2->Init("Assets/strawberry.png", sf::Vector2f(800, 900 - 200));

	//place strawberry in to vector
	strawberries.push_back(strawberry);
	//strawberries.push_back(strawberry2);

	//init hearts and place to vector
	Heart1->Init("Assets/heart.png", sf::Vector2f(25, 20));
	Heart2->Init("Assets/heart.png", sf::Vector2f(50, 20));
	Heart3->Init("Assets/heart.png", sf::Vector2f(75, 20));

	hearts.push_back(Heart1);
	hearts.push_back(Heart2);
	hearts.push_back(Heart3);

	//init key
	key->Init("Assets/key.png", sf::Vector2f(1380, 500));

	//initialize background
	background->Init("Assets/background.png", sf::Vector2f(0, 0));

// Floors and Walls
	//Floors init
	First_Floor->Init("Assets/first_floor.png", sf::Vector2f(384, 704), 1072);
	Second_Floor->Init("Assets/second_floor.png", sf::Vector2f(528, 544), 928);
	Third_Floor->Init("Assets/third_floor.png", sf::Vector2f(800, 384), 656);

	//place floors into vector
	floors.push_back(First_Floor);
	floors.push_back(Second_Floor);
	floors.push_back(Third_Floor);

	//Walls init
	First_Wall->Init("Assets/first_wall.png", sf::Vector2f(384, 0));
	Second_Wall->Init("Assets/second_wall.png", sf::Vector2f(1424, 416));
	Third_Wall->Init("Assets/third_wall.png", sf::Vector2f(800, 0));

};

//If key pressed move to the side chosen
void Game::UpdateInput() {
	sf::Event event;

	/// Key press.
	while (window->pollEvent(event))
	{

		if (event.type == sf::Event::KeyPressed) { //right key press 

			if (event.key.code == sf::Keyboard::Right)
			{
				playerMoving = true;
				inverse = false;
			}
		}

		if (event.type == sf::Event::KeyReleased) {

			if (event.key.code == sf::Keyboard::Right) { //right key released

				playerMoving = false;
				inverse = false;
			}

		}

		if (event.type == sf::Event::KeyPressed) {//left key press 

			if (event.key.code == sf::Keyboard::Left) 
			{
				playerMoving = true;
				inverse = true;
			}
		}

		if (event.type == sf::Event::KeyReleased) {

			if (event.key.code == sf::Keyboard::Left) { //left key release 

				playerMoving = false;
				inverse = true;
			}

		}

		if (event.key.code == sf::Keyboard::Up)
		{
			goose->jump(400.0f); // Jump Velocity
		}

		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) // press up
		{
			window->close();
		}
	}
};


void Game::draw(sf::RenderWindow& window) {
	window.draw(background->getSprite()); //draw background

	window.draw(goose->getSprite()); //draw goose

	window.draw(exit_door->getSprite()); //draw exit_door

	for (int i = 0; i < floors.size(); i++) {
		window.draw(floors[i]->getSprite()); //draw floors
	}

	window.draw(First_Wall->getSprite()); //draw walls

	window.draw(Second_Wall->getSprite()); //draw walls

	window.draw(Third_Wall->getSprite()); //draw walls

	if(key->isNotPickedUp()) window.draw(key->getSprite()); //draw key if not yet picked up

	for (int i = 0; i < goose->getHealth(); i++) { //draw health points
		window.draw(hearts[i]->getSprite());
	}

	for (int i = 0; i < platforms.size(); i++)
	{
		window.draw(platforms[i]->getSprite()); //draw platforms
	}

	for (int i = 0; i < spikes.size(); i++)
	{
		//spikes[i]->Draw(*window);	
		window.draw(spikes[i]->getSprite()); //draw spikes
	}

	for (int i = 0; i < carrots.size(); i++)
	{
		//spikes[i]->Draw(*window);	
		if (carrots[i]->isNotPickedUp())
		window.draw(carrots[i]->getSprite()); //draw carrots
	}

	for (int i = 0; i < strawberries.size(); i++) // draw strawberries
	{
		//spikes[i]->Draw(*window);	
		if (strawberries[i]->isNotPickedUp())
		window.draw(strawberries[i]->getSprite());
	}

};

void Game::drawFull() {
	window->clear(); // Dark gray. clear screan

	draw(*window); //draw all objects

	window->display(); //show
}

 //Update Duck position (move and jump)
void Game::update(float dt, bool playerMoving, bool inverse, float min_y, bool is_key_collected) { goose->update(dt, playerMoving, inverse, min_y, is_key_collected); }

int Game::StartGame() { //main loop

	InitGame(); //init all objects

	float min_y = 870 - 40; //minimal y duck to be

	window->setFramerateLimit(60); //framerate for screen

	sf::Clock clock; //create 

	while (window->isOpen())
	{
		// Collision with vector HAH
		if (goose->isDead()) {
			throw new Exception("Your goose died :( Try again!"); //if duck dies -> throw exception
		}

		if ((goose->isCollidingWith(exit_door->getSprite()) && key_collected == true)) {
			return EXIT_SUCCESS; //if duck open door 
		};

		for (int i = 0; i < platforms.size(); i++)
		{
			if (goose->jumps_on(platforms[i]->getSprite())) {
				goose->standOnPlatform(platforms[i]->getSprite());
				//break;
			}
		}

		for (int i = 0; i < floors.size(); i++)
		{
			if (goose->stands_on_Floor(floors[i]))
				goose->standOnFloor(floors[i]->getSprite());
		}
		/*if (goose->stands_on_second_floor(Second_Floor->getSprite()))
			goose->standOnSecondFloor(Second_Floor->getSprite());

		if (goose->stands_on_third_floor(Third_Floor->getSprite()))
			goose->standOnThirdFloor(Third_Floor->getSprite());*/

		for (int i = 0; i < spikes.size(); i++)
		{
			if (goose->isCollidingWith(spikes[i]->getSprite())) {
				//goose.decreaseHealth();
				//playerMoving = true;
				goose->takeDamage(spikes[i]->GetDamage());
				goose->restart();
			}
		}

		/*for (int i = 0; i < fires.size(); i++) {
			if (goose->isCollidingWith(fires[i]->getSprite())) {
				goose->takeDamage(fires[i]->GetDamage());
				goose->restart();
			}
		}*/
		
		for (int i = 0; i < strawberries.size(); i++) {
			if (strawberries[i]->isNotPickedUp() && goose->isCollidingWith(strawberries[i]->getSprite())) {
				goose->takeDamage(strawberries[i]->onCollect());
				goose->restart();
			}
		}

		for (int i = 0; i < carrots.size(); i++) {
			if (carrots[i]->isNotPickedUp() && goose->isCollidingWith(carrots[i]->getSprite())) {
				goose->increaseHealth(carrots[i]->onCollect());
			};
		};

		if (key->isNotPickedUp() && goose->isCollidingWith(key->getSprite())) {
			key_collected = true;
			key->onCollect();
		};

		UpdateInput();




		sf::Time dt = clock.restart();
		//update(dt.asSeconds(), playerMoving, inverse, min_y);
		goose->update(dt.asSeconds(), playerMoving, inverse, min_y, key_collected);

		drawFull();
	};
}