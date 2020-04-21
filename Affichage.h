/*************************************************************************
						   Affichage  -  Classe permettant l'affichage de l'application sur la console
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ------
#if ! defined ( AFFICHAGE_H )
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Affichage>
// Cette classe dispose de toutes les méthodes permettant d'afficher les divers
// menu à l'utilisateur, et permettant de récupérer ce qu'il rentre afin de
// déclencher par la suite les bonnes actions via le contrôleur
//
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void NettoyerConsole();
	// Mode d'emploi : L'appel à cette méthode permet de supprimer tout le texte
	// présent dans la console, pour passer à une autre "page" de l'application
	//
	// Contrat : Aucun
	//


//------------------------------------------------- Surcharge d'opérateurs
	Affichage & operator = (const Affichage & unAffichage);
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	Affichage (const Affichage & unAffichage);
	// Mode d'emploi (constructeur de copie) : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

	Affichage ();
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

	virtual ~Affichage ();
	// Mode d'emploi : Ne fait rien en particulier
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

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Affichage>

#endif // AFFICHAGE_H
