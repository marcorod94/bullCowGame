
#include "pch.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetGurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	EGuessStatus GuessStatus = EGuessStatus::OK;
	if (!IsIsogram(Guess)) {
		GuessStatus = EGuessStatus::Not_Isogram;
	} else if (!IsLowercase(Guess)) {
		GuessStatus = EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLength()) {
		GuessStatus = EGuessStatus::Wrong_Length;
	}
	return GuessStatus;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BCCount;
	int32 WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			if (MyHiddenWord[MHWChar] == Guess[GChar]) {
				if (MHWChar == GChar) {
					BCCount.Bulls++;
				} else {
					BCCount.Cows++;
				}
			}
		}
	}
	if (BCCount.Bulls == WordLength) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}
	return BCCount;
}


bool FBullCowGame::IsIsogram(FString Guess) const {
	if (Guess.length() <= 1) {
		return true;
	}
	TMap<char, bool> LetterSeen;
	for (char Letter : Guess) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		} else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess) {
		if (isupper(Letter)) {
			return false;
		}
	}
	return true;
}
