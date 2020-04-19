/*************************************************************************
						   AgenceGouvernementale  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <AgenceGouvernementale> (fichier AgenceGouvernementale.h) ------
#if ! defined ( AGENCEGOUVERNEMENTALE_H )
#define AGENCEGOUVERNEMENTALE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AgenceGouvernementale>
//
//
//------------------------------------------------------------------------ 

class AgenceGouvernementale
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
	AgenceGouvernementale & operator = (const AgenceGouvernementale & unAgenceGouvernementale);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	AgenceGouvernementale (const AgenceGouvernementale & unAgenceGouvernementale);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	AgenceGouvernementale ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~AgenceGouvernementale ();
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

//----------------------------------------- Types dépendants de <AgenceGouvernementale>

#endif // AGENCEGOUVERNEMENTALE_H