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
#include "UtilisateurPrive.h"
#include "EmployeFournisseur.h"
#include "EmployeAgenceGouvernementale.h"
#include "Admin.h"
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

	void AfficherFinCreationCompte(bool reussite);
	// Mode d'emploi : Méthode affichant à l'utilisateur si la création s'est bien passée
	// ou non.
	//
	// Contrat : Aucun
	//

	string* AffichageConnexion();
	// Mode d'emploi : Méthode affichant le menu de connexion et retournant
	// les informations entrées par l'utilisateur
	//
	// Contrat : Aucun
	//

	void AffichageFinConnexion(string etatConnexion);
	// Mode d'emploi : Méthode affichant à l'utilisateur si la connexion s'est bien passée
	// ou non. En particulier, pour les comptes 'agence' et 'fournisseur' affiche si le compte
	// est en attente
	//
	// Contrat : Aucun
	//

	void AfficherInformationsCompte(string type, Utilisateur* utilisateur);
	// Mode d'emploi : Cette méthode permet d'afficher en dessous du titre de l'application
	// les informations essentielles du compte : nom, prénom, type du compte, nb points si utilisateur
	// privé, nom compagnie si fournisseur
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionPrive(UtilisateurPrive* utilisateur);
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un utilisateur
	// privé et de récupérer le choix d'action que l'utilisateur a tapé.
	// On passe en paramètre le pointeur vers l'utilisateur afin d'avoir ses informations
	// (nom, prénom etc...)
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionFournisseur(EmployeFournisseur* utilisateur);
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un fournisseur
	// et de récupérer le choix d'action qu'il a tapé.
	// On passe en paramètre le pointeur vers l'utilisateur afin d'avoir ses informations
	// (nom, prénom etc...)
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionAgenceGouv(EmployeAgenceGouvernementale* utilisateur);
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un employé de
	// l'agence gouvernementale et de récupérer le choix d'action qu'il a tapé.
	// On passe en paramètre le pointeur vers l'utilisateur afin d'avoir ses informations
	// (nom, prénom etc...)
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionAdmin(Admin* utilisateur);
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un admin
	// et de récupérer le choix d'action qu'il a tapé.
	// On passe en paramètre le pointeur vers l'utilisateur afin d'avoir ses informations
	// (nom, prénom etc...)
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

    Affichage (const Affichage & unAffichage);
    // Mode d'emploi (constructeur de copie) : Ne fait rien en particulier
    // INTERDIT
    // Contrat : Aucun
    //

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
