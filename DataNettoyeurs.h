/*************************************************************************
						   DataNettoyeurs  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataNettoyeurs> (fichier DataNettoyeurs.h) ------
#if ! defined ( DATANETTOYEURS_H )
#define DATANETTOYEURS_H

//--------------------------------------------------- Interfaces utilisées
#include "NettoyeurAir.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataNettoyeurs>
//
//
//------------------------------------------------------------------------

class DataNettoyeurs
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    static bool ChargerNettoyeurs(string fichierNettoyeurs);

    static bool AjouterNettoyeur(NettoyeurAir & nettoyeur);

    static bool SupprimerNettoyeur(string idNettoyeur);

    static bool ActiverNettoyeur(string idNettoyeur);

    static bool DesactiverNettoyeur(string idNettoyeur);

    static double ObtenirRayonActionNettoyeur(string idNettoyeur);

    static NettoyeurAir* GetNettoyeurs();


//------------------------------------------------- Surcharge d'opérateurs
	DataNettoyeurs & operator = (const DataNettoyeurs & unDataNettoyeurs);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	DataNettoyeurs (const DataNettoyeurs & unDataNettoyeurs);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	DataNettoyeurs ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~DataNettoyeurs ();
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
    NettoyeurAir* nettoyeurs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataNettoyeurs>

#endif // DATANETTOYEURS_H
