/*************************************************************************
						   MesureUtilisateur  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <MesureUtilisateur> (fichier MesureUtilisateur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MesureUtilisateur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type MesureUtilisateur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void MesureUtilisateur::SetLabel(string lab)
// Algorithme : Aucun
//
{
	this->label = lab;
} //----- Fin de SetLabel


//------------------------------------------------- Surcharge d'opérateurs

MesureUtilisateur & MesureUtilisateur::operator = (const MesureUtilisateur & unMesureUtilisateur)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

MesureUtilisateur::MesureUtilisateur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <MesureUtilisateur>" << endl;
#endif
} //----- Fin de MesureUtilisateur

MesureUtilisateur::MesureUtilisateur(TypeAttribut* typeMesure,double valeurAttribut,string idCapteur,Horodatage dateMesure)
// Algorithme : Aucun
//
:Mesure(typeMesure,valeurAttribut,idCapteur,dateMesure),label("")
{
#ifdef MAP
	cout << "Appel au constructeur de <MesureUtilisateur>" << endl;
#endif
} //----- Fin de MesureUtilisateur


MesureUtilisateur::~MesureUtilisateur ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <MesureUtilisateur>" << endl;
#endif
} //----- Fin de ~MesureUtilisateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
