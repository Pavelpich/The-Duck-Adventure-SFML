/*
	modelling and data abstraction:
		all classes inherit from Static class, except Hero,
		Game class members of vectors with pointers and etc is composition example,
		classes like Carrot is hierhically inherited from Static class this is example of hierarchy,
		most classes have private and public methods
	polymorphism and virtual functions:
		virtual method onCollect for abs Collectable class
		virtual method GetDamage() for abs class Obstacles
	STL containers:
		vector of pointers: eg spikes, floors, platforms
	exception handling:
		Exception class instance with message of which is catched in main cpp by catch(Exception *ex)
*/
#include <SFML/Graphics.hpp>
#include <vector>
#include "duck.h"
#include "platform.h"
#include "obstacles.h"
#include "game.h"
#include "exception.h"
#include <iostream>

using namespace sf;

int main() {
	Game TheDuckAdventure; // Creating Game instance (in our case the duck game!)
	try {
		TheDuckAdventure.StartGame(); //Exception handling, we made class Exception 
	}								  // create new instance of it and raise it in case of errors
	catch(Exception * ex) // catch instance of exception cls
	{
		std::cout << ex->getMsg() << std::endl; //cout the message of error
		return -1;
	}
	return 0;
}