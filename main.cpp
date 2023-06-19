#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"
#include "game.h"

using namespace sf;

/// ADD BACKGROUND !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// goose is done 
// now you should make jumping on platform.

// Render window
//sf::Vector2f viewSize(1600, 900);
//sf::VideoMode vm(viewSize.x, viewSize.y);
//RenderWindow window(vm, "Jumping Duck", sf::Style::Default);
//
//
//sf::Vector2f playerPosition;
//
//// Create a rectangle shape
//
//
//
//// Check Goose moving status
//
//bool playerMoving = false;
//bool inverse = false;
//
//
//float currentTime;
//float prevTime = 0.0f;
//
//
///// To add in class make them private or so and with init function iniliaze ));
//
//Hero goose;   /// GOOSE SIZE 80x80
//
//Platform platform;
//Platform platform2;
//Platform platform3;
//Platform platform4;
//Platform platform5;
//
//std::vector<Platform> platforms;
//
//Spike spike1;
//Spike spike2;
//
//std::vector<Spike> spikes;
//
//// MINIMAL POSITION TO JUMP ON.
//
//// 900 - Max Height ; 40 - height of goose / 2.
//
//// If you want on exact coordinate declare with minus
//
//
//
//
//
//void init()
//{
//	goose.init("Assets/fanim.png", 6, 0.75f, sf::Vector2f(0 + 40, 900 - 40), 200);
//	srand((int)time(0));
//
//	platform.Init("Assets/platform.png", sf::Vector2f(100, 900 - 150 - 16), sf::Vector2f(1, 2));
//
//	platform2.Init("Assets/platform.png", sf::Vector2f(300, 900 - 150 - 26), sf::Vector2f(1,2));
//
//	platform3.Init("Assets/platform.png", sf::Vector2f(500, 900 - 150 - 26), sf::Vector2f(1, 2));
//
//	platform4.Init("Assets/platform.png", sf::Vector2f(600, 900 - 150 - 26), sf::Vector2f(1, 2));
//
//	platform5.Init("Assets/platform.png", sf::Vector2f(800, 900 - 150 - 26), sf::Vector2f(1, 2));
//
//	platforms.push_back(platform);
//	platforms.push_back(platform2);
//	platforms.push_back(platform3);
//	platforms.push_back(platform4);
//	platforms.push_back(platform5);
//
//	spike1.Init("Assets/spike.png", sf::Vector2f(1100, 900 - 50));
//
//	spike2.Init("Assets/spike.png", sf::Vector2f(1200, 900 - 50));
//
//	spikes.push_back(spike1);
//
//	spikes.push_back(spike2);
//}
//
//
//// jump 600.0f
//// Control flow (Key Press Handling)
//void updateInput()
//{
//	Event event;
//
//	/// Key press.
//	while (window.pollEvent(event))
//	{
//
//		if (event.type == sf::Event::KeyPressed) {
//
//			if (event.key.code == sf::Keyboard::Right)
//			{
//				playerMoving = true;
//				inverse = false;
//			}
//		}
//
//		if (event.type == sf::Event::KeyReleased) {
//
//			if (event.key.code == sf::Keyboard::Right) {
//
//				playerMoving = false;
//				inverse = false;
//			}
//
//		}
//
//		if (event.type == sf::Event::KeyPressed) {
//
//			if (event.key.code == sf::Keyboard::Left)
//			{
//				playerMoving = true;
//				inverse = true;
//			}
//		}
//
//		if (event.type == sf::Event::KeyReleased) {
//
//			if (event.key.code == sf::Keyboard::Left) {
//
//				playerMoving = false;
//				inverse = true;
//			}
//
//		}
//
//		if (event.key.code == sf::Keyboard::Up)
//		{
//			goose.jump(700.0f);
//		}
//
//		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
//		{
//			window.close();
//		}
//	}
//}
//
//
//// Update Duck position (move and jump)
//void update(float dt, bool playerMoving, bool inverse, float min_y) { goose.update(dt, playerMoving, inverse, min_y); }
//
//
//
//void draw() {
//	window.draw(goose.getSprite());
//
//	for (int i = 0; i < platforms.size(); i++)
//	{
//		window.draw(platforms[i].getSprite());
//	}
//
//	for (int i = 0; i < spikes.size(); i++)
//	{
//		window.draw(spikes[i].getSprite());
//	}
//}
//
//void drawFull()
//{
//	window.clear(); // Dark gray.
//
//	draw();
//
//	window.display();
//}
//
//
//
//
//int main()
//{
//	init();
//
//	float min_y = 900 - 40;
//
//	window.setFramerateLimit(60);
//
//	sf::Clock clock;
//
//
//
//
//	while (window.isOpen())
//	{
//
//		// Collision with vector HAH
//
//		if (goose.isDead()) {
//			return 0;
//		};
//
//
//		for (int i = 0; i < platforms.size(); i++)
//		{
//			if (goose.hitsHeadWith(platforms[i].getSprite())) {
//				goose.fallDown();
//				//break;
//			}
//
//			if (goose.jumps_on(platforms[i].getSprite())) {
//				goose.standOnPlatform(platforms[i].getSprite());
//				//break;
//			}
//		}
//
//		for (int i = 0; i < spikes.size(); i++)
//		{
//			if (goose.isCollidingWith(spikes[i].getSprite())) {
//				//goose.decreaseHealth();
//				//playerMoving = true;
//				inverse = true;
//				goose.jumpFromDamage();
//			}
//		}
//
//
//		updateInput();
//
//
//
//
//		sf::Time dt = clock.restart();
//		update(dt.asSeconds(), playerMoving, inverse, min_y);
//
//		drawFull();
//
//	}
//
//	return 0;
//}

int main() {
	Game TheDuckAdventure;
	TheDuckAdventure.StartGame();
	return 0;
}