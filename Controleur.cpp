#include "Affichage.h"
#include "DataUtilisateurs.h"
#include <iostream>

Affichage affichage;
int choix;
string* donneesSaisies;

int main(void)
{
	DataUtilisateurs::ChargerUtilisateurs("utilisateurs.txt");
	
	choix = affichage.AfficherMenuPrincipal();
	switch(choix)
	{
		case 1:
			donneesSaisies = affichage.AfficherCreationCompte();

			delete[] donneesSaisies;
		break;

		case 2:

		break;

		case 3:

		break;
	}
	return 0;
}