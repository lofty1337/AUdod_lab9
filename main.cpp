#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    int n;
    std::cin >> n;
    std::vector<sf::CircleShape> circles;   
    sf::RenderWindow window(sf::VideoMode(800, 600), "nge");
    float x = 700;
    float y = 0;
    float size = 30;
    for (int i = 0; i < n; i++) {
        sf::CircleShape shape(size);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(x , y + i * (size+size));
        circles.push_back(shape);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (x > 0)
            x--;
        window.clear();
        for(int i =0;i<circles.size();i++){
            window.draw(circles[i]);
            circles[i].setPosition(x, y + i * (size+size));
        }
        
        window.display();

        std::this_thread::sleep_for(0.1ms);
    }
    return 0;
}
