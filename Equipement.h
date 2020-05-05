/*************************************************************************
						   Equipement  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Equipement> (fichier Equipement.h) ------
#if ! defined ( EQUIPEMENT_H )
#define EQUIPEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "PointGeographique.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Equipement>
//
//
//------------------------------------------------------------------------

class Equipement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	string getID();

	int getIDInt();

	string getDescription();

	PointGeographique getPosition();


//------------------------------------------------- Surcharge d'opérateurs
	Equipement & operator = (const Equipement & unEquipement);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	Equipement (string id, string description,PointGeographique p);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Equipement ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Equipement ();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    Equipement (const Equipement & unEquipement);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //
protected:
//----------------------------------------------------- Attributs protégés
	string id;
	string description;
	PointGeographique position;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Equipement>

#endif // EQUIPEMENT_H
