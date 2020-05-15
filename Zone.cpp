/*************************************************************************
						   Zone  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Zone> (fichier Zone.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Zone.h"
#include "math.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Zone::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Zone::VerifierAppartenancePoint(PointGeographique & point)
// Algorithme : vérifie si le point passé en paramètre se trouve dans le cercle défini par son rayon et son centre
//
{	double longitude1=centre.getLongitude();
	double  latitude1=centre.getLatitude();
	double longitude2=point.getLongitude();
	double latitude2=point.getLatitude();

	if((acos(sin(M_PI/180*latitude1)*sin(M_PI/180*latitude2)+cos(M_PI/180*latitude1)*cos(M_PI/180*latitude2)*cos(M_PI/180*(longitude2-longitude1)))*6371)<=rayon)
	{
		return true;
	}
	return false;
} //----- Fin de VerifierAppartenancePoint

//------------------------------------------------- Surcharge d'opérateurs

Zone & Zone::operator = (const Zone & unZone)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Zone::Zone ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Zone>" << endl;
#endif
} //----- Fin de Zone

Zone::Zone(double rayon, PointGeographique p)
// Algorithme : initialise une zone circulaire avec un rayon et un centre
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Zone>" << endl;
#endif

this->rayon=rayon;
this->centre=p;
}


Zone::~Zone ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Zone>" << endl;
#endif
} //----- Fin de ~Zone


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
