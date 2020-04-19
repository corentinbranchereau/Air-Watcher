/*************************************************************************
						   PointGeographique  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <PointGeographique> (fichier PointGeographique.h) ------
#if ! defined ( POINTGEOGRAPHIQUE_H )
#define POINTGEOGRAPHIQUE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PointGeographique>
//
//
//------------------------------------------------------------------------

class PointGeographique
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
	PointGeographique & operator = (const PointGeographique & unPointGeographique);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	PointGeographique (const PointGeographique & unPointGeographique);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	PointGeographique ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~PointGeographique ();
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
	double longitude;
	double latitude;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <PointGeographique>

#endif // POINTGEOGRAPHIQUE_H
