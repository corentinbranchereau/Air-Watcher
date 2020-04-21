/*************************************************************************
						   DataMesures  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <DataMesures> (fichier DataMesures.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DataMesures.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataMesures::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataMesures::ChargerMesures(string fichierMesures)
// Algorithme :
//
{

} //----- Fin de ChargerMesures

Mesure* DataMesures::ConsulterMoyenneDonneesDatePrecise(Horodatage & date, Zone & zone)
// Algorithme :
//
{

} //----- Fin de ConsulterMoyenneDonneesDatePrecise

Mesure** DataMesures::ConsulterMoyenneDonneesPeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone)
// Algorithme :
//
{

} //----- Fin de ConsulterMoyenneDonneesPeriodePrecise

int DataMesures::ConsulterQualiteDatePrecise(Horodatage & date, Zone & zone)
// Algorithme :
//
{

} //----- Fin de ConsulterQualiteDatePrecise

int* DataMesures::ConsulterQualitePeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone)
// Algorithme :
//
{

} //----- Fin de ConsulterQualitePeriodePrecise

Mesure* DataMesures::ObtenirDonneesBrutes()
// Algorithme :
//
{

} //----- Fin de ObtenirDonneesBrutes

bool DataMesures::EntrerDonnees(string idAttribut, double valeur, UtilisateurPrive utilisateur)
// Algorithme :
//
{

} //----- Fin de EntrerDonnees

Capteur** DataMesures::IdentifierCapteursSimilaires()
// Algorithme :
//
{

} //----- Fin de IdentifierCapteursSimilaires

void DataMesures::LabeliserDonneesUtilisateur()
// Algorithme :
//
{

} //----- Fin de LabeliserDonneesUtilisateur

TypeAttribut* DataMesures::GetTypeAttributs()
// Algorithme :
//
{

} //----- Fin de GetTypeAttributs


//------------------------------------------------- Surcharge d'opérateurs

DataMesures & DataMesures::operator = (const DataMesures & unDataMesures)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataMesures::DataMesures (const DataMesures & unDataMesures)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataMesures>" << endl;
#endif
} //----- Fin de DataMesures (constructeur de copie)


DataMesures::DataMesures ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DataMesures>" << endl;
#endif
} //----- Fin de DataMesures


DataMesures::~DataMesures ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataMesures>" << endl;
#endif
} //----- Fin de ~DataMesures


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
