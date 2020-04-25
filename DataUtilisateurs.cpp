/*************************************************************************
						   DataUtilisateurs  -  Classe stockant et gérant les informations des utilisateurs
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <DataUtilisateurs> (fichier DataUtilisateurs.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "DataUtilisateurs.h"
#include "UtilisateurProfessionnel.h"
#include "Utilisateur.h"
#include "UtilisateurPrive.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
vector<Utilisateur*> DataUtilisateurs::utilisateurs; // initialisation de la variable static
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataUtilisateurs::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataUtilisateurs::ChargerUtilisateurs(string fichierUtilisateurs)
// Algorithme : La méthode ouvre en lecture le fichier, et lis pour chaque ligne
// les informations successives de l'utilisateur, puis l'ajoute à la liste
// des utilisateurs
//
{
	ifstream fUtilisateurs(fichierUtilisateurs);

	if(!fUtilisateurs.is_open())
	{
		return false;
	}

	string informationsLues[7];
	char charLecture[100]; // buffer de lecture
	while(fUtilisateurs)
	{
		fUtilisateurs.getline(charLecture,100,'|');
		if(!fUtilisateurs) // on vérifie si on a atteint la fin du fichier
		{
			break;
		}
		informationsLues[0]=charLecture;

		for(int i=1;i<6;i++) // on lit les informations une à une
		{
			fUtilisateurs.getline(charLecture,100,'|');
			informationsLues[i]=charLecture;
		}
		if(informationsLues[0]=="fournisseur" || informationsLues[0]=="prive") // si c'est un compte fournisseur, on lit le nom de la compagnie ; si c'est un compte privé, on lit l'id
		{
			fUtilisateurs.getline(charLecture,100);
			informationsLues[6]=charLecture;
		}

		
		// insertion dans la liste des utilisateurs
		Utilisateur* utilisateurLu;
		// on détecte d'abord le type
		if(informationsLues[0]=="prive")
		{
			utilisateurLu = new UtilisateurPrive(informationsLues[1],informationsLues[2],informationsLues[3],informationsLues[4],informationsLues[5],informationsLues[6]); 
			DataUtilisateurs::utilisateurs.push_back(utilisateurLu);
		}
		else if(informationsLues[0]=="agence")
		{

		}
		else
		{
			
		}
		
	}

} //----- Fin de ChargerUtilisateurs

bool DataUtilisateurs::VerifierUnCompte(string mail,bool validation)
// Algorithme :
//
{

} //----- Fin de VerifierUnCompte

vector<UtilisateurProfessionnel*> DataUtilisateurs::ObtenirComptesEnAttente()
// Algorithme :
//
{

} //----- Fin de ObtenirComptesEnAttente

bool DataUtilisateurs::GererCompte(string mail, string nom, string prenom, string mdp)
// Algorithme :
//
{

} //----- Fin de GererCompte

vector<Utilisateur*> DataUtilisateurs::GetUtilisateurs()
// Algorithme :
//
{

} //----- Fin de GetUtilisateurs

Utilisateur* DataUtilisateurs::SeConnecter(string identifiant, string mdp)
// Algorithme :
//
{

} //----- Fin de SeConnecter

bool DataUtilisateurs::SeCreerUnComptes(string* informationsUtilisateur)
// Algorithme :
//
{

} //----- Fin de SeCreerUnComptes

//------------------------------------------------- Surcharge d'opérateurs

DataUtilisateurs & DataUtilisateurs::operator = (const DataUtilisateurs & unDataUtilisateurs)
// Algorithme : Aucun
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataUtilisateurs::DataUtilisateurs (const DataUtilisateurs & unDataUtilisateurs)
// Algorithme :Aucun
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataUtilisateurs>" << endl;
#endif
} //----- Fin de DataUtilisateurs (constructeur de copie)


DataUtilisateurs::DataUtilisateurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DataUtilisateurs>" << endl;
#endif
} //----- Fin de DataUtilisateurs


DataUtilisateurs::~DataUtilisateurs ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataUtilisateurs>" << endl;
#endif
} //----- Fin de ~DataUtilisateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
