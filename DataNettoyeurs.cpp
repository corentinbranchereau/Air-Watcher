/*************************************************************************
						   DataNettoyeurs  -  Classe stockant et gérant les nettoyeurs d'air
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <DataNettoyeurs> (fichier DataNettoyeurs.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "DataNettoyeurs.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataNettoyeurs::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataNettoyeurs::ChargerNettoyeurs(string fichierNettoyeurs)
// Algorithme :
//
{

} //----- Fin de ChargerNettoyeurs

bool DataNettoyeurs::AjouterNettoyeur(NettoyeurAir & nettoyeur)
// Algorithme :
//
{

} //----- Fin de AjouterNettoyeur

bool DataNettoyeurs::SupprimerNettoyeur(string idNettoyeur)
// Algorithme :
//
{

} //----- Fin de SupprimerNettoyeur

bool DataNettoyeurs::ActiverNettoyeur(string idNettoyeur)
// Algorithme :
//
{

} //----- Fin de ActiverNettoyeur

bool DataNettoyeurs::DesactiverNettoyeur(string idNettoyeur)
// Algorithme :
//
{

} //----- Fin de DesactiverNettoyeur

double DataNettoyeurs::ObtenirRayonActionNettoyeur(string idNettoyeur)
// Algorithme :
//
{

} //----- Fin de ObtenirRayonActionNettoyeur

vector<NettoyeurAir> DataNettoyeurs::GetNettoyeurs()
// Algorithme :
//
{

} //----- Fin de GetNettoyeurs


//------------------------------------------------- Surcharge d'opérateurs

DataNettoyeurs & DataNettoyeurs::operator = (const DataNettoyeurs & unDataNettoyeurs)
// Algorithme : Aucun
//
{
	this->nettoyeurs = unDataNettoyeurs.nettoyeurs;
	this->cheminFichierNettoyeurs = unDataNettoyeurs.cheminFichierNettoyeurs;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataNettoyeurs::DataNettoyeurs (const DataNettoyeurs & unDataNettoyeurs)
// Algorithme : Aucun
//
:nettoyeurs(unDataNettoyeurs.nettoyeurs),cheminFichierNettoyeurs(unDataNettoyeurs.cheminFichierNettoyeurs)
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataNettoyeurs>" << endl;
#endif
} //----- Fin de DataNettoyeurs (constructeur de copie)


DataNettoyeurs::DataNettoyeurs ()
// Algorithme : Aucun
//
:cheminFichierNettoyeurs("")
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <DataNettoyeurs>" << endl;
#endif
} //----- Fin de DataNettoyeurs (par défaut)


DataNettoyeurs::~DataNettoyeurs ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataNettoyeurs>" << endl;
#endif
} //----- Fin de ~DataNettoyeurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
