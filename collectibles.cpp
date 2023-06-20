#include "collectibles.h"

//Collectibles section init and funcs
void Collectibles::Init(std::string textureName, sf::Vector2f position) {
	Static::Init(textureName, position);
};

bool Collectibles::isNotPickedUp() {
	return !picked_up;
};

//Collectibles section init and funcs

//Carrot section init and funcs
void Carrot::Init(std::string textureName, sf::Vector2f position) {
	Collectibles::Init(textureName, position);
};

int Carrot::onCollect() {
	picked_up = true;
	return 1;
}
//Carrot section init and funcs

//Strawberry section init and funcs
void Strawberry::Init(std::string textureName, sf::Vector2f position) {
	Collectibles::Init(textureName, position);
};

int Strawberry::onCollect() {
	picked_up = true;
	return -3;
}
//Strawberry section init and funcs

//Key section init and funcs
void Key::Init(std::string textureName, sf::Vector2f position) {
	Collectibles::Init(textureName, position);
};

int Key::onCollect() {
	picked_up = true;
	return 1;
}

//Key section init and funcs

