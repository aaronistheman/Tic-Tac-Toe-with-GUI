/*
  Contains class HiscoreEntry.

  This class contains the following elements of a hiscore entry:
  -ranking of the score
  -player 1's name (default: "player 1")
  -player 2's name (default: "player 2")
  -winner's name
  -number of turns taken by the winner
  -date the entry was made
*/

#ifndef HISCORE_ENTRY_H
#define HISCORE_ENTRY_H

#include <string>

class HiscoreEntry {
 public:
  
  /////////////////////////////////////////////////////////////////////
  // Constructors
  /////////////////////////////////////////////////////////////////////

  HiscoreEntry(int rank,
               const std::string &player1_name,
               const std::string &player2_name,
               const std::string &winner_name,
               const std::string &turns_taken_by_winner,
               const std::string &date_of_entry);

  HiscoreEntry();


  /////////////////////////////////////////////////////////////////////
  // Accessors and Mutators
  /////////////////////////////////////////////////////////////////////

  int rank() const;

  void set_rank(int rank);

  std::string player1() const;

  void set_player1(const std::string &player1_name);

  std::string player2() const;

  void set_player2(const std::string &player2_name);

  std::string winner() const;

  void set_winner(const std::string &winner);

  std::string turns() const;

  void set_turns(std::string turns);

  std::string date() const;

  void set_date(const std::string &date);

 private:
  
  // Ranking
  int r;

  // Player 1's name
  std::string p1;

  // Player 2's name
  std::string p2;

  // Winner's name
  std::string w;

  // Number of turns taken by the winner
  std::string t;

  // Data the entry was made
  std::string d;
};

#endif