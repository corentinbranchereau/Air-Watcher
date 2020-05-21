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
#include <algorithm>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "DataUtilisateurs.h"
#include "UtilisateurProfessionnel.h"
#include "Utilisateur.h"
#include "UtilisateurPrive.h"
#include "EmployeAgenceGouvernementale.h"
#include "EmployeFournisseur.h"
#include "Admin.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type DataUtilisateurs::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool DataUtilisateurs::ChargerFournisseurs(string fichierFournisseurs, const unordered_map<string, NettoyeurAir *> & nettoyeurs)
// Algorithme :
// Charge le fichier provider.csv en le lisant ligne par ligne et en créant les fournisseurs
// tout en maintenant à jour la liste des fournisseurs et leur liste de nettoyeurs via la structure donnée en paramètre
// Si un fournisseur existe déjà, on lui ajoute simplement le nettoyeur associé
// Si un des nettoyeurs n'existe pas, renvoi une erreur sur cerr et annule le chargement
{
    ifstream fFournisseurs(fichierFournisseurs);

    if(!fFournisseurs.is_open())
    {
        cerr<<"Erreur lors du chargement des fournisseurs"<<endl;
        return false;
    }

    while(!fFournisseurs.eof())
    {

        char idFournisseur[100];
        char idCleaner[100];
        char tampon[100];

        fFournisseurs.getline(idFournisseur,100,';');
        fFournisseurs.getline(idCleaner,100,';');
        fFournisseurs.getline(tampon,100,'\n');
        if(!string(idFournisseur).empty()) {

            CompagnieFournisseur *fournisseur = new CompagnieFournisseur(string(idFournisseur));

            //Insérer le fournisseur, et vérifier s'il existait ou non dans la map
            pair<unordered_map<string, CompagnieFournisseur *>::iterator, bool> ret = CompagniesFournisseurs.insert(
                    make_pair(string(idFournisseur), fournisseur));

            //S'il existe, on le delete et on récupère celui déjà présent
            if (!ret.second)
                delete fournisseur;

            fournisseur = ret.first->second;

            //Si le cleaner n'existe pas
            if (nettoyeurs.find(string(idCleaner)) == nettoyeurs.end()) {
                cerr << "Erreur lors du chargement des nettoyeurs, le nettoyeur " + string(idCleaner) +
                        " de providers.csv n'existe pas dans les données de cleaners.csv" << endl;
                return false;
            }

            NettoyeurAir *nettoyeur = nettoyeurs.find(string(idCleaner))->second;
            fournisseur->addNettoyeur(nettoyeur);
        }
    }

    return true;

} // ------ Fin de chargerNettoyeurs

bool DataUtilisateurs::ChargerUtilisateurs(string fichierUtilisateurs)
// Algorithme : La méthode ouvre en lecture le fichier, et lis pour chaque ligne
// les informations successives de l'utilisateur, puis l'ajoute à la liste
// des utilisateurs
//
{
	ifstream fUtilisateurs(fichierUtilisateurs);

	if(!fUtilisateurs.is_open())
	{
		cerr<<"Erreur lors du chargement des utilisateurs"<<endl;
		return false;
	}
	else
	{
		this->cheminFichierUtilisateurs = fichierUtilisateurs;
		string informationsLues[8];
		char charLecture[100]; // buffer de lecture
		while(fUtilisateurs)
		{
			fUtilisateurs.getline(charLecture,100,';');
			if(!fUtilisateurs) // on vérifie si on a atteint la fin du fichier
			{
				break;
			}
			informationsLues[0]=charLecture;

			for(int i=1;i<8;i++) // on lit les informations une à une
			{
				if(i==5 && informationsLues[0]=="admin")
				{
					fUtilisateurs.getline(charLecture,100,'\n');
					informationsLues[i] = charLecture;
					break;
				}
				else if(i==6 && (informationsLues[0]=="privé" || informationsLues[0]=="agence"))
				{
					fUtilisateurs.getline(charLecture,100,'\n');
					informationsLues[i] = charLecture;
					break;
				}
				else if(i==7) // dans le cas d'un fournisseur
				{
					fUtilisateurs.getline(charLecture,100,'\n');
					informationsLues[i] = charLecture;
					break;
				}
				else
				{
					fUtilisateurs.getline(charLecture,100,';');
					informationsLues[i] = charLecture;
				}
			}

			
			// insertion dans la liste des utilisateurs
			Utilisateur* utilisateurLu;
			// on détecte d'abord le type
			if(informationsLues[0]=="privé")
			{
				// nb de points
				int nbPoints;
				stringstream ssConversion;
				ssConversion<<informationsLues[6];
				ssConversion>>nbPoints;

				utilisateurLu = new UtilisateurPrive(informationsLues[1],informationsLues[2],informationsLues[3],informationsLues[4],informationsLues[5],nbPoints); 
			}
			else if(informationsLues[0]=="agence")
			{
				bool compteValide = (informationsLues[6]=="valide");
				utilisateurLu = new EmployeAgenceGouvernementale(informationsLues[1],informationsLues[2],informationsLues[3],informationsLues[4],informationsLues[5],compteValide);
			}
			else if(informationsLues[0]=="fournisseur")
			{
				// on recherche la compagnie
				CompagnieFournisseur * compagnie = this->CompagniesFournisseurs.find(informationsLues[7])->second;

				bool compteValide = (informationsLues[6]=="valide");

				utilisateurLu = new EmployeFournisseur(informationsLues[1],informationsLues[2],informationsLues[3],informationsLues[4],informationsLues[5],compteValide,compagnie);;
			}
			else // admin
			{
				utilisateurLu = new Admin(informationsLues[1],informationsLues[2],informationsLues[3],informationsLues[4],informationsLues[5]);
			}
			
			this->utilisateurs.push_back(utilisateurLu);
			
		}
	}

	return true;

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

vector<Utilisateur*> & DataUtilisateurs::GetUtilisateurs()
// Algorithme : Aucun
//
{
	return this->utilisateurs;
} //----- Fin de GetUtilisateurs

const unordered_map<string, CompagnieFournisseur *> DataUtilisateurs::GetFournisseurs()
// Algorithme : Aucun
{
    return this->CompagniesFournisseurs;
} //------ Fin de GetFournisseurs

Utilisateur* DataUtilisateurs::SeConnecter(string identifiant, string mdp)
// Algorithme : Vérifie dans la liste des utilisateurs si les informations
// données correspondent à un utilisateur
//
{
	vector<Utilisateur*>::iterator it;
	for(it=this->utilisateurs.begin();it!=this->utilisateurs.end();++it)
	{
		if((*it)->GetIdentifiant()==identifiant && (*it)->GetMdp()==mdp)
		{
			return (*it);
		}
	}
	// non trouvé
	return nullptr;
} //----- Fin de SeConnecter

bool DataUtilisateurs::SeCreerUnComptes(string* informationsUtilisateur)
// Algorithme : Aucun
//
{
	string typeCompte = informationsUtilisateur[0];
	Utilisateur* utilisateurCree;

	// vérification de l'unicité de l'identifiant et du mail
	vector<Utilisateur*>::iterator it;
	for(it=this->utilisateurs.begin();it!=this->utilisateurs.end();++it)
	{
		if((*it)->GetIdentifiant()==informationsUtilisateur[1] || (*it)->GetMail()==informationsUtilisateur[5])
		{
			// donnée(s) non unique(s)
			return false;
		}
	}

	if(typeCompte=="privé")
	{
		utilisateurCree = new UtilisateurPrive(informationsUtilisateur[1],informationsUtilisateur[2],informationsUtilisateur[3],informationsUtilisateur[4],informationsUtilisateur[5],0);
	}
	else if(typeCompte=="fournisseur")
	{
		// recherche compagnie
		CompagnieFournisseur * compagnie = this->CompagniesFournisseurs.find(informationsUtilisateur[6])->second;

		utilisateurCree = new EmployeFournisseur(informationsUtilisateur[1],informationsUtilisateur[2],informationsUtilisateur[3],informationsUtilisateur[4],informationsUtilisateur[5],false,compagnie);
	}
	else if(typeCompte=="agence")
	{
		utilisateurCree = new EmployeAgenceGouvernementale(informationsUtilisateur[1],informationsUtilisateur[2],informationsUtilisateur[3],informationsUtilisateur[4],informationsUtilisateur[5],false);
	}
	else // admin
	{
		utilisateurCree = new Admin(informationsUtilisateur[1],informationsUtilisateur[2],informationsUtilisateur[3],informationsUtilisateur[4],informationsUtilisateur[5]);
	}

	this->utilisateurs.push_back(utilisateurCree);


	// écriture dans le fichier du nouvel utilisateur
	ofstream fUtilisateurs(cheminFichierUtilisateurs,std::ofstream::app);
	if(!fUtilisateurs.is_open())
	{
		cerr<<"Erreur lors de l'écriture d'un nouvel utilisateur"<<endl;
		return false;
	}
	else
	{
		//construction de la ligne à écrire
		string ligneUtilisateur="";
		for(int i=0;i<8;i++)
		{

			if(i<=5)
			{
				ligneUtilisateur+=informationsUtilisateur[i];

				if(typeCompte=="admin" && i==5)
				{
					ligneUtilisateur+='\n';
					break;
				}
				ligneUtilisateur+=';';
			}

			if(i==6)
			{
				if(typeCompte=="privé")
				{
					ligneUtilisateur+='0';
					ligneUtilisateur+='\n';
					break;
				}
				else // agence et fournisseur
				{
					ligneUtilisateur+="attente";

					if(typeCompte=="agence")
					{
						ligneUtilisateur+='\n';
						break;
					}
					ligneUtilisateur+=';';
				}
			}

			if(i==7) // fournisseur
			{
				ligneUtilisateur+= informationsUtilisateur[6];
				ligneUtilisateur+='\n';
			}
		}
		
		fUtilisateurs<<ligneUtilisateur;
	}

	return true;	
} //----- Fin de SeCreerUnComptes

Utilisateur* DataUtilisateurs::TrouverUtilisateurParIdentifiant(string identifiant)
// Algorithme : Regarde pour chaque utilisateur si son identifiant correspond avec celui
// passé en paramètre
//
{
	vector<Utilisateur*>::iterator it;
	for(it=this->utilisateurs.begin();it<this->utilisateurs.end();++it)
	{
		if((*it)->GetIdentifiant()==identifiant)
		{
			return (*it);
		}
	}
	return nullptr; // utilisateur non trouvé
} //----- Fin de SeCreerUnComptes

//------------------------------------------------- Surcharge d'opérateurs

DataUtilisateurs & DataUtilisateurs::operator = (const DataUtilisateurs & unDataUtilisateurs)
// Algorithme : Aucun
//
{
	this->utilisateurs = unDataUtilisateurs.utilisateurs;
	this->cheminFichierUtilisateurs = unDataUtilisateurs.cheminFichierUtilisateurs;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

DataUtilisateurs::DataUtilisateurs ()
// Algorithme : Aucun
//
:cheminFichierUtilisateurs("")
{
#ifdef MAP
	cout << "Appel au constructeur de <DataUtilisateurs (par défaut)>" << endl;
#endif
} //----- Fin de DataUtilisateurs (par défaut)

DataUtilisateurs::~DataUtilisateurs ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataUtilisateurs>" << endl;
#endif
	// on libère tous les utilisateurs en parcourant 'utilisateurs' avec un itérateur
	vector<Utilisateur*>::iterator it;
	for(it=utilisateurs.begin(); it!=utilisateurs.end();++it)
	{
		delete (*it);
	}

	unordered_map<string,CompagnieFournisseur*>::iterator itF;
	for(itF=CompagniesFournisseurs.begin(); itF!=CompagniesFournisseurs.end();++it)
        delete (itF->second);

} //----- Fin de ~DataUtilisateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
