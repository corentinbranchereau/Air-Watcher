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

    static bool ChargerMesures(string fichierMesures);

    static Mesure* ConsulterMoyenneDonneesDatePrecise(Horodatage & date, Zone & zone);

    static Mesure** ConsulterMoyenneDonneesPeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone);

    static int ConsulterQualiteDatePrecise(Horodatage & date, Zone & zone);

    static int* ConsulterQualitePeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone);

    static Mesure* ObtenirDonneesBrutes();

    static bool EntrerDonnees(string idAttribut, double valeur, UtilisateurPrive & utilisateur);

    static Capteur** IdentifierCapteursSimilaires();

    static void LabeliserDonneesUtilisateur();

    static TypeAttribut* GetTypeAttributs();

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
	Mesure* mesures;
	TypeAttribut* typeAttributs;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataMesures>

#endif // DATAMESURES_H
