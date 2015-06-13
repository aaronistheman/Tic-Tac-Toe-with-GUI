#include "main_menu.h"

void ttt::MainMenu(sf::RenderWindow* window) {

  sf::Texture title_bar_texture;
  title_bar_texture.loadFromFile("Resources/Images/MainMenu/title_bar.png");
  sf::Sprite title_bar(title_bar_texture);
  title_bar.setPosition(50.0f, 50.0f);

  sf::Texture game_screenshot_texture;
  game_screenshot_texture.loadFromFile("Resources/Images/MainMenu/game_screenshot.png");
  sf::Sprite game_screenshot(game_screenshot_texture);
  game_screenshot.setPosition(700.0f, 50.0f);

  Button play("Resources/Images/MainMenu/play.png", "play");
  play.SetPosition(sf::Vector2f(150.0f, 200.0f));
  
  Button hiscores("Resources/Images/MainMenu/hiscores.png", "hiscores");
  hiscores.SetPosition(sf::Vector2f(150.0f, 300.0f));

  Button exit("Resources/Images/MainMenu/exit.png", "exit");
  exit.SetPosition(sf::Vector2f(150.0f, 400.0f));

  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window->close();
      if (event.type == sf::Event::MouseButtonReleased)
      {
        if (play.WasClickedOn(&event))
          ttt::Play(window);
        if (hiscores.WasClickedOn(&event))
          ttt::Hiscores(window);
        if (exit.WasClickedOn(&event))
          window->close();
      }
    }

    window->clear(sf::Color::Black);
    window->draw(title_bar);
    window->draw(game_screenshot);
    window->draw(*play.representation());
    window->draw(*hiscores.representation());
    window->draw(*exit.representation());
    window->display();
  }
}