#include "play.h"

void ttt::Play(sf::RenderWindow* window) {
  
  // Make button to exit from the game.
  Button return_button("Resources/Images/Play/return_button.png", 
                       "return_button");

  GameBoard game_board("Resources/Images/Play/board.png", "game_board");
  game_board.SetPosition(sf::Vector2f(50.0f, 50.0f));
  game_board.SetCoordinates(sf::Vector2f( 50.0f,  50.0f), "a1");
  game_board.SetCoordinates(sf::Vector2f(232.0f,  50.0f), "a2");
  game_board.SetCoordinates(sf::Vector2f(415.0f,  50.0f), "a3");
  game_board.SetCoordinates(sf::Vector2f( 50.0f, 232.0f), "b1");
  game_board.SetCoordinates(sf::Vector2f(232.0f, 232.0f), "b2");
  game_board.SetCoordinates(sf::Vector2f(415.0f, 232.0f), "b3");
  game_board.SetCoordinates(sf::Vector2f( 50.0f, 415.0f), "c1");
  game_board.SetCoordinates(sf::Vector2f(232.0f, 415.0f), "c2");
  game_board.SetCoordinates(sf::Vector2f(415.0f, 415.0f), "c3");

  // Initialize the sprite to output 'x' pieces.
  sf::Texture x_piece_texture;
  x_piece_texture.loadFromFile("Resources/Images/Play/x_piece.gif");
  sf::Sprite x_piece(x_piece_texture);
  x_piece.setScale(150.0f / x_piece.getTexture()->getSize().x, 
                   150.0f / x_piece.getTexture()->getSize().y);

  // Initialize the sprite to output 'o' pieces.
  sf::Texture o_piece_texture;
  o_piece_texture.loadFromFile("Resources/Images/Play/o_piece.gif");
  sf::Sprite o_piece(o_piece_texture);
  o_piece.setScale(150.0f / o_piece.getTexture()->getSize().x, 
                   150.0f / o_piece.getTexture()->getSize().y);
      
  // Initialize the sprite of the "'x' wins" menu.
  sf::Texture x_wins_texture;
  x_wins_texture.loadFromFile("Resources/Images/Play/x_wins.png");
  sf::Sprite x_wins(x_wins_texture);

  // Initialize the sprite of the "'o' wins" menu.
  sf::Texture o_wins_texture;
  o_wins_texture.loadFromFile("Resources/Images/Play/o_wins.png");
  sf::Sprite o_wins(o_wins_texture);

  // Initialize the spirte of the "draw" menu.
  sf::Texture draw_texture;
  draw_texture.loadFromFile("Resources/Images/Play/draw.png");
  sf::Sprite draw(draw_texture);

  std::string result = " ";
  char current_turn = 'x';

  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window->close();
      if (event.type == sf::Event::MouseButtonReleased)
      {
        result = game_board.FindSquareThatWasClickedOn(event, 150.0f);
        game_board.HandleSquareClickedOn(result, current_turn);

        if (return_button.WasClickedOn(&event))
          ttt::DoYouWantToReturnToMainMenu(window);
      }
    }
    
    window->clear(sf::Color::Black);
    window->draw(*return_button.representation());
    game_board.Draw(window, &x_piece, &o_piece);
    window->display();

    if (game_board.IsWin(current_turn)) {
      // Wait for a certain amount of time after a win so the
      // win can be seen.
      int time_to_wait = 1;
      sf::Clock clock;
      while (clock.getElapsedTime().asSeconds() < time_to_wait) 
      {
      }
      
      int turns_taken_by_winner = game_board.GetAmountOfPieceOnBoard(
                                    current_turn);

      // Convert turns_taken_by_winner to a string so it can be used
      // by IsHiscore();
      char turns_taken[10];
      sprintf(turns_taken, "%i", turns_taken_by_winner);

      std::string winner_string = "";
      if (current_turn == 'x')
        winner_string = "player 1";
      else
        winner_string = "player 2";

      UpdateHiscores("player 1", "player 2", winner_string, turns_taken, GetDateAsString());
      GameEndedMenu(window, current_turn, IsHiscore(turns_taken));
    }
    else if (game_board.IsDraw()) {
      // Wait for a certain amount of time after a win so the
      // win can be seen.
      int time_to_wait = 1;
      sf::Clock clock;
      while (clock.getElapsedTime().asSeconds() < time_to_wait) 
      {
      }
      // Set third argument false because a draw cannot achieve
      // a hiscore (third argument is true if a hiscore is achieved).
      ttt::GameEndedMenu(window, 'n', false);
    }
  }
}

void ttt::DisplayBoard(sf::RenderWindow* window, sf::Sprite* board) {
  window->draw(*board);
}

std::string ttt::GetDateAsString() {

  std::string date = "";

  // This will contain the ints that will be converted to
  // strings in the following code.
  char converted_string[10];

  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );
  
  sprintf(converted_string, "%i", (now->tm_mon + 1));
  date += converted_string;

  date += '-';

  sprintf(converted_string, "%i", (now->tm_mday));
  date += converted_string;

  date += '-';

  sprintf(converted_string, "%i", (now->tm_year + 1900));
  date += converted_string;

  return date;
}