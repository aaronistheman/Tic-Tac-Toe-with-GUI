#include "do_you_want_to_return_to_main_menu.h"

void ttt::DoYouWantToReturnToMainMenu(sf::RenderWindow* window) {

  ///////////////////////////////////////////////////////////////////
  /// Initialize the textures (not the buttons).
  ///////////////////////////////////////////////////////////////////

  sf::Texture menu_block_texture;
  menu_block_texture.loadFromFile(
    "Resources/Images/DoYouWantToReturnToMainMenu/menu_block.png");
  
  sf::Sprite menu_block;
  menu_block.setTexture(menu_block_texture);
  
  menu_block.setPosition(
    *GetCenteredCoordinatesOfSprite(window, &menu_block));


  ///////////////////////////////////////////////////////////////////
  /// Initialize the buttons.
  ///////////////////////////////////////////////////////////////////

  // Return to Main Menu button
  Button return_to_main_menu(
    "Resources/Images/DoYouWantToReturnToMainMenu/return_to_main_menu.png", 
    "return_to_main_menu");
  return_to_main_menu.SetPosition(sf::Vector2f(
                                    GetCenteredCoordinatesOfSprite(
                                      window, 
                                      return_to_main_menu.representation())->x,
                                    285.0f));

  // Continue Game button
  Button continue_game(
    "Resources/Images/DoYouWantToReturnToMainMenu/continue_game.png",
    "continue_game");
  continue_game.SetPosition(sf::Vector2f(
                              GetCenteredCoordinatesOfSprite(
                                window,
                                continue_game.representation())->x,
                              380.0f));

  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window->close();
      if (event.type == sf::Event::MouseButtonReleased) {
        if (return_to_main_menu.WasClickedOn(&event))
          ttt::MainMenu(window);
        if (continue_game.WasClickedOn(&event))
          // Close this menu so the game can resume.
          return;
      }
    }

    window->clear();
    window->draw(menu_block);
    window->draw(*return_to_main_menu.representation());
    window->draw(*continue_game.representation());
    window->display();
  }

}