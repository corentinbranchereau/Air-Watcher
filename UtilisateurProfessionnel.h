/*************************************************************************
						   UtilisateurProfessionnel  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <UtilisateurProfessionnel> (fichier UtilisateurProfessionnel.h) ------
#if ! defined ( UTILISATEURPROFESSIONNEL_H )
#define UTILISATEURPROFESSIONNEL_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "Mesure.h"
#include "Zone.h"
#include "Horodatage.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <UtilisateurProfessionnel>
//
//
//------------------------------------------------------------------------ 

class UtilisateurProfessionnel : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Mesure* ConsulterMoyenneDonneesDatePrecise(Horodatage& date, Zone& zone);

	Mesure** ConsulterMoyenneDonneesPeriodePrecise(Horodatage& dateDebut, Horodatage& dateFin, Zone& zone);

	int ConsulterQualiteDatePrecise(Horodatage& date, Zone& zone);

	int* ConsulterQualitePeriodePrecise(Horodatage& dateDebut, Horodatage& dateFin, Zone& zone);

	Mesure** ObtenirDonneesBrutes();


//------------------------------------------------- Surcharge d'opérateurs
	UtilisateurProfessionnel & operator = (const UtilisateurProfessionnel & unUtilisateurProfessionnel);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	UtilisateurProfessionnel (const UtilisateurProfessionnel & unUtilisateurProfessionnel);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	UtilisateurProfessionnel ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~UtilisateurProfessionnel ();
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
	bool compteValide;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <UtilisateurProfessionnel>

#endif // UTILISATEURPROFESSIONNEL_H