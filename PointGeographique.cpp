/*************************************************************************
						   PointGeographique  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <PointGeographique> (fichier PointGeographique.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PointGeographique.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type PointGeographique::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

PointGeographique & PointGeographique::operator = (const PointGeographique & unPointGeographique)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

PointGeographique::PointGeographique (const PointGeographique & unPointGeographique)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <PointGeographique>" << endl;
#endif
} //----- Fin de PointGeographique (constructeur de copie)


PointGeographique::PointGeographique ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <PointGeographique>" << endl;
#endif
} //----- Fin de PointGeographique


PointGeographique::~PointGeographique ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <PointGeographique>" << endl;
#endif
} //----- Fin de ~PointGeographique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
