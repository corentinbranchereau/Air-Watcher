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

CompagnieFournisseur* EmployeFournisseur::GetCompagnie()
// Algorithme : Aucun
//
{
	return this->compagnie;
} //----- Fin de GetCompagnie

//------------------------------------------------- Surcharge d'opérateurs

EmployeFournisseur & EmployeFournisseur::operator = (const EmployeFournisseur & unEmployeFournisseur)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

/*EmployeFournisseur::EmployeFournisseur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <EmployeFournisseur>" << endl;
#endif;
} //----- Fin de EmployeFournisseur
*/

EmployeFournisseur::EmployeFournisseur (string idFourn, string mdpFourn, string nomFourn, string prenomFourn, string mailFourn, bool validFourn, CompagnieFournisseur* compagnieFourn)
// Algorithme : Aucun
//
:UtilisateurProfessionnel(idFourn,mdpFourn,nomFourn,prenomFourn,mailFourn,validFourn),compagnie(compagnieFourn)
{

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
