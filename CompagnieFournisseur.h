/*************************************************************************
						   CompagnieFournisseur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <CompagnieFournisseur> (fichier CompagnieFournisseur.h) ------
#if ! defined ( COMPAGNIEFOURNISSEUR_H )
#define COMPAGNIEFOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "NettoyeurAir.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CompagnieFournisseur>
//
//
//------------------------------------------------------------------------ 

class CompagnieFournisseur
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
	CompagnieFournisseur & operator = (const CompagnieFournisseur & unCompagnieFournisseur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	CompagnieFournisseur (const CompagnieFournisseur & unCompagnieFournisseur);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	CompagnieFournisseur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~CompagnieFournisseur ();
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
	NettoyeurAir* nettoyeursCompagnie;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CompagnieFournisseur>

#endif // COMPAGNIEFOURNISSEUR_H