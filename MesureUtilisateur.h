/*************************************************************************
						   MesureUtilisateur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <MesureUtilisateur> (fichier MesureUtilisateur.h) ------
#if ! defined ( MESUREUTILISATEUR_H )
#define MESUREUTILISATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesureUtilisateur>
//
//
//------------------------------------------------------------------------

class MesureUtilisateur : public Mesure
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
	MesureUtilisateur & operator = (const MesureUtilisateur & unMesureUtilisateur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	MesureUtilisateur (const MesureUtilisateur & unMesureUtilisateur);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	MesureUtilisateur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~MesureUtilisateur ();
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
	string label;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <MesureUtilisateur>

#endif // MESUREUTILISATEUR_H
