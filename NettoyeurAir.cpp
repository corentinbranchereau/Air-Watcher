/*************************************************************************
						   NettoyeurAir  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <NettoyeurAir> (fichier NettoyeurAir.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "NettoyeurAir.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type NettoyeurAir::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

Horodatage & NettoyeurAir::getDebutActivite()
{
	return debutActivite;
}



Horodatage & NettoyeurAir:: getFinActivite()
{
	return finActivite;
}


double NettoyeurAir:: getRayon()
{
	return rayon;
}

void NettoyeurAir:: setActif(bool act)
{
	this->actif=act;
}


NettoyeurAir & NettoyeurAir::operator = (const NettoyeurAir & unNettoyeurAir)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

NettoyeurAir::NettoyeurAir ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <NettoyeurAir>" << endl;
#endif
} //----- Fin de NettoyeurAir (par défaut)

NettoyeurAir::NettoyeurAir (bool act, double ray, Horodatage horoDebut, Horodatage horoFin, string idNettoyeur, string desc, PointGeographique pGeo)
// Algorithme : Aucun
//
:Equipement(idNettoyeur,desc,pGeo),actif(act),rayon(ray),debutActivite(horoDebut),finActivite(horoFin)
{
#ifdef MAP
	cout << "Appel au constructeur de <NettoyeurAir>" << endl;
#endif
} //----- Fin de NettoyeurAir


NettoyeurAir::~NettoyeurAir ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <NettoyeurAir>" << endl;
#endif
} //----- Fin de ~NettoyeurAir


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
