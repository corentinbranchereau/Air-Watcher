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
	Horodatage & getDebutActivite();
	// Mode d'emploi :
	//
	// Contrat :
	//


	Horodatage & getFinActivite();
	// Mode d'emploi :
	//
	// Contrat :
	//

	double getRayon();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setActif(bool act);
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

	NettoyeurAir ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	NettoyeurAir (bool act, double ray, Horodatage horoDebut, Horodatage horoFin, string idNettoyeur, string desc, PointGeographique pGeo);
	// Mode d'emploi : Constructeur de NettoyeurAir qui remplit tous ses attributs
	//
	// Contrat : Aucun
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
    NettoyeurAir (const NettoyeurAir & unNettoyeurAir);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //
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
