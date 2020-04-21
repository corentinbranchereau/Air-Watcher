/*************************************************************************
						   DataUtilisateurs  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <DataUtilisateurs> (fichier DataUtilisateurs.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "DataUtilisateurs.h"
#include "UtilisateurProfessionnel.h"
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataUtilisateurs::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataUtilisateurs::ChargerUtilisateurs(string fichierUtilisateurs)
// Algorithme :
//
{

} //----- Fin de ChargerUtilisateurs

bool DataUtilisateurs::VerifierUnCompte(string mail,bool validation)
// Algorithme :
//
{

} //----- Fin de VerifierUnCompte

UtilisateurProfessionnel* DataUtilisateurs::ObtenirComptesEnAttente()
// Algorithme :
//
{

} //----- Fin de ObtenirComptesEnAttente

bool DataUtilisateurs::GererCompte(string mail, string nom, string prenom, string mdp)
// Algorithme :
//
{

} //----- Fin de GererCompte

Utilisateur* DataUtilisateurs::GetUtilisateurs()
// Algorithme :
//
{

} //----- Fin de GetUtilisateurs


//------------------------------------------------- Surcharge d'opérateurs

DataUtilisateurs & DataUtilisateurs::operator = (const DataUtilisateurs & unDataUtilisateurs)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataUtilisateurs::DataUtilisateurs (const DataUtilisateurs & unDataUtilisateurs)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataUtilisateurs>" << endl;
#endif
} //----- Fin de DataUtilisateurs (constructeur de copie)


DataUtilisateurs::DataUtilisateurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DataUtilisateurs>" << endl;
#endif
} //----- Fin de DataUtilisateurs


DataUtilisateurs::~DataUtilisateurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataUtilisateurs>" << endl;
#endif
} //----- Fin de ~DataUtilisateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
