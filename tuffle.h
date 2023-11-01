#include <string>
#include <vector>

#include "dictionary.h"
#include "gamestate.h"
#include "server_utils/crow_all.h"

#ifndef TUFFLE_H
#define TUFFLE_H

class TuffleGame {
 public:
  TuffleGame(Dictionary dict)
      : dictionary_(dict), game_state_(dict.GetRandomTuffle()) {}

  // Called by the Tuffle frontend when the user clicks "Next Tuffle".
  // void NewGame(){
  //   //Dictionary newdict = dictionary_;
  //   game_state_= GameState(dictionary_.GetRandomTuffle());

  //   //std::string boardcolor = "";
  //   //game_state_.Getboard_color_().push_back(boardcolor);

  // }

  void NewGame();

  // std::string CheckBoardColor(std::string guess, std::string answer) {
  //   std::string result = "BBBBB";
  //   //int index = 0;
  //   //std::vector<std::string> board_color = game_state_.Getboard_color_();
  //   for(int i = 0; i < answer.size(); i++) // for all green
  //     {
  //        //std::string guess = guesses[i];

  //       if(guess[i] == answer[i])
  //       {
  //         result[i] = 'G';
  //         answer[i] = '$';
  //       }
  //       for(int j = 0; j < answer.size(); j++)
  //         {
  //           if(answer.find(guess.at(i))!= std::string ::npos)
  //           {
  //             int index = answer.find(guess.at(i));
  //             if(result[i]!='G'){
  //             result[i] = 'Y';
  //             answer[index]='$';
  //             }
  //           }
  //         }
  //     }
  //   return result;
  // }
  std::string CheckBoardColor(std::string guess, std::string answer);
  // Called by the Tuffle frontend when the user enters a letter.
  // void LetterKeyPressed(char key){
  //   if(game_state_.CheckStatus())
  //   {
  //     game_state_.Seterrormsg("");
  //     std::vector<std::string>guesses = game_state_.Getguesses();
  //       if(guesses.size() == 0)
  //         {
  //           guesses.push_back("");
  //         }
  //     int index = guesses.size() - 1;
  //     std::string word = guesses.at(index);
  //       if(word.length() != 5)
  //       {
  //         guesses[index] = word + key;
  //         game_state_.Setguesses(guesses);
  //       }
  //   }
  //   //return;

  // }
  void LetterKeyPressed(char key);
  // Called by the Tuffle frontend when the user submits a guess.
  // void EnterKeyPressed(){
  //   std::vector<std::string> guesses = game_state_.Getguesses();
  //   //if(guesses.size() == 0|| !game_state_.CheckStatus())
  //   if(!game_state_.CheckStatus())
  //   {
  //     return;
  //   }
  //   game_state_.Seterrormsg("");
  //   int index = guesses.size() - 1;
  //   std::string word = guesses.at(index);
  //   if(word.length() != 5)
  //   {
  //     game_state_.Seterrormsg("Not Enough Letters");
  //     return;
  //   }
  //   else if(!dictionary_.IsValidGuess(word))
  //   {
  //     game_state_.Seterrormsg("Not valid guess");
  //     return;
  //   }
  // std::string color_mask = CheckBoardColor(word, game_state_.GetAnswer());
  // game_state_.Getboard_color_().push_back(color_mask);

  //   std::string Answer = game_state_.GetAnswer();
  //   if(color_mask == "GGGGG")
  //   {
  //     game_state_.Setstatus("win");
  //   }
  //   else if(game_state_.Getguesses().size() == 6)
  //   {
  //     game_state_.Setstatus("lose");
  //   }
  //   if(game_state_.CheckStatus()){
  //     guesses.push_back("");
  //     game_state_.Setguesses(guesses);
  //   }
  // }
  void EnterKeyPressed();
  // Called by the Tuffle frontend when the presses backspace.
  // void DeleteKeyPressed(){
  //   std::vector<std::string>guesses = game_state_.Getguesses();
  //   if(guesses.size() == 0 || !game_state_.CheckStatus())
  //   {
  //     return;
  //   }
  //   int index = guesses.size() - 1;
  //   std::string word = guesses.at(index);
  //  if(word.length() == 0)
  //  {
  //    return;
  //  }
  // word.pop_back();
  // //word = word.substr(0,word.length() - 1);
  // guesses.at(index) = word;
  // game_state_.Setguesses(guesses);
  //       //deleteguess.back() = '\0'; // use the pop function take guesses
  //       words and see if it is inactive and see if it is 0
  //       //use substr
  //       //current_guess.substr(0,currentguess.length()-1)
  //       //guesses.back() = deleteguess;
  //       //game_state_.Setguesses(guesses);

  // }
  void DeleteKeyPressed();
  // GameStateInJson returns a JSON object representing the game state.
  // This is used to send the game state to the Tuffle Frontend in a readable
  // format.
  crow::json::wvalue GameStateInJson();

 private:
  GameState game_state_;
  Dictionary dictionary_;
};

#endif  // TUFFLE_H