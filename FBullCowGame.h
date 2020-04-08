/* This is the logic part of the game, it doesn't interacts with the user
*/

#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};
class FBullCowGame {
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetGurrentTry() const;
	int32 GetHiddenWordLength()const;
	bool IsGameWon() const;
	void Reset();
	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
