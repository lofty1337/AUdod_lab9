#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
namespace ft
{
	class Rei
	{
	public:
		Rei();
		~Rei();
		
		bool Setup();

		void Move();
		
		void Shoot();

		bool Collide(sf::RectangleShape bullet, sf::Sprite target);

		sf::Sprite Get();

		int screen_w = 1600, screen_h = 900;
		float scale = 0.25;
		float pl_h = 512 * scale, pl_w = 512 * scale;
		int speed = 14;
		int reiPos_x = 800, reiPos_y = 772;
		float shot_w = 7, shot_h = 20;
		int delay = 0;

		std::vector<sf::RectangleShape> shots;
		std::vector<sf::Vector2f> coords;

		sf::Texture ReiTexture;
		sf::Sprite rei;
	};
}