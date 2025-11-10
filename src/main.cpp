#include <SFML/Graphics.hpp>

int main(void)
{
  unsigned int HEIGHT = 600;
  unsigned int WIDTH  = 800;
  
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "VIZIVALOVOZV", sf::Style::None, sf::State::Windowed); // 4-th argument will be sf::State::Fullscreen
  window.setFramerateLimit(60);

  float HERO_H = 100.f;
  float HERO_W = 100.f;
  float speed = 10.f;

  sf::RectangleShape hero({100.f, 100.f});
  hero.setFillColor(sf::Color::Green);

  const auto onClose = [&window](const sf::Event::Closed&)
  {
    window.close(); 
  };

  const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
  {
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
      window.close();
    
  };

  const auto isKeyDown = [&hero, &speed, &HERO_H, &HERO_W, &HEIGHT, &WIDTH]()
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    {
      if (hero.getPosition().x < WIDTH-HERO_W)
      {
        hero.move({speed, 0});
      }
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    {
      if (hero.getPosition().x > 0)
      {
        hero.move({-speed, 0});
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
      if (hero.getPosition().y > 0)
      {
        hero.move({0, -speed});
      }
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    {
      if (hero.getPosition().y < HEIGHT-HERO_H)
      {
        hero.move({0, speed});
      }
    }
  };

  while (window.isOpen())
  {
    window.handleEvents(onClose, onKeyPressed); 
    isKeyDown();

    window.clear();
    window.draw(hero);
    window.display();
  }

  return 0;
}


