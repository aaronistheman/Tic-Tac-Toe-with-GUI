#ifndef PLAY_H
#define PLAY_H

#include "button.h"
#include "do_you_want_to_return_to_main_menu.h"
#include "game_board.h"
#include "game_ended_menu.h"

#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

namespace ttt {

void Play(sf::RenderWindow* window);

// User is responsible for clearing the window before calling this
// function (if necessary).
void DisplayBoard(sf::RenderWindow* window, sf::Sprite* board);

// This is needed to submit a hiscore entry for evaluation,
// since an entry requires the date.
// Sample return: "5-25-2014"
std::string GetDateAsString();

} // namespace ttt

#endif