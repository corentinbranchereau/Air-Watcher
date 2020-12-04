/*************************************************************************
						   Admin  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Admin> (fichier Admin.h) ------
#if ! defined ( ADMIN_H )
#define ADMIN_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Admin>
//
//
//------------------------------------------------------------------------

class Admin : public Utilisateur
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
	Admin & operator =(const Admin & unAdmin);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	Admin();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Admin(string idAdmin, string mdpAdmin, string nomAdmin, string prenomAdmin, string mailAdmin);
	// Mode d'emploi : Constructeur qui initialise les attributs avec les valeurs fournies
	//
	// Contrat : Aucun
	//

	virtual ~Admin();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

    Admin(const Admin & unAdmin);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Admin>

#endif //_ADMIN_H
