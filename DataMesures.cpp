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

#include <limits>
#include <algorithm>
#include <math.h>


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
 double** memoire;
unordered_map<string,double> memoireClusters;


//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataMesures::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


bool DataMesures::ChargerMesures(string fichierMesures, unordered_map<string, string> & mapCapteurUtilisateur)
// Algorithme : permet de lire le fichier passé en paramètres  et de charger les mesures une par une dans une liste  
//
{
	ifstream fic(fichierMesures);
  string idCapteurIni="Sensor0";
  int nbMesuresCapteur=0;

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

      char date[100];
      char sensorID[100];
      char attributID[100];
      char valeur[100];
      char pb[100];

      //lecture ligne 

      fic.getline(date,20,';');
      fic.getline(sensorID,20,';');
      fic.getline(attributID,20,';');
      fic.getline(valeur,20,';');
      fic.getline(pb,5,'\n');

      //creation valeurs date

      int anneeS=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
      int moisS=(date[5]-'0')*10+(date[6]-'0');
      int jourS=(date[8]-'0')*10+(date[9]-'0');

      int heureS=(date[11]-'0')*10+(date[12]-'0');
      int minuteS=(date[14]-'0')*10+(date[15]-'0');
      int secondeS=(date[17]-'0')*10+(date[18]-'0');


      if((string)sensorID==idCapteurIni)
      {
        ++nbMesuresCapteur;//nb mesures par capteur
      }
      else
      {
        nbMesuresAttributs.push_back(nbMesuresCapteur);
        nbMesuresCapteur=0;
        idCapteurIni=(string)sensorID;
        //nouveau capteur : on réinitialise le nb de Mesures
      }
      
      Horodatage horo(anneeS,moisS,jourS,heureS,minuteS,secondeS);//creation de la date
      
      double value=stod((string)valeur);
    
      TypeAttribut* type=typeAttributs[(string)attributID];

      //on crée la mesure (en vérifiant si l'id Capteur correspond à un id Utilisateur ou non pour créer soit une Mesure soit une MesureUtilisateur)
      Mesure* mesure;
      if(mapCapteurUtilisateur.count(sensorID)>0)
      {
        // c'est une mesure utilisateur
        mesure = new MesureUtilisateur(type,value,string(sensorID),horo);
      }
      else
      {
        // c'est une simple mesure
        mesure = new Mesure(type,value,string(sensorID),horo);
      }
      
      mesures.push_back(mesure);//ajout de la mesure
      
      }

      return true;

} //----- Fin de ChargerMesures

bool DataMesures::ChargerAttributs(string fichierAttributs)
// Algorithme : permet de charger les attributs à partir du fichier passé en paramètre en lisant ligne par ligne
//
{
  ifstream fic(fichierAttributs);

	if(!fic.is_open())
	{
		cerr<<"Erreur lors du chargement des mesures "<<endl;
		return false;
	}

  char ligne1 [200];
  fic.getline(ligne1,150,'\n');//on enlève la première ligne car c'est l'entête

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

      //lecture d'une ligne

      fic.getline(typeAttribut,50,';');
      fic.getline(unite,50,';');
      fic.getline(description,50,';');
      fic.getline(pb,10,'\n');

      TypeAttribut* type=new TypeAttribut((string)typeAttribut,(string)unite,(string)description);
      typeAttributs.insert({(string)typeAttribut,type});//insertion dans la map de l'id Attribut associé à son typeAttribut

    }

    return true;


} //----- Fin de ChargerAttributs

bool DataMesures::ChargerLabels(string fichierLabel, unordered_map<string, string> & mapCapteurUtilisateur)
// Algorithme : La méthode construit tout d'abord une map contenant toutes les mesures
// des utilisateurs privés (la clé est une concaténation du timestamp, de l'id capteur et de
// l'id attribut). Ensuite, elle lit le fichier des labels pour associer à chaque mesure son label
//
{
  unordered_map<string,MesureUtilisateur*> mapMesuresUtilisateurs;

  vector<Mesure*>::iterator it;
  for(it=this->mesures.begin();it<this->mesures.end();++it)
  {
    string idCapteur = (*it)->getIdCapteur();
    if(mapCapteurUtilisateur.count(idCapteur)>0)
    {
      // l'idCapteur correspond à un utilisateur -> c'est une mesure utilisateur privé
      // on construit un idMesure en concaténant année,mois,jour,heure,minute,seconde,idCapteur,idAttribut
      string idMesure = to_string((*it)->getdateMesure().GetAnnee())+to_string((*it)->getdateMesure().GetMois())+to_string((*it)->getdateMesure().GetJour())+to_string((*it)->getdateMesure().GetHeure())+to_string((*it)->getdateMesure().GetMinute())+to_string((*it)->getdateMesure().GetSeconde())+(*it)->getIdCapteur()+(*it)->getTypeMesure()->getIdAttribut();
      MesureUtilisateur * mesure = dynamic_cast<MesureUtilisateur*>(*it); // conversion du pointeur Mesure* en MesureUtilisateur* (aucun problème normalement car c'est une mesure utilisateur)

      // stockage dans la map
      mapMesuresUtilisateurs.insert(make_pair(idMesure,mesure));
    }
  }

  ifstream fileLabel(fichierLabel);

  if(!fileLabel.is_open())
	{
		cerr<<"Erreur lors du chargement labels"<<endl;
		return false;
	}
  else
  {
    char idMesureLu[200];
    char labelLu[100];
    while(fileLabel)
    {
      fileLabel.getline(idMesureLu,200,';');
      if(!fileLabel) // on vérifie si on a atteint la fin du fichier
      {
        break;
      }
      fileLabel.getline(labelLu,100,'\n');
      mapMesuresUtilisateurs.find(idMesureLu)->second->SetLabel(labelLu);
    }
  }
  return true;
} //----- Fin de ChargerLabels

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

vector<vector<Capteur*>> DataMesures::IdentifierCapteursSimilaires(unordered_map<string,Capteur*> & mapCapteur, int nbClassesMin)
// Algorithme : méthode qui regroupe les capteurs similaires
//
{
  //nbClassesMin : nombre de classes minimum voulu

  vector<Capteur*>listCapteur;

 
  for(auto it=mapCapteur.begin();it!=mapCapteur.end();it++)
  {
    listCapteur.push_back((it->second));
    //cout<<((*(it->second)).getID())<<endl;
  
  }
  

  vector<vector<Capteur*>> classes;//liste des classes en cours
  vector<vector<Capteur*>> resultats;//liste de tous les groupes de classes rencontrés


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
    vector<Capteur*>listInter;
    listInter.push_back(listCapteur[a]);
    classes.push_back(listInter);
  }

  vector<vector<vector<Capteur*>>> listClasses;//contient les différents groupes de classe déjà fait

   while(classes.size()>nbClassesMin)
    {
      vector<double> vect(classes.size(),0.0);
      vector<vector<double>> matDim(classes.size());//matrice des dissimilarités

      for(int i=0;i<matDim.size();i++)
      {
        matDim[i]=vect;//initialisation
      }

      for(int i=0;i<matDim.size();i++)
      {
        for(int j=0;j<matDim.size();j++)
        {
          matDim[i][j]=0;
        }
       
      }

      double mininumDiss=numeric_limits<double>::max(); //minimum de la dissimilarité

      int i1=0;
      int j1=1;

      for(int i=0;i<classes.size();i++)
      {
        for(int j=i+1;j<classes.size();j++)
        {

          matDim[i][j]=dissimMax(classes[i],classes[j]);

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

bool hashFunction(Capteur* c1, Capteur* c2)
{
  //permet de comparer 2 capteurs en fonction de leur ID

  return ((*c1).getIDInt()<(*c2).getIDInt());
}

double DataMesures:: dissimMax(vector<Capteur*> & v1,vector<Capteur*> & v2 )
// Algorithme : renvoie le max de dissimilarité  entre les 2 classes
//
{ 
  double sommeDeltagrad=0;
  double nbDeltats=0;

  double maxDiss=-100;

  sort(v1.begin(),v1.end(),hashFunction);//on trie par ordre croissant d'ID les groupes de capteurs
  sort(v2.begin(),v2.end(),hashFunction);
  
  string clef1="";//clef unique identifiant une comparaison de 2 clusters

  //format clef : ID1ID2ID3ID4|ID5ID6ID7

  for(int i=0;i<v1.size();i++)
  {
    string num=to_string((*(v1[i])).getIDInt());
    clef1.append(num);
  }

  clef1.append("|");

    for(int i=0;i<v2.size();i++)
  {
    string num=to_string((*(v2[i])).getIDInt());
    clef1.append(num);
    
  }

  //clef finie de créer 

  if(memoireClusters.find(clef1)!=memoireClusters.end())
  {
    //si comparaison déjà faite avant
    return memoireClusters[clef1];
  }

  for(int z=0;z<v1.size();z++)
  {
    for(int j=0;j<v2.size();j++)
    {

      Capteur* c1=v1[z];
      Capteur* c2=v2[j];

      int minID=(*c1).getIDInt();
      int maxID=(*c2).getIDInt();


      if((*c2).getIDInt()<minID)
      {
        //on repère le minimum et le maximum des ID capteurs à comparer
        minID=(*c2).getIDInt();
        maxID=(*c1).getIDInt();
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
      nbDeltats=1;
      int iCapteur1=0;
      int iCapteur2=0;

      int numSensor1=0;
      int numSensor2=0;

      for(int i=0;i<nbMesuresAttributs.size();i++)
      {
        //on compte le nombre de mesures à sauter pour le capteur1
        if(minID==i)
        { numSensor1=i;
          break;
        }
        iCapteur1+=nbMesuresAttributs[i];
      }

      for(int i=0;i<nbMesuresAttributs.size();i++)
      {
        //on compte le nombre de mesures à sauter pour le capteur2
        if(maxID==i)
        { numSensor2=i;
          break;
        }
        iCapteur2+=nbMesuresAttributs[i];
      }

      for(auto it=typeAttributs.begin();it!=typeAttributs.end();++it)
      {
        int ecart=0;

        while(ecart+iCapteur1<mesures.size() && (((*(it->second)).getIdAttribut())==((*((*mesures[ecart+iCapteur1]).getTypeMesure())).getIdAttribut())==false))
        {//on recherche la 1 ère valeur du capteur avec le bon attributID
          ++ecart;
          
        }

        int i2=iCapteur2+ecart;
        for(int i=iCapteur1+ecart;i+7<nbMesuresAttributs[numSensor1]+iCapteur1 && i2+7<nbMesuresAttributs[numSensor2]+iCapteur2;i+=4)
        {
        
          int q1=i;//indice t pour le capteur1
          int q2=q1+4;//indice t+1 pour le capteur1

          int p1=i2;//indice t pour le capteur 2
          int p2=p1+4; // indice t+1 pour le capteur 2

          double ecartTemps=24*3600;


          gradient1=((*mesures[q2]).getValeurAttribut()-(*mesures[q1]).getValeurAttribut())/ecartTemps;
          
          gradient2=((*mesures[p2]).getValeurAttribut()-(*mesures[p1]).getValeurAttribut())/ecartTemps;
  
          //gradient2=((listMesure[m].valeur-listMesure[p].valeur)/(listMesure[m].temps-listMesure[p].temps));

          sommeDeltagrad+=abs(gradient1-gradient2);//valeur absolue de la différence entre les pentes des 2 capteurs
          nbDeltats+=1;//nombre de pentes considérées

          i2+=4;
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

    memoireClusters.insert({clef1,maxDiss});//insertion de la valeur dans la map pour pouvoir la retrouver après

    return maxDiss;


} //----- Fin de dissimMax


double DataMesures::evalClasses(vector<vector<Capteur*>> &classI)
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

bool DataMesures:: LabelliserUneDonnee(vector<Mesure*> &listMesuresBonnes,Mesure*& m, unordered_map<string,Capteur*>& mapCapteurs)
{

  vector<Mesure> MesuresBonnesTris;

  for(int i=0;i<listMesuresBonnes.size();i++)
  {
   
    if(abs((*listMesuresBonnes[i]).getdateMesure().getTempsSecondes()-(*m).getdateMesure().getTempsSecondes())<=24*3600 && *((*listMesuresBonnes[i]).getTypeMesure())==*((*m).getTypeMesure()))
    {
      MesuresBonnesTris.push_back(*listMesuresBonnes[i]);
    }

  }

  PointGeographique p1=(*mapCapteurs[(*m).getIdCapteur()]).getPosition();
  double latitude1=p1.getLatitude();
  double longitude1=p1.getLongitude();


  double moyenne=0;
  double denominateur=0;
  for(int i=0;i<MesuresBonnesTris.size();i++)
  {
    PointGeographique p2=(*mapCapteurs[(MesuresBonnesTris[i]).getIdCapteur()]).getPosition();
    double latitude2=p2.getLatitude();
    double longitude2=p2.getLongitude();
    double distance=acos(sin(latitude1)*sin(latitude2)+cos(latitude1)*cos(latitude2)*cos(longitude2-longitude1))*6371;
    moyenne+=(1/(distance+0.1)*MesuresBonnesTris[i].getValeurAttribut());
    denominateur+=1/(distance+0.1);
  }

  double valeurEstime=moyenne/denominateur;

  double minimum=(*m).getValeurAttribut();

  if(minimum>valeurEstime)
  {
    minimum=valeurEstime;
  }

  if((abs(valeurEstime-(*m).getValeurAttribut())/(minimum))>2)
  {
    return false;//valeur aberrante
  }
  return true;//valeur OK

}

void DataMesures::LabeliserDonneesUtilisateur()
// Algorithme :
//
{
  

} //----- Fin de LabeliserDonneesUtilisateur
unordered_map<string,TypeAttribut*>&   DataMesures::GetTypeAttributs()
// Algorithme :
//
{return typeAttributs;

} //----- Fin de GetTypeAttributs


vector<Mesure*>& DataMesures::GetMesures()
// Algorithme :
{
  return mesures;
}
//----- Fin de GetMesures



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
