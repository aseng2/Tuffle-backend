#include "tuffle.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement the member
// functions declared in the header, only if you didn't implement
// them inline in the header.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the TuffleGame class.
// ===================================================================
// void TuffleGame::Clearguesses(){

//}
void TuffleGame::NewGame() {
  // Dictionary newdict = dictionary_;
  // std::vector<std::string> guesses{"","","","","",""};
  //  std::vector<std::string> guessedWords;
  //  std::string Answer = dictionary_.GetRandomTuffle();
  //  std::vector<std::string>board_color;
  //  game_state_.SetAnswer(Answer);
  //  game_state_.Seterrormsg("");
  //  game_state_.Setboard_colors_(board_color);
  //  game_state_.SetguessedWords(guessedWords);
  //  game_state_.Setstatus("active");
  game_state_ = GameState(dictionary_.GetRandomTuffle());  // worked

  // std::vector<std::string> guesses = game_state_.Getguesses();
}
std::string TuffleGame::CheckBoardColor(std::string guess, std::string answer) {
  std::string result = "BBBBB";
  // int index = 0;
  // std::vector<std::string> board_color = game_state_.Getboard_color_();
  for (int i = 0; i < answer.size(); i++)  // for all green
  {
    // std::string guess = guesses[i];

    if (guess[i] == answer[i]) {
      result[i] = 'G';
      answer[i] = '$';
    }
  }
  for (int i = 0; i < answer.size(); i++) {
    if (answer.find(guess.at(i)) != std::string ::npos) {
      int index = answer.find(guess.at(i));
      if (result[i] != 'G') {
        result[i] = 'Y';
        answer[index] = '$';
      }
    }
  }

  return result;
}
void TuffleGame::LetterKeyPressed(char key) {
  if (game_state_.CheckStatus()) {
    game_state_.Seterrormsg("");
    std::vector<std::string> guesses = game_state_.GetguessedWords();
    if (guesses.size() == 0) {
      guesses.push_back("");
    }
    int index = guesses.size() - 1;
    std::string word = guesses.at(index);
    if (word.length() != 5) {
      guesses[index] = word + key;
      game_state_.SetguessedWords(guesses);
    }
    // game_state_.Setguesses(guesses);
  }
  return;
}
void TuffleGame::EnterKeyPressed() {
  std::vector<std::string> guesses = game_state_.GetguessedWords();
  if (guesses.size() == 0 || !game_state_.CheckStatus()) {
    return;
  }
  // if(!game_state_.CheckStatus()) // works
  game_state_.Seterrormsg("");
  int index = guesses.size() - 1;
  std::string word = guesses.at(index);
  if (word.length() != 5) {
    game_state_.Seterrormsg("Not Enough Letters");
    return;
  } else if (!dictionary_.IsValidGuess(word)) {
    game_state_.Seterrormsg("Not valid guess");
    return;
  }
  std::string colorMask = CheckBoardColor(word, game_state_.GetAnswer());
  // game_state_.Getboard_color_().push_back(color_mask);
  std::vector<std::string> boardColor = game_state_.GetboardColor();
  boardColor.push_back(colorMask);
  game_state_.SetboardColors(boardColor);

  // std::string Answer = game_state_.GetAnswer();
  if (colorMask == "GGGGG") {
    game_state_.Setstatus("win");
  } else if (guesses.size() > 5) {
    game_state_.Setstatus("lose");
  } else {
    guesses.push_back("");
    game_state_.SetguessedWords(guesses);
  }
}
void TuffleGame::DeleteKeyPressed() {
  std::vector<std::string> guesses = game_state_.GetguessedWords();
  if (guesses.size() == 0 || !game_state_.CheckStatus()) {
    return;
  }
  int index = guesses.size() - 1;
  std::string word = guesses.at(index);
  if (word == "") {
    return;
  }
  word.pop_back();
  // word = word.substr(0,word.length() - 1);
  guesses.at(index) = word;
  game_state_.SetguessedWords(guesses);
}
crow::json::wvalue TuffleGame::GameStateInJson() {
  // The JSON object to return to the Tuffle Frontend.
  crow::json::wvalue game_state_json({});

  // ===================== YOUR CODE HERE =====================
  // Fill the game_state_json with the data expected by the
  // Tuffle frontend. The frontend expects the following keys:
  //   1. "answer"
  //   2. "boardColors"
  //   3. "guessedWords"
  //   4. "gameStatus"
  //   5. "errorMessage"
  //   6. [OPTIONAL] "letterColors"
  // See the "JSON Response" section of tinyurl.com/cpsc121-f22-tuffle
  //
  // You can set the key in the JSON to a value like so:
  //             game_state_json[<key>] = <value>
  //
  // See below for an example to set the "answer" key:
  game_state_json["answer"] = game_state_.GetAnswer();  // Replace this!
  // std::vector<std::string> guesses;
  game_state_json["boardColors"] = game_state_.GetboardColor();
  game_state_json["guessedWords"] = game_state_.GetguessedWords();
  game_state_json["gameStatus"] = game_state_.Getstatus();
  game_state_json["errorMessage"] = game_state_.Geterrormsg();
  // game_state_json["letterColors"] = game_state_.Getletter_color_();
  // ==========================================================
  return game_state_json;
}