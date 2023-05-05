#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
label:
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "The Chess", sf::Style::Default);
    Game chess(sf::Color(139, 69, 19), sf::Color(255, 255, 153));
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/background.jpg"))
    {
        cout << " not laod" << endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    // get the size of the window

    // set the scale of the sprite to match the window size
    backgroundSprite.setScale(
        float(window.getSize().x) / backgroundTexture.getSize().x,
        float(window.getSize().y) / backgroundTexture.getSize().y
    );
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (e.mouseButton.x >= 0 && e.mouseButton.x <= 800 && e.mouseButton.y >= 0 && e.mouseButton.y <= 800)
                    {
                        int x = e.mouseButton.y / 80, y = e.mouseButton.x / 80;
                        if (!chess.getSelected() && chess.isOver == false)
                        {
                            chess.SelectPiece(chess.cells, x, y);
                        }
                        else
                        {
                            chess.moveSelected(chess.cells, e.mouseButton.y / 80, e.mouseButton.x / 80);
                        }
                    }
                    if (e.mouseButton.x >= 850 && e.mouseButton.x <= 1024 && e.mouseButton.y >= 5 && e.mouseButton.y <= 55)
                    {
                        goto label;
                    }
                }
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(chess);
        window.display();
    }
    return 0;
}
