#include <SFML/Graphics.hpp>
#include<iostream>
sf::Texture spritesheet;
sf::Sprite invader;
sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

void Load() {
    if (!spritesheet.loadFromFile("C:/Users/PC/gspaceinvaders/res/img/invaders_sheet.png")) {
       std::cout << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Render() {
    window.draw(invader);
}
int main(){
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()){
      sf::Event event;
      Load();
      while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
    window.clear();
    //window.draw(shape);
    Render();

    window.display();
  }
  return 0;
}