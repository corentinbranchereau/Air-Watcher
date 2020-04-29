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
#include "DataCapteurs.h"
#include "DataCapteurs.h"

#include <limits>
#include <math.h>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
 double** memoire;


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

vector<vector<Capteur>> DataMesures::IdentifierCapteursSimilaires(vector<Capteur>& listCapteur, int nbClassesMin)
// Algorithme : méthode qui regroupe les capteurs similaires
//
{

  //nbClassesMin : nombre de classes minimum voulu

  vector<vector<Capteur>> classes;//liste des classes en cours
  vector<vector<Capteur>> resultats;//liste de tous les groupes de classes rencontrés

 
  memoire=(double**)malloc(sizeof(double*)*listCapteur.size());//initialise la mémoire

  for(int i=0;i<listCapteur.size();i++)
  {
    memoire[i]=(double*)malloc(sizeof(double)*listCapteur.size());

    for(int j=0;j<listCapteur.size();j++)
    {
      if(i==j)
      {
        memoire[i][j]=0;//les 2 mêmes capteurs ont une dissimilarité de 0
      }
      else
      {
      memoire[i][j]=-1;//on initialise à -1 car on ne connait pas la vrai valeur
      }
    }
  }

  for(int a=0;a<listCapteur.size();a++)
  {
    //initialisation des capteurs : tous dans des classes différentes
    vector<Capteur>listInter;
    listInter.push_back(listCapteur[a]);
    classes.push_back(listInter);
  }

  vector<vector<vector<Capteur>>> listClasses;//contient les différents groupes de classe déjà fait

   while(classes.size()>nbClassesMin)
    {
      vector<double> vect(classes.size(),0.0);
      vector<vector<double>> matDim(classes.size());//matrice des dissimilarités

      for(int i=0;i<matDim.size();i++)
      {
        matDim[i]=vect;//initialisation
      }

      double mininumDiss=numeric_limits<double>::max(); //minimum de la dissimilarité

      int i1;
      int j1;

      for(int i=0;i<classes.size();i++)
      {
        for(int j=i+1;j<classes.size();j++)
        {
          matDim[i][j]=dissimMax(classes[i],classes[j]);
          //calcul de la dissimilarité entre 2 classes

          if(matDim[i][j]<mininumDiss  )
          {
            //mise a jour du minimum de dissimilarité
            mininumDiss=matDim[i][j];
            i1=i;
            j1=j;
          }

        }
      }

      for(int i=0;i<classes[j1].size();i++)
      {
        classes[i1].push_back(classes[j1][i]);
        //on fusionne les 2 classes les plus proches cad avec le minimum de dissimilarité
      }

      classes.erase(classes.begin()+j1);

      listClasses.push_back(classes);//ajout de ce groupe de clase dans la liste des solutions

    }

    double maxPente=numeric_limits<int>::max();

    double evalIni=evalClasses(listClasses[0]);

    for(int a=1;a<listClasses.size();a++)
    {
      //on calcule le maximum de dissimilarité au sein d'une même classe pour chaque solution
      double eval2=evalClasses(listClasses[a]);
      cout<<eval2<<endl;

      if(eval2-evalIni<=maxPente)
      {
        //on conserve uniquement le groupe de classes dont la pente est la plus faible
        maxPente=eval2-evalIni;
        resultats=listClasses[a+1];

      }
      evalIni=eval2;

    }

    return resultats;


} //----- Fin de IdentifierCapteursSimilaires

double DataMesures:: dissimMax(vector<Capteur> v1,vector<Capteur> v2 )
// Algorithme :
//
{  //renvoie le max de dissimilarité  entre les 2 classes
  double sommeDeltagrad=0;
  double nbDeltats=0;

  double maxDiss=numeric_limits<double>::min();

  for(int i=0;i<v1.size();i++)
  {
    for(int j=0;j<v2.size();j++)
    {
      Capteur c1=v1[i];
      Capteur c2= v2[j];

      int minID=c1.getIDInt();
      int maxID=c2.getIDInt();

      if(c2.getIDInt()<minID)
      {
        //on repère le minimum et le maximum des ID capteurs à comparer
        minID=c2.getIDInt();
        maxID=c1.getIDInt();
      }

      if(memoire[minID][maxID]>=0)
      {
        //la valeur a déjà été calculée auparavant

        if(memoire[minID][maxID]>maxDiss)
        {
          //maj du max
          maxDiss=memoire[minID][maxID];
        }
        continue;//on passe au capteur suivant

      }

      double gradient1;//pente instantanée des capteurs
      double gradient2;

      sommeDeltagrad=0;
      nbDeltats=0;

      int aIni=minID*4; // indice de la 1 ère mesure qui nous intéresse

      int deltaID=maxID-minID;

      for(int a=aIni;a+40+3+deltaID<mesures.size()-1;a+=40)
      {
    
        for(int b=0;b<typeAttributs.size();b++)
        {
          int ecart=a;
          while((mesures[ecart].getTypeMesure()==typeAttributs[((mesures[ecart]).getTypeMesure()).getIdAttribut()])==false)
          {//on recherche la 1 ère valeur du capteur avec le bon attributID
            ++ecart;
          }

          int q=ecart+40;//indice t+1 pour le capteur1

          int p=ecart+deltaID*4;//indice t pour le capteur 2

          int m=p+40; // indice t+1 pour le capteur 2

          //calcul des pentes
          gradient1=((mesures[q].getValeurAttribut()-mesures[ecart].getValeurAttribut())/(mesures[q].getdateMesure().getTempsSecondes()-mesures[ecart].getdateMesure().getTempsSecondes()));
          
          gradient2=((mesures[m].getValeurAttribut()-mesures[p].getValeurAttribut())/(mesures[m].getdateMesure().getTempsSecondes()-mesures[p].getdateMesure().getTempsSecondes()));
          
          //gradient2=((listMesure[m].valeur-listMesure[p].valeur)/(listMesure[m].temps-listMesure[p].temps));

          sommeDeltagrad+=abs(gradient1-gradient2);//valeur absolue de la différence entre les pentes des 2 capteurs
          nbDeltats+=1;//nombre de pentes considérées

        }
      }

      memoire[minID][maxID]=sommeDeltagrad/nbDeltats; //on sauvegarde la valeur en mémoire

      if((sommeDeltagrad/nbDeltats)>maxDiss)
      {
        //maj du max de la dissymétrie
        maxDiss=sommeDeltagrad/nbDeltats;
      }
    }
  }
    return maxDiss;


} //----- Fin de dissimMax


double DataMesures::evalClasses(vector<vector<Capteur>> classI)
{
  //renvoie le maximum de dissimilarité inter-classe pour la liste de classe passé en paramètre

  double* matDim=(double*)malloc(sizeof(double)*classI.size());//tableau des dissimilarités

  double maxDiss=numeric_limits<double>::min();

  for(int i=0;i<classI.size();i++)
  {
      matDim[i]=dissimMax(classI[i],classI[i]);//renvoie le max de dissimilarité entre les 2 classes (ce sont les mêmes classes)
      
      if(matDim[i]>maxDiss)
      {
        //maj du max
        maxDiss=matDim[i];
      }

  }
  return maxDiss;

}//----- Fin de evalClasses



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
