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
#include <set>
#include <string.h>
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
	  char latitude[100];
      //char  description[100];
      char pb[50];

      fic.getline(id,50,';');
      fic.getline(latitude,50,';');
      fic.getline(longitude,50,';');
	  fic.getline(pb,10,'\n');

    if(strcmp(id,"")!=0)
    {
	  PointGeographique p(atof(longitude),atof(latitude));

      Capteur* capteur=new Capteur((string)id,"",p);

      mapIDCapteurs.insert(make_pair((string)id,capteur));

    }
   
	  //capteurs.push_back(capteur);

    }
    return true;

} //----- Fin de ChargerCapteurs

bool DataCapteurs::ChargerCapteursPrives(string fichierCapteursPrives, string fichierUtilisateurs)
// Algorithme : La méthode ouvre en lecture le fichier, et lit pour chaque ligne
// les informations à entrer dans la map.
//
{
    set<string> idExistants; // va stocker les id déjà existants dans le fichier des comptes
    fstream fileUtilisateurs(fichierUtilisateurs,ios::in|ios::out|ios::app); // ouverture en lecture et en écriture du fichier des comptes
    if(!fileUtilisateurs.is_open())
    {
        cerr<<"Erreur lors de l'ouverture du fichier des comptes"<<endl;
        return false;
    }
    else
    {
        // tout d'abord on lit tous les identifiants des utilisateurs privés existants (pour ne pas les ajouter en double ensuite)
        char typeCompte[100];
        char identifiant[100];
        char buffTemp[500];
        while(fileUtilisateurs)
        {
            fileUtilisateurs.getline(typeCompte,100,';');
            if(!fileUtilisateurs) // on vérifie si on a atteint la fin du fichier
            {
                break;
            }
            if(string(typeCompte)==string("privé"))
            {
                fileUtilisateurs.getline(identifiant,100,';');
                fileUtilisateurs.getline(buffTemp,500,'\n'); // on lit jusqu'à la fin de la ligne pour passer à la ligne d'après
                idExistants.insert(string(identifiant));
            }
            else
            {
                fileUtilisateurs.getline(buffTemp,500,'\n'); // on lit jusqu'à la fin de la ligne pour passer à la ligne d'après
            }
        }
    }
    fileUtilisateurs.clear(); // on nettoie le flag 'eof' pour pouvoir écrire dans le fichier ensuite

    ifstream file(fichierCapteursPrives);
    if(!file.is_open())
	{
		cerr<<"Erreur lors du chargement des capteurs 'privés'"<<endl;
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
            file.getline(idCapteur,100,';');
            file.get(); // on lit le \n de fin de ligne
            this->mapCapteurUtilisateur.insert(make_pair(idCapteur,idUser));

            if(idExistants.count(string(idUser))==0) // l'id n'existe pas encore de le fichier des comptes, on va alors l'insérer
            {
                string id(idUser);
                string ligneInsertion = "privé;"+id+";"+id+";"+id+";"+id+";"+id+"\n";
                fileUtilisateurs<<ligneInsertion;
            }
        }
    }
    return true;
    
} //----- Fin de ChargerCapteursPrives


bool DataCapteurs::SauvegarderCapteursPrives(string fichierCapteurs, string fichierUtilisateurs)
// Algorithme :
//
{
    ofstream fileCapteurs(fichierCapteurs,ios::trunc);
    if(!fileCapteurs.is_open())
	{
		cerr<<"Erreur lors de la sauvegarde de capteurs"<<endl;
		return false;
	}
    else
    {

        unordered_map<string,Capteur*>::iterator it;
        for(it=mapIDCapteurs.begin();it!=mapIDCapteurs.end();it++)
        {
               fileCapteurs << it->second->getID() << ";"
                            << it->second->getPosition().getLatitude() << ";"
                            << it->second->getPosition().getLongitude() << ";"
                            << "\n";
        }
    }    
    fileCapteurs.clear();

     ofstream fileUsers(fichierUtilisateurs,ios::trunc);
     if(!fileUsers.is_open())
	{
		cerr<<"Erreur lors de la sauvegarde de capteurs"<<endl;
		return false;
	}
    else
    {
        unordered_map<string, string>:: iterator itM;
        for(itM=mapCapteurUtilisateur.begin();itM!=mapCapteurUtilisateur.end();itM++)
        {        
                fileUsers << itM->second << ";"
                          << itM->first  << ";"
                          << "\n";
        }
    }

    return true;
}//----- Fin de SauvegarderCapteursPrives

bool DataCapteurs::AjouterCapteur(Capteur & capteur,string idUtilisateurPrive)
// Algorithme :
//
{
    /*string Id=capteur.getID();
	int nb=0;
	unordered_map<string,Capteur*>::const_iterator got = mapIDCapteurs.find (newId);
	while(got!=mapIDCapteurs.end() || newId=="") //tant que l'id existe dans la map, ou est défini sur null, on cherche un nouvel id
	{
		newId="Sensor"+to_string(mapIDCapteurs.size()+nb);
		got = mapIDCapteurs.find (newId);
		nb++;
	}	
	capteur.setID(newId);
	mapCapteurUtilisateur.insert(make_pair(capteur.getID(),idUtilisateurPrive));

    return mapIDCapteurs.insert(make_pair(capteur.getID(),&capteur)).second;
    */
} //----- Fin de AjouterCapteur


bool DataCapteurs::ModifierCapteur(string idCapteur, double longitude, double latitude, string etat, string description)
// Algorithme :
//
{
    unordered_map<string,Capteur*>::const_iterator got = mapIDCapteurs.find (idCapteur);
    if(got!=mapIDCapteurs.end())
    {
        Capteur* c=got->second;
        c->setDescription(description);
        c->setEtat(etat);
        c->setPosition(longitude,latitude);
    }
    else{
        return false;
    }
    return true;
} //----- Fin de ModifierCapteur



unordered_map<string,Capteur*> & DataCapteurs::GetCapteurs()
// Algorithme :
//
{
    return mapIDCapteurs;
} //----- Fin de GetCapteurs


unordered_map<string,string> & DataCapteurs::GetMapCapteurUtilisateur()
// Algorithme : Aucun
//
{
    return this->mapCapteurUtilisateur;
} //----- Fin de GetMapCapteurUtilisateur


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
    unordered_map<string,Capteur*>::iterator it;
    for(it=mapIDCapteurs.begin();it!=mapIDCapteurs.end();it++)
    {
        delete(it->second);
    }
} //----- Fin de ~DataCapteurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
