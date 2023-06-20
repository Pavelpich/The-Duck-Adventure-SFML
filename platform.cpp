#include <SFML/Graphics.hpp>
#include "platform.h"

/// PLATFORM FILE IS FOR BETA TEST!


///  CHANGE ONLY THIS PIECE OF CODE


///  USE FLOATS EVERYWHERE 

Platform::Platform():Static() {};
Platform::~Platform() {};


void Platform::Init(std::string textureName, sf::Vector2f position)
{
	Static::Init(textureName, position);


	// Platform size , position , centre;
	//rectangle.setSize(m_size);
	
}

//float Platform::getY() { return m_position.y; }
//
//float Platform::getX() { return m_position.x; }

//bool Platform::Detect(float x, float y)
//{
//	// Should Equal both
//		
//	//&& x <= m_position.x + m_size.x)
//	// (x >= 600 && x <= 800) && 
//	if ((x >= m_position.x && x <= m_position.x + m_size.x) && (y >= m_position.y - 40 && y <= m_position.y + m_size.y - 40))
//	{
//		return true; /// Y should become equal to platform y position 
//		/// I think it would be better to return y and set Y everywhere .
//	}
//	else 
//	{
//		return false;
//	}
//
//	return false;
//}