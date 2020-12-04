/*************************************************************************
						   Mesure  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Mesure::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

TypeAttribut* Mesure::getTypeMesure()
{
	return typeMesure;
}

double Mesure::getValeurAttribut()
{
	return valeurAttribut;
}

string Mesure::getIdCapteur()
{
	return idCapteur;
}

Horodatage Mesure::getdateMesure()
{
	return dateMesure;
}

void Mesure::setValue(double valeur)
{
	this->valeurAttribut=valeur;;
}


//------------------------------------------------- Surcharge d'opérateurs

Mesure & Mesure::operator = (const Mesure & unMesure)
// Algorithme :
//
{
	this->typeMesure=unMesure.typeMesure;
	this->valeurAttribut=unMesure.valeurAttribut;
	this->idCapteur=unMesure.idCapteur;
	this->dateMesure=unMesure.dateMesure;

	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Mesure::Mesure (const Mesure & unMesure)
// Algorithme :
//
{
	this->typeMesure=unMesure.typeMesure;
	this->valeurAttribut=unMesure.valeurAttribut;
	this->idCapteur=unMesure.idCapteur;
	this->dateMesure=unMesure.dateMesure;
	
#ifdef MAP
	cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif
} //----- Fin de Mesure (constructeur de copie)



Mesure::Mesure (TypeAttribut* typeMesure,double valeurAttribut,string idCapteur,Horodatage dateMesure)
// Algorithme :
//
{
	this->typeMesure=typeMesure;
	this->valeurAttribut=valeurAttribut;
	this->idCapteur=idCapteur;
	this->dateMesure=dateMesure;
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Mesure




Mesure::Mesure ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Mesure


Mesure::~Mesure ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
