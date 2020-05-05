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
#include <fstream>
#include <sstream>

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
// Algorithme : La méthode ouvre en lecture le fichier, et construit pour
// chaque ligne un nettoyeur, puis le stocke
//
{
	ifstream file(fichierNettoyeurs);
    if(!file.is_open())
	{
		cerr<<"Erreur lors du chargement des nettoyeurs"<<endl;
		return false;
	}
    else
    {
        char idNettoyeur[100];
        char latitudeString[100];
		char longitudeString[100];
		char timestampDebut[200];
		char timestampFin[200];
        while(file)
        {
            file.getline(idNettoyeur,100,';');
			if(!file) // on vérifie si on a atteint la fin du fichier
			{
				break;
			}
            file.getline(latitudeString,100,';');
			file.getline(longitudeString,100,';');
			file.get(); // on enlève le ; supplémentaire
			file.getline(timestampDebut,200,';');
			file.getline(timestampFin,200,';');
            file.get(); // on lit le \n de fin de ligne

			stringstream ssConversion;

			double latitude;
			double longitude;

			ssConversion<<latitudeString;
			ssConversion>>latitude;
			ssConversion.clear();
			ssConversion<<longitudeString;
			ssConversion>>longitude;

			// horodatage début

			int anneeDebut = (timestampDebut[0]-'0')*1000 + (timestampDebut[1]-'0')*100 + (timestampDebut[2]-'0')*10 + (timestampDebut[3]-'0');
			int moisDebut = (timestampDebut[5]-'0')*10 + (timestampDebut[6]-'0');
			int jourDebut = (timestampDebut[8]-'0')*10 + (timestampDebut[9]-'0');
			int heureDebut = (timestampDebut[11]-'0')*10 + (timestampDebut[12]-'0');
			int minuteDebut = (timestampDebut[14]-'0')*10 + (timestampDebut[15]-'0');
			int secondeDebut = (timestampDebut[17]-'0')*10 + (timestampDebut[18]-'0');

			// horodatage fin

			int anneeFin = (timestampFin[0]-'0')*1000 + (timestampFin[1]-'0')*100 + (timestampFin[2]-'0')*10 + (timestampFin[3]-'0');
			int moisFin = (timestampFin[5]-'0')*10 + (timestampFin[6]-'0');
			int jourFin = (timestampFin[8]-'0')*10 + (timestampFin[9]-'0');
			int heureFin = (timestampFin[11]-'0')*10 + (timestampFin[12]-'0');
			int minuteFin = (timestampFin[14]-'0')*10 + (timestampFin[15]-'0');
			int secondeFin = (timestampFin[17]-'0')*10 + (timestampFin[18]-'0');

			Horodatage horoDebut(anneeDebut,moisDebut,jourDebut,heureDebut,minuteDebut,secondeDebut);
			Horodatage horoFin(anneeFin,moisFin,jourFin,heureFin,minuteFin,secondeFin);

			PointGeographique pGeo(longitude,latitude);

			NettoyeurAir* nettoyeur = new NettoyeurAir(false,0.0,horoDebut,horoFin,string(idNettoyeur),"",pGeo);

			this->nettoyeurs.insert(make_pair(string(idNettoyeur),nettoyeur));

        }
    }
    return true;
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
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataNettoyeurs::DataNettoyeurs (const DataNettoyeurs & unDataNettoyeurs)
// Algorithme : Aucun
//
:nettoyeurs(unDataNettoyeurs.nettoyeurs)
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataNettoyeurs>" << endl;
#endif
} //----- Fin de DataNettoyeurs (constructeur de copie)


DataNettoyeurs::DataNettoyeurs ()
// Algorithme : Aucun
//
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
