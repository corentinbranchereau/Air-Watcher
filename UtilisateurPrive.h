/*************************************************************************
						   UtilisateurPrive  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <UtilisateurPrive> (fichier UtilisateurPrive.h) ------
#if ! defined ( UTILISATEURPRIVE_H )
#define UTILISATEURPRIVE_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "Mesure.h"
#include "MesureUtilisateur.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <UtilisateurPrive>
//
//
//------------------------------------------------------------------------ 

class UtilisateurPrive : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool EntrerDonnees(string idAttribut, double valeur);

	int ObtenirPoints();

	Mesure** ConsulterDonneesEntrees();

//------------------------------------------------- Surcharge d'opérateurs
	UtilisateurPrive & operator = (const UtilisateurPrive & unUtilisateurPrive);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	UtilisateurPrive (const UtilisateurPrive & unUtilisateurPrive);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	UtilisateurPrive ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~UtilisateurPrive ();
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
	int nbPoints;
	string idUtilisateur;
	MesureUtilisateur* donneesEntrees;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <UtilisateurPrive>

#endif // UTILISATEURPRIVE_H