#include "Button.h"

// Initializes n.
// Uses the file path to load the file for t.
// If the file_path is wrong, then the default constructor
// for sf::Sprite representation is called.
Button::Button(std::string file_path, std::string name)
    : n(name)
{
  if (t.loadFromFile(file_path))
    r.setTexture(t);
  else
    r = sf::Sprite();
}

Button::Button()
    : n(" "), r(sf::Sprite())
{
}

std::string Button::name() {
  return n;
}

void Button::set_name(std::string &name) {
  n = name;
}

sf::Sprite* Button::representation() {
  return &r;
}

void Button::SetPosition(sf::Vector2f &position) {
  r.setPosition(position);
}

// Checks if the click coordinates of the argument are within the boundaries
// of the button.
// Compares both the x and the y coordinates to determine this.
bool Button::WasClickedOn(sf::Event* what) {
  if (what->mouseButton.x > r.getPosition().x &&
      what->mouseButton.y > r.getPosition().y &&
      what->mouseButton.x < r.getPosition().x + r.getTexture()->getSize().x &&
      what->mouseButton.y < r.getPosition().y + r.getTexture()->getSize().y) 
  {
    return true;
  }

  return false;
}