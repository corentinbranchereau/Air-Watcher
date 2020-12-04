/*************************************************************************
						   UtilisateurProfessionnel  -  Classe représentant un utilisateur professionnel de l'application
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <UtilisateurProfessionnel> (fichier UtilisateurProfessionnel.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UtilisateurProfessionnel.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type UtilisateurProfessionnel::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool UtilisateurProfessionnel::GetCompteValide()
// Algorithme : Aucun
//
{
	return this->compteValide;
} //----- Fin de GetCompteValide

void UtilisateurProfessionnel::setCompteValide(bool compteValide)
// Algorithme : Aucun
{
    this->compteValide = compteValide;
} // ----- Fin de setCompteValide

//------------------------------------------------- Surcharge d'opérateurs

UtilisateurProfessionnel & UtilisateurProfessionnel::operator = (const UtilisateurProfessionnel & unUtilisateurProfessionnel)
// Algorithme : Aucun
//
{
	this->identifiant = unUtilisateurProfessionnel.identifiant;
	this->mail = unUtilisateurProfessionnel.mail;
	this->mdp = unUtilisateurProfessionnel.mdp;
	this->nom = unUtilisateurProfessionnel.nom;
	this->prenom = unUtilisateurProfessionnel.prenom;
	this->compteValide = unUtilisateurProfessionnel.compteValide;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

UtilisateurProfessionnel::UtilisateurProfessionnel ()
// Algorithme : Aucun
//
:compteValide(false)
{
#ifdef MAP
	cout << "Appel au constructeur (par défaut) de <UtilisateurProfessionnel>" << endl;
#endif
} //----- Fin de UtilisateurProfessionnel (par défaut)

UtilisateurProfessionnel::UtilisateurProfessionnel(string idPro,string mdpPro,string nomPro,string prenomPro,string mailPro, bool validPro)
// Algorithme : Aucun
//
:Utilisateur(idPro,mdpPro,nomPro,prenomPro,mailPro),compteValide(validPro)
{

} //----- Fin de UtilisateurProfessionnel


UtilisateurProfessionnel::~UtilisateurProfessionnel ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <UtilisateurProfessionnel>" << endl;
#endif
} //----- Fin de ~UtilisateurProfessionnel


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
