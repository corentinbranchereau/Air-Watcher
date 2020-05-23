/*************************************************************************
						   DataUtilisateurs  -  Classe stockant et gérant les informations des utilisateurs
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <DataUtilisateurs> (fichier DataUtilisateurs.h) ------
#if ! defined ( DATAUTILISATEURS_H )
#define DATAUTILISATEURS_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "UtilisateurProfessionnel.h"
#include "NettoyeurAir.h"
#include "CompagnieFournisseur.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataUtilisateurs>
// Cette classe va servir de stockage de tous les utilisateurs inscrits à
// l'application, et va permettre les différentes opérations possibles sur
// un compte (création, modification, connexion ...)
//
//------------------------------------------------------------------------

class DataUtilisateurs
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

    bool ChargerFournisseurs(string fichierNettoyeurs, const unordered_map<string, NettoyeurAir *> & nettoyeurs);
    // Mode d'emploi :
    // Charge le fichier de fournisseurs passé en paramètre.
    // Renvoi vrai si l'opération s'est bien passé, faux sinon
    // Contrat :
    // Aucun.


    bool ChargerUtilisateurs(string fichierUtilisateurs);
	// Mode d'emploi : Cette méthode va permettre de charger les utilisateurs
	// déja inscrits depuis le fichier fourni. Pour cela, le fichier
	// est ouvert en lecture, et construit pour chaque ligne un utilisateur.
	//
	// Contrat : Le fichier doit contenir les utilisateurs(1 par ligne) selon le bon format
	// à savoir :
	// * utilisateur privé : privé;identifiant;mdp;nom;prénom;mail;nbPoints
	// * employé agence : agence;identifiant;mdp;nom;prénom;mail;validité compte
	// * employé fournisseur : fournisseur;identifiant;mdp;nom;prénom;mail;validité compte;id compagnie
	// * admin : admin;identifiant;mdp;nom;prénom;mail
	//

    const unordered_map<string,CompagnieFournisseur*> GetFournisseurs();
    // Mode d'emploi :
    // Renvoi simplement les fournisseurs
    // Contrat :
    // Aucun

    bool VerifierUnCompte(string mail,bool validation);
	// Mode d'emploi :
	// Vérifie ou non le compte dont l'identifiant est passé en paramètre.
	// Renvoi true si tout s'est bien passé, false sinon
	// Contrat :
	// Aucun

    vector<UtilisateurProfessionnel*> ObtenirComptesEnAttente();
	// Mode d'emploi :
	// Renvoi la liste des comptes en attente d'une validation par un admin
	// Contrat :
	// Aucun

    bool GererCompte(string mail, string nom, string prenom, string mdp);
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<Utilisateur*> & GetUtilisateurs();
	// Mode d'emploi : Permet de renvoyer la liste des utilisateurs de l'application
	//
	// Contrat : Aucun
	//

	Utilisateur* TrouverUtilisateurParIdentifiant(string identifiant);
	// Mode d'emploi : Cette méthode permet de chercher et de retourner un utilisateur
	// grâce à son identifiant
	//
	// Contrat : Aucun
	//

	Utilisateur* SeConnecter(string identifiant, string mdp);
	// Mode d'emploi : Permet de chercher si un compte existe avec
	// l'identifiant et le mdp fournis, et si c'est le cas, le renvoie
	//
	// Contrat : Aucun
	//

	bool SeCreerUnComptes(string* informationsUtilisateur);
	// Mode d'emploi : Méthode qui permet la création d'un compte dans
	// l'application, c'est à dire l'ajout de l'utilisateur à l'attribut
	// 'utilisateurs' de la classe mais également son ajout dans le fichier
	// des utilisateurs. La méthode vérifie en premier que les informations
	// sont correctes
	//
	// Contrat : Le paramètre 'informationsUtilisateur' doit être un tableau
	// de string contenant dans l'ordre : type de compte, identifiant, mdp, 
	// nom, prénom, mail, id compagnie (si fournisseur)
	//


//------------------------------------------------- Surcharge d'opérateurs
	DataUtilisateurs & operator = (const DataUtilisateurs & unAffichage);
	// Mode d'emploi : Opérateur qui copie simplement les attributs de la classe
	//
	// Contrat : Aucun
	//


//-------------------------------------------- Constructeurs - destructeur

	DataUtilisateurs ();
	// Mode d'emploi : Ne fait rien de particulier
	//
	// Contrat : Aucun
	//

	virtual ~DataUtilisateurs ();
	// Mode d'emploi : Libère les utilisateurs à la destruction
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    DataUtilisateurs (const DataUtilisateurs & unAffichage);
    // Mode d'emploi (constructeur de copie) :
    // INTERDIT
    // Contrat : Aucun
    //
protected:
//----------------------------------------------------- Attributs protégés
	vector<Utilisateur*> utilisateurs;
	string cheminFichierUtilisateurs;
	unordered_map<string,CompagnieFournisseur*> CompagniesFournisseurs;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DataUtilisateurs>

#endif // DATAUTILISATEURS_H
