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
// Algorithme : permet de lire le fichier passé en paramètres  et de charger les mesures une par une dans une liste  
//
{
	ifstream fic(fichierMesures);

	if(!fic.is_open())
	{
		cerr<<"Erreur lors du chargement des mesures "<<endl;
		return false;
	}

    while(1)
    {
 
      if (fic.eof())
      {
          //fin de lecture du fichier
          break;
      }

      char ligne[500];
      string ligneString;

      fic.getline(ligne,500,'\n');
      string ligneS=string(ligne);

      string anneeS=ligneS.substr(0,4);

      string moisS=ligneS.substr(5,2);
 
      string jourS=ligneS.substr(8,2);
    
      string heureS=ligneS.substr(11,2);
      
      string minuteS=ligneS.substr(14,2);
      
      string secondeS=ligneS.substr(17,2);
    
      int posSensor=ligneS.find_first_of(",",28);
      string numSensorS=ligneS.substr(28,posSensor-28);
  
      int posAttr=ligneS.find_first_of(",",posSensor+1);
      string attributS=ligneS.substr(posSensor+1,posAttr-posSensor-1);
      
      string valuesS=ligneS.substr(posAttr+1,-1);
   
      Horodatage horo(stoi(anneeS),stoi(moisS),stoi(jourS),stoi(heureS),stoi(minuteS),stoi(secondeS));
      
      double value=stod(valuesS);
    

      TypeAttribut type=typeAttributs[attributS];

      //on crée la mesure
      Mesure mesure=Mesure(type,value,numSensorS,horo);

      mesures.push_back(mesure);//ajout de la mesure
      

      }

      return true;




} //----- Fin de ChargerMesures

bool DataMesures::ChargerAttributs(string fichierAttributs)
// Algorithme :
//
{
  ifstream fic(fichierAttributs);

	if(!fic.is_open())
	{
		cerr<<"Erreur lors du chargement des mesures "<<endl;
		return false;
	}

    while(1)
    {

      if (fic.eof())
      {
          //fin de lecture du fichier
          break;
      }
      char unite[100];
      char typeAttribut[100];
      char  description[100];
      char pb[50];

      fic.getline(typeAttribut,50,';');
      fic.getline(unite,50,';');
      fic.getline(description,50,';');
      fic.getline(pb,10,'\n');

      TypeAttribut type=TypeAttribut((string)typeAttribut,(string)unite,(string)description);

      typeAttributs.insert({(string)typeAttribut,type});

      }

      return true;


} //----- Fin de ChargerAttributs

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

bool DataMesures::EntrerDonnees(string idAttribut, double valeur, UtilisateurPrive & utilisateur)
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
