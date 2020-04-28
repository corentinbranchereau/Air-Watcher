/*************************************************************************
						   Mesure  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées
#include "Horodatage.h"
#include "TypeAttribut.h"
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	TypeAttribut getTypeMesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	double getValeurAttribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	string getIdCapteur();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Horodatage getdateMesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	
	


//------------------------------------------------- Surcharge d'opérateurs
	Mesure & operator = (const Mesure & unMesure);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Mesure (const Mesure & unMesure);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Mesure(TypeAttribut typeMesure,double valeurAttribut,string idCapteur,Horodatage dateMesure);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Mesure ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Mesure ();
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
	TypeAttribut typeMesure;
	double valeurAttribut;
	string idCapteur;
	Horodatage dateMesure;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Mesure>

#endif // MESURE_H
