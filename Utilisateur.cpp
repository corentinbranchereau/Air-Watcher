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

Utilisateur::Utilisateur (const Utilisateur & unUtilisateur)
// Algorithme : Aucun
//
:identifiant(unUtilisateur.identifiant),mail(unUtilisateur.mail),mdp(unUtilisateur.mdp),nom(unUtilisateur.nom),prenom(unUtilisateur.prenom)
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ()
// Algorithme : Aucun
//
:identifiant(""),mail(""),mdp(""),nom(""),prenom("")
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (par défaut)

Utilisateur::Utilisateur (string identifiant_c, string mdp_c, string nom_c, string prenom_c, string mail_c)
// Algorithme : Aucun
//
:identifiant(identifiant_c),mail(mail_c),mdp(mdp_c),nom(nom_c),prenom(prenom_c)
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
