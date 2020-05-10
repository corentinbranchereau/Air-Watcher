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

	void SetLabel(string lab);
	// Mode d'emploi : Change la valeur de l'attribut label
	//
	// Contrat : Aucun
	//


//------------------------------------------------- Surcharge d'opérateurs
	MesureUtilisateur & operator = (const MesureUtilisateur & unMesureUtilisateur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	MesureUtilisateur ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	MesureUtilisateur(TypeAttribut* typeMesure,double valeurAttribut,string idCapteur,Horodatage dateMesure);
	// Mode d'emploi : Constructeur initialisant les attributs avec les valeurs fournies (initialise le label 
	// à une chaine vide)
	//
	// Contrat : Aucun
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
    MesureUtilisateur (const MesureUtilisateur & unMesureUtilisateur);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //
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
