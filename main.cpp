#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    float Cx,Cy,Sx,Sy,Ox,Oy;
    sf::RenderWindow window(sf::VideoMode(800, 600), "nge");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Cx = 700;
    Cy = 0;
    shape.setPosition(Cx, Cy);
    sf::CircleShape square(80.f, 4);
    square.setFillColor(sf::Color::Blue);
    Sx = 700;
    Sy = 200;
    square.setPosition(Sx, Sy);
    sf::CircleShape octagon(80.f, 8);
    octagon.setFillColor(sf::Color::Red);
    Ox = 700;
    Oy = 400;
    octagon.setPosition(Ox, Oy);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(square);
        window.draw(octagon);
        window.display();
        if (Ox > 0)
            --Ox;
        if (Cx > 0)
            --Cx;
        if (Sx > 0)
            --Sx;
        shape.setPosition(Cx, Cy);
        square.setPosition(Sx, Sy);
        octagon.setPosition(Ox, Oy);
        std::this_thread::sleep_for(0.1ms);
    }

    return 0;
}