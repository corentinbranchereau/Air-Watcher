/*************************************************************************
						   CompagnieFournisseur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <CompagnieFournisseur> (fichier CompagnieFournisseur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CompagnieFournisseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type CompagnieFournisseur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

CompagnieFournisseur & CompagnieFournisseur::operator = (const CompagnieFournisseur & unCompagnieFournisseur)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

CompagnieFournisseur::CompagnieFournisseur (const CompagnieFournisseur & unCompagnieFournisseur)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <CompagnieFournisseur>" << endl;
#endif
} //----- Fin de CompagnieFournisseur (constructeur de copie)


CompagnieFournisseur::CompagnieFournisseur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <CompagnieFournisseur>" << endl;
#endif
} //----- Fin de CompagnieFournisseur


CompagnieFournisseur::~CompagnieFournisseur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CompagnieFournisseur>" << endl;
#endif
} //----- Fin de ~CompagnieFournisseur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
