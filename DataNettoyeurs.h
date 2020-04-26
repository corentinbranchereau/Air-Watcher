/*************************************************************************
						   DataNettoyeurs  -  Classe stockant et gérant les nettoyeurs d'air
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
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataNettoyeurs>
// Cette classe va servir de stockage pour tous les nettoyeurs d'air de
// l'application, et va permettre les différentes opérations possibles sur
// ces derniers
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

    bool ChargerNettoyeurs(string fichierNettoyeurs);
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool AjouterNettoyeur(NettoyeurAir & nettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool SupprimerNettoyeur(string idNettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool ActiverNettoyeur(string idNettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool DesactiverNettoyeur(string idNettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	//

    double ObtenirRayonActionNettoyeur(string idNettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	//

    vector<NettoyeurAir> GetNettoyeurs();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
	DataNettoyeurs & operator = (const DataNettoyeurs & unDataNettoyeurs);
	// Mode d'emploi : Opérateur qui copie simplement les attributs de la classe
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	DataNettoyeurs (const DataNettoyeurs & unDataNettoyeurs);
	// Mode d'emploi (constructeur de copie) : Constructeur qui copie simplement 
	// les attributs de la classe
	//
	// Contrat : Aucun
	//

	DataNettoyeurs ();
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

	virtual ~DataNettoyeurs ();
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    vector<NettoyeurAir> nettoyeurs;
	string cheminFichierNettoyeurs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataNettoyeurs>

#endif // DATANETTOYEURS_H
