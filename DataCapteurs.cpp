/*************************************************************************
						   DataCapteurs  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <DataCapteurs> (fichier DataCapteurs.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DataCapteurs.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataCapteurs::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataCapteurs::ChargerCapteurs(string fichierCapteurs)
// Algorithme :
//
{

} //----- Fin de ChargerCapteurs

bool DataCapteurs::AjouterCapteur(Capteur & capteur)
// Algorithme :
//
{

} //----- Fin de AjouterCapteur

bool DataCapteurs::ModifierCapteur(string idCapteur, double longitude, double latitude, string etat, string description)
// Algorithme :
//
{

} //----- Fin de ModifierCapteur

Capteur* DataCapteurs::GetCapteurs()
// Algorithme :
//
{

} //----- Fin de GetCapteurs


//------------------------------------------------- Surcharge d'opérateurs

DataCapteurs & DataCapteurs::operator = (const DataCapteurs & unDataCapteurs)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataCapteurs::DataCapteurs (const DataCapteurs & unDataCapteurs)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataCapteurs>" << endl;
#endif
} //----- Fin de DataCapteurs (constructeur de copie)


DataCapteurs::DataCapteurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DataCapteurs>" << endl;
#endif
} //----- Fin de DataCapteurs


DataCapteurs::~DataCapteurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataCapteurs>" << endl;
#endif
} //----- Fin de ~DataCapteurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
