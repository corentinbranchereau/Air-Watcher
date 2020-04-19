/*************************************************************************
						   EmployeAgenceGouvernementale  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <EmployeAgenceGouvernementale> (fichier EmployeAgenceGouvernementale.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EmployeAgenceGouvernementale.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type EmployeAgenceGouvernementale::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Capteur* EmployeAgenceGouvernementale::ConsulterListeCapteurs()
// Algorithme :
//
{
	return nullptr;
} //----- Fin de ConsulterListeCapteurs

Capteur** EmployeAgenceGouvernementale::IdentifierCapteursSimilaires()
// Algorithme :
//
{
	return nullptr;
} //----- Fin de IdentifierCapteursSimilaires

void EmployeAgenceGouvernementale::LabeliserDonneesUtilisateurs()
// Algorithme :
//
{
	return;
} //----- Fin de LabeliserDonneesUtilisateurs

//------------------------------------------------- Surcharge d'opérateurs

EmployeAgenceGouvernementale & EmployeAgenceGouvernementale::operator = (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

EmployeAgenceGouvernementale::EmployeAgenceGouvernementale (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <EmployeAgenceGouvernementale>" << endl;
#endif
} //----- Fin de EmployeAgenceGouvernementale (constructeur de copie)


EmployeAgenceGouvernementale::EmployeAgenceGouvernementale ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <EmployeAgenceGouvernementale>" << endl;
#endif
} //----- Fin de EmployeAgenceGouvernementale


EmployeAgenceGouvernementale::~EmployeAgenceGouvernementale ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <EmployeAgenceGouvernementale>" << endl;
#endif
} //----- Fin de ~EmployeAgenceGouvernementale


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
