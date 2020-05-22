/*************************************************************************
						   Horodatage  -  description
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Interface de la classe <Horodatage> (fichier Horodatage.h) ------
#if ! defined ( HORODATAGE_H )
#define HORODATAGE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Horodatage>
//
//
//------------------------------------------------------------------------

class Horodatage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Horodatage & enleverJour(int nbJours);

	Horodatage & ajouterJour(int nbJours);
	
	double getTempsSecondes();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setSeconde(int sec);

	void setMinute(int min);

	void setheure(int heure);
	
	int GetAnnee();
	// Mode d'emploi : Retourne l'attribut annee
	//
	// Contrat : Aucun
	//

	int GetMois();
	// Mode d'emploi : Retourne l'attribut mois
	//
	// Contrat : Aucun
	//

	int GetJour();
	// Mode d'emploi : Retourne l'attribut jour
	//
	// Contrat : Aucun
	//

	int GetHeure();
	// Mode d'emploi : Retourne l'attribut heure
	//
	// Contrat : Aucun
	//

	int GetMinute();
	// Mode d'emploi : Retourne l'attribut minute
	//
	// Contrat : Aucun
	//

	int GetSeconde();
	// Mode d'emploi : Retourne l'attribut seconde
	//
	// Contrat : Aucun
	//

//------------------------------------------------- Surcharge d'opérateurs
	Horodatage & operator = (const Horodatage & unHorodatage);
	// Mode d'emploi : 
	//
	// Contrat :
	//
	
	bool operator >= (const Horodatage & unHorodatage) const;

	bool operator == (const Horodatage & unHorodatage) const;

	bool less (const Horodatage & unHorodatage) const;
	// Mode d'emploi : permet de comparer 2 dates
	//
	// Contrat :
	//

	friend ostream& operator<<(std::ostream&, const Horodatage &h);
	


//-------------------------------------------- Constructeurs - destructeur
	Horodatage (const Horodatage & unHorodatage);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Horodatage ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Horodatage (int annee, int mois, int jour, int heure, int minute, int seconde);
	// Mode d'emploi :
	//
	// Contrat :
	//



	virtual ~Horodatage ();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	int annee;
	int mois;
	int jour;
	int heure;
	int minute;
	int seconde;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Horodatage>

#endif // HORODATAGE_H
