#include<SFML/Graphics.hpp>
#include<iostream>
#include "Animation.h"

constexpr float playerSizeX = 48.0f;
constexpr float playerSizeY = 68.0f;
//constexpr float playerSizeX = 482.0f;
//constexpr float playerSizeY = 300.0f;

int main() {
        //sf = namespace for sfml
        sf::RenderWindow window(sf::VideoMode(512, 512), "MineParrot", sf::Style::Close | sf::Style::Resize);
        sf::RectangleShape player(sf::Vector2f(playerSizeX, playerSizeY));
        //player.setOrigin(playerSizeX/2, playerSizeY/2); //so when clicking mouse sprite is in the centre when moved
        player.setPosition(206.0f, 206.0f);
        sf::Texture playerTexture; //texture of miner

        if (!playerTexture.loadFromFile("SFML.png")) {
            std::cout << "error" << std::endl;
        }
        player.setTexture(&playerTexture);
        
        Animation animation(&playerTexture, sf::Vector2u(10, 1), 0.3f);

        sf::Vector2u textureSize = playerTexture.getSize(); 
        std::cout << "TextureSize.x = " << textureSize.x << std::endl;
        std::cout << "TextureSize.y = " << textureSize.y << std::endl;

        //sf::Vector2u textureSize = playerTexture.getSize();
        //textureSize.x /= 10;
        int sizeOfPlayerx = 44;
        sizeOfPlayerx *= 4;
        player.setTextureRect(sf::IntRect(sizeOfPlayerx,0, 44,67));

        while (window.isOpen()) {
            sf::Event evnt;
            while (window.pollEvent(evnt)) {
                switch (evnt.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::Resized:
                        std::cout << "New Window Width: " << evnt.size.width << " New Window Height: " << evnt.size.height << std::endl;
                        break;
                    case sf::Event::TextEntered:
                        if (evnt.text.unicode < 128) {
                            printf("%c", evnt.text.unicode);
                        }
                        break;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                player.move(-1.9f, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                player.move(1.9f, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                player.move(0.0f, 1.9f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                player.move(0.0f, -1.9f);
            }

            //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //    player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y)); //using two types of casting, c style shorter but could cause data corruption
            //}

            window.clear();
            window.draw(player);
            window.display();
        }
        return 0;
}

//https://youtu.be/Aa8bXSq5LDE?list=PL21OsoBLPpMOO6zyVlxZ4S4hwkY_SLRW9&t=805
