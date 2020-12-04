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

vector<MesureUtilisateur*> & UtilisateurPrive::ConsulterDonneesEntrees()
// Algorithme : Aucun
//
{
	return this->donneesEntrees;
} //----- Fin de ConsulterDonneesEntrees

void UtilisateurPrive::EntrerDonnee(MesureUtilisateur* nouvelleDonnee)
// Algorithme : Aucun
//
{
	this->donneesEntrees.push_back(nouvelleDonnee);
} //----- Fin de EntrerDonnee

void UtilisateurPrive::AjouterPoint(int nb)
// Algorithme : Aucun
//
{
	this->nbPoints += nb;
} //----- Fin de AjouterPoint

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

UtilisateurPrive::UtilisateurPrive (string idPrive, string mdpPrive, string nomPrive, string prenomPrive, string mailPrive, int pointsPrive)
// Algorithme : Aucun
//
:Utilisateur(idPrive,mdpPrive,nomPrive,prenomPrive,mailPrive), nbPoints(pointsPrive)
{
#ifdef MAP
	cout << "Appel au constructeur de <UtilisateurPrive>" << endl;
#endif
} //----- Fin de UtilisateurPrive


UtilisateurPrive::~UtilisateurPrive ()
// Algorithme : Aucun
// doit être supprimé dans DataMesures
{
#ifdef MAP
	cout << "Appel au destructeur de <UtilisateurPrive>" << endl;
#endif
/*
	vector<MesureUtilisateur*>::iterator it;
		for(it=donneesEntrees.begin(); it!=donneesEntrees.end();++it)
		{
			delete (*it);
		}*/
} //----- Fin de ~UtilisateurPrive


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
