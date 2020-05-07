/*************************************************************************
						   UtilisateurPrive  -  Classe représentant un utilisateur privé de l'application
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <UtilisateurPrive> (fichier UtilisateurPrive.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UtilisateurPrive.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type UtilisateurPrive::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int UtilisateurPrive::ObtenirPoints()
// Algorithme : Aucun
//
{
	return this->nbPoints;
} //----- Fin de ObtenirPoints

vector<MesureUtilisateur*> UtilisateurPrive::ConsulterDonneesEntrees()
// Algorithme : Aucun
//
{
	return donneesEntrees;
} //----- Fin de ConsulterDonneesEntrees

//------------------------------------------------- Surcharge d'opérateurs

UtilisateurPrive & UtilisateurPrive::operator = (const UtilisateurPrive & unUtilisateurPrive)
// Algorithme : Aucun
//
{
	this->identifiant=unUtilisateurPrive.identifiant;
	this->mail=unUtilisateurPrive.mail;
	this->mdp=unUtilisateurPrive.mdp;
	this->nom=unUtilisateurPrive.nom;
	this->prenom=unUtilisateurPrive.prenom;
	this->nbPoints=unUtilisateurPrive.nbPoints;
	this->donneesEntrees=unUtilisateurPrive.donneesEntrees;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

UtilisateurPrive::UtilisateurPrive ()
// Algorithme : Aucun
//
:nbPoints(0)
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de UtilisateurPrive (par défaut)

UtilisateurPrive::UtilisateurPrive (string identifiant_c, string mdp_c, string nom_c, string prenom_c, string mail_c)
// Algorithme : Aucun
//
:Utilisateur(identifiant_c,mdp_c,nom_c,prenom_c,mail_c), nbPoints(0)
{
#ifdef MAP
	cout << "Appel au constructeur de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de UtilisateurPrive


UtilisateurPrive::~UtilisateurPrive ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de ~UtilisateurPrive


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
