/*************************************************************************
						   Affichage  -  Classe permettant l'affichage de l'application sur la console
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ------
#if ! defined ( AFFICHAGE_H )
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Affichage>
// Cette classe dispose de toutes les méthodes permettant d'afficher les divers
// menu à l'utilisateur, et permettant de récupérer ce qu'il rentre afin de
// déclencher par la suite les bonnes actions via le contrôleur
//
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void NettoyerConsole();
	// Mode d'emploi : L'appel à cette méthode permet de supprimer tout le texte
	// présent dans la console, pour passer à une autre "page" de l'application
	//
	// Contrat : Aucun
	//

	void AfficherTitre();
	// Mode d'emploi : Cette méthode permet d'afficher le titre de l'application
	// dans la console, ainsi que les auteurs
	//
	// Contrat : Il faut que la fenêtre de la console soit suffisamment grande
	//

	string Souligner(const string & chaine);
	// Mode d'emploi : Cette méthode prend en paramètre une chaine de caractère
	// à souligner dans la console, et renvoie la chaine encadrée par des 
	// manipulateurs qui permettent de la souligner dans la console
	//
	// Contrat : Aucun
	//

	int SaisirChoix(int choixMax);
	// Mode d'emploi : Cette méthode permet de récupérer le choix (entier) saisi
	// par l'utilisateur en gérant les erreurs (si l'utilisateur n'a pas rentré un
	// entier, ou si l'entier est trop petit/grand)
	//
	// Contrat : Aucun
	//

	int AfficherMenuPrincipal();
	// Mode d'emploi : Cette méthode permet d'afficher le menu principal et de
	// récupérer le choix d'action que l'utilisateur a tapé
	//
	// Contrat : Aucun
	//

	string* AfficherCreationCompte();
	// Mode d'emploi : Méthode affichant le menu de création de compte et retournant
	// les informations rentrées par l'utilisateur, sous forme d'un tableau de string
	//
	// Contrat : Aucun
	//


//------------------------------------------------- Surcharge d'opérateurs
	Affichage & operator = (const Affichage & unAffichage);
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	Affichage (const Affichage & unAffichage);
	// Mode d'emploi (constructeur de copie) : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

	Affichage ();
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

	virtual ~Affichage ();
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Affichage>

#endif // AFFICHAGE_H
