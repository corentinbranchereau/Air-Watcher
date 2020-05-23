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

	bool ChargerCapteursPrives(string fichierCapteursPrives, string fichierUtilisateurs);
	// Mode d'emploi : Méthode qui va lire le fichier renseignant pour chaque utilisateur l'id
	// du capteur associé afin de construire la map reliant les deux id. Pour cela, le fichier
	// est ouvert en lecture, et construit pour chaque ligne une entrée dans la map. Par ailleurs
	// la méthode écrit également les utilisateurs lus dans le fichier stockant les comptes (si ils
	// n'existent pas déjà dedans)
	//
	// Contrat : Chaque ligne doit être au format idUser;idCapteur;
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

  	unordered_map<string,Capteur*> & GetCapteurs();
	// Mode d'emploi :
	//
	// Contrat :
	//

	unordered_map<string,string> & GetMapCapteurUtilisateur();
	// Mode d'emploi : Retourne la map liant les id Capteur aux id Utilisateur
	//
	// Contrat : Aucun
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

	~DataCapteurs ();
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
	unordered_map<string, string> mapCapteurUtilisateur; // clé = idCapteur, valeur = idUtilisateurPrivé
	unordered_map<string,Capteur*> mapIDCapteurs; // clé = idCapteur
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataCapteurs>

#endif // DATACAPTEURS_H
