#pragma once
#include <iostream>
#include <string>

using namespace std;

struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class ClassBullCow
{
public:
	ClassBullCow();
	~ClassBullCow();

	void SetJeuDebut();

	void Essai();

	int TestLongueurMot(string Mot);

	int TestLowerCase(string Mot);

	int TestIsogramme(string Mot);

	int TestMotJuste(string Mot);

	int TestLettreBonEndroit(string Mot);

	int TestLettreBonne(string Mot);

	int GetMaxTries() const;

	int Defaite();

	int Victoire();



private:
	int  MyCurrentTry;
	string MyHiddenWord;
	bool bGameIsWon;
};

