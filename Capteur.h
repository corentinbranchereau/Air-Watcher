/*************************************************************************
						   Capteur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Equipement.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur : public Equipement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	string getEtat();
	
	
	


//------------------------------------------------- Surcharge d'opérateurs
	Capteur & operator = (const Capteur & unCapteur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	Capteur (string id, string description,PointGeographique p,string etat="fonctionne");
	// Mode d'emploi :
	//
	// Contrat :
	//


	Capteur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Capteur ();
	// Mode d'emploi :
	//
	// Contrat :
	//



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
	Capteur (const Capteur &unCapteur);
	// Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés
	string etat;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Capteur>

#endif // CAPTEUR_H
