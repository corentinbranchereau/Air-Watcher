/*************************************************************************
						   UtilisateurPrive  -  Classe représentant un utilisateur privé de l'application
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <UtilisateurPrive> (fichier UtilisateurPrive.h) ------
#if ! defined ( UTILISATEURPRIVE_H )
#define UTILISATEURPRIVE_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "MesureUtilisateur.h"
#include <string>
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <UtilisateurPrive>
// Cette classe permet de représenter un utilisateur individuel privé qui
// utilise l'application. Elle stocke notamment son nombre de points et ses
// données rentrées, et lui permet de rentrer de nouvelles données.
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

	int ObtenirPoints();
	// Mode d'emploi : Renvoie l'attribut 'nbPoints' de l'utilisateur privé
	//
	// Contrat : Aucun
	//

	vector<MesureUtilisateur> ConsulterDonneesEntrees();
	// Mode d'emploi : Renvoie l'attribut 'donneesEntrees' de l'utilisateur privé
	//
	// Contrat : Aucun
	//

//------------------------------------------------- Surcharge d'opérateurs
	UtilisateurPrive & operator = (const UtilisateurPrive & unUtilisateurPrive);
	// Mode d'emploi : Opérateur qui effectue une copie de tous les attributs,
	// notamment de la liste des données entrées (copie en profondeur)
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur

	UtilisateurPrive ();
	// Mode d'emploi : Constructeur qui initialise les attributs à des valeurs nulles
	//
	// Contrat : Aucun
	//

	UtilisateurPrive (string identifiant_c, string mdp_c, string nom_c, string prenom_c, string mail_c);
	// Mode d'emploi : Constructeur qui initialise les attributs avec les valeurs fournies
	//
	// Contrat : Aucun
	//

	virtual ~UtilisateurPrive ();
	// Mode d'emploi : Destructeur qui ne fait rien de particulier
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    UtilisateurPrive (const UtilisateurPrive & unUtilisateurPrive);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat : Aucun
    //
protected:
//----------------------------------------------------- Attributs protégés
	int nbPoints;
	vector<MesureUtilisateur> donneesEntrees;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <UtilisateurPrive>

#endif // UTILISATEURPRIVE_H
