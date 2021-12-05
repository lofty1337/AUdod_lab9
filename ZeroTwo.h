#pragma once
#include "Rei.h"

namespace ft
{
	class ZeroTwo
	{
	public:
		ZeroTwo();
		~ZeroTwo();

		bool Setup();

		sf::Sprite GetZ();
		
		void spawn();

		void MoveZ();

		int screen_w = 1600, screen_h = 900;
		float enemySpeed = 6;
		float zt_scale = 0.3;
		float zt_w = 470*zt_scale, zt_h = 643*zt_scale;
		int edge = screen_w - int(zt_w);
		float zt_x=400, zt_y=-200;
	
		sf::Texture zeroTwoTexture;
		sf::Sprite zerotwo;

	};
}