/*************************************************************************
						   Capteur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Capteur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Capteur::getEtat()
{
	return etat;
}

void Capteur::setEtat(string state)
{
	this->etat=state;
}

//------------------------------------------------- Surcharge d'opérateurs

Capteur & Capteur::operator = (const Capteur & unCapteur)
// Algorithme :
//

{
	this->id=unCapteur.id;
	this->description=unCapteur.description;
	this->position=unCapteur.position;
	this->etat=unCapteur.etat;
	return *this;
} //----- Fin de operator =


//------------t------------------------------- Constructeurs - destructeur

Capteur::Capteur (string id, string description,PointGeographique p,string etat)
// Algorithme :
//
:Equipement(id,description,p)
{	
	this->etat=etat;
#ifdef MAP
	cout << "Appel au constructeur de <Capteur>" << endl;
#endif
} //----- Fin de Capteur


Capteur::~Capteur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
