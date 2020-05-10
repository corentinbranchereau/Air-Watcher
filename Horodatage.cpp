/*************************************************************************
						   Horodatage  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Horodatage> (fichier Horodatage.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Horodatage.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Horodatage::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

double Horodatage::getTempsSecondes()
{
	return annee*365*24*3600+mois*30*24*3600+jour*24*3600+heure*3600+minute*60+seconde;
}

int Horodatage::GetAnnee()
// Algorithme :
//
{
	return this->annee;
} //----- Fin de GetAnnee

int Horodatage::GetMois()
// Algorithme :
//
{
	return this->mois;
} //----- Fin de GetMois

int Horodatage::GetJour()
// Algorithme :
//
{
	return this->jour;
} //----- Fin de GetJour

int Horodatage::GetHeure()
// Algorithme :
//
{
	return this->heure;
} //----- Fin de GetHeure

int Horodatage::GetMinute()
// Algorithme :
//
{
	return this->minute;
} //----- Fin de GetMinute

int Horodatage::GetSeconde()
// Algorithme :
//
{
	return this->seconde;
} //----- Fin de GetSeconde


//------------------------------------------------- Surcharge d'opérateurs

Horodatage & Horodatage::operator = (const Horodatage & unHorodatage)
// Algorithme :
//
{
	this->annee=unHorodatage.annee;
	this->mois=unHorodatage.mois;
	this->jour=unHorodatage.jour;
	this->heure=unHorodatage.heure;
	this->minute=unHorodatage.minute;
	this->seconde=unHorodatage.seconde;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Horodatage::Horodatage (const Horodatage & unHorodatage)
// Algorithme :
//
{
	this->annee=unHorodatage.annee;
	this->mois=unHorodatage.mois;
	this->jour=unHorodatage.jour;
	this->heure=unHorodatage.heure;
	this->minute=unHorodatage.minute;
	this->seconde=unHorodatage.seconde;
#ifdef MAP
	cout << "Appel au constructeur de copie de <Horodatage>" << endl;
#endif
} //----- Fin de Horodatage (constructeur de copie)


Horodatage::Horodatage ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Horodatage>" << endl;
#endif
} //----- Fin de Horodatage


Horodatage::Horodatage (int annee, int mois, int jour, int heure, int minute, int seconde)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Horodatage>" << endl;
#endif
	this->annee=annee;
	this->mois=mois;
	this->jour=jour;
	this->heure=heure;
	this->minute=minute;
	this->seconde=seconde;

} //----- Fin de Horodatage


Horodatage::~Horodatage ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Horodatage>" << endl;
#endif
} //----- Fin de ~Horodatage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
