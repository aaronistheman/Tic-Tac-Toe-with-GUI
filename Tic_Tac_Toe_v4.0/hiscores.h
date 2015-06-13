/*
  Contains function Hiscores(), which outputs a list of the
  hiscores.

  The list is displayed in a table of six columns and eleven rows.

  For each hiscore entry, the different elements are:
  -rank
  -player 1's name
  -player 2's name
  -winner
  -number of turns taken by the winner
  -date of entry
*/

#ifndef HISCORES_H
#define HISCORES_H

#include "button.h"
#include "hiscore_entry.h"
#include "main_menu.h"

#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace ttt {

/////////////////////////////////////////////////////////////////////
/// Functions
/////////////////////////////////////////////////////////////////////

void Hiscores(sf::RenderWindow* window);

// Takes the hiscores from a (preferably .txt) file.
// Makes them into hiscore entries (using the class HiscoreEntry).
// Places those entries into vector hiscores.
void UploadHiscoresToVector(std::vector<HiscoreEntry> &hiscores,
                            const std::string &file_path);

// Takes the elements of a hiscore entry and the stylistic elements of
// the desired sf::Text object.
// Converts the given hiscore entry into the needed number of sf::Text
// objects and puts them into the argument vector.
// Argument rank_string is needed as a string (and not an int)
// because the hiscore_entry's
// member variable rank is incompatible with the sf::Text's
// requirement of a string for the text to display in Text::setString().
// The vector is assumed to be empty and the elements of the hiscore
// entry are put into the vector in the appropriate order
// (rank, player1, player2, winner, turns, date).
void ConvertHiscoreEntryToOutputFormat(std::vector<sf::Text> &texts,
                                       const HiscoreEntry &hiscore_entry,
                                       const std::string &rank_string,
                                       const sf::Font &font,
                                       const int &character_size,
                                       const double &row_coordinate);

// Is a hiscore achieved?
bool IsHiscore(std::string turns_taken);

// Checks where the hiscore_entry should be ranked.
// Writes to the hiscores file to make it match the contents of the
// vector hiscores.
// Does nothing if hiscore_entry is not really a hiscore.
void UpdateHiscores(const std::string &player1_name,
                    const std::string &player2_name,
                    const std::string &winner_name,
                    const std::string &turns_taken_by_winner,
                    const std::string &date_of_entry);

// Updates the vector of hiscore entries based on the second and third
// arguments (the new hiscore entry and its rank).
void UpdateHiscoresVector(std::vector<HiscoreEntry> &hiscores,
                          const HiscoreEntry &hiscore_entry,
                          int rank_of_new_entry);

// Uses the information from the vector of hiscore entries
// to update the file containing the hiscores.
void UpdateHiscoresFile(const std::vector<HiscoreEntry> &hiscores);
    
/////////////////////////////////////////////////////////////////////
/// Coordinate for either a column (x-coordinate)
/// or a row (y-coordinate).
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// Columns:
/////////////////////////////////////////////////////////////////////
extern const double column1;
extern const double column2;
extern const double column3;
extern const double column4;
extern const double column5;
extern const double column6;

/////////////////////////////////////////////////////////////////////
// Rows:
/////////////////////////////////////////////////////////////////////
extern const double row1;
extern const double row2;
extern const double row3;
extern const double row4;
extern const double row5;
extern const double row6;
extern const double row7;
extern const double row8;
extern const double row9;
extern const double row10;
extern const double row11;

} // end namespace ttt

#endif