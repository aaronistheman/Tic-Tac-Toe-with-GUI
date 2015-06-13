/*
  Contains class Square.
  This class is primarily for the purpose of organizing the squares on
  class GameBoard.
*/

#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <string>

class Square {
 public:

  Square(std::string name,
         char mark = ' ', 
         const sf::Vector2f &coordinates = sf::Vector2f(0.0f, 0.0f));

  Square();

  std::string name();

  void set_name(const std::string &name);

  char mark();

  void set_mark(char mark);

  sf::Vector2f* coordinates();

  void set_coordinates(const sf::Vector2f &coordinates);

 private:
  
  std::string n;

  char m;

  sf::Vector2f c;
};

#endif