/*************************************************************************
						   TypeAttribut  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <TypeAttribut> (fichier TypeAttribut.h) ------
#if ! defined ( TYPEATTRIBUT_H )
#define TYPEATTRIBUT_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TypeAttribut>
//
//
//------------------------------------------------------------------------

class TypeAttribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string getIdAttribut();

	string getUnite();

	string getDescription();


//------------------------------------------------- Surcharge d'opérateurs


	TypeAttribut & operator = (const TypeAttribut & unTypeAttribut);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool operator == (const TypeAttribut & unTypeAttribut) const;
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	TypeAttribut (const TypeAttribut & unTypeAttribut);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	TypeAttribut (string id, string unite,string description);
	// Mode d'emploi :
	//
	// Contrat :
	//

	TypeAttribut ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~TypeAttribut ();
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
	string idAttribut;
	string unite;
	string description;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <TypeAttribut>

#endif // TYPEATTRIBUT_H
