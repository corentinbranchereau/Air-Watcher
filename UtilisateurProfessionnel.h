/*************************************************************************
						   UtilisateurProfessionnel  -  Classe représentant un utilisateur professionnel de l'application
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <UtilisateurProfessionnel> (fichier UtilisateurProfessionnel.h) ------
#if ! defined ( UTILISATEURPROFESSIONNEL_H )
#define UTILISATEURPROFESSIONNEL_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <UtilisateurProfessionnel>
// Cette classe va représenter de manière abstraite un utilisateur privé afin
// de stocker et gérer tous type d'utilisateur qui dérive de cette classe
// (fournisseurs et employés de l'agence)
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

	bool GetCompteValide();
	// Mode d'emploi : Renvoie l'attribut 'compteValide' de l'utilisateur
	//
	// Contrat : Aucun
	//

//------------------------------------------------- Surcharge d'opérateurs
	UtilisateurProfessionnel & operator = (const UtilisateurProfessionnel & unUtilisateurProfessionnel);
	// Mode d'emploi : Opérateur qui copie l'attribut 'compteValide' ainsi que les attributs
	// de la classe 'Utilisateur'
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur

	UtilisateurProfessionnel ();
	// Mode d'emploi : Constructeur par défaut, ne fait rien de particulier
	//
	// Contrat :
	//

	UtilisateurProfessionnel(string identifiant_c,string mdp_c,string nom_c,string prenom_c,string mail_c);
	// Mode d'emploi : Constructeur qui initialise les attributs avec les valeurs fournies
	//
	// Contrat : Aucun
	//

	virtual ~UtilisateurProfessionnel ();
	// Mode d'emploi : Destructeur qui ne fait rien de particulier
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    UtilisateurProfessionnel (const UtilisateurProfessionnel & unUtilisateurProfessionnel);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat : Aucun
    //
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
