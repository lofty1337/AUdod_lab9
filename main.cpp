#include "Rei.h"
#include "ZeroTwo.h"
using namespace std::chrono_literals;

int main()
{

    


    int score = 0;
    bool begin = false;
    ft::Rei* rei = nullptr;
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
        return -1;
    }
    
    sf::Text text;
    text.setFont(font);
    text.setString("Press P to start");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setPosition(650, 350);


    rei = new ft::Rei();

    if (!zero.Setup())
    {
        window.close();
        return -1;
    }
    if (!rei->Setup())
    {
        delete rei;
        window.close();
        return -1;
    }

    while (window.isOpen())
    {
        sf::Image icon;
        if (!icon.loadFromFile("img/icon.png"))
        {
            return -1;
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
            text.setString(std::string("Score ") + std::to_string(score));
            text.setPosition(0, 0);
        }
        if (!begin)
        {
            window.draw(start);
            window.draw(text);
            window.display();
        }
        if(begin){
            window.draw(back);
        
            text.setString(std::string("Score ") + std::to_string(score));
            window.draw(text);

            if (rei != nullptr) {
                rei->Move();
                window.draw(*rei->Get());
                rei->Shoot();
                for (int i = 0; i < rei->shots.size(); i++) {
                    window.draw(rei->shots[i]);
                    if (rei->Collide(rei->shots[i], zero.GetZ())) {
                        
                        zero.spawn();
                        //rei->shots.erase(rei->shots.begin()+i);
                        //rei->Shoot();
                        ++score;
                        std::cout << rei->shots.size();
                        if ((score % 10 == 0) && (score != 0))
                            zero.enemySpeed += 0.5;
                        
                    }
                    
                }
            }
            
            zero.MoveZ();
            window.draw(zero.GetZ());
            if (zero.zt_y > zero.screen_h) {
                score = 0;
                zero.enemySpeed = 6;
                zero.spawn();
            }
            rei->delay++;

            window.display();

            std::this_thread::sleep_for(1ms);
        }
    }
    if (rei != nullptr)
        delete rei;
    return 0;
}