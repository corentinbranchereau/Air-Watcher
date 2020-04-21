/*************************************************************************
						   Controleur  -  Classe de contrôle faisant le lien entre l'affichage et les données
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ------
#if ! defined ( CONTROLEUR_H )
#define CONTROLEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "Affichage.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controleur>
// Cette classe va permettre de centraliser toutes les actions de l'utilisateur 
// afin de traiter sa demande et renvoyer les résultats à l'affichage, qui est 
// également géré par ce contrôleur.
//
//------------------------------------------------------------------------

class Controleur
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
	Controleur & operator = (const Controleur & unControleur);
	// Mode d'emploi : Copie l'attribut affichage et effectue une copie
	// en profondeur de l'attribut utilisateurConnecte
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	Controleur (const Controleur & unControleur);
	// Mode d'emploi (constructeur de copie) : Copie l'attribut affichage et effectue une copie
	// en profondeur de l'attribut utilisateurConnecte
	//
	// Contrat : Aucun
	//

	Controleur ();
	// Mode d'emploi : Initialise l'attribut utilisateurConnecte à nullptr
	//
	// Contrat : Aucun
	//

	virtual ~Controleur ();
	// Mode d'emploi : Détruit le contrôleur en supprimant (en profondeur),
	// si il y a besoin, l'attribut utilisateurConnecte
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Utilisateur* utilisateurConnecte;
	Affichage affichage;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Controleur>

#endif // CONTROLEUR_H
