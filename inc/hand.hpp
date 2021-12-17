#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace mt
{
	class Hand
	{
	public:
		Hand(int x, int y, float r);
		~Hand();

		bool Setup();

		void Mirror();

		void Move(float y);
		void MoveDown(float v);

		float GetY();

		sf::Sprite* Get();

	private:
		float m_x, m_y, m_r;

		sf::Texture m_texture;
		sf::Sprite* m_hand = nullptr;
	};
}


