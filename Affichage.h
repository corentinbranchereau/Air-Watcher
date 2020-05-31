/*************************************************************************
						   Affichage  -  Classe permettant l'affichage de l'application sur la console
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ------
#if ! defined ( AFFICHAGE_H )
#define AFFICHAGE_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "UtilisateurPrive.h"
#include "EmployeFournisseur.h"
#include "EmployeAgenceGouvernementale.h"
#include "Admin.h"
#include "Capteur.h"
#include "Zone.h"
#include "Horodatage.h"
#include "Mesure.h"
#include "DataNettoyeurs.h"

#include <string>
#include <vector>
#include <map>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Affichage>
// Cette classe dispose de toutes les méthodes permettant d'afficher les divers
// menu à l'utilisateur, et permettant de récupérer ce qu'il rentre afin de
// déclencher par la suite les bonnes actions via le contrôleur
//
//------------------------------------------------------------------------

class Affichage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void NettoyerConsole();
	// Mode d'emploi : L'appel à cette méthode permet de supprimer tout le texte
	// présent dans la console, pour passer à une autre "page" de l'application
	//
	// Contrat : Aucun
	//

	void AfficherTitre();
	// Mode d'emploi : Cette méthode permet d'afficher le titre de l'application
	// dans la console, ainsi que les auteurs
	//
	// Contrat : Il faut que la fenêtre de la console soit suffisamment grande
	//

	string Souligner(const string & chaine);
	// Mode d'emploi : Cette méthode prend en paramètre une chaine de caractère
	// à souligner dans la console, et renvoie la chaine encadrée par des 
	// manipulateurs qui permettent de la souligner dans la console
	//
	// Contrat : Aucun
	//

	int SaisirChoix(int choixMax);
	// Mode d'emploi : Cette méthode permet de récupérer le choix (entier) saisi
	// par l'utilisateur en gérant les erreurs (si l'utilisateur n'a pas rentré un
	// entier, ou si l'entier est trop petit/grand)
	//
	// Contrat : Aucun
	//

	int AfficherMenuPrincipal();
	// Mode d'emploi : Cette méthode permet d'afficher le menu principal et de
	// récupérer le choix d'action que l'utilisateur a tapé
	//
	// Contrat : Aucun
	//

	string* AfficherCreationCompte();
	// Mode d'emploi : Méthode affichant le menu de création de compte et retournant
	// les informations rentrées par l'utilisateur, sous forme d'un tableau de string
	//
	// Contrat : Aucun
	//

	void AfficherFinCreationCompte(bool reussite);
	// Mode d'emploi : Méthode affichant à l'utilisateur si la création s'est bien passée
	// ou non.
	//
	// Contrat : Aucun
	//

	string* AffichageConnexion();
	// Mode d'emploi : Méthode affichant le menu de connexion et retournant
	// les informations entrées par l'utilisateur
	//
	// Contrat : Aucun
	//

	void AffichageFinConnexion(string etatConnexion);
	// Mode d'emploi : Méthode affichant à l'utilisateur si la connexion s'est bien passée
	// ou non. En particulier, pour les comptes 'agence' et 'fournisseur' affiche si le compte
	// est en attente
	//
	// Contrat : Aucun
	//

	void AfficherInformationsCompte();
	// Mode d'emploi : Cette méthode permet d'afficher en dessous du titre de l'application
	// les informations essentielles du compte : nom, prénom, type du compte, nb points si utilisateur
	// privé, nom compagnie si fournisseur
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionPrive();
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un utilisateur
	// privé et de récupérer le choix d'action que l'utilisateur a tapé.
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionFournisseur();
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un fournisseur
	// et de récupérer le choix d'action qu'il a tapé.
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionAgenceGouv();
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un employé de
	// l'agence gouvernementale et de récupérer le choix d'action qu'il a tapé.
	//
	// Contrat : Aucun
	//

	int AfficherMenuActionAdmin();
	// Mode d'emploi : Cette méthode permet d'afficher le menu d'action d'un admin
	// et de récupérer le choix d'action qu'il a tapé.
	//
	// Contrat : Aucun
	//

	int ClustersCapteursNbClassesMini(int nbClassesMax);
	// Mode d'emploi : Cette méthode va permettre à l'utilisateur de saisir le
	// nombre minimum de classes qu'il souhaite pour grouper les capteurs (au max
	// il peut y avoir autant de classes que de capteurs)
	//
	// Contrat : Aucun
	//


	void PreparationConsole(string message);
	// Mode d'emploi : Cette méthode prépare la console avant l'affichage d'un résultat c'est à dire effacer la console, afficher le titre en paramètre etc...
	//
	// Contrat : Aucun
	//
	

	Horodatage SaisirDate(string type="");
	// Mode d'emploi : Cette méthode va permettre à l'utilisateur de saisir une date puis de la créer et de la retourner
	//
	// Contrat : Aucun
	//

	double SaisirDouble(double choixMin,double choixMax);
	// Mode d'emploi : demande à l'utilisateur de saisir un double compris entre choixMin et choixMax
	//
	// Contrat : Aucun
	//

	Zone SaisirZone();
	// Mode d'emploi : Cette méthode va permettre à l'utilisateur de saisir une date puis de la créer et de la retourner
	//
	// Contrat : Aucun
	//


	void DefinirUtilisateur(Utilisateur* utilisateur, string type);
	// Mode d'emploi : Cette méthode permet de définir les attributs 'utilisateurConnecte'
	// et 'typeCompte' afin de disposer des informations de l'utilisateur dans les affichages
	//
	// Contrat : Aucun
	//

	void AfficherClusterCapteursSimilaires(vector<vector<Capteur*>> & res);
	// Mode d'emploi : Affiche le résultat du regroupement des capteurs en
	// groupes ayant un comportement similaire
	//
	// Contrat : Aucun
	//

	void AfficherMoyennesPeriodePrecise(Mesure** moyennesMesure);
	// Mode d'emploi : Affiche le résultat des moyennes des mesures journalières
	//
	// Contrat : Aucun
	//

	void AfficherQualitePeriodePrecise(map<Horodatage,int> mapDateIndices);
	// Mode d'emploi : Affiche le résultat des moyennes des indices atmos journaliers
	//
	//
	// Contrat : Aucun
	//

	void AfficherApresLabel();
	// Mode d'emploi : Affiche un message lorsque les mesures sont finies de labelliser
	//
	// Contrat : Aucun
	//

	void AfficherDonnesUtilisateurPrive(Horodatage debut, Horodatage fin);
	// Mode d'emploi : Affiche les données que l'utilisateur (privé) a
	// précédemment entrées entre les dates de début et de fin données
	//
	// Contrat : Aucun
	//

	void AfficherDonneesBrutes(Horodatage debut, Horodatage fin, vector<Mesure*> & mesures);
	// Mode d'emploi : Affiche les données brutes de l'application comprise
	// entre les dates de début et de fin données
	//
	// Contrat : Aucun
	//

	void AfficherRayonAction(vector<double>& res, double rayonMax,string idNettoyeur);
	// Mode d'emploi : Affiche le rayon du nettoyeur, le rayonMax permet de connaitre si une valeur de retour spéciale a eu lieu avec rayon>rayonMax
	// 
	//
	// Contrat : Aucun
	//

	void AfficherNettoyeursCompagnie(vector<NettoyeurAir *> & nettoyeurs, bool actif, bool inactif, bool fin=true);
    // Mode d'emploi : Affiche les nettoyeurs propre à une compagnie
    // actif et inactif permettent d'afficher les nettoyeurs actifs et/inactifs
    // Contrat : Aucun

    int AfficherMenuAjoutSuppressionNettoyeur();
    // Mode d'emploi : Permet d'afficher le choix lors de l'ajout ou de la suppression d'un nettoyeur
    // Renvoi le choix réalisé entre 1 et 3
    // Contrat : Aucun

    int AfficherMenuActiverDesactiverNettoyeur();
    // Mode d'emploi : Permet d'afficher le choix lors de l'activer
    // ou de la désactivation d'un nettoyeur
    // Renvoi le choix réalisé entre 1 et 3
    // Contrat : Aucun

    void AfficherSupprimerNettoyeur(DataNettoyeurs & dataNettoyeurs, CompagnieFournisseur & compagnieFournisseur);
    // Mode d'emploi : Permet d'afficher les différents choix
    // Pour supprimer un nettoyeur
    // Contrat : Aucun

    void AfficherAjouterNettoyeur(DataNettoyeurs & dataNettoyeurs, CompagnieFournisseur & compagnieFournisseur, PointGeographique & p);
    // Mode d'emploi : Permet d'afficher les différents choix
    // Pour ajouter un nettoyeur
    // Contrat : Aucun

    void AfficherActiverNettoyeur(DataNettoyeurs & dataNettoyeurs);
    // Mode d'emploi : Permet d'afficher les différents choix
    // Pour activer un nettoyeur
    // Contrat : Aucun

    void AfficherDesactiverNettoyeur(DataNettoyeurs & dataNettoyeurs);
    // Mode d'emploi : Permet d'afficher les différents choix
    // Pour désactiver un nettoyeur
    // Contrat : Aucun

	NettoyeurAir* AfficherSaisieRayonNettoyeur(DataNettoyeurs & dataNettoyeurs,vector<NettoyeurAir*>& nettoyeursCompagnie);
	// Mode d'emploi : Permet d'afficher les différents choix
    // Pour choisir un nettoyeur pour son rayon d'action
    // Contrat : Aucun

    void AfficherComptesEnAttente(vector<UtilisateurProfessionnel*> & comptesAttente, bool fin);
    // Mode d'emploi : Permet d'afficher les différents comptes en attente
    // Mettre le boolean fin à true permet de revenir directement au menu d'action
    // Contrat : Aucun

    int AfficherMenuValidationCompte();
    // Mode d'emploi : Permet d'afficher le choix lors de la validation ou du refus d'un compte en attente
    // Renvoi le choix réalisé entre 1 et 3
    // Contrat : Aucun

    void AfficherValiderCompte(vector<UtilisateurProfessionnel*> & comptesAttente);
    // Mode d'emploi : Permet d'afficher les différents choix
    // pour valider un compte en attente
    // Contrat : Aucun

    void AfficherRefuserCompte(vector<UtilisateurProfessionnel*> & comptesAttente);
    // Mode d'emploi : Permet d'afficher les différents choix
    // pour refuser un compte en attente
    // Contrat : Aucun

    PointGeographique SaisirPosition();
    // Mode d'emploi : Permet la saisie d'un point géographique
    // Renvoi le point géographique
    // Contrat : Aucun

    double SaisirValeur(string attribut);
    // Mode d'emploi : Permet la saisie d'une valeur pour un atribut
    // Renvoi la valeur
    // Contrat : Aucun

	void AfficherConfirmation(string message);
	 // Mode d'emploi : Permet d'afficher un message puis de revenir au menu
    // Renvoi la valeur
    // Contrat : Aucun

	void AfficherMessage(string message);
	// Mode d'emploi : Permet d'afficher un message 

    // Contrat : Aucun



    void AfficherSaisirIdCapteur(unordered_map<string,Capteur*> & mapCapteur, DataMesures & donneesMesures);
    // Mode d'emploi : Permet de saisir un id capteur et epsilon pour analyser les capteurs similaires
    // Affiche les capteurs similaires
    // Contrat : Aucun

//------------------------------------------------- Surcharge d'opérateurs
	Affichage & operator = (const Affichage & unAffichage);
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur

	Affichage ();
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

	virtual ~Affichage ();
	// Mode d'emploi : Ne fait rien en particulier
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    Affichage (const Affichage & unAffichage);
    // Mode d'emploi (constructeur de copie) : Ne fait rien en particulier
    // INTERDIT
    // Contrat : Aucun
    //

protected:
//----------------------------------------------------- Attributs protégés
	Utilisateur* utilisateurConnecte;
	string typeCompte;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Affichage>

#endif // AFFICHAGE_H
