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
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool ChargerCapteursPrives(string fichierCapteursPrives);
	// Mode d'emploi : Méthode qui va lire le fichier 'users.csv' afin de construire
	// la map reliant un ID capteur à un ID utilisateur privé. Pour cela, le fichier
	// est ouvert en lecture, et construit pour chaque ligne une entrée dans la map
	//
	// Contrat : Chaque ligne doit être au format idUser;idCapteur
	//

    bool AjouterCapteur(Capteur & capteur);
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool ModifierCapteur(string idCapteur, double longitude, double latitude, string etat, string description);
	// Mode d'emploi :
	//
	// Contrat :
	//

    vector<Capteur>& GetCapteurs();
	// Mode d'emploi :
	//
	// Contrat :
	//


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
