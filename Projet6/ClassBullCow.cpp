#include "ClassBullCow.h"
#include <string>
#include <map>

using namespace std;

ClassBullCow::ClassBullCow()
{
}


ClassBullCow::~ClassBullCow()
{
}

// Initialise le jeu
void ClassBullCow::SetJeuDebut() {
	bGameIsWon = false;
	MyHiddenWord = "jongler";
	MyCurrentTry = 0;
}

// Fonction pour gérer les mots que rentre le joueur
void ClassBullCow::Essai()
{
	string MotEssai; //Mot entrer par le joueur
	cout << "Il vous reste " << GetMaxTries() - MyCurrentTry << " tentative" << endl;
	MyCurrentTry = MyCurrentTry + 1;
	cout << "entrer un mot" << endl;
	getline(cin, MotEssai);
	if (TestLongueurMot(MotEssai) == 0) {
		cout << "Mot de mauvaise longueur" << endl;
	}
	if (TestLowerCase(MotEssai) == 0) {
		cout << "Mot avec des majuscule" << endl;
	}
	if (TestIsogramme(MotEssai) == 0) {
		cout << "Mot avec plusieurs meme lettre" << endl;
	}
	if (TestLongueurMot(MotEssai) == 1 && TestLowerCase(MotEssai) == 1 && TestIsogramme(MotEssai) == 1)
	{
		cout << "Bull " << TestLettreBonEndroit(MotEssai) << endl;
		cout << "Cow " << TestLettreBonne(MotEssai) << endl;
		if (TestMotJuste(MotEssai) == 1) 
		{
			bGameIsWon = true;
		}
	}

}

//Test la longueur du mot
int ClassBullCow::TestLongueurMot(string Mot ) {
	
	if ((Mot.length()) == (MyHiddenWord.length()))
		return 1;
	else
		return 0;

}

//Test si le mot est en minuscule
int ClassBullCow::TestLowerCase(string Mot) {
	int i;

	for (i = 0; i< Mot.length(); i++)
	{
		if (!((Mot[i] >= '0' &&  Mot[i] <= '9') || (Mot[i] >= 'a' &&  Mot[i] <= 'z'))) return 0;
	}

	return 1;

}

//Test si c'est un isogramme
int ClassBullCow::TestIsogramme(string Mot) {
	int i;
	int i1;
	int longueurMot;

	longueurMot = Mot.length();

	for (i = 0; i < longueurMot; i++)
	{
		for (i1 = 0; i1 < longueurMot; i1++)
		{
			if (i != i1) 
			{
				if (Mot[i] == Mot[i1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//Test si le mot est juste
int ClassBullCow::TestMotJuste(string Mot) {
	int i;
	int i1;
	int longueurMot;
	int longueurHiddenWord;

	longueurMot = Mot.length();
	longueurHiddenWord = MyHiddenWord.length();

	for (i = 0; i < longueurMot; i++)
	{
		for (i1 = 0; i1 < longueurHiddenWord; i1++)
		{
			if (i == i1)
			{
				if (Mot[i] != MyHiddenWord[i1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//Test les Bull
int ClassBullCow::TestLettreBonEndroit(string Mot) {
	int i;
	int i1;
	int compteur = 0;

	int longueurMot;
	int longueurHiddenWord;

	longueurMot = Mot.length();
	longueurHiddenWord = MyHiddenWord.length();

	for (i = 0; i < longueurMot; i++)
	{
		for (i1 = 0; i1 < longueurHiddenWord; i1++)
		{
			if (i == i1)
			{
				if (Mot[i] == MyHiddenWord[i1])
				{
					compteur = compteur + 1;
				}
			}
		}
	}
	return compteur;
}

//Test les Cows
int ClassBullCow::TestLettreBonne(string Mot) {
	int i;
	int i1;
	int compteur = 0;

	int longueurMot;
	int longueurHiddenWord;

	longueurMot = Mot.length();
	longueurHiddenWord = MyHiddenWord.length();

	for (i = 0; i < longueurMot; i++)
	{
		for (i1 = 0; i1 < longueurHiddenWord; i1++)
		{
			if (Mot[i] == MyHiddenWord[i1])
			{
				compteur = compteur + 1;
			}
		}
	}
	return (compteur - TestLettreBonEndroit(Mot));
}

//Test les tentatives max
int ClassBullCow::GetMaxTries() const
{
	map<int, int> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

//Test la defaite
int ClassBullCow::Defaite()
{
	if (MyCurrentTry >= GetMaxTries())
	{
		return 1;
	}

	return 0;
}

//Test la victoire
int ClassBullCow::Victoire()
{
	if (bGameIsWon == 1) {
		return 1;
	}

	return 0;
}