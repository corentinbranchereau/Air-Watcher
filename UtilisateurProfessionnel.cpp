/*************************************************************************
						   UtilisateurProfessionnel  -  Classe représentant un utilisateur professionnel de l'application
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <UtilisateurProfessionnel> (fichier UtilisateurProfessionnel.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UtilisateurProfessionnel.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type UtilisateurProfessionnel::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

UtilisateurProfessionnel & UtilisateurProfessionnel::operator = (const UtilisateurProfessionnel & unUtilisateurProfessionnel)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

UtilisateurProfessionnel::UtilisateurProfessionnel (const UtilisateurProfessionnel & unUtilisateurProfessionnel)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <UtilisateurProfessionnel>" << endl;
#endif
} //----- Fin de UtilisateurProfessionnel (constructeur de copie)


UtilisateurProfessionnel::UtilisateurProfessionnel ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <UtilisateurProfessionnel>" << endl;
#endif
} //----- Fin de UtilisateurProfessionnel


UtilisateurProfessionnel::~UtilisateurProfessionnel ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <UtilisateurProfessionnel>" << endl;
#endif
} //----- Fin de ~UtilisateurProfessionnel


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
