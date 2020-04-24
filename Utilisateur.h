/*************************************************************************
						   Utilisateur  -  Classe abstraite représentant un utilisateur
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ------
#if ! defined ( UTILISATEUR_H )
#define UTILISATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
// Cette classe va permette de représenter de manière abstraite un utilisateur
// et ce quel que soit son type. Elle permettra donc notamment le stockage de
// plusieurs utilisateurs dans une même structure
//
//------------------------------------------------------------------------

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
	Utilisateur & operator = (const Utilisateur & unUtilisateur);
	// Mode d'emploi : L'opérateur copie simplement les valeurs de
	// chaque attribut
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	Utilisateur (const Utilisateur & unUtilisateur);
	// Mode d'emploi (constructeur de copie) : Construit un objet Utilisateur
	// en copiant les attributs de l'utilisateur passé en paramètre
	//
	// Contrat : Aucun
	//

	Utilisateur ();
	// Mode d'emploi : Constructeur qui fixe tous les attributs à des chaines vide
	//
	// Contrat : Aucun
	//

	Utilisateur(string identifiant_c, string mdp_c, string nom_c, string prenom_c, string mail_c);
	// Mode d'emploi : Constructeur qui initialise les attributs avec les valeurs fournies
	//
	// Contrat : Aucun
	//

	virtual ~Utilisateur ();
	// Mode d'emploi : Destructeur qui n'a pas d'action particulière
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	string nom;
	string prenom;
	string mail;
	string mdp;
	string identifiant;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Utilisateur>

#endif // UTILISATEUR_H
