#include "game_ended_menu.h"

void ttt::GameEndedMenu(sf::RenderWindow* window, char winner, bool is_hiscore_achieved) {
  
  // This will be set based on who the winner was.
  sf::Sprite menu_message;

  /*
    Initialize the textures for each menu message.
    Because they are textures, they cannot be created in the switch
    statement because they must remain in scope wherever any sprite
    (in this case the sf::Sprite menu_message) that requires them uses them.
  */
  sf::Texture player_1_wins_texture;
  player_1_wins_texture.loadFromFile("Resources/Images/GameEndedMenu/player_1_wins.png");
  sf::Texture player_2_wins_texture;
  player_2_wins_texture.loadFromFile("Resources/Images/GameEndedMenu/player_2_wins.png");
  sf::Texture draw_texture;
  draw_texture.loadFromFile("Resources/Images/GameEndedMenu/draw.png");

  /*
    Initialize the buttons.
  */
  // Play Again button
  Button play_again("Resources/Images/GameEndedMenu/play_again.png", "play_again");
  play_again.SetPosition(sf::Vector2f(
                           GetCenteredCoordinatesOfSprite(window, 
                           play_again.representation())->x,
                         245.0f));
  // Return to Main Menu button
  Button return_to_main_menu("Resources/Images/GameEndedMenu/return_to_main_menu.png", 
                             "return_to_main_menu");
  return_to_main_menu.SetPosition(sf::Vector2f(
                                    GetCenteredCoordinatesOfSprite(window, 
                                    return_to_main_menu.representation())->x,
                                  336.0f));
  // Quit button
  Button quit("Resources/Images/GameEndedMenu/quit.png", "quit");
  quit.SetPosition(sf::Vector2f(
                     GetCenteredCoordinatesOfSprite(window,
                     quit.representation())->x,
                   420.0f));

  /*
    Initialize texture for message that hiscore has been achieved.
  */
  sf::Texture hiscores_updated_texture;
  hiscores_updated_texture.loadFromFile("Resources/Images/GameEndedMenu/hiscores_updated.png");
  sf::Sprite hiscores_updated;
  hiscores_updated.setTexture(hiscores_updated_texture);

  switch (winner) {
    case 'x':
    {
      // Initialize the sprite of the "player 1 wins" menu.
      menu_message = sf::Sprite(player_1_wins_texture);
      menu_message.setPosition(*GetCenteredCoordinatesOfSprite(window, &menu_message));
      break;
    }
    case 'o':
    {
      // Initialize the sprite of the "player 2 wins" menu.
      menu_message = sf::Sprite(player_2_wins_texture);
      menu_message.setPosition(*GetCenteredCoordinatesOfSprite(window, &menu_message));
      break;
    }
    case 'n': // case of draw
    {
      // Initialize the spirte of the "draw" menu.
      menu_message = sf::Sprite(draw_texture);
      menu_message.setPosition(*GetCenteredCoordinatesOfSprite(window, &menu_message));
      break;
    }
  }

  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window->close();
      if (event.type == sf::Event::MouseButtonReleased) {
        if (play_again.WasClickedOn(&event))
          ttt::Play(window);
        if (return_to_main_menu.WasClickedOn(&event))
          ttt::MainMenu(window);
        if (quit.WasClickedOn(&event))
          window->close();
      }
    }
    window->clear();
    window->draw(menu_message);
    window->draw(*play_again.representation());
    window->draw(*return_to_main_menu.representation());
    window->draw(*quit.representation());
    
    if (is_hiscore_achieved)
      window->draw(hiscores_updated);

    window->display();
  }
}

sf::Vector2f* ttt::GetCenteredCoordinatesOfSprite(sf::RenderWindow* window, sf::Sprite* sprite) {
  // This operation creates the coordinates for centering the sprite on the window.
  sf::Vector2f result(window->getSize().x / 2 - sprite->getTexture()->getSize().x / 2, 
                      window->getSize().y / 2 - sprite->getTexture()->getSize().y / 2);
  return &result;
}