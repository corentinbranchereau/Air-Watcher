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
#include "UtilisateurProfessionnel.h"
#include "Capteur.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Admin>
//
//
//------------------------------------------------------------------------ 

class Admin: public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public: 
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool VerifierUnCompte(string mail, bool validation);

	UtilisateurProfessionnel* ObtenirComptesEnAttente();

	bool GererCompte(string mail, string nom, string prenom, string mdp);

	bool AjouterCapteur(Capteur & capteur);

	bool ModifierCapteur(string id, string longitude, string latitude, string etat, string description);

//------------------------------------------------- Surcharge d'opérateurs
	Admin & operator =(const Admin & unAdmin);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Admin(const Admin & unAdmin);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Admin();
	// Mode d'emploi :
	//
	// Contrat :
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