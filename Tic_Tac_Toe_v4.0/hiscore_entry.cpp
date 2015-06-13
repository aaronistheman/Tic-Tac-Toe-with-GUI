#include "hiscore_entry.h"

/////////////////////////////////////////////////////////////////////
// Constructors
/////////////////////////////////////////////////////////////////////

// There is nothing about the arguments to check.
HiscoreEntry::HiscoreEntry(int rank,
                           const std::string &player1_name,
                           const std::string &player2_name,
                           const std::string &winner_name,
                           const std::string &turns_taken_by_winner,
                           const std::string &date_of_entry)
    : r(rank), p1(player1_name), p2(player2_name), w(winner_name),
      t(turns_taken_by_winner), d(date_of_entry)
{
}

// The default turns taken is assigned 10 rather than 0 so that it
// does not accidently get ranked as the highest high score entry
// (the maximum number of turns a player can take is 5).
HiscoreEntry::HiscoreEntry()
    : r(0), p1(" "), p2(" "), w(" "),
      t("10"), d(" ")
{
}


/////////////////////////////////////////////////////////////////////
// Accessors and Mutators
/////////////////////////////////////////////////////////////////////

int HiscoreEntry::rank() const {
  return r;
}

void HiscoreEntry::set_rank(int rank) {
  r = rank;
}

std::string HiscoreEntry::player1() const {
  return p1;
}

void HiscoreEntry::set_player1(const std::string &player1_name) {
  p1 = player1_name;
}

std::string HiscoreEntry::player2() const {
  return p2;
}

void HiscoreEntry::set_player2(const std::string &player2_name) {
  p2 = player2_name;
}

std::string HiscoreEntry::winner() const {
  return w;
}

void HiscoreEntry::set_winner(const std::string &winner) {
  w = winner;
}

std::string HiscoreEntry::turns() const {
  return t;
}

void HiscoreEntry::set_turns(std::string turns) {
  t = turns;
}

std::string HiscoreEntry::date() const {
  return d;
}

void HiscoreEntry::set_date(const std::string &date) {
  d = date;
}