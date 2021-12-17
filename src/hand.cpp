#include <SFML/Graphics.hpp>
#include <iostream>
#include <hand.hpp>

namespace mt
{
	Hand::Hand(int x, int y, float r)
	{
		m_x = x;
		m_y = y;
		m_r = r;
	}

	Hand::~Hand()
	{
		if (m_hand != nullptr)
			delete m_hand;
	}

	bool Hand::Setup()
	{
		if (!m_texture.loadFromFile("img/hand.png"))
		{
			std::cout << "ERROR while loading [hand.png]" << std::endl;
			return false;
		}

		m_hand = new sf::Sprite();
		m_hand->setTexture(m_texture);
		m_hand->setOrigin(m_r, m_r);
		m_hand->setPosition(m_x, m_y);
		m_hand->getPosition();
		return true;
	}

	void Hand::Mirror()
	{
		m_hand->scale(sf::Vector2f(-1.f, 1.f));
	}

	void Hand::Move(float y)
	{
		if (m_y >= y)
		{
			m_y -= 3;
			m_hand->setPosition(m_x, m_y);
		}
	}

	void Hand::MoveDown(float v)
	{
		m_y += v;
		m_hand->setPosition(m_x, m_y);
	}

	float Hand::GetY() { return m_y; }
	
	sf::Sprite* Hand::Get() { return m_hand; }
}

