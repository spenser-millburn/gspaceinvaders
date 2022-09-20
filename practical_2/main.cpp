#include <SFML/Graphics.hpp>
#include<iostream>
#include "ship.h"
#include "game.h"
sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;
sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "SFML works!");


void Load() {
    if (!spritesheet.loadFromFile("C:/Users/PC/gspaceinvaders/res/img/invaders_sheet.png")) {
        std::cout << "Failed to load spritesheet!" << std::endl;
    }
    for (int r = 0; r < invaders_rows; ++r) {
        auto rect = sf::IntRect(0, 0, 32, 32);
        for (int c = 0; c < invaders_columns; ++c) {
            sf::Vector2f position = { 100 + 50 * float(c), 100 + 20 * float(r) };
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
    Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), { 100,100 });
    ships.push_back(inv);
};
void Update(){
    static sf::Clock clock;

    float dt = clock.restart().asSeconds();


    for (auto& s : ships) {
        s->Update(dt);
    }

    };
void Render() {
    for (const auto s : ships) {
        window.draw(*s);
    }
    };

    int main() {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen()) {
            sf::Event event;
            Load();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear();
            //window.draw(shape);
            Update();
            Render();


            window.display();
        }
        return 0;
    }