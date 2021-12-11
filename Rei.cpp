#include "Rei.h"

namespace ft
{
	Rei::Rei()
	{}
	Rei::~Rei()
	{}

	bool Rei::Setup()
	{
		if (!ReiTexture.loadFromFile("img/Rei.png"))
		{
			std::cout << "ERROR when loading bg.png" << std::endl;
			return false;
		}

		
		rei.setTexture(ReiTexture);
		rei.setPosition(reiPos_x, reiPos_y);
		rei.scale(scale, scale);

		return true;
	}
	void Rei::Move()
	{
		rei.setPosition(reiPos_x, reiPos_y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (reiPos_y > 0) 
				reiPos_y -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (reiPos_y < screen_h - pl_h)
				reiPos_y += speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (reiPos_x < screen_w - pl_w)
				reiPos_x += speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			if (reiPos_x > 0)
				reiPos_x -= speed;
	}

	sf::Sprite Rei::Get() { return rei; }
	sf::RectangleShape Get(sf::RectangleShape sprite) { return sprite; }

	void Rei::Shoot()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (delay > 45) {
				delay = 0;
				sf::RectangleShape shape(sf::Vector2f(shot_w, shot_h));
				shape.setFillColor(sf::Color::Red);
				sf::Vector2f coord;
				coord.x = reiPos_x + 60;
				coord.y = reiPos_y;
				shape.setPosition(coord);
				coords.push_back(coord);
				shots.push_back(shape);
			}
		}
		for (int i = 0; i < shots.size(); i++)
		{
			if (coords[i].y < 0)
			{
				coords.erase(coords.begin() + i);
				shots.erase(shots.begin() + i);
				i--;
			}
			else
			{
				coords[i].y-=30;
				shots[i].setPosition(coords[i]);
			}
		}
	}
	bool Rei::Collide(sf::RectangleShape bullet, sf::Sprite target)
	{
		if ((bullet.getPosition().x > target.getPosition().x) && (bullet.getPosition().x < target.getPosition().x + 141)) {
			if ((bullet.getPosition().y < target.getPosition().y)&&(bullet.getPosition().y> target.getPosition().y-193)){
				return true;
			}
		}
		return false;
	}
}

