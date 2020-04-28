/*************************************************************************
						   TypeAttribut  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <TypeAttribut> (fichier TypeAttribut.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TypeAttribut.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type TypeAttribut::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

TypeAttribut & TypeAttribut::operator = (const TypeAttribut & unTypeAttribut)
// Algorithme :
//
{
	this->idAttribut=unTypeAttribut.idAttribut;
	this->unite=unTypeAttribut.unite;
	this->description=unTypeAttribut.description;

	return*this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

TypeAttribut::TypeAttribut (const TypeAttribut & unTypeAttribut)
// Algorithme :
//
{
	this->idAttribut=unTypeAttribut.idAttribut;
	this->unite=unTypeAttribut.unite;
	this->description=unTypeAttribut.description;

#ifdef MAP
	cout << "Appel au constructeur de copie de <TypeAttribut>" << endl;
#endif
} //----- Fin de TypeAttribut (constructeur de copie)

TypeAttribut::TypeAttribut (string id, string unite,string description)
// Algorithme :
//
{
	this->idAttribut=id;
	this->unite=unite;
	this->description=description;
#ifdef MAP
	cout << "Appel au constructeur de <TypeAttribut>" << endl;
#endif
} //----- Fin de TypeAttribut


TypeAttribut::TypeAttribut ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <TypeAttribut>" << endl;
#endif
} //----- Fin de TypeAttribut



TypeAttribut::~TypeAttribut ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <TypeAttribut>" << endl;
#endif
} //----- Fin de ~TypeAttribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
