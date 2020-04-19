/*************************************************************************
						   Utilisateur  -  description
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
//
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

	static Utilisateur* SeConnecter(string mail, string mdp);

	static bool SeDeconnecter(Utilisateur* utilisateur);

	static bool SeCreerUnCompte(string nom, string prenom, string mail, string mdp, string compagnie, string typeCompte);

	bool ModifierSonCompte(string nom, string prenom, string mdp);


//------------------------------------------------- Surcharge d'opérateurs
	Utilisateur & operator = (const Utilisateur & unUtilisateur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Utilisateur (const Utilisateur & unUtilisateur);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Utilisateur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Utilisateur ();
	// Mode d'emploi :
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
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Utilisateur>

#endif // UTILISATEUR_H
