
#include "pch.h"
#include "main.h"

FBullCowGame BCGame;

int32 main()
{
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PrintIntro() {
	std::cout << "Welcome to Bull and Cows, a fun word game.\n";
	std::cout << "Can you gues the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	while (!BCGame.IsGameWon() && BCGame.GetGurrentTry() <= MaxTries) {
		FString Guess = GetValidGuess();
		FBullCowCount BCCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BCCount.Bulls;
		std::cout << ". Cows: " << BCCount.Bulls << "\n\n";
	}
	PrintGameSummary();
}

FString GetValidGuess() {
	FString Guess = "";
	EGuessStatus GuessStatus = EGuessStatus::Invalid_Status;
	do {
		std::cout << "Try " << BCGame.GetGurrentTry() << " of "<< BCGame.GetMaxTries() << ". Enter your guess: ";
		getline(std::cin, Guess);
		GuessStatus = BCGame.CheckGuessValidity(Guess);
		ValidateGuessStatus(GuessStatus);
		std::cout << std::endl;
	} while (GuessStatus != EGuessStatus::OK);
	return Guess;
}

void ValidateGuessStatus(EGuessStatus GuessStatus) {
	switch (GuessStatus) {
	case EGuessStatus::Wrong_Length:
		std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
		break;
	case EGuessStatus::Not_Isogram:
		std::cout << "Please enter a word without repeating letters.\n";
		break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "Please enter all lowercase letters.\n";
		break;
	default:
		break;
	}
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FString Response = "";
	getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else {
		std::cout << "Better luck next time!\n";
	}
}