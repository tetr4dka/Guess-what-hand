#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <coin.hpp>

namespace mt
{

	Coin::Coin(int x, int y, float r, float a, float v)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_a = (360 - a) / 180 * acos(-1);
		m_v = v;
	}

	Coin::~Coin()
	{
		if (m_coin != nullptr)
			delete m_coin;
	}

	bool Coin::Setup()
	{
		if (!m_texture.loadFromFile("img/coin.png"))
		{
			std::cout << "ERROR while loading [coin.png]" << std::endl;
			return false;
		}

		m_coin = new sf::Sprite();
		m_coin->setTexture(m_texture);
		m_coin->setOrigin(m_r, m_r);
		m_coin->setPosition(m_x, m_y);
		m_coin->getPosition();

		return true;
	}

	void Coin::Move(float t)
	{
		sx = m_x + m_v * cos(m_a) * t;
		sy = m_y + m_v * sin(m_a) * t + g * t * t / 2;
		m_coin->setPosition(sx, sy);
	}

	float Coin::GetX() { return m_x; }
	float Coin::GetY() { return sy; }

	void Coin::Teleport(float y)
	{
		if ((y > 599) && (y <= 610))
		{
			srand(time(0));
			m_x = 200 * (rand() % 2 + 1);
			m_coin->setPosition(m_x, y);
		}
	}

	sf::Sprite* Coin::Get() { return m_coin; }
}
