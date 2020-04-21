/*************************************************************************
						   Admin  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Admin> (fichier Admin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Admin.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Admin::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

Admin & Admin::operator = (const Admin & unAdmin)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Admin::Admin (const Admin & unAdmin)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Admin>" << endl;
#endif
} //----- Fin de Admin (constructeur de copie)


Admin::Admin ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Admin>" << endl;
#endif
} //----- Fin de Admin


Admin::~Admin ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Admin>" << endl;
#endif
} //----- Fin de ~Admin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
