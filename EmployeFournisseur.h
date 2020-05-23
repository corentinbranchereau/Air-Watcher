/*************************************************************************
						   EmployeFournisseur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <EmployeFournisseur> (fichier EmployeFournisseur.h) ------
#if ! defined ( EMPLOYEFOURNISSEUR_H )
#define EMPLOYEFOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "UtilisateurProfessionnel.h"
#include "CompagnieFournisseur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EmployeFournisseur>
//
//
//------------------------------------------------------------------------

class EmployeFournisseur : public UtilisateurProfessionnel
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	CompagnieFournisseur* GetCompagnie();
	// Mode d'emploi : Retourne l'attribut 'compagnie' de l'employé
	//
	// Contrat : Aucun
	//

//------------------------------------------------- Surcharge d'opérateurs
	EmployeFournisseur & operator = (const EmployeFournisseur & unEmployeFournisseur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	EmployeFournisseur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	EmployeFournisseur (string idFourn, string mdpFourn, string nomFourn, string prenomFourn, string mailFourn, bool validFourn, CompagnieFournisseur* compagnieFourn);
	// Mode d'emploi : Constructeur qui initialise les attributs avec les valeurs fournies
	//
	// Contrat : Aucun
	//

	virtual ~EmployeFournisseur ();
	// Mode d'emploi :
	// compagie supprimée dans DataUtilisateurs
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    EmployeFournisseur (const EmployeFournisseur & unEmployeFournisseur);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //
protected:
//----------------------------------------------------- Attributs protégés
	CompagnieFournisseur* compagnie;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <EmployeFournisseur>

#endif // EMPLOYEFOURNISSEUR_H
