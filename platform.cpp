#include <SFML/Graphics.hpp>

/// PLATFORM FILE IS FOR BETA TEST!


///  CHANGE ONLY THIS PIECE OF CODE


///  USE FLOATS EVERYWHERE 


class Platform {
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_size;

	sf::RectangleShape rectangle;

public:
	Platform() { }
	~Platform() { }

	void init(sf::Vector2f position, sf::Vector2f size)
	{
		m_position = position;
		m_size = size;


		// Platform size , position , centre
		rectangle.setSize(m_size);
		rectangle.setOrigin(0, 0);
		rectangle.setPosition(m_position);
	}

	float getY() { return m_position.y; }

	float getX() { return m_position.x; }

	bool Detect(float x, float y)
	{
		// Should Equal both
		
		//&& x <= m_position.x + m_size.x)
		// (x >= 600 && x <= 800) && 
		if ((x >= m_position.x && x <= m_position.x + m_size.x) && (y >= m_position.y - 40 && y <= m_position.y + m_size.y - 40))
		{
			return true; /// Y should become equal to platform y position 
			/// I think it would be better to return y and set Y everywhere .
		}
		else 
		{
			return false;
		}

		return false;
	}

	sf::RectangleShape shape() { return rectangle; }
};