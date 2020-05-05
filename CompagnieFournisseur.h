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
#include <vector>

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

	void addNettoyeur(NettoyeurAir * nettoyeurAir);
    // Mode d'emploi :
    // Passe en paramètre le nettoyeur à ajouter
    // Contrat :
    // Le pointeur est bien défini et pointe vers le nettoyeur en mémoire

    vector<NettoyeurAir*> getNettoyeurs();
    // Mode d'emploi :
    // Retourne la liste des nettoyeurs d'une compagnie
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'opérateurs
	CompagnieFournisseur & operator = (const CompagnieFournisseur & unCompagnieFournisseur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	CompagnieFournisseur (string id);
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

    CompagnieFournisseur (const CompagnieFournisseur & unCompagnieFournisseur);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés
	string idProvider;
	vector<NettoyeurAir*> nettoyeurs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CompagnieFournisseur>

#endif // COMPAGNIEFOURNISSEUR_H
