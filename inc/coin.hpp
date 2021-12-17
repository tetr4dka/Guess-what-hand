#pragma once 
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

const float g = 13;

namespace mt
{
	class Coin
	{
	public:
		Coin(int x, int y, float r, float a, float v);
		~Coin();

		bool Setup();

		void Move(float t);

		float GetX();
		float GetY();

		void Teleport(float y);

		sf::Sprite* Get();

	private:
		float m_x, m_y;
		float m_r, m_a, m_v;
		float sx, sy;

		sf::Texture m_texture;
		sf::Sprite* m_coin = nullptr;
	};
}

