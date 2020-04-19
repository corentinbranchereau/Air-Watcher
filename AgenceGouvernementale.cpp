/*************************************************************************
						   AgenceGouvernementale  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <AgenceGouvernementale> (fichier AgenceGouvernementale.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AgenceGouvernementale.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type AgenceGouvernementale::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

AgenceGouvernementale & AgenceGouvernementale::operator = (const AgenceGouvernementale & unAgenceGouvernementale)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

AgenceGouvernementale::AgenceGouvernementale (const AgenceGouvernementale & unAgenceGouvernementale)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <AgenceGouvernementale>" << endl;
#endif
} //----- Fin de AgenceGouvernementale (constructeur de copie)


AgenceGouvernementale::AgenceGouvernementale ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <AgenceGouvernementale>" << endl;
#endif
} //----- Fin de AgenceGouvernementale


AgenceGouvernementale::~AgenceGouvernementale ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <AgenceGouvernementale>" << endl;
#endif
} //----- Fin de ~AgenceGouvernementale


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
