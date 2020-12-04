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
		string idS=id.substr(6,id.length());
		return  stoi(idS);
	}

	void Equipement:: setID(string unId)
	{
		this->id=unId;
	}

	string Equipement::getDescription()
	{
		return description;
	}

	PointGeographique Equipement:: getPosition()
	{
		return position;
	}

	void Equipement::setDescription(string desc)
	{
		this->description=desc;
	}

	void Equipement::setPosition(double lon,double lat)
	{
		this->position.setLatitude(lat);
		this->position.setLongitude(lon);
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
