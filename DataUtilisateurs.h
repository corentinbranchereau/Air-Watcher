/*************************************************************************
						   DataUtilisateurs  -  description
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
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataUtilisateurs>
//
//
//------------------------------------------------------------------------

class DataUtilisateurs
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    static bool ChargerUtilisateurs(string fichierUtilisateurs);

    static bool VerifierUnCompte(string mail,bool validation);

    static UtilisateurProfessionnel* ObtenirComptesEnAttente();

    static bool GererCompte(string mail, string nom, string prenom, string mdp);

	static Utilisateur* GetUtilisateurs();


//------------------------------------------------- Surcharge d'opérateurs
	DataUtilisateurs & operator = (const DataUtilisateurs & unAffichage);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	DataUtilisateurs (const DataUtilisateurs & unAffichage);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	DataUtilisateurs ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~DataUtilisateurs ();
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
	Utilisateur* utilisateurs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataUtilisateurs>

#endif // DATAUTILISATEURS_H
