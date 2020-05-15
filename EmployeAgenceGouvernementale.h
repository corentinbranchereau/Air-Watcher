/*************************************************************************
						   EmployeAgenceGouvernementale  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <EmployeAgenceGouvernementale> (fichier EmployeAgenceGouvernementale.h) ------
#if ! defined ( EMPLOYEAGENCEGOUVERNEMENTALE_H )
#define EMPLOYEAGENCEGOUVERNEMENTALE_H

//--------------------------------------------------- Interfaces utilisées
#include "UtilisateurProfessionnel.h"
#include "AgenceGouvernementale.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EmployeAgenceGouvernementale>
//
//
//------------------------------------------------------------------------

class EmployeAgenceGouvernementale : public UtilisateurProfessionnel
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
	EmployeAgenceGouvernementale & operator = (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	EmployeAgenceGouvernementale ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~EmployeAgenceGouvernementale ();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    EmployeAgenceGouvernementale (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat :
    //
protected:
//----------------------------------------------------- Attributs protégés
	AgenceGouvernementale* agence;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <EmployeAgenceGouvernementale>

#endif // EMPLOYEAGENCEGOUVERNEMENTALE_H
