#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.cpp"
#include <vector>

using namespace sf;


// Render window
sf::Vector2f viewSize(1600, 900);
sf::VideoMode vm(viewSize.x, viewSize.y);
RenderWindow window(vm, "Jumping Duck", sf::Style::Default);



Vector2f playerPosition;


// Checks goose moving status.

bool playerMoving = false;
bool inverse = false;



float currentTime;
float prevTime = 0.0f;


// Initialize Classes (maybe in other place?)

Hero duck;
Platform rect;
Platform rectT;





// MINIMAL POSITION TO JUMP ON.

float min_y = 900 - 40; // 900 - Max Height ; 40 - height of duck/2.


// If you want on exact coordinate declare with minus
// FOR DUCK -40 because origin is at centre
// FOR PLATFORM -height because origin is at 0,0;


// Function To fully initialize
void init()
{
	duck.init("Assets/fanim.png", 6, 0.75f, sf::Vector2f(40, 900-40), 200);
	srand((int)time(0));

	rect.init(sf::Vector2f(600, 750-50), sf::Vector2f(200, 50));
	rectT.init(sf::Vector2f(900, 650 - 50), sf::Vector2f(200, 50));
}


// Control flow
void updateInput()
{
	Event event;

	/// Key press.
	while (window.pollEvent(event))
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
			duck.jump(750.0f);
		}

		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}


// Update Duck position (move and jump)
void update(float dt, bool playerMoving, bool inverse, float min_y) { duck.update(dt, playerMoving, inverse, min_y);  }


// Object Draw.
void draw() { window.draw(duck.getSprite()); window.draw(rect.shape()); window.draw(rectT.shape()); }


// Window Background draw + Object draw.
void drawFull()
{
	window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.

	draw();
	
	window.display();
}



int main()
{
	init();
	

	window.setFramerateLimit(60);

	sf::Clock clock;		// Clock for delta time ; to manage smooth moving + jump

	
	

	while (window.isOpen())
	{
		updateInput();

		
		
		/// COLLISION DETECTION IS NOT WORKING FIX THEM IN PLATFORM FILE.

		if (rect.Detect(duck.getX(), duck.getY()))
		{
			min_y = rect.getY() - 40;
		} 
		else if (!rect.Detect(duck.getX(), duck.getY()))
		{
			min_y = 900 - 40;
		}


		/// ONE IS WORKING SECOND WILL NOT WORK
		/// FIX IT!
		

		sf::Time dt = clock.restart();

		update(dt.asSeconds(), playerMoving, inverse, min_y);
		

		drawFull();

	}

	return 0;
}

/// I tried to fully optimize code and I did it 
/// by deriving object into separate files main file is only compiling window.