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

//------------------------------------------------- Surcharge d'opérateurs
	EmployeFournisseur & operator = (const EmployeFournisseur & unEmployeFournisseur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	EmployeFournisseur (const EmployeFournisseur & unEmployeFournisseur);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	EmployeFournisseur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~EmployeFournisseur ();
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
	CompagnieFournisseur compagnie;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <EmployeFournisseur>

#endif // EMPLOYEFOURNISSEUR_H
