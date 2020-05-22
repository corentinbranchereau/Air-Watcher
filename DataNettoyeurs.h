/*************************************************************************
						   DataNettoyeurs  -  Classe stockant et gérant les nettoyeurs d'air
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataNettoyeurs> (fichier DataNettoyeurs.h) ------
#if ! defined ( DATANETTOYEURS_H )
#define DATANETTOYEURS_H

//--------------------------------------------------- Interfaces utilisées
#include "NettoyeurAir.h"
#include "DataMesures.h"
#include "CompagnieFournisseur.h"
#include "Mesure.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataNettoyeurs>
// Cette classe va servir de stockage pour tous les nettoyeurs d'air de
// l'application, et va permettre les différentes opérations possibles sur
// ces derniers
//
//------------------------------------------------------------------------

class DataNettoyeurs
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool ChargerNettoyeurs(string fichierNettoyeurs);
	// Mode d'emploi : Méthode qui va lire le fichier des nettoyeurs afin de charger
	// tous les nettoyeurs dans l'application. Pour cela, le fichier est ouvert en lecture,
	// et construit pour chaque ligne un nettoyeur
	//
	// Contrat : Chaque ligne doit être au format idNettoyeur;latitude;longitude;;DateDebut;DateFin;
	//

	bool SauvegarderNettoyeurs(string fichierNettoyeurs);
	// Mode d'emploi : Méthode qui va ouvrir le fichier en paramètre en écriture, afin d'y 
	// ecrire les informations propres à chaque nettoyeur présent dans l'attribut map< > nettoyeurs
	//
	// ATTENTION : les informations qui étaient initialement présente dans le fichier sont écrasées, afin de permettre
	// la mise à jour des nettoyeurs modifiés ou supprimés. 
	// 
	// Contrat : Chaque ligne doit être au format idNettoyeur;latitude;longitude;;DateDebut;DateFin;
	//			 La méthode ChargerNettoyeurs doit avoir été appelée au début de l'application

    bool AjouterNettoyeur(NettoyeurAir & nettoyeur,CompagnieFournisseur & fournisseur);
	// Mode d'emploi : Ajoute le nettoyeur dans la liste de DataNettoyeurs, et va l'ajouter 
	// dans la liste du fournisseur passé en paramètre
	//
	// Contrat :
	//le fournisseur en paramètre doit être celui qui crée le nettoyeur
	// Il faut appeler SauvegarderNettoyeur à la fin de l'application pour pouvoir enregistrer les changements

    bool SupprimerNettoyeur(string idNettoyeur,CompagnieFournisseur & fournisseur);
	// Mode d'emploi : Supprime le nettoyeur dans la liste des nettoyeurs de DataNettoyeurs, va également 
	//le supprimer dans la liste des Fournisseurs, et désalloue la mémoire liée à ce nettoyeur 
	// 
	// Contrat :
	// le fournisseur en paramètre doit être celui qui possède le nettoyeur
	// Il faut appeler SauvegarderNettoyeur à la fin de l'application pour pouvoir enregistrer les changements

    bool ActiverNettoyeur(string idNettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	// Il faut appeler SauvegarderNettoyeur à la fin de l'application pour pouvoir enregistrer les changements

    bool DesactiverNettoyeur(string idNettoyeur);
	// Mode d'emploi :
	//
	// Contrat :
	// Il faut appeler SauvegarderNettoyeur à la fin de l'application pour pouvoir enregistrer les changements

	NettoyeurAir* VerifierAppartenanceNettoyeur(string idNettoyeur,vector<NettoyeurAir*>& nettoyeursCompagnie);
	// Mode d'emploi : indique si le ntettoyeur avec l'id passé en paramètre appartient au provider et le renvoie 
	//
	// Contrat :
	//



    double ObtenirRayonActionNettoyeur(string idNettoyeur, DataMesures & dataM,vector<Mesure*>& listMesuresBonnes,unordered_map<string,Capteur*>& mapCapteurs,double precision,double epsilon, double rayonMax);
	// Mode d'emploi :Renvoie le rayon d'action du nettoyeur passé en paramètre
	//
	// Contrat : aucun
	//

    unordered_map<string,NettoyeurAir*> GetNettoyeurs();
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
	DataNettoyeurs & operator = (const DataNettoyeurs & unDataNettoyeurs);
	// Mode d'emploi : Opérateur qui copie simplement les attributs de la classe
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur
	DataNettoyeurs (const DataNettoyeurs & unDataNettoyeurs);
	// Mode d'emploi (constructeur de copie) : Constructeur qui copie simplement 
	// les attributs de la classe
	//
	// Contrat : Aucun
	//

	DataNettoyeurs ();
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

	virtual ~DataNettoyeurs ();
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    unordered_map<string,NettoyeurAir*> nettoyeurs; // clé = id nettoyeur, valeur = objet nettoyeur
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataNettoyeurs>

#endif // DATANETTOYEURS_H
