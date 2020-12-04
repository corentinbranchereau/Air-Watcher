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

string TypeAttribut::getIdAttribut()
{
	return idAttribut;
}

string TypeAttribut::getUnite()
{
	return unite;
}

string TypeAttribut::getDescription()
{
	return description;
}



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

bool  TypeAttribut ::operator == (const TypeAttribut & unTypeAttribut)const
	// Algorithme :
//
{
	if(idAttribut==unTypeAttribut.idAttribut && unite==unTypeAttribut.unite && description==unTypeAttribut.description)
	{
		return true;
	}
	

	return false;
	
} //----- Fin de operator ==
	


//-------------------------------------------- Constructeurs - destructeur

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
