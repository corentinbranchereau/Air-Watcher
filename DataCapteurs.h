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
#include <vector>
#include <unordered_map>

using namespace std;

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

    bool ChargerCapteurs(string fichierCapteurs);

    bool AjouterCapteur(Capteur & capteur);

    bool ModifierCapteur(string idCapteur, double longitude, double latitude, string etat, string description);

    vector<Capteur>& GetCapteurs();


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
    vector<Capteur> capteurs;
	unordered_map<string, string> mapCapteurUtilisateur; // clé = idCapteur, valeur = idUtilisateurPrivé
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataCapteurs>

#endif // DATACAPTEURS_H
