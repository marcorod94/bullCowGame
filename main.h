/* This is the console executable, that uses the BullCow class
This acts as the view in MVC patter, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <string>
#include <iostream>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
FString GetValidGuess();
void ValidateGuessStatus(EGuessStatus);
bool AskToPlayAgain();
void PrintGameSummary();