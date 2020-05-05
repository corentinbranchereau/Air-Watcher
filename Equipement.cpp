/*************************************************************************
						   Equipement  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Equipement> (fichier Equipement.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Equipement.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Equipement::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

	string Equipement:: getID()
	{
		return id;
	}

	int Equipement:: getIDInt()
	{
		return  id[6]-'0';
	}


	string Equipement::getDescription()
	{
		return description;
	}

	PointGeographique Equipement:: getPosition()
	{
		return position;
	}


//------------------------------------------------- Surcharge d'opérateurs

Equipement & Equipement::operator = (const Equipement & unEquipement)
// Algorithme :
//
{
	this->id=unEquipement.id;
	this->description=unEquipement.description;
	this->position=unEquipement.position;

	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Equipement::Equipement (string id, string description,PointGeographique p)
// Algorithme :
//
{
	this->id=id;
	this->description=description;
	this->position=p;
#ifdef MAP
	cout << "Appel au constructeur de <Equipement>" << endl;
#endif
} //-


Equipement::Equipement ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Equipement>" << endl;
#endif
} //----- Fin de Equipement


Equipement::~Equipement ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Equipement>" << endl;
#endif
} //----- Fin de ~Equipement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
