/*************************************************************************
						   DataMesures  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataMesures> (fichier DataMesures.h) ------
#if ! defined ( DATAMESURES_H )
#define DATAMESURES_H

//--------------------------------------------------- Interfaces utilisées
#include "Zone.h"
#include "Horodatage.h"
#include "Mesure.h"
#include "Capteur.h"
#include "UtilisateurPrive.h"
#include "TypeAttribut.h"
#include "DataCapteurs.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataMesures>
//
//
//------------------------------------------------------------------------

class DataMesures
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool ChargerMesures(string fichierMesures, unordered_map<string, string> & mapCapteurUtilisateur, vector<Utilisateur*> & utilisateurs);
	// Mode d'emploi : permet de charger les mesures dans la structure de données appropriée et de remplir également
	// les données entrées de chaque utilisateur privé
	//
	// Contrat : Aucun
	//

    bool ChargerAttributs(string fichierAttributs);
	// Mode d'emploi : permet de charger les attributs dans la structure de données appropriée
	//
	// Contrat : Aucun
	//

	bool ChargerLabels(string fichierLabel, unordered_map<string, string> & mapCapteurUtilisateur);
	// Mode d'emploi : Méthode qui va permettre d'associer à chaque mesure
	// des utilisateurs privés leur label (si il y en a)
	//
	// Contrat : Aucun
	//

	bool SauvegarderMesuresAjoutees(string fichierMesures);
	// Mode d'emploi : écrit dans le fichier des mesures toutes les mesures notamment celles ajoutées
	//
	// Contrat : Aucun
	//

    Mesure* ConsulterMoyenneDonneesDatePrecise(Horodatage & date,Zone& zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs);
	// Mode d'emploi :renvoie les 4 mesures moyennées sur le jour demandé ou un pointeur nul si pas de mesures pour le calcul
	// Contrat : nécessite que ConsulterMoyenneDonneesPeriodePrecise soit implémenté
	//

    Mesure** ConsulterMoyenneDonneesPeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs);
	// Mode d'emploi : renvoie un tableau 2D avec resultat[numJour][indiceAttribut] qui est une mesure avec pour valeur la valeur pondérée de la journée dans la zone correspondante
	//Attention le 1 er élement est ficitf, sa valeur contient le nombre de jours c.a.d la taille du tableau-1
	// Contrat : nécessite une liste de mesures fiables
	//


    int ConsulterQualiteDatePrecise(Horodatage & date,Zone& zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs);
	// Mode d'emploi :renvoie un entier correspondant à l'indice atmo du jour demandé ou bien une valeur nulle si pas de mesure
	// Contrat : nécessite que ConsulterQualitePeriodePrecise soit implémenté
	//

    map<Horodatage,int> ConsulterQualitePeriodePrecise(Horodatage & dateDebut, Horodatage & dateFin, Zone & zone,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs);
	// Mode d'emploi :renvoie une liste d'entiers correspondant aux indices atmos, un par jour (s'il y avait des mesures à ce jour correspondant)
	//Attention le 1 er élement est ficitf, sa valeur contient le nombre de jours c.a.d la taille du tableau-1
	// Contrat : nécessite une liste de mesures fiables
	//

    vector<Mesure*>&  ObtenirDonneesBrutes();
	// Mode d'emploi : renvoie toutes les mesures 
	//
	// Contrat : aucun
	//
	bool CapteurNouveau(string idUser,unordered_map<string, string> & mapCapteurUtilisateur);
	// Mode d'emploi : renvoie true si besoin d'un nouveau capteur pour l'utilisateur
	//
	// Contrat : aucun
	//

    Capteur* EntrerDonnees(string fichierUsers,string fichierCapteurs, vector<double>& valeurs,Horodatage& date, PointGeographique& p,UtilisateurPrive & utilisateur,unordered_map<string, string> & mapCapteurUtilisateur,unordered_map<string,Capteur*>& mapIDCapteurs);
	// Mode d'emploi : permet d'entrer de nouvelles données 
	//
	// Contrat : aucun
	
	int LabelliserUneDonnee(vector<Mesure*>& listMesuresBonnes,Mesure*& m,unordered_map<string,Capteur*>& mapCapteurs);
	// Mode d'emploi : renvoie 1 si la mesure à vérifier est non aberrante, 0 sinon. Si on ne peut pas décider, renvoie 0
	// Contrat : nécessite une liste de mesures fiables
	//

    vector<Capteur*> IdentifierCapteursSimilaires(unordered_map<string,Capteur*> & mapCapteur, string id_ref_capt, double epsilon);
    // Mode d'emploi : Renvoi les capteurs similaires à celui passé en paramètre
    //
    // Contrat : Aucun
    //

    vector<vector<Capteur*>> IdentifierClusterCapteursSimilaires(unordered_map<string,Capteur*> &  listCapteur,int nbClassesMin);
	// Mode d'emploi : renvoi les capteurs similaires à partir d'une liste de capteurs et du nombre de classes minimum
	//
	// Contrat : aucun
	//

    void LabeliserDonneesUtilisateur(string fichierLabel,unordered_map<string,Capteur*>& mapCapteurs, unordered_map<string, string> mapCapteurPrive, vector<Utilisateur*> utilisateurs);
	// Mode d'emploi : écrit dans le fichier des labels les labels des mesures non labellisées
	//
	// Contrat : aucun
	//

	void SauvegarderMesures(string fichierMesures);
	// Mode d'emploi : écrit dans le fichier des labels les labels des mesures non labellisées
	//
	// Contrat : aucun
	//


    unordered_map<string,TypeAttribut*>&  GetTypeAttributs();
	// Mode d'emploi : renvoie la structure de données contenant les attributs 
	//
	// Contrat : aucun
	//

	vector<Mesure*>& GetMesures();
	// Mode d'emploi : renvoie la structure de données contenant les mesures 
	//
	// Contrat : aucun
	//

	vector<Mesure*> ObtenirMesuresFiables(unordered_map<string, string> mapCapteurPrive, vector<Utilisateur*> utilisateurs);
	// Mode d'emploi : renvoie sous forme d'un vecteur toutes les mesures fiables
	//
	// Contrat : aucun
	//

	vector<Mesure*> ObtenirMesuresNonLabelisees();
	// Mode d'emploi : renvoie sous forme d'un vecteur toutes les mesures non labellisés
	//
	// Contrat : aucun
	//


//------------------------------------------------- Surcharge d'opérateurs
	DataMesures & operator = (const DataMesures & unDataMesures);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	DataMesures (const DataMesures & unDataMesures);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	DataMesures ();
	// Mode d'emploi : constructeur par défaut
	//
	// Contrat :
	//

	virtual ~DataMesures ();
	// Mode d'emploi : destructeur  
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	double dissimMax(vector<Capteur*> & v1,vector<Capteur*> & v2 );
	//mode d'emploi : renvoi le maximum de dissimilarité inter-classe entre les 2 groupes de capteur passés en paramètre
	//contrat: aucun
	
	double evalClasses(vector<vector<Capteur*>> & classI);
	//mode d'emploi : renvoi le maximum de dissimilarité intra-classe sur le groupe de capteur passé en paramètre
	//contrat: aucun

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	vector<Mesure*> mesures;//liste des mesures
	unordered_map<string,TypeAttribut*> typeAttributs;//map des types d'Attributs
	vector <int>nbMesuresAttributs;//nb mesures par capteur
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataMesures>

#endif // DATAMESURES_H
