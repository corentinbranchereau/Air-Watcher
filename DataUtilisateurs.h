/*************************************************************************
						   DataUtilisateurs  -  Classe stockant et gérant les informations des utilisateurs
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataUtilisateurs> (fichier DataUtilisateurs.h) ------
#if ! defined ( DATAUTILISATEURS_H )
#define DATAUTILISATEURS_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "UtilisateurProfessionnel.h"
#include <string>
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataUtilisateurs>
// Cette classe va servir de stockage de tous les utilisateurs inscrits à
// l'application, et va permettre les différentes opérations possibles sur
// un compte (création, modification, connexion ...)
//
//------------------------------------------------------------------------

class DataUtilisateurs
{
//----------------------------------------------------------------- PUBLIC

public:
	static vector<Utilisateur*> utilisateurs; // variable static qui va servir à stocker les utilisateurs
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    static bool ChargerUtilisateurs(string fichierUtilisateurs);
	// Mode d'emploi : Cette méthode va permettre de charger les utilisateurs
	// déja inscrits depuis le fichier fourni. Pour cela, le fichier
	// est ouvert en lecture, et construit pour chaque ligne un utilisateur
	//
	// Contrat : Le fichier doit contenir les utilisateurs selon le bon format
	// à savoir : 1 utilisateur par ligne et dans l'ordre : 
	// type de compte|identifiant|mdp|nom|prénom|mail|nom compagnie (si fournisseur) ou idUtilisateur (si privé)
	//

    static bool VerifierUnCompte(string mail,bool validation);
	// Mode d'emploi :
	//
	// Contrat :
	//

    static UtilisateurProfessionnel* ObtenirComptesEnAttente();
	// Mode d'emploi :
	//
	// Contrat :
	//

    static bool GererCompte(string mail, string nom, string prenom, string mdp);
	// Mode d'emploi :
	//
	// Contrat :
	//

	static Utilisateur* GetUtilisateurs();
	// Mode d'emploi :
	//
	// Contrat :
	//

	static Utilisateur* SeConnecter(string identifiant, string mdp);
	// Mode d'emploi :
	//
	// Contrat :
	//

	static bool SeCreerUnComptes(string* informationsUtilisateur);
	// Mode d'emploi : Méthode qui permet la création d'un compte dans
	// l'application, c'est à dire l'ajout de l'utilisateur à l'attribut
	// 'utilisateurs' de la classe mais également son ajout dans le fichier
	// des utilisateurs. La méthode vérifie en premier que les informations
	// sont correctes
	//
	// Contrat : Le paramètre 'informationsUtilisateur' doit être un tableau
	// de string contenant dans l'ordre : type de compte, identifiant, mdp, 
	// nom, prénom, mail, nom compagnie (si fournisseur)
	//


//------------------------------------------------- Surcharge d'opérateurs
	DataUtilisateurs & operator = (const DataUtilisateurs & unAffichage);
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	DataUtilisateurs (const DataUtilisateurs & unAffichage);
	// Mode d'emploi (constructeur de copie) : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

	DataUtilisateurs ();
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

	virtual ~DataUtilisateurs ();
	// Mode d'emploi : Ne fait rien de particulier
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

//----------------------------------------- Types dépendants de <DataUtilisateurs>

#endif // DATAUTILISATEURS_H
