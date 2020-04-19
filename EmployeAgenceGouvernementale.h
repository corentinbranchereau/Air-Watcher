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
#include "Capteur.h"
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

	Capteur* ConsulterListeCapteurs();

	Capteur** IdentifierCapteursSimilaires();

	void LabeliserDonneesUtilisateurs();


//------------------------------------------------- Surcharge d'opérateurs
	EmployeAgenceGouvernementale & operator = (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	EmployeAgenceGouvernementale (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

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

protected:
//----------------------------------------------------- Attributs protégés
	AgenceGouvernementale agence;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <EmployeAgenceGouvernementale>

#endif // EMPLOYEAGENCEGOUVERNEMENTALE_H