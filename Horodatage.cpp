/*************************************************************************
						   Horodatage  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Horodatage> (fichier Horodatage.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Horodatage.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Horodatage::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

Horodatage & Horodatage::operator = (const Horodatage & unHorodatage)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Horodatage::Horodatage (const Horodatage & unHorodatage)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Horodatage>" << endl;
#endif
} //----- Fin de Horodatage (constructeur de copie)


Horodatage::Horodatage ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Horodatage>" << endl;
#endif
} //----- Fin de Horodatage


Horodatage::~Horodatage ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Horodatage>" << endl;
#endif
} //----- Fin de ~Horodatage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
