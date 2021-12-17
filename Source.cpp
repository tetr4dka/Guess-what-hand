#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <coin.hpp>
#include <hand.hpp>

#pragma comment (linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std::chrono_literals;

bool GameOn()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "Let's Guess");

    sf::Texture texture;
    if (!texture.loadFromFile("img/back.png"))
    {
        std::cout << "ERROR while loading [back.png]" << std::endl;
        return -1;
    }
    sf::Sprite back;
    back.setTexture(texture);

    sf::Font font;
    if(!font.loadFromFile("fonts/comic.ttf"))
    {
        std::cout << "ERROR while loading [comic.ttf]" << std::endl;
        return -1;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("JULNICHAEM???");
    text.setCharacterSize(40);
    text.setPosition(150, 300);

    sf::Image icon;
    if (!icon.loadFromFile("img/coin_icon.png"))
    {
        return -1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    float t = 0;

    mt::Coin coin(300, 597, 30, 90, 110);
    mt::Hand hand1(200, 1150, 128);
    mt::Hand hand2(400, 1165, 128);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            return true;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return false;

        if (coin.GetX() != 300)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))          
                hand1.MoveDown(0.8);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                hand2.MoveDown(0.8);
        }

        if (!coin.Setup())
        {
            delete& coin;
            window.close();
            return false;
        }

        if (!hand1.Setup())
        {
            delete& hand1;
            window.close();
            return false;
        }

        if (!hand2.Setup())
        {
            delete& hand2;
            window.close();
            return false;
        }

        hand1.Mirror();

        if (coin.GetX() == 300)
        {
            hand1.Move(670);
            hand2.Move(670);
        }

        if (coin.GetY() <= 629)
            coin.Move(t);

        if (coin.GetX() == 300)
            coin.Teleport(coin.GetY());

        window.clear();

        window.draw(back);

        if(coin.GetX() != 300)
            if ((hand1.GetY() >= 720) && (hand2.GetY() >= 720))
                window.draw(text);

        window.draw(*coin.Get());
        window.draw(*hand1.Get());
        window.draw(*hand2.Get());
        window.display();

        std::this_thread::sleep_for(20ms);
        t += 0.1;
    }
    return 0;
}

void Start()
{
    if (GameOn())
        Start();
}

int main()
{
    Start();
    return 0;
}