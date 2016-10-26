#include <iostream>
#include <string>
#include "ClassBullCow.h"

using namespace std;

int main()
{
	int nb;
	string rejouer = "Y";
	ClassBullCow Jeu;

	while (rejouer == "y" || rejouer == "Y") //While pour la rejouabilité
	{
		Jeu.SetJeuDebut();
		while (Jeu.Defaite() == 0 && Jeu.Victoire() == 0)//While pour le jeu
		{
			Jeu.Essai();
		}
		if (Jeu.Defaite() == 1)
		{
			cout << "Desole mais vous avez perdue" << endl;
		}
		if (Jeu.Victoire() == 1)
		{
			cout << "Bravo vous avez gagné" << endl;
		}
		cout << "Voulez-vous rejouer (Y/N)" << endl;
		getline(cin, rejouer);
	}

	return 0;

}