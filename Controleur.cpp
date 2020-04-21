/*************************************************************************
						   Controleur  -  Classe de contrôle faisant le lien entre l'affichage et les données
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Controleur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Controleur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

Controleur & Controleur::operator = (const Controleur & unControleur)
// Algorithme : Aucun
//
{
	if(unControleur.utilisateurConnecte==nullptr)
	{
		delete utilisateurConnecte;
	}
	else
	{
		if(utilisateurConnecte!=nullptr)
		{
			delete utilisateurConnecte;
		}
		utilisateurConnecte = new Utilisateur;
		*utilisateurConnecte = *unControleur.utilisateurConnecte;
	}
	affichage = unControleur.affichage;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Controleur::Controleur (const Controleur & unControleur)
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Controleur>" << endl;
#endif
	utilisateurConnecte = new Utilisateur;
	*utilisateurConnecte = *unControleur.utilisateurConnecte;
	affichage=unControleur.affichage;
} //----- Fin de Controleur (constructeur de copie)


Controleur::Controleur ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Controleur>" << endl;
#endif
	utilisateurConnecte = nullptr;
} //----- Fin de Controleur


Controleur::~Controleur ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Controleur>" << endl;
#endif
	if(utilisateurConnecte!=nullptr)
	{
		delete utilisateurConnecte;
	}
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
