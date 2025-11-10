#include <SFML/Graphics.hpp>

int main(void)
{
  unsigned int HEIGHT = 800;
  unsigned int WIDTH  = 600;
  
  sf::RenderWindow window(sf::VideoMode({HEIGHT, WIDTH}), "VIZIVALOVOZV", sf::Style::None, sf::State::Windowed); // 4-th argument will be sf::State::Fullscreen
  window.setFramerateLimit(60);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  const auto onClose = [&window](const sf::Event::Closed&)
  {
    window.close(); 
  };

  const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
  {
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
      window.close();
  };

  while (window.isOpen())
  {
    window.handleEvents(onClose, onKeyPressed); 

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}


