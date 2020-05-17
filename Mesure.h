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

	TypeAttribut* getTypeMesure();
	// Mode d'emploi : renvoie le type de Mesure
	//
	// Contrat : aucun
	//

	double getValeurAttribut();
	// Mode d'emploi : renvoie la valeur de l'attribut
	//
	// Contrat : aucun
	//

	string getIdCapteur();
	// Mode d'emploi : renvoie l'id capteur associé à la mesure
	//
	// Contrat : aucun
	//

	Horodatage getdateMesure();
	// Mode d'emploi : renvoie la date de la mesure
	//
	// Contrat : aucun
	//

	void setValue(double valeur);
	// Mode d'emploi : permet de définir la valeur de la mesure arbitrairement
	//
	// Contrat : aucun
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

	Mesure(TypeAttribut* typeMesure,double valeurAttribut,string idCapteur,Horodatage dateMesure);
	// Mode d'emploi : construit un TypeAttribut
	//
	// Contrat : aucun
	//

	Mesure ();
	// Mode d'emploi :
	//
	// Contrat : aucun
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
	TypeAttribut* typeMesure;
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
