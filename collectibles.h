#pragma once
#include "static.h"
class Collectibles : public Static{ //abstract cls Collectables
protected:
	bool picked_up = false; //bool if object was previously picked up
public:
	void Init(std::string textureName, sf::Vector2f position); //init for collectable obj
	virtual int onCollect() = 0; //virtual func
	bool isNotPickedUp(); //getter bool func returns picked_up
};
class Carrot : public Collectibles { //carrot cls
public:
	void Init(std::string textureName, sf::Vector2f position); //init for carrot
	int onCollect(); //redefined virt oncollect func
};
class Strawberry : public Collectibles {
public:
	void Init(std::string textureName, sf::Vector2f position); //init for strawberry
	int onCollect();//redefined virt oncollect func
};
class Key : public Collectibles {
public:
	void Init(std::string textureName, sf::Vector2f position);//init for key
	int onCollect();//redefined virt oncollect func
};