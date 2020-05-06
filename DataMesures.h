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
#include "DataCapteurs.h"

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
	
	bool LabelliserUneDonnee(vector<Mesure*> listMesuresBonnes,Mesure* m,unordered_map<string,Capteur*>& mapCapteurs);

    vector<vector<Capteur>> IdentifierCapteursSimilaires(unordered_map<string,Capteur*> &  listCapteur,int nbClassesMin);
	//mode d'emploi : renvoi les capteurs similaires à partir d'une liste de capteurs et du nombre de classes minimum
	//contrat:

    void LabeliserDonneesUtilisateur();

    unordered_map<string,TypeAttribut*>&  GetTypeAttributs();
	vector<Mesure*>& GetMesures();

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
	// Mode d'emploi : constructeur par défaut
	//
	// Contrat :
	//

	virtual ~DataMesures ();
	// Mode d'emploi : destructeur  
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	double dissimMax(vector<Capteur> & v1,vector<Capteur> & v2 );
	//mode d'emploi : renvoi le maximum de dissimilarité inter-classe entre les 2 groupes de capteur passés en paramètre
	//contrat:
	
	double evalClasses(vector<vector<Capteur>> & classI);
	//mode d'emploi : renvoi le maximum de dissimilarité intra-classe sur le groupe de capteur passé en paramètre
	//contrat:

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	vector<Mesure*> mesures;//liste des mesures
	unordered_map<string,TypeAttribut*> typeAttributs;//map des types d'Attributs
	vector <int>nbMesuresAttributs;//nb mesures par capteur
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataMesures>

#endif // DATAMESURES_H
