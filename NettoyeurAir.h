/*************************************************************************
						   NettoyeurAir  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <NettoyeurAir> (fichier NettoyeurAir.h) ------
#if ! defined ( NETTOYEURAIR_H )
#define NETTOYEURAIR_H

//--------------------------------------------------- Interfaces utilisées
#include "Equipement.h"
#include "Horodatage.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <NettoyeurAir>
//
//
//------------------------------------------------------------------------

class NettoyeurAir : public Equipement
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
	NettoyeurAir & operator = (const NettoyeurAir & unNettoyeurAir);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	NettoyeurAir (const NettoyeurAir & unNettoyeurAir);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	NettoyeurAir ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~NettoyeurAir ();
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
	bool actif;
	double rayon;
	Horodatage debutActivite;
	Horodatage finActivite;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <NettoyeurAir>

#endif // NETTOYEURAIR_H
