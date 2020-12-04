/*************************************************************************
						   Admin  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Admin> (fichier Admin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Admin.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Admin::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

Admin & Admin::operator = (const Admin & unAdmin)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Admin::Admin ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <Admin>" << endl;
#endif
} //----- Fin de Admin (par défaut)

Admin::Admin(string idAdmin, string mdpAdmin, string nomAdmin, string prenomAdmin, string mailAdmin)
// Algorithme : Aucun
//
:Utilisateur(idAdmin,mdpAdmin,nomAdmin,prenomAdmin,mailAdmin)
{

} //----- Fin de Admin


Admin::~Admin ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Admin>" << endl;
#endif
} //----- Fin de ~Admin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
