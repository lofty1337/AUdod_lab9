#include "Rei.h"
#include "ZeroTwo.h"
using namespace std::chrono_literals;

int main()
{
    int score = 0;
    bool begin = false;
    ft::Rei rei;
    ft::ZeroTwo zero;
    sf::RenderWindow window(sf::VideoMode(1600, 900, 32), "Nge");

    sf::Texture texture;
    if (!texture.loadFromFile("img/bg.jpg"))
    {
        std::cout << "ERROR when loading bg.jpg" << std::endl;
        return false;
    }
    sf::Sprite back;
    back.setTexture(texture);

    sf::Texture start_texture;
    if (!start_texture.loadFromFile("img/start.jpg"))
    {
        std::cout << "ERROR when loading start.jpg" << std::endl;
        return false;
    }
    sf::Sprite start;
    start.setTexture(start_texture);

    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -5;
    }
    
    sf::Text text;
    text.setFont(font);
    text.setString("Press P to start");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setPosition(650, 350);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString(std::string("Score ") + std::to_string(score));
    scoreText.setPosition(0, 0);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(sf::Color::Red);
    

    if (!zero.Setup())
    {
        window.close();
        return -5;
    }
    if (!rei.Setup())
    {
        window.close();
        return -5;
    }

    while (window.isOpen())
    {
        sf::Image icon;
        if (!icon.loadFromFile("img/icon.png"))
        {
            return -5;
        }
        window.setIcon(32, 32, icon.getPixelsPtr());

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            begin = true;
            
        }
        if (!begin)
        {
            window.draw(start);
            window.draw(text);
            window.display();
        }
        if(begin){
            window.draw(back);
        
            window.draw(scoreText);


            rei.Move();
            window.draw(rei.Get());
            rei.Shoot();
            for (int i = 0; i < rei.shots.size(); i++) {
                window.draw(rei.shots[i]);
                if (rei.Collide(rei.shots[i], zero.GetZ())) {
                    zero.spawn();
                    ++score;
                    scoreText.setString(std::string("Score ") + std::to_string(score));
                    if ((score % 10 == 0) && (score != 0))
                        zero.enemySpeed += 0.5;
                }
                    
            }
            
            
            zero.MoveZ();
            window.draw(zero.GetZ());
            if (zero.zt_y > zero.screen_h)
            {
                zero.spawn();
                score = 0;
                scoreText.setString(std::string("Score ") + std::to_string(score));
                begin = false;
            }
            rei.delay++;

            window.display();

            std::this_thread::sleep_for(1ms);
        }
    }

    return 0;
}