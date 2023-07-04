/*


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