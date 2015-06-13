/*
  Contains class Button, which represents a button (its function, its
  graphical appearance, etc.).
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/graphics.hpp>
#include <string>


class Button {
 public:

  // Name is used to identify the button, which is important in identifying
  // what button was clicked in order to determine what the user desires.
  // File_path is used to find the texture which is used by member
  // representation to graphically represent the button.
  Button(std::string file_path, std::string name);

  // Default constructor.
  Button();

  std::string name();

  void set_name(std::string &name);

  sf::Sprite* representation();

  void SetPosition(sf::Vector2f &position);

  // Returns true if the coordinates of the argument indicate that the
  // button has been clicked on.
  bool WasClickedOn(sf::Event* what);

 private:

  std::string n;

  sf::Sprite r;

  sf::Texture t;
};

#endif