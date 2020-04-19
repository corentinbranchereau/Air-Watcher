/*************************************************************************
						   Utilisateur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Utilisateur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Utilisateur* Utilisateur::SeConnecter(string mail, string mdp)
// Algorithme :
//
{
	return nullptr;
} //----- Fin de SeConnecter

bool Utilisateur::SeDeconnecter(Utilisateur* utilisateur)
// Algorithme :
//
{
	return false;
} //----- Fin de SeDeconnecter

bool Utilisateur::SeCreerUnCompte(string nom, string prenom, string mail, string mdp, string compagnie, string typeCompte)
// Algorithme :
//
{
	return false;
} //----- Fin de SeCreerUnCompte

bool Utilisateur::ModifierSonCompte(string nom, string prenom, string mdp)
// Algorithme :
//
{
	return false;
} //----- Fin de ModifierSonCompte

//------------------------------------------------- Surcharge d'opérateurs

Utilisateur & Utilisateur::operator = (const Utilisateur & unUtilisateur)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Utilisateur::Utilisateur (const Utilisateur & unUtilisateur)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur


Utilisateur::~Utilisateur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
