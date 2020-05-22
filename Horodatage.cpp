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
#include <iomanip>

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
Horodatage& Horodatage::enleverJour(int nbJours)
{
	Horodatage* res= new Horodatage(*this);
	if(jour>nbJours)
	{
		res->jour-=nbJours;
		return *res;
	}
	if(mois>=2)
	{
		res->jour=(30)-(nbJours-jour);
		res->mois-=1;


	}
	else
	{
		res->annee-=1;
		res->mois=12;
		res->jour=(31)-(nbJours-jour);
	}
	return *res;
	
}


Horodatage& Horodatage::ajouterJour(int nbJours)
{
	Horodatage* res= new Horodatage(*this);

	if(nbJours+jour<30)
	{
		res->jour+=nbJours;
		return *res;
	}
	if(mois<=11)
	{
		res->jour=(nbJours+jour)-30;
		res->mois+=1;


	}
	else
	{
		res->annee+=1;
		res->mois=1;
		res->jour=(nbJours+jour)-30;
	}
	return *res;
	
}
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

void Horodatage:: setSeconde(int sec)
{
	seconde=sec;
}
void Horodatage:: setMinute(int min)
{
	minute=min;
}

void Horodatage:: setheure(int heure)
{
	this->heure=heure;
}



//------------------------------------------------- Surcharge d'opérateurs

Horodatage & Horodatage::operator = (const Horodatage & unHorodatage)
// Algorithme :compare 2 dates en fonction des attributs
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

std::ostream& operator<<(std::ostream &strm, const Horodatage &h)
{
	string sAnnee=to_string(h.annee);
	string sMois=to_string(h.mois);
	string sJour=to_string(h.jour);
	string sHeure=to_string(h.heure);
	string sMinute=to_string(h.minute);
	string sSeconde=to_string(h.seconde);

	strm << setfill('0') << setw(4)<<  h.annee << "-" 
		<< setfill('0') << setw(2) << h.mois << "-" 
		<< setfill('0') << setw(2) << h.jour << " " 
		<< setfill('0') << setw(2) << h.heure <<":" 
		<< setfill('0') << setw(2) << h.minute << ":" 
		<< setfill('0') << setw(2) << h.seconde;
	return strm;
}


bool Horodatage::operator >= (const Horodatage & unHorodatage) const
// Algorithme : renvoie true si la date en paramètre est avant celle qui appelle la méthode ou égale
//
{	bool res=false;

	if(this->annee>unHorodatage.annee)
	{
		return true;
	}

	if(this->annee==unHorodatage.annee && mois>unHorodatage.mois)
	{
		return true;
	}

	if(this->annee==unHorodatage.annee && mois==unHorodatage.mois && jour>unHorodatage.jour)
	{
		return true;
	}

	if(this->annee==unHorodatage.annee && mois==unHorodatage.mois && jour==unHorodatage.jour && heure>unHorodatage.heure)
	{
		return true;
	}

	if(this->annee==unHorodatage.annee && mois==unHorodatage.mois && jour==unHorodatage.jour && heure==unHorodatage.heure &&minute>unHorodatage.minute )
	{
		return true;
	}
	if(this->annee==unHorodatage.annee && mois==unHorodatage.mois && jour==unHorodatage.jour && heure==unHorodatage.heure &&minute==unHorodatage.minute&& seconde>=unHorodatage.seconde )
	{
		return true;
	}
	return false;

} //----- Fin de operator >=


bool Horodatage::operator == (const Horodatage & unHorodatage) const
// Algorithme : renvoie true si la date en paramètre est égale 
//
{	
	if(this->annee==unHorodatage.annee && mois==unHorodatage.mois && jour==unHorodatage.jour && heure==unHorodatage.heure &&minute==unHorodatage.minute&& seconde==unHorodatage.seconde )
	{
		return true;
	}
	return false;

} //----- Fin de operator >=

bool Horodatage::less(const Horodatage & unHorodatage) const
// Algorithme : joue le rôle de l'opérateur <
//
{	
	return !((*this)>=unHorodatage);
} //----- Fin de less

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
