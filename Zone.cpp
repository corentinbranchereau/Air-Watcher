/*************************************************************************
						   Zone  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Zone> (fichier Zone.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Zone.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Zone::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Zone::VerifierAppartenancePoint(PointGeographique & point)
// Algorithme :
//
{
	return false;
} //----- Fin de VerifierAppartenancePoint

//------------------------------------------------- Surcharge d'opérateurs

Zone & Zone::operator = (const Zone & unZone)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Zone::Zone ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Zone>" << endl;
#endif
} //----- Fin de Zone


Zone::~Zone ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Zone>" << endl;
#endif
} //----- Fin de ~Zone


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
