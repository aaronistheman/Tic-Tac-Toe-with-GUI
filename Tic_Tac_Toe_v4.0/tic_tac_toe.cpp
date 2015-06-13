#include "tic_tac_toe.h"

void ttt::TicTacToe() {
  sf::RenderWindow window(sf::VideoMode(1300, 600), "Tic Tac Toe", sf::Style::Titlebar);

  ttt::MainMenu(&window);
}