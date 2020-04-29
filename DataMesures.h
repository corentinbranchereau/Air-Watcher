/*************************************************************************
						   DataMesures  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataMesures> (fichier DataMesures.h) ------
#if ! defined ( DATAMESURES_H )
#define DATAMESURES_H

//--------------------------------------------------- Interfaces utilisées
#include "Zone.h"
#include "Horodatage.h"
#include "Mesure.h"
#include "Capteur.h"
#include "UtilisateurPrive.h"
#include "TypeAttribut.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataMesures>
//
//
//------------------------------------------------------------------------

class DataMesures
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool ChargerMesures(string fichierMesures);

    bool ChargerAttributs(string fichierAttributs);

    Mesure* ConsulterMoyenneDonneesDatePrecise(Horodatage & date, Zone & zone);

    Mesure** ConsulterMoyenneDonneesPeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone);

    int ConsulterQualiteDatePrecise(Horodatage & date, Zone & zone);

    int* ConsulterQualitePeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone);

    Mesure* ObtenirDonneesBrutes();

    bool EntrerDonnees(string idAttribut, double valeur, UtilisateurPrive & utilisateur);

    vector<vector<Capteur>> IdentifierCapteursSimilaires(vector<Capteur>& listCapteur,int nbClassesMin);

	double dissimMax(vector<Capteur> v1,vector<Capteur> v2 );
	
	double evalClasses(vector<vector<Capteur>> classI);



    void LabeliserDonneesUtilisateur();

    TypeAttribut* GetTypeAttributs();

//------------------------------------------------- Surcharge d'opérateurs
	DataMesures & operator = (const DataMesures & unDataMesures);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	DataMesures (const DataMesures & unDataMesures);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	DataMesures ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~DataMesures ();
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
	vector<Mesure> mesures;
	unordered_map<string,TypeAttribut> typeAttributs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataMesures>

#endif // DATAMESURES_H
