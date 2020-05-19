/*************************************************************************
						   Utilisateur  -  Classe abstraite représentant un utilisateur
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Utilisateur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Utilisateur::GetNom()
// Algorithme : Aucun
//
{
	return this->nom;
} //----- Fin de GetNom

string Utilisateur::GetPrenom()
// Algorithme : Aucun
//
{
	return this->prenom;
} //----- Fin de GetPrenom

string Utilisateur::GetMail()
// Algorithme : Aucun
//
{
	return this->mail;
} //----- Fin de GetMail

string Utilisateur::GetMdp()
// Algorithme : Aucun
//
{
	return this->mdp;
} //----- Fin de GetMdp

string Utilisateur::GetIdentifiant()
// Algorithme : Aucun
//
{
	return this->identifiant;
} //----- Fin de GetIdentifiant

//------------------------------------------------- Surcharge d'opérateurs

Utilisateur & Utilisateur::operator = (const Utilisateur & unUtilisateur)
// Algorithme : Aucun
//
{
	this->identifiant=unUtilisateur.identifiant;
	this->mail=unUtilisateur.mail;
	this->mdp=unUtilisateur.mdp;
	this->nom=unUtilisateur.nom;
	this->prenom=unUtilisateur.prenom;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Utilisateur::Utilisateur ()
// Algorithme : Aucun
//
:identifiant(""),mail(""),mdp(""),nom(""),prenom("")
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (par défaut)

Utilisateur::Utilisateur (string idUtil, string mdpUtil, string nomUtil, string prenomUtil, string mailUtil)
// Algorithme : Aucun
//
:identifiant(idUtil),mdp(mdpUtil),nom(nomUtil),prenom(prenomUtil),mail(mailUtil)
{
#ifdef MAP
	cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur


Utilisateur::~Utilisateur ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
