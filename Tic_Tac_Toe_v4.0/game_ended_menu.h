/*
  Contains functions for outputting the menu that shoulnd be output
  after a game has ended.
  
  Message: 
    -Player 1 Wins! OR
    -Player 2 Wins! OR
    -Draw!

  Options (buttons):
    -Play again
    -Return to main menu
    -Quit
*/

#ifndef GAME_ENDED_MENU_H
#define GAME_ENDED_MENU_H

#include "button.h"
#include "main_menu.h"
#include "play.h"

#include <SFML/Graphics.hpp>

namespace ttt {

// Handles menu that pops up when a game ends. Argument winner must be
// either 'x' or 'o', or 'n' if there is no winner (draw).
void GameEndedMenu(sf::RenderWindow* window, char winner, bool is_hiscore_achieved);

// Uses both the size of the window and the size of the sprite to generate
// coordinates that would center the sprite on the window.
sf::Vector2f* GetCenteredCoordinatesOfSprite(sf::RenderWindow* window, sf::Sprite* sprite);

} // namespace ttt

#endif