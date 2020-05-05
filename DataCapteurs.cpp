/*************************************************************************
						   DataCapteurs  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <DataCapteurs> (fichier DataCapteurs.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "DataCapteurs.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataCapteurs::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataCapteurs::ChargerCapteurs(string fichierCapteurs)
// Algorithme :
//
{
	ifstream fic(fichierCapteurs);

	if(!fic.is_open())
	{
		cerr<<"Erreur lors du chargement des capteurs "<<endl;
		return false;
	}

    while(1)
    {

   
      if (fic.eof())
      {
          //fin de lecture du fichier
          break;
      }
      char id[100];
      char longitude[100];
	  char latitude[100];;
      char pb[50];

      fic.getline(id,50,';');
      fic.getline(latitude,50,';');
      fic.getline(longitude,50,';');
	  fic.getline(pb,10,'\n');

	  PointGeographique p(atof(longitude),atof(latitude));

      Capteur capteur((string)id,"",p);
	  capteurs.push_back(capteur);

      }

      return true;

} //----- Fin de ChargerCapteurs

bool DataCapteurs::ChargerCapteursPrives(string fichierCapteursPrives)
// Algorithme : La méthode ouvre en lecture le fichier, et lis pour chaque ligne
// les informations à entrer dans la map
//
{
    ifstream file(fichierCapteursPrives);
    if(!file.is_open())
	{
		cerr<<"Erreur lors du des capteurs 'privés'"<<endl;
		return false;
	}
    else
    {
        char idCapteur[100];
        char idUser[100];
        while(file)
        {
            file.getline(idUser,100,';');
			if(!file) // on vérifie si on a atteint la fin du fichier
			{
				break;
			}
            file.getline(idCapteur,100,'\n');
            this->mapCapteurUtilisateur[idCapteur]=idUser;
        }
    }
    return true;
    
} //----- Fin de ChargerCapteursPrives

bool DataCapteurs::AjouterCapteur(Capteur & capteur)
// Algorithme :
//
{

} //----- Fin de AjouterCapteur

bool DataCapteurs::ModifierCapteur(string idCapteur, double longitude, double latitude, string etat, string description)
// Algorithme :
//
{

} //----- Fin de ModifierCapteur

vector<Capteur>& DataCapteurs::GetCapteurs()
// Algorithme :
//
{
    return capteurs;

} //----- Fin de GetCapteurs


//------------------------------------------------- Surcharge d'opérateurs

DataCapteurs & DataCapteurs::operator = (const DataCapteurs & unDataCapteurs)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataCapteurs::DataCapteurs (const DataCapteurs & unDataCapteurs)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataCapteurs>" << endl;
#endif
} //----- Fin de DataCapteurs (constructeur de copie)


DataCapteurs::DataCapteurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DataCapteurs>" << endl;
#endif
} //----- Fin de DataCapteurs


DataCapteurs::~DataCapteurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataCapteurs>" << endl;
#endif
} //----- Fin de ~DataCapteurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
