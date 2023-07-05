#include "collectibles.h"

//Collectibles section init and funcs
void Collectibles::Init(std::string textureName, sf::Vector2f position) {//init for collectable obj
	Static::Init(textureName, position);
};

bool Collectibles::isNotPickedUp() { //true if object was not previously picked up
	return !picked_up;
};

//Collectibles section init and funcs

//Carrot section init and funcs
void Carrot::Init(std::string textureName, sf::Vector2f position) {
	Collectibles::Init(textureName, position);
};

int Carrot::onCollect() { ////redefined virt oncollect func
	picked_up = true;
	return 1;
}
//Carrot section init and funcs

//Strawberry section init and funcs
void Strawberry::Init(std::string textureName, sf::Vector2f position) {
	Collectibles::Init(textureName, position);
};

int Strawberry::onCollect() {//redefined virt oncollect func
	picked_up = true;
	return -3;
}
//Strawberry section init and funcs

//Key section init and funcs
void Key::Init(std::string textureName, sf::Vector2f position) {
	Collectibles::Init(textureName, position);
};

int Key::onCollect() {//redefined virt oncollect func
	picked_up = true;
	return 1;
}

//Key section init and funcs

