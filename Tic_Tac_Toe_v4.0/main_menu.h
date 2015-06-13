/*
  Contains function MainMenu(), which will output the main menu in the
  argument window, as well as functions that help in this task.
*/

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "button.h"
#include "hiscores.h"
#include "play.h"

#include <SFML/Graphics.hpp>
#include <vector>

namespace ttt {

void MainMenu(sf::RenderWindow* window);

// Goes through the argument vector to find and return what was clicked on.
// If nothing in the vector was clicked on, an empty object is returned.
sf::Shape* FindOutWhatWasClickedOn(std::vector<sf::Shape*> buttons, sf::Event* what);

} // end namespace ttt

#endif