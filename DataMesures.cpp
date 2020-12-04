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
#include "UtilisateurPrive.h"
#include "EmployeAgenceGouvernementale.h"
#include "EmployeFournisseur.h"
#include "Admin.h"

#include <limits>
#include <algorithm>
#include <math.h>
#include<map>
#include<string.h>
#include <set>
#include <map>

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


bool DataMesures::ChargerMesures(string fichierMesures, unordered_map<string, string> & mapCapteurUtilisateur, vector<Utilisateur*> & utilisateurs)
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
          nbMesuresAttributs.push_back(nbMesuresCapteur);
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

      if(strcmp(sensorID,"")!=0)
      {

        if((string)sensorID==idCapteurIni)
        {
          ++nbMesuresCapteur;//nb mesures par capteur
        }
        else
        {
          if((string(sensorID)).size()>1)
          {
          nbMesuresAttributs.push_back(nbMesuresCapteur);
          nbMesuresCapteur=1;

          idCapteurIni=(string)sensorID;
          }
          //nouveau capteur : on réinitialise le nb de Mesures
        }
        
        Horodatage horo(anneeS,moisS,jourS,heureS,minuteS,secondeS);//creation de la date
        
        double value=stod((string)valeur);
      
        TypeAttribut* type=typeAttributs[(string)attributID];

        //on crée la mesure (en vérifiant si l'id Capteur correspond à un id Utilisateur ou non pour créer soit une Mesure soit une MesureUtilisateur)
        Mesure* mesure;
        unordered_map<string,string>::iterator itCapteurUtilisateur;
        itCapteurUtilisateur = mapCapteurUtilisateur.find(sensorID);

        if(itCapteurUtilisateur!=mapCapteurUtilisateur.end()) // id trouvé dans la map
        {
          // c'est une mesure utilisateur
          mesure = new MesureUtilisateur(type,value,string(sensorID),horo);

          // on l'insère également dans les données entrées de l'utilisateur correspondant
          vector<Utilisateur*>::iterator itUtilisateur;
          for(itUtilisateur=utilisateurs.begin();itUtilisateur<utilisateurs.end();++itUtilisateur)
          {
            if((*itUtilisateur)->GetIdentifiant()==itCapteurUtilisateur->second) // l'identifiant de l'utilisateur est le même que celui trouvé pour la mesure
            {
              UtilisateurPrive * uPrive = dynamic_cast<UtilisateurPrive*>(*itUtilisateur);
              MesureUtilisateur * mesureUtilisateur = dynamic_cast<MesureUtilisateur*>(mesure);
              uPrive->EntrerDonnee(mesureUtilisateur);
            }
          }
        }
        else
        {
          // c'est une simple mesure
          mesure = new Mesure(type,value,string(sensorID),horo);
        }
        
        mesures.push_back(mesure);//ajout de la mesure
        
        }
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

    while(fileLabel)
    {
      char idMesureLu[200];
      char labelLu[100];
      
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

bool DataMesures::SauvegarderMesuresAjoutees(string fichierMesure)
// Algorithme : renvoie faux si problème d'ouverture sinon réécrit toutes les mesures dans le fichier puis renvoie true

{

  ofstream fileMesure(fichierMesure,ios::trunc);

  if(!fileMesure.is_open())
	{
		cerr<<"Erreur lors de la sauvegarde des mesures"<<endl;
		return false;
	}
  else
  {
    for(int i=0;i<mesures.size();i++)
    {
      Horodatage date=mesures[i]->getdateMesure();
      string idCapteur=mesures[i]->getIdCapteur();
      string type=(mesures[i]->getTypeMesure())->getIdAttribut();
      double valeur=mesures[i]->getValeurAttribut();

      string mois;
      string jour;
      string heure;
      string minute;
      string seconde;

      string suffixe="0";

      if(date.GetMois()<10)
      {
        mois="0"+to_string(date.GetMois());
      }
      else
      {
        mois=to_string(date.GetMois());
      }

      if(date.GetJour()<10)
      {
        jour="0"+(to_string(date.GetJour()));
      }
      else
      {
        jour=to_string(date.GetJour());
      }
      if(date.GetHeure()<10)
      {
        heure="0"+to_string(date.GetHeure());
      }
      else
      {
        heure=to_string(date.GetHeure());
      }
      if(date.GetMinute()<10)
      {
        minute="0"+to_string(date.GetMinute());
      }
      else
      {
        minute=to_string(date.GetMinute());
      }

      if(date.GetSeconde()<10)
      {
        seconde="0"+to_string(date.GetSeconde());
      }
      else
      {
        seconde=to_string(date.GetSeconde());
      }
      
   
      fileMesure<<date.GetAnnee()<<"-"<<mois<<"-"<<jour<<" "<<heure<<":"<<minute<<":"<<seconde<<";"<<idCapteur<<";"<<type<<";"<<valeur<<";\n";
   
    }
  
  }
  return true;
} //----- Fin de SauvegarderMesuresAjoutees




vector<Mesure*> DataMesures:: ObtenirMesuresFiables(unordered_map<string, string>& mapCapteurPrive, vector<Utilisateur*>& utilisateurs, string fichierUtilisateurPerso)
// Algorithme : parcours toutes les mesures et renvoie uniquement les mesuresUtilisateurs avec le label fiable et les mesures des capteurs fixes
//
{
  set<string> utilisateursDejaIncremente; // set pour retenir les utilisateurs dont on a déjà augmenter le nb de points

  vector<Mesure*> listMesuresFiables;
  for(int i=0;i<mesures.size();i++)
  {
    MesureUtilisateur* m=dynamic_cast<MesureUtilisateur*>(mesures[i]);

    if(m==nullptr)
    {
      //ce n'est pas une mesure utilisateur elle est donc toujours fiable
      listMesuresFiables.push_back(mesures[i]);

    }
    else
    {
     if((*m).GetLabel()=="fiable")
     {
        listMesuresFiables.push_back(mesures[i]);
        //si la mesure utilisateur on peut l'utiliser

        // on ajoute l'id à la liste des utilisateurs à incrémenter (nb de points)
        string idUser = mapCapteurPrive.find(mesures[i]->getIdCapteur())->second;
        utilisateursDejaIncremente.insert(idUser);
     }
    }
    
  }

  // on ajoute les points aux utilisateurs et on les écrit dans le fichier
  ofstream fileUtilisateur(fichierUtilisateurPerso);
  vector<Utilisateur*>::iterator it;
  for(it=utilisateurs.begin();it!=utilisateurs.end();++it)
  {
    if(utilisateursDejaIncremente.find((*it)->GetIdentifiant())!=utilisateursDejaIncremente.end())
    {
      UtilisateurPrive* uPrive = dynamic_cast<UtilisateurPrive*>((*it));

      if(uPrive!=nullptr) // normalement toujours non nul
      {
        uPrive->AjouterPoint(1);
      }
    }

    // construction de la ligne à écrire
    string ligneEcriture = "";

    // on cherche le type du compte
    EmployeAgenceGouvernementale* uAgence = dynamic_cast<EmployeAgenceGouvernementale*>((*it));
    EmployeFournisseur* uFournisseur = dynamic_cast<EmployeFournisseur*>((*it));
    Admin* uAdmin = dynamic_cast<Admin*>((*it));
    UtilisateurPrive* uPrive = dynamic_cast<UtilisateurPrive*>((*it));

    if (uAgence!=nullptr)
    {
      // agence
      ligneEcriture+="agence;"+uAgence->GetIdentifiant()+";"+uAgence->GetMdp()+";"+uAgence->GetNom()+";"+uAgence->GetPrenom()+";"+uAgence->GetMail()+";";
      if(uAgence->GetCompteValide())
      {
        ligneEcriture+="valide\n";
      }
      else
      {
        ligneEcriture+="attente\n";
      }
    }
    else if (uFournisseur!=nullptr)
    {
      // fournisseur
      ligneEcriture+="fournisseur;"+uFournisseur->GetIdentifiant()+";"+uFournisseur->GetMdp()+";"+uFournisseur->GetNom()+";"+uFournisseur->GetPrenom()+";"+uFournisseur->GetMail()+";";
      if(uFournisseur->GetCompteValide())
      {
        ligneEcriture+="valide;";
      }
      else
      {
        ligneEcriture+="attente;";
      }
      ligneEcriture+=uFournisseur->GetCompagnie()->getId()+"\n";
    }
    else if (uAdmin!=nullptr)
    {
      // admin
      ligneEcriture+="admin;"+uAdmin->GetIdentifiant()+";"+uAdmin->GetMdp()+";"+uAdmin->GetNom()+";"+uAdmin->GetPrenom()+";"+uAdmin->GetMail()+"\n";
    }
    else
    {
      // privé
      ligneEcriture+="privé;"+uPrive->GetIdentifiant()+";"+uPrive->GetMdp()+";"+uPrive->GetNom()+";"+uPrive->GetPrenom()+";"+uPrive->GetMail()+";"+to_string(uPrive->ObtenirPoints())+"\n";
    }

    fileUtilisateur<<ligneEcriture;
    
  }

  /*
  // on écrit dans le fichier pour l'actualiser
  fstream fileUtilisateur(fichierUtilisateurPerso);
  if(!fileUtilisateur.is_open())
  {
    cerr<<"Erreur lors de l'écriture des points. Aucune écriture n'a donc été faite"<<endl;
  }
  else
  {
    char ligne[600];
    while(fileUtilisateur)
    {
      fileUtilisateur.getline(ligne,600,'\n');

      if(!fileUtilisateur) // on vérifie si on a atteint la fin du fichier
      { 
        break;
      }
      int tailleLigne = strlen(ligne);
      char * token = strtok(ligne,";"); // on split la ligne grâce aux ';'
      if(strcmp(token,"privé")==0) // type de compte privé
      {
        //on regarde si l'identifiant fait partie de ceux où on ajouté un point
        token = strtok(NULL,";"); // on récupère l'identifiant de la ligne lue
        if(utilisateursDejaIncremente.find(token)!=utilisateursDejaIncremente.end())
        {
          // on construit la ligne progressivement en prenant les infos de celle qui a été lue
          string ligneEcriture = "privé;"+string(token)+";";

          int i;
          for(i=0; i<4; ++i) // on ajoute toutes les infos sauf le nb de points à la fin
          {
            token = strtok(NULL,";");
            ligneEcriture += string(token)+";";
          }

          token = strtok(NULL,";");
          int nbPointsUtilisateur = atoi(token) + 1; // on a rajouté 1 point

          ligneEcriture += to_string(nbPointsUtilisateur)+"\n";

          // on se positionne au début de la ligne qui avait été lue
          fileUtilisateur.seekg(-tailleLigne-1, ios::cur); // -1 à cause du \n
          fileUtilisateur<<ligneEcriture;

          // on reprend la ligne pour éviter de la relire à l'itération d'après
          //fileUtilisateur.getline(ligne,600,'\n');
        }
      }
    }
    
  }
  */

  return listMesuresFiables;
}
//----- Fin de ObtenirMesuresFiables

vector<Mesure*> DataMesures:: ObtenirMesuresNonLabelisees()
// Algorithme : parcours toutes les mesures et renvoie uniquement les mesuresUtilisateurs non labellisees
//
{
  vector<Mesure*> mesuresNonLabelisees;

   for(int i=0;i<mesures.size();i++)
  {
    MesureUtilisateur* m=dynamic_cast<MesureUtilisateur*>(mesures[i]);

    if(m==nullptr)
    {
      //ce n'est pas une mesure utilisateur 
     
    }
    else
    {
     if((*m).GetLabel()=="")
     {
       mesuresNonLabelisees.push_back(mesures[i]);
       //si la mesure utilisateur est non labellise on l'ajoute
     }
    } 
    
  }

  return mesuresNonLabelisees;

    
 
}
//----- Fin de ObtenirMesuresFiables

Mesure* DataMesures::ConsulterMoyenneDonneesDatePrecise(Horodatage & date,Zone& zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs)
// Algorithme : renvoie un tableau de mesures avec pour chaque type d'attribut une mesure moyenne correspondante.
//Attention le 1 er élement est une mesure fictive avec pur valeur le nombre de jours (1 ou 0)
{

  Mesure** mesuresMoyennes=ConsulterMoyenneDonneesPeriodePrecise(date,date,zone, listMesuresBonnes, mapCapteurs);
  if(mesuresMoyennes[0][0].getValeurAttribut()>0)
  {
    return mesuresMoyennes[1];
  }
  else
  {
    //pas de valeur on renvoie un pointeur nul
    return nullptr;
  }
  

} //----- Fin de ConsulterMoyenneDonneesDatePrecise

Mesure** DataMesures::ConsulterMoyenneDonneesPeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs, Zone* zoneMin)
// Algorithme : renvoie un tableau 2D de mesures représentant les jours avec la liste des mesures journalière moyennées 
//nous parcourons toutes les mesures fiables pour ne garder que celles dans la zone et la date correspondante puis on moyenne
{
  map<Horodatage,vector<Mesure*>> datesRencontrees;
  //clef : date, valeur : liste de Mesure*
  
  for(int i=0;i<listMesuresBonnes.size();i++)
  {
    PointGeographique p=(*mapCapteurs[(*(listMesuresBonnes[i])).getIdCapteur()]).getPosition();

    Horodatage h=(*(listMesuresBonnes[i])).getdateMesure();
    
    if(zone.VerifierAppartenancePoint(p) && h>=dateDebut && dateFin>=h && (zoneMin==nullptr || !zoneMin->VerifierAppartenancePoint(p)))
    {
      //si la mesure est dans la bonne zone etdans le bon intervalle de temps
      h.setheure(0);
      h.setMinute(0);
      h.setSeconde(0);
      //on ne garde pas l'heure, le mois, le jour

      if(datesRencontrees.find(h)==datesRencontrees.end())
      {
        //si la date a déjà été vu on l'ajoute
        vector<Mesure*> v;
        v.push_back(listMesuresBonnes[i]);
        datesRencontrees.insert({h,v});
      }
      else
      {
        //sinon on ajoute uniquement la mesure dans la map
       (datesRencontrees[h]).push_back(listMesuresBonnes[i]);
      }
      
    }
  }

  Mesure ** resultat=new Mesure*[datesRencontrees.size()+1];//contient les indices ATMO journaliers
  //on crée le résultat : il  va contenir toutes les mesures moyennées 
 

  for(int p=1;p<=datesRencontrees.size();p++)
  {
    resultat[p]=new Mesure[4];
    //4 mesures par date : une pour chaque attribut

  }

  resultat[0]=new Mesure[1];

  resultat[0][0]= Mesure();

  resultat[0][0].setValue(datesRencontrees.size());
   //le premier élement contient une mesure fictive qui indique la taille du tableau final

  double moyenneValeurs [datesRencontrees.size()][4];//1 er indice : indice date, 2 ème indice : typeAttribut

  int numDate=0;

  //nb de mesures prises en compte
  double nPM10;
  double nSO2;
  double nNO2;
  double nO3;

  for(auto it=datesRencontrees.begin();it!=datesRencontrees.end();it++)
  {
    numDate++;

    //initialisation paramètres
    nPM10=0;
    nSO2=0;
    nNO2=0;
    nO3=0;
 
    //tableau des moyennes
    moyenneValeurs[numDate-1][0]=0;
    moyenneValeurs[numDate-1][1]=0;
    moyenneValeurs[numDate-1][2]=0;
    moyenneValeurs[numDate-1][3]=0;
    
    for(int i=0;i<(it->second).size();i++)
    {
      Mesure* mesure=((it->second)[i]);
      string attributID1=(*((*mesure).getTypeMesure())).getIdAttribut();
      Horodatage date=(*mesure).getdateMesure();
      
      if(attributID1=="O3")
      {
          //MAJ moyenne

          moyenneValeurs[numDate-1][0]+=((*mesure).getValeurAttribut());
          resultat[numDate][0]=Mesure((*mesure).getTypeMesure(),moyenneValeurs[numDate-1][0],(*mesure).getIdCapteur(),date);
          ++nO3;
        
      }

      if(attributID1=="SO2")
      {
          //MAJ moyenne
          moyenneValeurs[numDate-1][1]+=((*mesure).getValeurAttribut());
          resultat[numDate][1]=Mesure((*mesure).getTypeMesure(),moyenneValeurs[numDate-1][1],(*mesure).getIdCapteur(),date);
          ++nSO2;
        
      }

      if(attributID1=="NO2")
      {
          //MAJ moyenne
          moyenneValeurs[numDate-1][2]+=((*mesure).getValeurAttribut());
          resultat[numDate][2]=Mesure((*mesure).getTypeMesure(),moyenneValeurs[numDate-1][2],(*mesure).getIdCapteur(),date);
          ++nNO2;
        
      }
        if(attributID1=="PM10")
      {
        //MAJ moyenne
        moyenneValeurs[numDate-1][3]+=((*mesure).getValeurAttribut());
        resultat[numDate][3]=Mesure((*mesure).getTypeMesure(),moyenneValeurs[numDate-1][3],(*mesure).getIdCapteur(),date);
        ++nPM10;
      }
    }

    moyenneValeurs[numDate-1][3]/=(nPM10+0.001);
    //on divise par le nombre de mesures pour obtenir la moyenne 
    resultat[numDate][3].setValue(moyenneValeurs[numDate-1][3]);

    moyenneValeurs[numDate-1][2]/=(nNO2+0.001);
    resultat[numDate][2].setValue(moyenneValeurs[numDate-1][2]);


    moyenneValeurs[numDate-1][1]/=(nSO2+0.001);
    resultat[numDate][1].setValue(moyenneValeurs[numDate-1][1]);

    moyenneValeurs[numDate-1][0]/=(nO3+0.001);
    resultat[numDate][0].setValue(moyenneValeurs[numDate-1][0]);

  }

  return resultat;

} //----- Fin de ConsulterMoyenneDonneesPeriodePrecise

int DataMesures::ConsulterQualiteDatePrecise(Horodatage & date, Zone & zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs)

// Algorithme :renvoie l'indice atmo moyen sur le jour et la zone souhaitée en calculant les moyennes journalières des attributs concernés
// si pas de mesures correspondantes, renvoie 0
{
  map<Horodatage,int> indicesAtmos=ConsulterQualitePeriodePrecise(date,date,zone, listMesuresBonnes, mapCapteurs);
  if(indicesAtmos.size()>0)
  {
    return indicesAtmos[date];
  }
  else
  {
    //pas de valeur
    return 0;
  }
  

} //----- Fin de ConsulterQualiteDatePrecise

bool operator <(const Horodatage& h1, const Horodatage& h2)
{
  //utile pour la map dans ConsulterQualitePeriodePrecise
  return h1.less(h2);
}

map<Horodatage,int> DataMesures::ConsulterQualitePeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs)
// Algorithme :renvoie l'indice atmo moyen sur la période voulue et la zone souhaitée en calculant les moyennes journalières des attributs concernés
//atention le 1 er élément du tableau renvoyé contient le nombre de jours pris en compte 
{
  map<Horodatage,vector<Mesure*>> datesRencontrees;
  //clef : date, valeur : liste de Mesure*

  map<Horodatage,int> resultats;
  //clef : date, valeur: indiceAtmo 
  
  for(int i=0;i<listMesuresBonnes.size();i++)
  {
    PointGeographique p=(*mapCapteurs[(*(listMesuresBonnes[i])).getIdCapteur()]).getPosition();

    Horodatage h=(*(listMesuresBonnes[i])).getdateMesure();
    
    if(zone.VerifierAppartenancePoint(p) && h>=dateDebut && dateFin>=h)
    {
      //si la mesure est dans la bonne zone etdans le bon intervalle de temps
      h.setheure(0);
      h.setMinute(0);
      h.setSeconde(0);
      //on ne garde pas l'heure, le mois, le jour

      if(datesRencontrees.find(h)==datesRencontrees.end())
      {
        //si la date a déjà été vu on l'ajoute
        vector<Mesure*> v;
        v.push_back(listMesuresBonnes[i]);
        datesRencontrees.insert({h,v});

        resultats.insert({h,0});
      }
      else
      {
        //sinon on ajoute uniquement la mesure dans la map
       (datesRencontrees[h]).push_back(listMesuresBonnes[i]);
       
      }
      
    }
  }

  //int *indicesAtmo=new int[datesRencontrees.size()+1];//contient les indices ATMO journaliers


  //indicesAtmo[0]=datesRencontrees.size();

  double moyenneValeurs [datesRencontrees.size()][4];//1 er indice : indice date, 2 ème indice : typeAttribut

  int numDate=-1;

  int nPM10;
  int minSO2;
  int minNO2;
  int minO3;

  for(auto it=datesRencontrees.begin();it!=datesRencontrees.end();it++)
  {
    numDate++;

    //initialisation paramètres
    nPM10=0;
 
    moyenneValeurs[numDate][0]=-100;
    moyenneValeurs[numDate][1]=-100;
    moyenneValeurs[numDate][2]=-100;//pour les 3 premiers éléments on garde le max et non pas la moyenne

    moyenneValeurs[numDate][3]=0;//pour les particules on fait la moyenne (PM10)

    for(int i=0;i<(it->second).size();i++)
    {
      Mesure* mesure=((it->second)[i]);
      string attributID1=(*((*mesure).getTypeMesure())).getIdAttribut();

      if(attributID1=="O3")
      {
        if(moyenneValeurs[numDate][0]<((*mesure).getValeurAttribut()))
        {
          //MAJ max 
          moyenneValeurs[numDate][0]=((*mesure).getValeurAttribut());
        }
        
      }

      if(attributID1=="SO2")
      {
        if(moyenneValeurs[numDate][1]<((*mesure).getValeurAttribut()))
        {
          //MAJ max
          moyenneValeurs[numDate][1]=((*mesure).getValeurAttribut());
        }
      
      }

      if(attributID1=="NO2")
      {
        if(moyenneValeurs[numDate][2]<((*mesure).getValeurAttribut()))
        {
          //MAJ max
          moyenneValeurs[numDate][2]=((*mesure).getValeurAttribut());
        }
      }
        if(attributID1=="PM10")
      {
        //MAJ moyenne
        moyenneValeurs[numDate][3]+=((*mesure).getValeurAttribut());
        ++nPM10;
      }
    }

    moyenneValeurs[numDate][3]/=(nPM10+0.001);//on divise par le nombre de mesures pour obtenir la moyenne (PM10)

  }

  //initialisation tableaux pour calculer les sous indices-atmo

  int tabPM10min[]={0,7,14,21,28,35,42,50,65,80};
  int tabPM10max[]={6,13,20,27,34,41,49,64,79,1000000};

  int tabNO2min[]={0,30,55,85,110,135,165,200,275,400};
  int tabNO2max[]={29,54,84,109,134,164,199,274,399,1000000};

  int tabO3min []={0,30,55,80,105,130,150,180,210,240};
  int tabO3max []={29,54,79,104,129,149,179,209,239,1000000};

  int tabSO2min []={0,40,80,120,160,200,250,300,400,500};
  int tabSO2max []={39,79,119,159,199,249,299,399,499,1000000};

  int* tabMin[4];
  int* tabMax[4];

  tabMin[0]=tabO3min;
  tabMin[1]=tabSO2min;
  tabMin[2]=tabNO2min;
  tabMin[3]=tabPM10min;

  tabMax[0]=tabO3max;
  tabMax[1]=tabSO2max;
  tabMax[2]=tabNO2max;
  tabMax[3]=tabPM10max;

  //début calculs sous-indices atmo

  int i=-1;

  for(auto it=datesRencontrees.begin();it!=datesRencontrees.end();it++)
  {
    i++;
     //indicesAtmo[i+1]=-1;
     resultats[it->first]=-1;
     for(int k=0;k<4;k++)
     {
       double valeur=moyenneValeurs[i][k];
        for(int j=0;j<=9;j++)
        {
         if(valeur>tabMin[k][j] && valeur<tabMax[k][j])
         {
           if(j+1>resultats[it->first])
           {
             //on garde que le max pour chaque jour : c'est l'indice final
           //indicesAtmo[i+1]=j+1;
            resultats[it->first]=j+1;
           }
         }
        }

     }
   }

   /*for(int i=0;i<=numDate;i++)
   {
     cout<<indicesAtmo[i]<<endl;
   }
   */

   return resultats;

} //----- Fin de ConsulterQualitePeriodePrecise

vector<Mesure*>&  DataMesures::ObtenirDonneesBrutes()
// Algorithme : renvoie toutes les mesures 
//
{
  return mesures;

} //----- Fin de ObtenirDonneesBrutes

bool DataMesures::CapteurNouveau(string idUser,unordered_map<string, string> & mapCapteurUtilisateur)
//Algorithme : renvoie true si on a besoin d'un nouveau capteur pour l'utilisateur
{
  for(auto it=mapCapteurUtilisateur.begin();it!=mapCapteurUtilisateur.end();it++)
  {
    if(it->second==idUser)
    {
      return false;
    }
  }

  return true;

}//----- Fin de CapteurNouveau

Capteur* DataMesures::EntrerDonnees(string fichierUsers,string fichierCapteurs,vector<double>& valeurs,Horodatage& date,PointGeographique& p, UtilisateurPrive & utilisateur,unordered_map<string, string> & mapCapteurUtilisateur,unordered_map<string,Capteur*>& mapIDCapteurs)
// Algorithme : regarde si l'utilisateur a un capteur associé, sinon on crée son capteur puis on inscrit la mesure dans le fichier des mesures
//
{

  string idUser=utilisateur.GetIdentifiant();
  string idCapteurNouveau="";

  Capteur* capteurNouveau;

  //vérifie si l'utilisateur a déjà un capteur
  for(auto it=mapCapteurUtilisateur.begin();it!=mapCapteurUtilisateur.end();it++)
  {
    if(it->second==idUser)
    {
      idCapteurNouveau=it->first;
      capteurNouveau=mapIDCapteurs[idCapteurNouveau];
      break;
    }
  }

  int idMax=0;

  if(idCapteurNouveau=="")
  {
    //pas de capteur attribué : on le créee
    for(auto it=mapIDCapteurs.begin();it!=mapIDCapteurs.end();it++)
    {
     if((*(it->second)).getIDInt()>idMax)
     {
       idMax=(*(it->second)).getIDInt();
     }
    } 

    idCapteurNouveau="Sensor";
    idCapteurNouveau.append(to_string(idMax+1));

    capteurNouveau=new Capteur(idCapteurNouveau,"",p);
    mapCapteurUtilisateur.insert({idCapteurNouveau,idUser});
    mapIDCapteurs.insert({idCapteurNouveau,capteurNouveau});

    ofstream fileCapteurs(fichierCapteurs,ios::app);
    if(fileCapteurs)
    {
    fileCapteurs<<idCapteurNouveau<<";"<<p.getLatitude()<<";"<<p.getLongitude()<<";\n";
    }

    else
    {
      cerr<<"Erreur lors de l'écriture du nouveau capteur dans le fichier des capteurs"<<endl;
      
    }

    ofstream fileUsers(fichierUsers,ios::app);
    if(fileUsers)
    {
      fileUsers<<utilisateur.GetIdentifiant()<<";"<<idCapteurNouveau<<";\n";
    }
    else
    {
      cerr<<"Erreur lors de l'écriture du nouveau capteur dans le fichier des utilisateurs"<<endl;
    }

  }

  if(idMax==0)
  {
    //capteur déjà existant
		string idS=idCapteurNouveau.substr(6,idCapteurNouveau.length());
    
    int nbMesure=0;

    for(int i=0;i<nbMesuresAttributs.size();i++)
      {
        //on compte le nombre de mesures à sauter pour le capteur1

        nbMesure+=nbMesuresAttributs[i];

        if(std::stoi(idS)==i)
        { 
          break;
        }
       
      }

    //ajout des mesures au bon endroit dans la liste
    vector<Mesure*>::iterator it;
    it=mesures.begin();
    TypeAttribut* typeO3 =(typeAttributs.find("O3"))->second;
    MesureUtilisateur* nouvelleMesureO3=new MesureUtilisateur(typeO3,valeurs[0],idCapteurNouveau,date);
    utilisateur.EntrerDonnee(nouvelleMesureO3);

    mesures.insert(it+nbMesure,nouvelleMesureO3);
    

    TypeAttribut* typeSO2 =(typeAttributs.find("SO2"))->second;
    MesureUtilisateur* nouvelleMesureSO2=new MesureUtilisateur(typeSO2,valeurs[1],idCapteurNouveau,date);
    mesures.insert(it+nbMesure+1,nouvelleMesureSO2);
    utilisateur.EntrerDonnee(nouvelleMesureSO2);


    TypeAttribut* typeNO2 =(typeAttributs.find("NO2"))->second;
    MesureUtilisateur* nouvelleMesureNO2=new MesureUtilisateur(typeNO2,valeurs[2],idCapteurNouveau,date);
    mesures.insert(it+nbMesure+2,nouvelleMesureNO2);
    utilisateur.EntrerDonnee(nouvelleMesureNO2);


    TypeAttribut* typePM10 =(typeAttributs.find("PM10"))->second;
    MesureUtilisateur* nouvelleMesurePM10=new MesureUtilisateur(typePM10,valeurs[3],idCapteurNouveau,date);
    mesures.insert(it+nbMesure+3,nouvelleMesurePM10);
    utilisateur.EntrerDonnee(nouvelleMesurePM10);

    nbMesuresAttributs[std::stoi(idS)]+=4;


  }
  else
  {
    //capteur nouveau

    //ajout des mesures à la fin 
    TypeAttribut* typeO3 =(typeAttributs.find("O3"))->second;
    MesureUtilisateur* nouvelleMesureO3=new MesureUtilisateur(typeO3,valeurs[0],idCapteurNouveau,date);
    mesures.push_back(nouvelleMesureO3);
    utilisateur.EntrerDonnee(nouvelleMesureO3);


    TypeAttribut* typeSO2 =(typeAttributs.find("SO2"))->second;
    MesureUtilisateur* nouvelleMesureSO2=new MesureUtilisateur(typeSO2,valeurs[1],idCapteurNouveau,date);
    mesures.push_back(nouvelleMesureSO2);
    utilisateur.EntrerDonnee(nouvelleMesureSO2);


    TypeAttribut* typeNO2 =(typeAttributs.find("NO2"))->second;
    MesureUtilisateur* nouvelleMesureNO2=new MesureUtilisateur(typeNO2,valeurs[2],idCapteurNouveau,date);
    mesures.push_back(nouvelleMesureNO2);
    utilisateur.EntrerDonnee(nouvelleMesureNO2);


    TypeAttribut* typePM10 =(typeAttributs.find("PM10"))->second;
    MesureUtilisateur* nouvelleMesurePM10=new MesureUtilisateur(typePM10,valeurs[3],idCapteurNouveau,date);
    mesures.push_back(nouvelleMesurePM10);
    utilisateur.EntrerDonnee(nouvelleMesurePM10);


    nbMesuresAttributs.push_back(4);

   /* ofstream fileMesures(fichierMesures,ios::app);
    fileMesures<<date.GetAnnee()<<"-"<<date.GetMois()<<"-"<<date.GetJour()<<" "<<date.GetHeure()<<":"<<date.GetMinute()<<":"<<date.GetSeconde()<<";"<<idCapteurNouveau<<";"<<"O3"<<";"<<valeurs[0]<<";\n";
    fileMesures<<date.GetAnnee()<<"-"<<date.GetMois()<<"-"<<date.GetJour()<<" "<<date.GetHeure()<<":"<<date.GetMinute()<<":"<<date.GetSeconde()<<";"<<idCapteurNouveau<<";"<<"NO2"<<";"<<valeurs[1]<<";\n";
    fileMesures<<date.GetAnnee()<<"-"<<date.GetMois()<<"-"<<date.GetJour()<<" "<<date.GetHeure()<<":"<<date.GetMinute()<<":"<<date.GetSeconde()<<";"<<idCapteurNouveau<<";"<<"SO2"<<";"<<valeurs[2]<<";\n";
    fileMesures<<date.GetAnnee()<<"-"<<date.GetMois()<<"-"<<date.GetJour()<<" "<<date.GetHeure()<<":"<<date.GetMinute()<<":"<<date.GetSeconde()<<";"<<idCapteurNouveau<<";"<<"PM10"<<";"<<valeurs[3]<<";\n";
  */
  }
  
  return capteurNouveau;
} //----- Fin de EntrerDonnees

vector<Capteur*> DataMesures::IdentifierCapteursSimilaires(unordered_map<string,Capteur*> & mapCapteur, string id_ref_capt, double epsilon)
//Algorithme : Permet d'identifier l'ensemble des capteurs ayant des valeurs proches du capteurChoisi avec un
// écart relatif epsilon donné entre chacune de ses valeurs
{
    vector<Capteur*> list_capteur_similaire;
    Capteur *ref_capt = mapCapteur[id_ref_capt];
    int nb_mesures_ref_capt = nbMesuresAttributs[ref_capt->getIDInt()];
    vector<Mesure*>::iterator mesure_ref_begin = mesures.begin();
    vector<Mesure*>::iterator mesure_ref_end;

    //cout << "Capteur choisi : " << id_ref_capt << " - id_int : " << ref_capt->getIDInt() << " - nb_mesure : " << nb_mesures_ref_capt << endl << endl;

    //Récupération de l'emplacement des mesures de notre capteur de référence
    for(int i = 0; i<ref_capt->getIDInt();i++)
    {
        mesure_ref_begin+=nbMesuresAttributs[i];
    }

    //comme un pointeur de fin, pointe sur la suivante à ne pas regarder.
    mesure_ref_end = mesure_ref_begin + nb_mesures_ref_capt;

    //cout << "Premier mesure du sensor - type : " << (*mesure_ref_begin)->getTypeMesure()->getIdAttribut() << " - valeur :" << (*mesure_ref_begin)->getValeurAttribut() << " - date : " << (*mesure_ref_begin)->getdateMesure().GetJour() << "/" <<  (*mesure_ref_begin)->getdateMesure().GetMois() << endl << endl;
    //cout << "Dernière mesure du sensor - type : " << (*mesure_ref_end)->getTypeMesure()->getIdAttribut() << " - valeur :" << (*mesure_ref_end)->getValeurAttribut() << " - date : " << (*mesure_ref_end)->getdateMesure().GetJour() << "/" <<  (*mesure_ref_end)->getdateMesure().GetMois() << endl << endl;

    //Pour chacun des capteurs différent de notre capteur choisi
    //Pour chaque jour
    //Pour chaque type de mesure
    //En faire un écart relatif et le sommer
    //En faire un écart relatif moyen sur le nb de valeurs/4
    //Vérifier si la moyenne de ses 4 écarts-types moyen est < epsilon --> si oui l'ajouter au set

    for(unordered_map<string,Capteur*>::iterator it = mapCapteur.begin() ; it != mapCapteur.end() ; ++it )
    {
        Capteur * to_study = it->second;
        vector<Mesure*>::iterator mesure_study_begin = mesures.begin();

        if(to_study->getIDInt()==ref_capt->getIDInt())
            continue;

        double ecart_relatif_total[] = {0, 0, 0, 0};

        //Récupération de l'emplacement des mesures de notre capteur à étudier
        for(int i = 0; i<to_study->getIDInt();i++)
        {
            mesure_study_begin+=nbMesuresAttributs[i];
        }

        int nb_valeurs_mini = ( (nb_mesures_ref_capt < nbMesuresAttributs[to_study->getIDInt()]) ? (nb_mesures_ref_capt) : (nbMesuresAttributs[to_study->getIDInt()]) );

        //Sommer les écarts types pour chaque type de mesure
        for(int i = 0; i< nb_valeurs_mini; ++i)
        {

            //Etude de 03
            ecart_relatif_total[0] += abs(((*(mesure_ref_begin+i))->getValeurAttribut() - (*(mesure_study_begin+i))->getValeurAttribut()))/(*(mesure_study_begin+i))->getValeurAttribut();

            ++i;
            //Etude de NO2
            ecart_relatif_total[1] += abs(((*(mesure_ref_begin+i))->getValeurAttribut() - (*(mesure_study_begin+i))->getValeurAttribut()))/(*(mesure_study_begin+i))->getValeurAttribut();

            ++i;
            //Etude de SO2
            ecart_relatif_total[2] += abs(((*(mesure_ref_begin+i))->getValeurAttribut() - (*(mesure_study_begin+i))->getValeurAttribut()))/(*(mesure_study_begin+i))->getValeurAttribut();

            ++i;
            //Etude de PM10
            ecart_relatif_total[3] += abs(((*(mesure_ref_begin+i))->getValeurAttribut() - (*(mesure_study_begin+i))->getValeurAttribut()))/(*(mesure_study_begin+i))->getValeurAttribut();
        }

        //En faire un écart type moyen pour chaque type de mesure
        for(int i = 0; i<4; ++i)
        {
            ecart_relatif_total[i] /= nb_valeurs_mini;
        }

        double ecart_relatif_moyen_final = ecart_relatif_total[0]+ecart_relatif_total[1]+ecart_relatif_total[2]+ecart_relatif_total[3];
        ecart_relatif_moyen_final /= 4;

        //cout << "Ecart relatif total moyen sensor " << (*it).second->getID() << " : " << ecart_relatif_moyen_final << endl << endl;

        if(ecart_relatif_moyen_final < epsilon)
            list_capteur_similaire.push_back(to_study);
    }

    return list_capteur_similaire;
} // Fin de IdentifierCapteursSimilaires

vector<vector<Capteur*>> DataMesures::IdentifierClusterCapteursSimilaires(unordered_map<string,Capteur*> & mapCapteur, int nbClassesMin)
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
        resultats=listClasses[a];

      }
      evalIni=eval2;

    }

    for(int i=0; i<listCapteur.size(); i++)
    {
      free(memoire[i]);
    }
    free(memoire);

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
  free(matDim);
  return maxDiss;

}//----- Fin de evalClasses

int DataMesures:: LabelliserUneDonnee(map<Horodatage,int>& nbMesuresPardate,set<Mesure*,classcomp>& listMesuresBonnes,Mesure*& m, unordered_map<string,Capteur*>& mapCapteurs)
{

  vector<Mesure> MesuresBonnesTris;

  int avantApresjour;
  int avantApresMois;
  int avantApresAnnee;

  for(auto it =listMesuresBonnes.begin();it!=listMesuresBonnes.end();)
  {
    //si le temps correspond et le type de mesure aussi
   
    avantApresMois=(*(*it)).getdateMesure().GetMois()-(*m).getdateMesure().GetMois();
    avantApresAnnee=(*(*it)).getdateMesure().GetAnnee()-(*m).getdateMesure().GetAnnee();
    avantApresjour=(*(*it)).getdateMesure().GetJour()-(*m).getdateMesure().GetJour();

    if(avantApresAnnee<0 ||(avantApresAnnee==0 && avantApresMois<0 )||(avantApresAnnee==0 && avantApresMois==0 &&avantApresjour<0))
    {
      int n=(nbMesuresPardate.find((*(*it)).getdateMesure()))->second;
    
      advance(it,n);

      continue;
    }

    else
    {
      if(avantApresAnnee==0 && avantApresMois==0 &&avantApresjour==0)
      {
        MesuresBonnesTris.push_back(*(*it));

      }
      else
      {
        break;
      }
      
    }
    it++;
    
  }

  PointGeographique p1=(*mapCapteurs[(*m).getIdCapteur()]).getPosition();
  double latitude1=p1.getLatitude();
  double longitude1=p1.getLongitude();

  double moyenne=0;
  double denominateur=0;
  if(MesuresBonnesTris.size()>0)
  {
    for(int i=0;i<MesuresBonnesTris.size();i++)
    {
      PointGeographique p2=(*mapCapteurs[(MesuresBonnesTris[i]).getIdCapteur()]).getPosition();
      double latitude2=p2.getLatitude();
      double longitude2=p2.getLongitude();

      double distance=acos(sin(M_PI/180*latitude1)*sin(M_PI/180*latitude2)+cos(M_PI/180*latitude1)*cos(M_PI/180*latitude2)*cos(M_PI/180*(longitude2-longitude1)))*6371;
      //calcul de la distance entre le point à vérifier et le point où se trouve la mesure fiable

      moyenne+=((1/(distance+0.1))*MesuresBonnesTris[i].getValeurAttribut());

      //on pondère le poids de la mesure fiable par sa distane par rapport au point à vérifier
      denominateur+=1/(distance+0.1);
    }

    double valeurEstime=moyenne/denominateur;

    double minimum=(*m).getValeurAttribut();

    if(minimum>valeurEstime)
    {
      minimum=valeurEstime;
    }

    if((abs(valeurEstime-(*m).getValeurAttribut())/(minimum))>0.3)
    {
      //on compare l'indicateur de fiabilité avec une valeur arbitraire (2)
      
      return -1;//valeur aberrante
    }
  }

  else
  {
    return 0;
  }
  
  return 1;//valeur OK

}


/*bool fncomp (Mesure* m1,Mesure* m2) 
{
  return );
}
*/

void DataMesures::LabeliserDonneesUtilisateur(string fichierLabel, unordered_map<string,Capteur*>& mapCapteurs, unordered_map<string, string>& mapCapteurPrive, vector<Utilisateur*>& utilisateurs, string fichierUtilisateurPerso)
// Algorithme : parcourt les mesures non labellisées et calcule leur label grâce à LabelliserUnedonnee puis les écrit dans le fichier des labels
//
{
  map<Horodatage,int> nbMesuresPardate;
  vector<Mesure*> mesuresNonLabellisees=this->ObtenirMesuresNonLabelisees();
  vector<Mesure*> mesuresFiables=this->ObtenirMesuresFiables(mapCapteurPrive,utilisateurs,fichierUtilisateurPerso);
  ofstream fileLabel(fichierLabel,ios::app);

  //bool(*fn_pt)(int,int) = fncomp;
  set<Mesure*,classcomp> mesuresFiablesTriees ;

  for(int i=0;i<mesuresFiables.size();i++)
  {
    mesuresFiablesTriees.insert(mesuresFiables[i]);
  }

  int nbMesuredate=0;
  Horodatage date1=(*mesuresFiablesTriees.begin())->getdateMesure();
  //Horodatage date1=(*mesuresFiablesTriees[0]).getdateMesure();

  for(auto it=mesuresFiablesTriees.begin();it!=mesuresFiablesTriees.end();it++)
  {
    if((*it)->getdateMesure()==date1)
    {
      nbMesuredate++;
    }

    else
    {
      nbMesuresPardate.insert({date1,nbMesuredate});
      //cout<<date1.GetJour()<<"/"<<date1.GetMois()<<"/"<<date1.GetAnnee()<<":"<<nbMesuredate<<endl;
      nbMesuredate=1;
      date1=(*it)->getdateMesure();
      
    }
  }
  nbMesuresPardate.insert({date1,nbMesuredate});


  if(!fileLabel.is_open())
	{
		cerr<<"Erreur lors de l'écriture des  labels"<<endl;
		
	}
 
  else
  {
    for(int i=0;i<mesuresNonLabellisees.size();i++)
    {
      int res=this->LabelliserUneDonnee(nbMesuresPardate,mesuresFiablesTriees,mesuresNonLabellisees[i],mapCapteurs);
      string label;
      MesureUtilisateur* m=dynamic_cast<MesureUtilisateur*>(mesuresNonLabellisees[i]);

      if(m!=nullptr)
      {
        string idMesure = to_string((m)->getdateMesure().GetAnnee())+to_string((m)->getdateMesure().GetMois())+to_string((m)->getdateMesure().GetJour())+to_string((m)->getdateMesure().GetHeure())+to_string((m)->getdateMesure().GetMinute())+to_string((m)->getdateMesure().GetSeconde())+(m)->getIdCapteur()+(m)->getTypeMesure()->getIdAttribut();
        if(res==1)
        {
          //mesure fiable
          label="fiable";
          fileLabel<<idMesure<<";"<<label<<"\n";
          m->SetLabel(label);

        }

        if(res==-1)
        {
          //mesure non fiable
          label="non fiable";
          fileLabel<<idMesure<<";"<<label<<"\n";
          m->SetLabel(label);
        }

      
      }
      
    }

  }

} //----- Fin de LabeliserDonneesUtilisateur
unordered_map<string,TypeAttribut*>&   DataMesures::GetTypeAttributs()
// Algorithme :
//
{
  return typeAttributs;

} //----- Fin de GetTypeAttributs


vector<Mesure*>& DataMesures::GetMesures()
// Algorithme : renvoie toutes les mesures
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
  vector<Mesure*>::iterator itM;
  for(itM=mesures.begin();itM!=mesures.end();itM++)
  {
    delete(*itM);
  }
  
  unordered_map<string,TypeAttribut*>:: iterator it;
  for(it=typeAttributs.begin();it!=typeAttributs.end();it++)
  {
    delete(it->second);
  }
} //----- Fin de ~DataMesures


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
