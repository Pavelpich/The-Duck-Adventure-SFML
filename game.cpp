#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"
#include "game.h"

void Game::InitGame() {

	sf::Vector2f viewSize(1600, 900);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	window = new sf::RenderWindow(vm, "Jumping Duck", sf::Style::Default);

	sf::Vector2f playerPosition;

	playerMoving = false;
	inverse = false;


	float currentTime;
	float prevTime = 0.0f;

	/// GOOSE SIZE 80x80

	Platform* platform = new Platform();
	Platform* platform2 = new Platform();
	Platform* platform3 = new Platform();
	Platform* platform4 = new Platform();
	Platform* platform5 = new Platform();
	
	Spike* spike1 = new Spike();
	Spike* spike2 = new Spike();

	goose = new Hero();

	goose->init("Assets/fanim.png", 6, 0.75f, sf::Vector2f(0 + 40, 900 - 40), 200);
	srand((int)time(0));

	platform->Init("Assets/platform.png", sf::Vector2f(100, 900 - 150 - 16), sf::Vector2f(1, 2));

	platform2->Init("Assets/platform.png", sf::Vector2f(300, 900 - 150 - 26), sf::Vector2f(1, 2));

	platform3->Init("Assets/platform.png", sf::Vector2f(500, 900 - 150 - 26), sf::Vector2f(1, 2));

	platform4->Init("Assets/platform.png", sf::Vector2f(600, 900 - 150 - 26), sf::Vector2f(1, 2));

	platform5->Init("Assets/platform.png", sf::Vector2f(800, 900 - 150 - 26), sf::Vector2f(1, 2));

	platforms.push_back(platform);
	platforms.push_back(platform2);
	platforms.push_back(platform3);
	platforms.push_back(platform4);
	platforms.push_back(platform5);

	spike1->Init("Assets/spike.png", sf::Vector2f(1100, 900 - 50));

	spike2->Init("Assets/spike.png", sf::Vector2f(1200, 900 - 50));

	spikes.push_back(spike1);

	spikes.push_back(spike2);
};

void Game::UpdateInput() {
	sf::Event event;

	/// Key press.
	while (window->pollEvent(event))
	{

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Right)
			{
				playerMoving = true;
				inverse = false;
			}
		}

		if (event.type == sf::Event::KeyReleased) {

			if (event.key.code == sf::Keyboard::Right) {

				playerMoving = false;
				inverse = false;
			}

		}

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Left)
			{
				playerMoving = true;
				inverse = true;
			}
		}

		if (event.type == sf::Event::KeyReleased) {

			if (event.key.code == sf::Keyboard::Left) {

				playerMoving = false;
				inverse = true;
			}

		}

		if (event.key.code == sf::Keyboard::Up)
		{
			goose->jump(700.0f);
		}

		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
};


void Game::draw(sf::RenderWindow& window) {
	window.draw(goose->getSprite());

	for (int i = 0; i < platforms.size(); i++)
	{
		window.draw(platforms[i]->getSprite());
	}

	for (int i = 0; i < spikes.size(); i++)
	{
		//spikes[i]->Draw(*window);	
		window.draw(spikes[i]->getSprite());
	}
};

void Game::drawFull() {
	window->clear(); // Dark gray.

	draw(*window);

	window->display();
}

 //Update Duck position (move and jump)
void Game::update(float dt, bool playerMoving, bool inverse, float min_y) { goose->update(dt, playerMoving, inverse, min_y); }

int Game::StartGame() {

	InitGame();

	float min_y = 900 - 40;

	window->setFramerateLimit(60);

	sf::Clock clock;


	while (window->isOpen())
	{

		// Collision with vector HAH

		if (goose->isDead()) {
			return 0;
		};


		for (int i = 0; i < platforms.size(); i++)
		{
			if (goose->hitsHeadWith(platforms[i]->getSprite())) {
				goose->fallDown();
				//break;
		}

			if (goose->jumps_on(platforms[i]->getSprite())) {
				goose->standOnPlatform(platforms[i]->getSprite());
				//break;
			}
		}

		for (int i = 0; i < spikes.size(); i++)
		{
			if (goose->isCollidingWith(spikes[i]->getSprite())) {
				//goose.decreaseHealth();
				//playerMoving = true;
				inverse = true;
				goose->jumpFromDamage();
			}
		}


		UpdateInput();




		sf::Time dt = clock.restart();
		//update(dt.asSeconds(), playerMoving, inverse, min_y);
		goose->update(dt.asSeconds(), playerMoving, inverse, min_y);

		drawFull();
	};
}