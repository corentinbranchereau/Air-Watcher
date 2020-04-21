/*************************************************************************
						   DataCapteurs  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataCapteurs> (fichier DataCapteurs.h) ------
#if ! defined ( DATACAPTEURS_H )
#define DATACAPTEURS_H

//--------------------------------------------------- Interfaces utilisées
#include "Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataCapteurs>
//
//
//------------------------------------------------------------------------

class DataCapteurs
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    static bool ChargerCapteurs(string fichierCapteurs);

    static bool AjouterCapteur(Capteur & capteur);

    static bool ModifierCapteur(string idCapteur, double longitude, double latitude, string etat, string description);

    static Capteur* GetCapteurs();


//------------------------------------------------- Surcharge d'opérateurs
	DataCapteurs & operator = (const DataCapteurs & unDataCapteurs);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	DataCapteurs (const DataCapteurs & unDataCapteurs);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	DataCapteurs ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~DataCapteurs ();
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
    Capteur* capteurs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataCapteurs>

#endif // DATACAPTEURS_H
