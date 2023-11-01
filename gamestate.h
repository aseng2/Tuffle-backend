#pragma once

#include <cstdlib>
#include <string>
#include <vector>

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
 public:
  //=================== YOUR CODE HERE ===================
  // TODO: Add the constructor(s), accessors, mutators,
  // and any other member function you may need here.
  //======================================================
  GameState(const std::string& answer)
      : answer_(answer), status_("active"), errormsg_("") {}
  // GameState(const int& numGuesses) : numGuesses_(numGuesses) {}
  // GameState(const std::vector<std::string>& guesses) : guesses_(guesses){}
  // GameState(const bool& win) : win_(win){}
  // Game

  std::string GetAnswer() { return answer_; }
  std::string Geterrormsg() { return errormsg_; }
  std::vector<std::string> GetguessedWords() { return guessedWords_; }
  std::string Getstatus() { return status_; }
  std::vector<std::string> GetboardColor() { return boardColors_; }

  void SetAnswer(const std::string& answer) { answer_ = answer; }
  void Seterrormsg(const std::string& errormsg) { errormsg_ = errormsg; }
  void Setstatus(const std::string& status) { status_ = status; }
  void SetguessedWords(const std::vector<std::string>& guessedWords) {
    guessedWords_ = guessedWords;
  }
  void SetboardColors(const std::vector<std::string>& boardColor) {
    boardColors_ = boardColor;
  }

  bool CheckStatus() {
    if (status_ == "active") {
      return true;
    }
    return false;
  }
  // write setters just for the vector and letter color

 private:
  std::string answer_;
  std::string errormsg_;
  std::vector<std::string> guessedWords_;
  std::string status_;
  // std::string letter_colors_;  // make it as a vector
  std::vector<std::string> boardColors_;

  //=================== YOUR CODE HERE ===================
  // TODO: Add any member variables you need here to store
  // the state of the game. What information needs to be
  // stored to fully represent the game state at a single
  // point in time?
  //======================================================
};

#endif  // GAMESTATE_H