#include "hiscores.h"

/////////////////////////////////////////////////////////////////////
/// Definitions for column x-coordinates.
/////////////////////////////////////////////////////////////////////
const double ttt::column1 = 60.0f;
const double ttt::column2 = 230.0f;
const double ttt::column3 = 440.0f;
const double ttt::column4 = 650.0f;
const double ttt::column5 = 860.0f;
const double ttt::column6 = 1150.0f;


/////////////////////////////////////////////////////////////////////
/// Definitions for column y-coordinates.
/////////////////////////////////////////////////////////////////////
double vertical_distance_between_rows = 50.0f;
const double ttt::row1 =  20.0f;
const double ttt::row2 =  ttt::row1 + vertical_distance_between_rows;
const double ttt::row3 =  ttt::row2 + vertical_distance_between_rows;
const double ttt::row4 =  ttt::row3 + vertical_distance_between_rows;
const double ttt::row5 =  ttt::row4 + vertical_distance_between_rows;
const double ttt::row6 =  ttt::row5 + vertical_distance_between_rows;
const double ttt::row7 =  ttt::row6 + vertical_distance_between_rows;
const double ttt::row8 =  ttt::row7 + vertical_distance_between_rows;
const double ttt::row9 =  ttt::row8 + vertical_distance_between_rows;
const double ttt::row10 = ttt::row9 + vertical_distance_between_rows;
const double ttt::row11 = ttt::row10 + vertical_distance_between_rows;


/////////////////////////////////////////////////////////////////////
/// Functions
/////////////////////////////////////////////////////////////////////

// Makes the sf::Text objects for the table categories and different
// hiscore elements for displaying the hiscores in eleven rows
// (including the labels' row) and six columns.
// Uses an sf::Event loop.
void ttt::Hiscores(sf::RenderWindow* window) {

  // Make button to exit from the hiscores.
  Button return_button("Resources/Images/Hiscores/return_button.png", 
                       "return_button");

  // Font to print hiscores.
  sf::Font calibri_font;
  calibri_font.loadFromFile("Resources/Fonts/Calibri/Calibri.ttf");

  // File to read hiscores.
  std::vector<HiscoreEntry> hiscores;
  UploadHiscoresToVector(hiscores, "Resources/Hiscores/hiscores.txt");

  /////////////////////////////////////////////////////////////////////
  /// Labels for each category in the hiscores table.
  /////////////////////////////////////////////////////////////////////

  sf::Text rank_label;
  rank_label.setFont(calibri_font);
  rank_label.setString("Rank");
  rank_label.setCharacterSize(40);
  rank_label.setPosition(column1, row1);

  sf::Text player_1_label;
  player_1_label.setFont(calibri_font);
  player_1_label.setString("Player 1");
  player_1_label.setCharacterSize(40);
  player_1_label.setPosition(column2, row1);

  sf::Text player_2_label;
  player_2_label.setFont(calibri_font);
  player_2_label.setString("Player 2");
  player_2_label.setCharacterSize(40);
  player_2_label.setPosition(column3, row1);

  sf::Text winner_label;
  winner_label.setFont(calibri_font);
  winner_label.setString("Winner");
  winner_label.setCharacterSize(40);
  winner_label.setPosition(column4, row1);

  sf::Text turns_taken_label;
  turns_taken_label.setFont(calibri_font);
  turns_taken_label.setString("Turns Taken");
  turns_taken_label.setCharacterSize(40);
  turns_taken_label.setPosition(column5, row1);

  sf::Text date_label;
  date_label.setFont(calibri_font);
  date_label.setString("Date");
  date_label.setCharacterSize(40);
  date_label.setPosition(column6, row1);

  /////////////////////////////////////////////////////////////////////
  /// Load number one hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_one;
  ConvertHiscoreEntryToOutputFormat(entry_one,
                                    hiscores[0],
                                    "1",
                                    calibri_font,
                                    30,
                                    row2);

  /////////////////////////////////////////////////////////////////////
  /// Load number two hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_two;
  ConvertHiscoreEntryToOutputFormat(entry_two,
                                    hiscores[1],
                                    "2",
                                    calibri_font,
                                    30,
                                    row3);

  /////////////////////////////////////////////////////////////////////
  /// Load number three hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_three;
  ConvertHiscoreEntryToOutputFormat(entry_three,
                                    hiscores[2],
                                    "3",
                                    calibri_font,
                                    30,
                                    row4);

  /////////////////////////////////////////////////////////////////////
  /// Load number four hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_four;
  ConvertHiscoreEntryToOutputFormat(entry_four,
                                    hiscores[3],
                                    "4",
                                    calibri_font,
                                    30,
                                    row5);

  /////////////////////////////////////////////////////////////////////
  /// Load number five hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_five;
  ConvertHiscoreEntryToOutputFormat(entry_five,
                                    hiscores[4],
                                    "5",
                                    calibri_font,
                                    30,
                                    row6);

  /////////////////////////////////////////////////////////////////////
  /// Load number six hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_six;
  ConvertHiscoreEntryToOutputFormat(entry_six,
                                    hiscores[5],
                                    "6",
                                    calibri_font,
                                    30,
                                    row7);

  ////////////////////////////////////////////////////////////////////
  /// Load number seven hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_seven;
  ConvertHiscoreEntryToOutputFormat(entry_seven,
                                    hiscores[6],
                                    "7",
                                    calibri_font,
                                    30,
                                    row8);

  ////////////////////////////////////////////////////////////////////
  /// Load number eight hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_eight;
  ConvertHiscoreEntryToOutputFormat(entry_eight,
                                    hiscores[7],
                                    "8",
                                    calibri_font,
                                    30,
                                    row9);

  ////////////////////////////////////////////////////////////////////
  /// Load number nine hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_nine;
  ConvertHiscoreEntryToOutputFormat(entry_nine,
                                    hiscores[8],
                                    "9",
                                    calibri_font,
                                    30,
                                    row10);

  /////////////////////////////////////////////////////////////////////
  /// Load number ten hiscore.
  /////////////////////////////////////////////////////////////////////

  std::vector<sf::Text> entry_ten;
  ConvertHiscoreEntryToOutputFormat(entry_ten,
                                    hiscores[9],
                                    "10",
                                    calibri_font,
                                    30,
                                    row11);

  /////////////////////////////////////////////////////////////////////
  /// Event handling of this function.
  /////////////////////////////////////////////////////////////////////

  // For use in the for loop used to output each hiscore entry.
  // There are six hiscore elements.
  const int number_of_hiscore_elements = 6;

  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window->close();
      if (event.type == sf::Event::MouseButtonReleased) {
        if (return_button.WasClickedOn(&event))
          ttt::MainMenu(window);
      }
    }
    
    window->clear(sf::Color::Black);

    // Draw buttons.
    window->draw(*return_button.representation());
    
    // Output the labels (row 1).
    window->draw(rank_label);
    window->draw(player_1_label);
    window->draw(player_2_label);
    window->draw(winner_label);
    window->draw(turns_taken_label);
    window->draw(date_label);

    // Output each hiscore entry, column by column (NOT row by row).
    for (size_t i = 0; i < number_of_hiscore_elements; ++i)
    {
      window->draw(entry_one[i]);
      window->draw(entry_two[i]);
      window->draw(entry_three[i]);
      window->draw(entry_four[i]);
      window->draw(entry_five[i]);
      window->draw(entry_six[i]);
      window->draw(entry_seven[i]);
      window->draw(entry_eight[i]);
      window->draw(entry_nine[i]);
      window->draw(entry_ten[i]);
    }

    window->display();
  }
}


// Goes through the file.
// Stores each element of a hiscore entry in a corresponding variable.
// After one loop that fills each variable, a hiscore entry is created.
// That entry is stored in the argument vector hiscores.
// The same process is repeated to get each hiscore entry from the file.
void ttt::UploadHiscoresToVector(std::vector<HiscoreEntry> &hiscores,
                                 const std::string &file_path) {
  // ifstream to access the file.
  std::ifstream ist(file_path.c_str());
  
  // Variables to store each element of a hiscore entry.
  int rank = 0;
  std::string p1 = " ";
  std::string p2 = " ";
  std::string winner = " ";
  std::string turns = " ";
  std::string date = " ";

  // Holds each character that is read.
  char character = ' ';
  // Holds each number that is read.
  int number = 0;

  while (ist >> character) {
    if (ist.eof()) return;

    // Clear each variable in case of another parse.
    rank = 0;
    p1 = "";
    p2 = "";
    winner = "";
    turns = ""; // Turns is default 10 in case reading fails (0 would
                // make it seem to be the highest record).
    date = "";
    
    // If the character is a '(', reading of a hiscore entry can begin.
    if (character == '(') {
      // Obtain the rank of the entry.
      ist >> rank;

      // Input the (expected) comma so it does not end up in player 1's name.
      // Read until that comma is reached.
      while (ist >> character && character != ',')
        ;

      // Get player 1's name by reading until another comma.
      while (ist >> character && character != ',')
        p1 += character;

      // Now, get player 2's name by reading until another comma.
      while (ist >> character && character != ',')
        p2 += character;

      // Now, get the winner's name by reading until another comma.
      while (ist >> character && character != ',')
        winner += character;

      // Now, get the amount of turns taken by the winner by reading
      // until another comma.
      while (ist >> character && character != ',')
        turns += character;

      // Now, get the date by reading until a closing parenthesis.
      while (ist >> character && character != ')')
        date += character;

      hiscores.push_back(HiscoreEntry(rank, p1, p2, winner, turns, date));
    } // end hiscore entry 
  } // end file parsing

  ist.close();

  // The vector hiscores must have at least ten objects to prevent a
  // crash (the tenth element is called by way of hiscores[9]).
  // So, make the size of vector hiscores 10.
  while (hiscores.size() < 10)
    hiscores.push_back(HiscoreEntry());

}


// Makes an sf::Text object for each element of the hiscore entry.
// Edits each object according the arguments.
// Puts each object into the vector.
void ttt::ConvertHiscoreEntryToOutputFormat(
    std::vector<sf::Text> &texts,
    const HiscoreEntry &hiscore_entry,
    const std::string &rank_string,
    const sf::Font &font,
    const int &character_size,
    const double &row_coordinate) {
  
  sf::Text rank;
  rank.setFont(font);
  rank.setString(rank_string);
  rank.setCharacterSize(character_size);
  rank.setPosition(column1, row_coordinate);
  texts.push_back(rank);

  sf::Text player1;
  player1.setFont(font);
  player1.setString(hiscore_entry.player1());
  player1.setCharacterSize(character_size);
  player1.setPosition(column2, row_coordinate);
  texts.push_back(player1);

  sf::Text player2;
  player2.setFont(font);
  player2.setString(hiscore_entry.player2());
  player2.setCharacterSize(character_size);
  player2.setPosition(column3, row_coordinate);
  texts.push_back(player2);

  sf::Text winner;
  winner.setFont(font);
  winner.setString(hiscore_entry.winner());
  winner.setCharacterSize(character_size);
  winner.setPosition(column4, row_coordinate);
  texts.push_back(winner);

  sf::Text turns;
  turns.setFont(font);
  turns.setString(hiscore_entry.turns());
  turns.setCharacterSize(character_size);
  turns.setPosition(column5, row_coordinate);
  texts.push_back(turns);

  sf::Text date;
  date.setFont(font);
  date.setString(hiscore_entry.date());
  date.setCharacterSize(character_size);
  date.setPosition(column6, row_coordinate);
  texts.push_back(date);
}

bool ttt::IsHiscore(std::string turns_taken) {
  // File to read hiscores.
  std::vector<HiscoreEntry> hiscores;
  UploadHiscoresToVector(hiscores, "Resources/Hiscores/hiscores.txt");

  // If turns_taken is greater than the turns taken in the tenth entry,
  // or if the tenth entry does not exist,
  // then a hiscore has been achieved.
  if (turns_taken < hiscores[9].turns() || hiscores[9].turns() == "")
    return true;

  return false;
}

// Determines the rank of the new hiscore (or does nothing
// if it is not really a hiscore).
// Calls UploadHiscoresVector() and UploadHiscoresFile() to finish the
// process of uploading hiscores.
void ttt::UpdateHiscores(const std::string &player1_name,
                         const std::string &player2_name,
                         const std::string &winner_name,
                         const std::string &turns_taken_by_winner,
                         const std::string &date_of_entry) {
  // "-1" is just a random number that cannot be the rank of a hiscore
  // entry.
  int rank_of_new_hiscore = -1;

  // File to read/write hiscores.
  std::vector<HiscoreEntry> hiscores;
  UploadHiscoresToVector(hiscores, "Resources/Hiscores/hiscores.txt");

  // This is for the for loop that follows.
  // It indicates that the hiscore rank has been found so looping
  // can stop.
  bool found_new_rank = false;

  // Compare each hiscore's number of turns (the basis of ranking)
  // to the turns in the argument hiscore_entry, starting from the
  // top hiscore moving down, to figure out the rank of the new
  // hiscore.
  for (size_t i = 0; i < hiscores.size() && !found_new_rank; ++i) {
    if (hiscores[i].turns() > turns_taken_by_winner || hiscores[i].turns() == "") {
      // The new hiscore must have the rank of the higest ranked
      // score it beats.
      rank_of_new_hiscore = hiscores[i].rank();
      found_new_rank = true;
    }
  }

  // If the rank is not -1, then it has been changed in the for loop
  // above and is therefore a valid rank.
  if (rank_of_new_hiscore != -1) {
    HiscoreEntry new_hiscore_entry(rank_of_new_hiscore,
                                   player1_name,
                                   player2_name,
                                   winner_name,
                                   turns_taken_by_winner,
                                   date_of_entry);
    UpdateHiscoresVector(hiscores, new_hiscore_entry, rank_of_new_hiscore);
    UpdateHiscoresFile(hiscores);
  }
}

void ttt::UpdateHiscoresVector(std::vector<HiscoreEntry> &hiscores,
                               const HiscoreEntry &hiscore_entry,
                               int rank_of_new_entry) {
  // This contains a hiscore_entry to be moved to the next rank.
  HiscoreEntry hiscore_entry_holder;

  bool done_hiscore_updating = false;
  size_t i = 0;

  const int number_of_hiscores = 10;

  // Find the first hiscore entry (starting from the highest) that has
  // the rank given in rank_of_new_entry (so the updating can begin from
  // that hiscore entry moving downward).
  while (i < hiscores.size() && !done_hiscore_updating) {
    if (hiscores[i].rank() == rank_of_new_entry) {

      // Assign each hiscore entry the value of the entry
      // above it, until the hiscore entry of the rank_of_new_entry
      // is reached.

      int rank_to_update = number_of_hiscores;
      // The vector address of each hiscore entry is the rank minus 1.
      int vector_address_to_update = rank_to_update - 1;

      while (vector_address_to_update > rank_of_new_entry - 1) {
        hiscores[vector_address_to_update] = hiscores[vector_address_to_update - 1];
        // Do not let the ranks change as a result of assignment.
        hiscores[vector_address_to_update].set_rank(vector_address_to_update + 1);

        --vector_address_to_update;
      }
      // Update the actual new hiscore entry.
      hiscores[rank_of_new_entry -1] = hiscore_entry;
    }
    

    ++i;
  }
}

void ttt::UpdateHiscoresFile(const std::vector<HiscoreEntry> &hiscores) {
  std::string file_path = "Resources/Hiscores/hiscores.txt";

  // ofstream to access the file.
  std::ofstream ost(file_path.c_str());

  // Sample output to file:
  /*
  (1, player 1, player 2, player 1, 3, 05-02-14)
  (2, player 1, player 2, player 2, 5, 05-02-14)
  (3, , , , , )
  (4, , , , , )
  (5, , , , , )
  (6, , , , , )
  (7, , , , , )
  (8, , , , , )
  (9, , , , , )
  (10, , , , , )
  */
  for (size_t i = 0; i < hiscores.size(); ++i)
    ost << '('
        << hiscores[i].rank()
        << ','
        << ' '
        << hiscores[i].player1()
        << ','
        << ' '
        << hiscores[i].player2()
        << ','
        << ' '
        << hiscores[i].winner()
        << ','
        << ' '
        << hiscores[i].turns()
        << ','
        << ' '
        << hiscores[i].date()
        << ')'
        << '\n';
}