/*************************************************************************
						   Zone  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Zone> (fichier Zone.h) ------
#if ! defined ( ZONE_H )
#define ZONE_H

//--------------------------------------------------- Interfaces utilisées
#include "PointGeographique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Zone>
//
//
//------------------------------------------------------------------------

class Zone
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool VerifierAppartenancePoint(PointGeographique & point);


//------------------------------------------------- Surcharge d'opérateurs
	Zone & operator = (const Zone & unZone);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	Zone ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Zone ();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    Zone (const Zone & unZone);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //
protected:
//----------------------------------------------------- Attributs protégés
	double rayon;
	PointGeographique centre;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Zone>

#endif // ZONE_H
