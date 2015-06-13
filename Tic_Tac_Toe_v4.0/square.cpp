#include "square.h"

Square::Square(std::string name,
               char mark,
               const sf::Vector2f &coordinates)
    : n(name), m(mark), c(coordinates)
{
}

Square::Square()
    : n(" "), m(' '), c(sf::Vector2f())
{
}

std::string Square::name() {
  return n;
}

void Square::set_name(const std::string &name) {
  n = name;
}

char Square::mark() {
  return m;
}

void Square::set_mark(char mark) {
  m = mark;
}

sf::Vector2f* Square::coordinates() {
  return &c;
}

void Square::set_coordinates(const sf::Vector2f &coordinates) {
  c = coordinates;
}