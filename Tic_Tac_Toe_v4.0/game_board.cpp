#include "game_board.h"

GameBoard::GameBoard(std::string file_path, std::string name)
    : n(name)
{
  if (t.loadFromFile(file_path))
    r.setTexture(t);
  else
    r = sf::Sprite();

  s.push_back(Square("a1"));
  s.push_back(Square("a2"));
  s.push_back(Square("a3"));
  s.push_back(Square("b1"));
  s.push_back(Square("b2"));
  s.push_back(Square("b3"));
  s.push_back(Square("c1"));
  s.push_back(Square("c2"));
  s.push_back(Square("c3"));
}

GameBoard::GameBoard()
    : n(" "), r(sf::Sprite()), s(std::vector<Square>())
{
}

void GameBoard::Draw(sf::RenderWindow* window, 
                     sf::Sprite* x_sprite, 
                     sf::Sprite* o_sprite) {
  // Draw the board.
  window->draw(r);

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].mark() == 'x') {
      x_sprite->setPosition(*s[i].coordinates());
      window->draw(*x_sprite);
    } else if (s[i].mark() == 'o') {
      o_sprite->setPosition(*s[i].coordinates());
      window->draw(*o_sprite);
    }
  }
}

std::string GameBoard::name() {
  return n;
}

void GameBoard::set_name(std::string &name) {
  n = name;
}

sf::Sprite* GameBoard::representation() {
  return &r;
}

std::vector<Square>* GameBoard::squares() {
  return &s;
}

Square* GameBoard::GetSquare(const std::string &square) {
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].name() == square)
      return &s[i];
  }
  return NULL;
}

void GameBoard::SetPosition(const sf::Vector2f &position) {
  r.setPosition(position);
}

void GameBoard::SetCoordinates(const sf::Vector2f &coordinates,
                               const std::string &square)
{
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].name() == square)
      s[i].set_coordinates(coordinates);
  }
}

sf::Vector2f* GameBoard::GetCoordinates(const std::string &square) {
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].name() == square)
      return s[i].coordinates();
  }
  return &sf::Vector2f();
}

std::string GameBoard::FindSquareThatWasClickedOn(const sf::Event &what, 
                                                  const float &square_width)
{
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].coordinates()->x < what.mouseButton.x &&
        what.mouseButton.x < s[i].coordinates()->x + square_width &&
        s[i].coordinates()->y < what.mouseButton.y &&
        what.mouseButton.y < s[i].coordinates()->y + square_width)
      return s[i].name();
  }
  return " ";
}

// Checks if the argument is really a square (a1-c3). Function ends if the
// argument is not a square.
// Checks if the square is unoccuppied.
// If both of those conditions are satisfied, then the object in
// vector<Square> s is found that has the same name as argument square.
// After this, that object's mark is assigned the current turn ('x' or 'o').
// Check for a win or draw.
// The current turn is then updated (flipped to the next turn).
void GameBoard::HandleSquareClickedOn(const std::string &square, char &turn) {
  if (!IsSquare(square))
    return;

  if (GetSquare(square)->mark() != ' ') 
    return;

  GetSquare(square)->set_mark(turn);

  if (IsWin(turn) || IsDraw())
    return;

  // Switch the turn.
  if (turn == 'x') {
    turn = 'o';
  } else {
    turn = 'x';
  }
}

bool GameBoard::IsSquare(const std::string &square) {
  if (square == "a1" || square == "a2" || square == "a3" || 
      square == "b1" || square == "b2" || square == "b3" ||
      square == "c1" || square == "c2" || square == "c3")
      return true;
  return false;
}

// Test each win condition to see if x wins.
bool GameBoard::IsWin(char mark) {
  // 1) a1, a2, a3
	if(s[0].mark() == mark && s[1].mark() == mark && s[2].mark() == mark)  
    return true;

  // 2) b1, b2, b3
	if(s[3].mark() == mark && s[4].mark() == mark && s[5].mark() == mark)  
    return true;

  // 3) c1, c2, c3
	if(s[6].mark() == mark && s[7].mark() == mark && s[8].mark() == mark)  
    return true;

  // 4) a1, b1, c1
	if(s[0].mark() == mark && s[3].mark() == mark && s[6].mark() == mark)  
    return true;

  // 5) a2, b2, c2
	if(s[1].mark() == mark && s[4].mark() == mark && s[7].mark() == mark)  
    return true;

  // 6) a3, b3, c3
	if(s[2].mark() == mark && s[5].mark() == mark && s[8].mark() == mark)  
    return true;

  // 7) a1, b2, c3
	if(s[0].mark() == mark && s[4].mark() == mark && s[8].mark() == mark)  
    return true;

  // 8) a3, b2, c1
	if(s[2].mark() == mark && s[4].mark() == mark && s[6].mark() == mark)  
    return true;

	return false;
}

// Checks if each square is occupied,
// then checks if there is neither a win for Player 1 nor a win for
// Player 2.
bool GameBoard::IsDraw() {
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].mark() == ' ')
      // There is still a square to occupy.
      return false;
  }

  if (!IsWin('x') && !IsWin('o'))
    return true;
  return false;
}


int GameBoard::GetAmountOfPieceOnBoard(char piece) {
  int result = 0;

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i].mark() == piece)
      ++result;
  }
  return result;
}