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

//------------------------------------------------- Surcharge d'opérateurs

EmployeAgenceGouvernementale & EmployeAgenceGouvernementale::operator = (const EmployeAgenceGouvernementale & unEmployeAgenceGouvernementale)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

EmployeAgenceGouvernementale::EmployeAgenceGouvernementale ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <EmployeAgenceGouvernementale>" << endl;
#endif
} //----- Fin de EmployeAgenceGouvernementale (par défaut)

EmployeAgenceGouvernementale::EmployeAgenceGouvernementale (string identifiant_c, string mdp_c, string nom_c, string prenom_c, string mail_c)
// Algorithme : Aucun
//
:UtilisateurProfessionnel(identifiant_c,mdp_c,nom_c,prenom_c,mail_c)
{
#ifdef MAP
	cout << "Appel au constructeur de <EmployeAgenceGouvernementale>" << endl;
#endif
	this->agence = new AgenceGouvernementale();
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
