/*************************************************************************
						   UtilisateurPrive  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <UtilisateurPrive> (fichier UtilisateurPrive.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UtilisateurPrive.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type UtilisateurPrive::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool UtilisateurPrive::EntrerDonnees(string idAttribut, double valeur)
// Algorithme :
//
{
	return false;
} //----- Fin de EntrerDonnees

int UtilisateurPrive::ObtenirPoints()
// Algorithme :
//
{
	return 0;
} //----- Fin de ObtenirPoints

Mesure** UtilisateurPrive::ConsulterDonneesEntrees()
// Algorithme :
//
{
	return nullptr;
} //----- Fin de ConsulterDonneesEntrees

//------------------------------------------------- Surcharge d'opérateurs

UtilisateurPrive & UtilisateurPrive::operator = (const UtilisateurPrive & unUtilisateurPrive)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

UtilisateurPrive::UtilisateurPrive (const UtilisateurPrive & unUtilisateurPrive)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de UtilisateurPrive (constructeur de copie)


UtilisateurPrive::UtilisateurPrive ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de UtilisateurPrive


UtilisateurPrive::~UtilisateurPrive ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de ~UtilisateurPrive


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
