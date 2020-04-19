/*************************************************************************
						   EmployeFournisseur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <EmployeFournisseur> (fichier EmployeFournisseur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EmployeFournisseur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type EmployeFournisseur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool EmployeFournisseur::AjouterNettoyeur(NettoyeurAir& nettoyeur)
// Algorithme :
//
{
	return false;
} //----- Fin de AjouterNettoyeur

bool EmployeFournisseur::SupprimerNettoyeur(string idNettoyeur)
// Algorithme :
//
{
	return false;
} //----- Fin de SupprimerNettoyeur

bool EmployeFournisseur::ActiverNettoyeur(string idNettoyeur)
// Algorithme :
//
{
	return false;
} //----- Fin de ActiverNettoyeur

bool EmployeFournisseur::DesactiverNettoyeur(string idNettoyeur)
// Algorithme :
//
{
	return false;
} //----- Fin de DesactiverNettoyeur

double EmployeFournisseur::ObtenirRayonActionNettoyeur(string idNettoyeur)
// Algorithme :
//
{
	return 0.0;
} //----- Fin de ObtenirRayonActionNettoyeur

NettoyeurAir* EmployeFournisseur::AfficherListeNettoyeur()
// Algorithme :
//
{
	return nullptr;
} //----- Fin de AfficherListeNettoyeur

//------------------------------------------------- Surcharge d'opérateurs

EmployeFournisseur & EmployeFournisseur::operator = (const EmployeFournisseur & unEmployeFournisseur)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

EmployeFournisseur::EmployeFournisseur (const EmployeFournisseur & unEmployeFournisseur)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <EmployeFournisseur>" << endl;
#endif
} //----- Fin de EmployeFournisseur (constructeur de copie)


EmployeFournisseur::EmployeFournisseur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <EmployeFournisseur>" << endl;
#endif
} //----- Fin de EmployeFournisseur


EmployeFournisseur::~EmployeFournisseur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <EmployeFournisseur>" << endl;
#endif
} //----- Fin de ~EmployeFournisseur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
