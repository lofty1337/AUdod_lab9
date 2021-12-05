#include "ZeroTwo.h"

namespace ft
{
	ZeroTwo::ZeroTwo()
	{
	}
	ZeroTwo::~ZeroTwo(){}

	bool ZeroTwo::Setup()
	{
		if (!zeroTwoTexture.loadFromFile("img/02.png"))
		{
			std::cout << "ERROR when loading 02.png" << std::endl;
			return false;
		}

		zerotwo.setTexture(zeroTwoTexture);
		zerotwo.setPosition(zt_x, zt_y);
		zerotwo.scale(zt_scale, zt_scale);
		
		return true;
	}

	void ZeroTwo::spawn()
	{
		zt_y = -200;
		zt_x = rand() % edge + 0;
	}
	sf::Sprite ZeroTwo::GetZ() { return zerotwo; }
	void ZeroTwo::MoveZ()
	{
		zerotwo.setPosition(zt_x, zt_y);
		zt_y += enemySpeed;
	}
}