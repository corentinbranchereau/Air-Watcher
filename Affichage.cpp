/*************************************************************************
						   Affichage  -  Classe permettant l'affichage de l'application sur la console
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Affichage> (fichier Affichage.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Affichage.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Affichage::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Affichage::NettoyerConsole()
// Algorithme : Détecte si l'utilisateur est sur Windows ou Linux et appelle la
// méthode adéquate pour nettoyer la console
//
{
	#ifdef _WIN32
	// Windows
	system("cls");
	#else
	// Linux
	system("clear");
	#endif // _WIN32
	
} //----- Fin de NettoyerConsole


//------------------------------------------------- Surcharge d'opérateurs

Affichage & Affichage::operator = (const Affichage & unAffichage)
// Algorithme : Aucun
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Affichage::Affichage (const Affichage & unAffichage)
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Affichage>" << endl;
#endif
} //----- Fin de Affichage (constructeur de copie)


Affichage::Affichage ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Affichage>" << endl;
#endif
} //----- Fin de Affichage


Affichage::~Affichage ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Affichage>" << endl;
#endif
} //----- Fin de ~Affichage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
