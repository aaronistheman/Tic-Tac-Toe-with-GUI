/*
  Contains class GameBoard.
  
  Class GameBoard holds:
  -sprite of an image (texture) to represent the game board
  -nine coordinates, each representing the spot to place a piece (for
   example, to place a piece on square b3, I would use the b3 coordinates)
   **the game board is for tic tac toe and therefore assumes nine squares,
     a1, a2, a3, b1, b2, b3, c1, c2, c3
*/

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "square.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class GameBoard {
 public:

  GameBoard(std::string file_path, std::string name);

  GameBoard();

  // Draws both the board and each of the pieces (if any) that occupy
  // the squares in vector<Square> s.
  void Draw(sf::RenderWindow* window, 
            sf::Sprite* x_sprite, 
            sf::Sprite* o_sprite);

  std::string name();

  void set_name(std::string &name);

  sf::Sprite* representation();

  std::vector<Square>* squares();

  // Returns the square from vector<Square> s that has the same name as
  // indicated in the argument.
  Square* GetSquare(const std::string &square);

  void SetPosition(const sf::Vector2f &position);

  // Sets the coordinates of a square.
  void SetCoordinates(const sf::Vector2f &coordinates,
                      const std::string &square);

  // Gets the coordinates of a square.
  sf::Vector2f* GetCoordinates(const std::string &square);

  // Returns the name of a square that (based on the argument sf::Event
  // what) was clicked on.
  std::string FindSquareThatWasClickedOn(const sf::Event &what, 
                                         const float &square_width);

  // Handles what to do if a square was clicked on based on the square
  // that was clicked on.
  // If the square is good for selection, its mark is assigned the value
  // of the current turn ('x' or 'o').
  // If there is a win or draw, this function immediately returns after
  // detection of this, but does not handle what to do about a win or
  // draw.
  void HandleSquareClickedOn(const std::string &square, char &turn);

  // Returns true if argument square is a square (a1-c3).
  static bool IsSquare(const std::string &square);

  bool IsWin(char mark);

  bool IsDraw();

  void HandleWin();

  void HandleDraw();

  // Get the amount of pieces on the board of the same mark as
  // argument piece.
  int GetAmountOfPieceOnBoard(char piece);

 private:

  std::string n;

  sf::Sprite r;

  sf::Texture t;

  std::vector<Square> s;
};

#endif