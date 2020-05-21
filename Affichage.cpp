/*************************************************************************
						   Affichage  -  Classe permettant l'affichage de l'application sur la console
							 -------------------
	début                : 18/04/2020
	copyright            : (C) 2020 par Killian OECHSLIN, Thomas MIGNOT, Thibaut GRAVEY, Corentin BRANCHEREAU
*************************************************************************/

//---------- Réalisation de la classe <Affichage> (fichier Affichage.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <limits>
#include <vector>
//------------------------------------------------------ Include personnel
#include "Affichage.h"
#include "Utilisateur.h"
#include "UtilisateurPrive.h"
#include "EmployeFournisseur.h"
#include "EmployeAgenceGouvernementale.h"
#include "Admin.h"
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

// type Affichage::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Affichage::NettoyerConsole()
// Algorithme : Détecte si l'utilisateur est sur Windows ou Linux et appelle la
// méthode adéquate pour nettoyer la console
//
{
	#ifdef _WIN32
	// Windows
	system("cls");
	#else
	// Linux
	system("clear");
	#endif // _WIN32
	
} //----- Fin de NettoyerConsole

void Affichage::AfficherTitre()
// Algorithme : Aucun
//
{
	cout << "\n";
	cout << "	# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # " << endl;
	cout << "	#     _    _       __        __    _       _                #" << endl;
	cout << "	#    /_\\  (_)_ __  \\ \\      / /_ _| |_ ___| |__   ___ _ __  #" << endl;
	cout << "	#   //_\\\\ | | '__|  \\ \\ /\\ / / _` | __/ __| '_ \\ / _ \\ '__| #" << endl;
	cout << "	#  / ___ \\| | |      \\ V  V / (_| | || (__| | | |  __/ |    #" << endl;
	cout << "	# /_/   \\_\\_|_|       \\_/\\_/ \\__,_|\\__\\___|_| |_|\\___|_|    #" << endl;
	cout << "	#                                                           #" << endl;
	cout << "	# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
	cout << "	Projet réalisé par : BRANCHEREAU, GRAVEY, MIGNOT, OECHSLIN\n\n";
} //----- Fin de AfficherTitre

string Affichage::Souligner(const string & chaine)
// Algorithme : Aucun
//
{
	string chaineSoulignee = chaine;
	chaineSoulignee.insert(0,"\033[4m");
	chaineSoulignee+="\033[0m";
	return chaineSoulignee;
} //----- Fin de Souligner

int Affichage::SaisirChoix(int choixMax)
// Algorithme : Vérifie que le retour de cin est correct, et
// vérifie que l'entier est compris entre 1 et choixMax
//
{
	int choix = 0;
	cout<<"Choix : ";
	while(!(cin>>choix) || choix>choixMax || choix<1)
	{
		cout<<"Veuillez saisir une option valide.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Choix : ";
	}
	return choix;
} //----- Fin de SaisirChoix

double Affichage::SaisirDouble(double choixMin,double choixMax)
// Algorithme : Vérifie que le retour de cin est correct, et
// vérifie que l'entier est compris entre 1 et choixMax
//
{
	double choix = 0;
	cout<<"Choix : ";
	while(!(cin>>choix) || choix>choixMax || choix<choixMin)
	{
		cout<<"Veuillez saisir une option valide.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Choix : ";
	}
	return choix;
} //----- Fin de SaisirChoix


int Affichage::AfficherMenuPrincipal()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	cout << "  Bienvenue dans l'application 'AirWatcher' !\n  Pour sélectionner une action, rentrez simplement le numéro correspondant.\n";
	cout<<"\n  "<<Souligner("Menu principal")<<" : \n\n";
	cout << "	1) Créer un compte.\n";
	cout << "	2) Se connecter.\n";
	cout << "	3) Quitter l'application.\n\n";

	return SaisirChoix(3);
} //----- Fin de AfficherMenuPrincipal

string* Affichage::AfficherCreationCompte()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	cout<<"  "<<Souligner("Interface de création de compte")<<" :\n\n";
	string * donneesSaisies = new string[7];
	// dans l'ordre : type de compte, identifiant, mdp, nom, prénom, mail, nom compagnie (si fournisseur)

	cout<<"Quel type de compte souhaitez vous créer ? : \n";
	cout<<"	1) Individu privé\n";
	cout<<"	2) Employé de l'agence gouvernementale\n";
	cout<<"	3) Fournisseur de nettoyeurs d'air\n\n";
	int choix = SaisirChoix(3);

	switch(choix)
	{
		case 1:
			donneesSaisies[0]="privé";
		break;

		case 2:
			donneesSaisies[0]="agence";
		break;

		case 3:
			donneesSaisies[0]="fournisseur";
		break;
	}

	cout<<"\nIdentifiant : ";
	cin>>donneesSaisies[1];
	cout<<"Mot de passe : ";
	cin>>donneesSaisies[2];
	cout<<"Nom : ";
	cin>>donneesSaisies[3];
	cout<<"Prénom : ";
	cin>>donneesSaisies[4];
	cout<<"Mail : ";
	cin>>donneesSaisies[5];
	if(choix==3)
	{
		cout<<"Compagnie : ";
		cin>>donneesSaisies[6];
	}
	else
	{
		donneesSaisies[6]="";
	}
	return donneesSaisies;

} //----- Fin de AfficherCreationCompte

void Affichage::AfficherFinCreationCompte(bool reussite)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	if(reussite)
	{
		cout<<"Le compte a été créé avec succès ! "<<endl;
	}
	else
	{
		cout<<"Une erreur s'est produite lors de la création du compte ! "<<endl;
	}
	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu principal");
	
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
	
} //----- Fin de AfficherFinCreationCompte

string* Affichage::AffichageConnexion()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	cout<<"  "<<Souligner("Interface de connexion")<<" :\n\n";
	string * donneesSaisies = new string[2];
	// dans l'ordre : identifiant, mdp

	cout<<"\nIdentifiant : ";
	cin>>donneesSaisies[0];
	cout<<"Mot de passe : ";
	cin>>donneesSaisies[1];

	return donneesSaisies;

} //----- Fin de AffichageConnexion

void Affichage::AffichageFinConnexion(string etatConnexion)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	
	if(etatConnexion=="réussite")
	{
		cout<<"La connexion a réussie ! "<<endl;
		cout<<"\nAppuyez sur 'Entrée' pour être redirigé vers le "<<Souligner("menu d'action");
	}
	else if(etatConnexion=="attente")
	{
		cout<<"Votre compte est actuellement en attente. Vous devez attendre qu'un admin le valide."<<endl;
		cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu principal");
	}
	else if(etatConnexion=="échec")
	{
		cout<<"La connexion a échouée ! "<<endl;
		cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu principal");
	}
	
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
} //----- Fin de AffichageConnexion

void Affichage::AfficherInformationsCompte()
// Algorithme : Aucun
//
{
	cout<<"	"<<Souligner("Utilisateur")<<" : "<<this->utilisateurConnecte->GetPrenom()<<" "<<this->utilisateurConnecte->GetNom();
	cout<<"   "<<Souligner("Compte de type")<<" : "<<this->typeCompte<<endl;
	if(this->typeCompte=="Utilisateur privé")
	{
		UtilisateurPrive* uPrive = dynamic_cast<UtilisateurPrive*>(this->utilisateurConnecte);
		cout<<"\n	"<<Souligner("Nombre de points")<<" : "<<uPrive->ObtenirPoints()<<endl;
	}
	else if(this->typeCompte=="Fournisseur")
	{
		EmployeFournisseur* uFournisseur = dynamic_cast<EmployeFournisseur*>(this->utilisateurConnecte);
		cout<<"\n	"<<Souligner("Compagnie")<<" : "<<uFournisseur->GetCompagnie()->getId()<<endl;
	}
} //----- Fin de AfficherInformationsCompte

int Affichage::AfficherMenuActionPrive()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Menu d'action")<<"\n\n";
	cout<<"	1) Consulter mes données rentrées.\n";
	cout<<"	2) Entrer une nouvelle donnée.\n";
	cout<<"\n	3) Modifier mon compte.\n";
	cout<<"	4) Me déconnecter.\n";
	return SaisirChoix(4);
} //----- Fin de AfficherMenuActionPrive

int Affichage::AfficherMenuActionFournisseur()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Menu d'action")<<"\n\n";
	cout<<"	1) Ajouter/Supprimer un nettoyeur d'air.\n";
	cout<<"	2) Activer/Désactiver un nettoyeur d'air.\n";
	cout<<"	3) Afficher la liste des nettoyeurs d'air de la compagnie.\n";
	cout<<"	4) Obtenir le rayon d'action d'un nettoyeur d'air.\n";
	cout<<"	5) Consulter les données brutes de l'application.\n";
	cout<<"	6) Obtenir la moyenne des données brutes d'une zone (circulaire).\n";
	cout<<"	7) Obtenir la qualité d'air moyenne d'une zone (circulaire).\n";
	cout<<"\n	8) Modifier mon compte.\n";
	cout<<"	9) Me déconnecter.\n";
	return SaisirChoix(9);
} //----- Fin de AfficherMenuActionFournisseur

int Affichage::AfficherMenuActionAgenceGouv()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Menu d'action")<<"\n\n";
	cout<<"	1) Afficher la liste de tous les capteurs.\n";
	cout<<"	2) Afficher l'état de tous les capteurs.\n";
	cout<<"	3) Identifier les capteurs ayant un comportement similaire.\n";
	cout<<"	4) Consulter les données brutes de l'application.\n";
	cout<<"	5) Obtenir la moyenne des données brutes d'une zone (circulaire).\n";
	cout<<"	6) Obtenir la qualité d'air moyenne d'une zone (circulaire).\n";
	cout<<"	7) Labelliser les données des utilisateurs privés.\n";
	cout<<"\n	8) Modifier mon compte.\n";
	cout<<"	9) Me déconnecter.\n";
	return SaisirChoix(9);
} //----- Fin de AfficherMenuActionAgenceGouv

int Affichage::AfficherMenuActionAdmin()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Menu d'action")<<"\n\n";
	cout<<"	1) Afficher la liste des comptes en attente.\n";
	cout<<"	2) Valider/Refuser la création d'un compte.\n";
	cout<<"	3) Gérer un compte.\n";
	cout<<"	4) Ajouter un capteur à l'application.\n";
	cout<<"	5) Modifier un capteur de l'application.\n";
	cout<<"\n	6) Modifier mon compte.\n";
	cout<<"	7) Me déconnecter.\n";
	return SaisirChoix(7);
} //----- Fin de AfficherMenuActionAdmin

int Affichage::CapteursSimilairesNbClassesMini(int nbClassesMax)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Identification des capteurs similaires")<<"\n\n";
	cout<<"Combien de groupe de capteurs voulez-vous au minimum ? : ";
	return SaisirChoix(nbClassesMax);
} //----- Fin de CapteursSimilairesNbClassesMini

void Affichage::PreparationConsole(string message)
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner(message)<<"\n\n";
}

Horodatage Affichage::SaisirDate(string type)
// Algorithme : Aucun
//
{	
	if(type=="")
	{
	cout<<"Quelle date voulez vous ? : "<<endl;
	}
	if(type=="début")
	{
		cout<<"Quelle date de début voulez vous ? : "<<endl;
	}

	if(type=="fin")
	{
	cout<<"Quelle date de fin voulez vous ? : "<<endl;	
	}
	
	cout <<"Quelle année ? :";
	int annee=SaisirChoix(2050);
	cout <<"Quel mois (entre 1 et 12) ? :";
	int mois=SaisirChoix(12);
	cout <<"Quel jour (entre 1 et 31) ?  :";
	int jour=SaisirChoix(31);

	Horodatage date(annee,mois,jour,0,0,0);

	return date;

} //----- Fin de SaisirDate

Zone Affichage::SaisirZone()
// Algorithme : Aucun
//
{
	cout<<"Définisez votre zone  : "<<endl;
	cout <<"Quelle longitude ? ";
	double longitude=SaisirDouble(-100,100);
	cout <<"Quelle latitude ? :";
	double latitude=SaisirDouble(-100,100);
	cout <<"Quel rayon de zone (km)?  :";
	double rayon =SaisirDouble(0.000001,numeric_limits<double>::max());

	PointGeographique p(longitude,latitude);
	Zone zone(rayon,p);

	return zone;

} //----- Fin de SaisirDate

void Affichage::DefinirUtilisateur(Utilisateur* utilisateur, string type)
// Algorithme : Aucun
//
{
	this->utilisateurConnecte = utilisateur;
	this->typeCompte = type;
} //----- Fin de SetUtilisateurConnecte

void Affichage::AfficherCapteursSimilaires(vector<vector<Capteur*>> & res)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Résultats du regroupement")<<"\n\n";

	for(int i = 0; i<res.size(); i++)
    {
		cout<<"**********************"<<endl;
        cout<<"CLASSE N° "<<(i+1)<<endl;

        for(int j = 0; j<res[i].size(); j++)
        {
            cout<<"CAPTEUR ID = "<<(*(res[i][j])).getID()<<endl;
        }
		cout<<"**********************"<<endl;
    }

	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
} //----- Fin de AfficherCapteursSimilaires

void Affichage::AfficherMoyennesPeriodePrecise(Mesure** moyennesMesure)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Resultats des moyennes journalieres des mesures")<<"\n\n";

	for(int i = 1; i<moyennesMesure[0]->getValeurAttribut()+1; i++)
    {
		Mesure* m=moyennesMesure[i];
		Horodatage date=m->getdateMesure();
		cout<<"**********************"<<endl;
       	// cout<<"JOUR n° "<<i<<endl;
		cout <<"JOUR : "<<date.GetJour()<<"/"<<date.GetMois()<<"/"<<date.GetAnnee()<<endl;

		cout<<"MOYENNE O3 : "<<m[0].getValeurAttribut()<<(m[0].getTypeMesure())->getUnite()<<endl;
		cout<<"MOYENNE SO2 : "<<m[1].getValeurAttribut()<<(m[1].getTypeMesure())->getUnite()<<endl;
		cout<<"MOYENNE NO2 : "<<m[2].getValeurAttribut()<<(m[2].getTypeMesure())->getUnite()<<endl;
		cout<<"MOYENNE PM10 : "<<m[3].getValeurAttribut()<<(m[3].getTypeMesure())->getUnite()<<endl;

		cout<<"**********************"<<endl;
    }

	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
} //----- Fin de AfficherMoyennesPeriodePrecise

void Affichage::AfficherQualitePeriodePrecise(map<Horodatage,int> mapDatesIndices)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	//cout<<"\n\n  "<<Souligner("Resultats des moyennes journalieres des mesures")<<"\n\n";

	for(auto it=mapDatesIndices.begin(); it!=mapDatesIndices.end(); it++)
    {

		Horodatage date=it->first;
		int indiceAtmo=it->second;
		cout<<"**********************"<<endl;
       	// cout<<"JOUR n° "<<i<<endl;
		cout <<"JOUR : "<<date.GetJour()<<"/"<<date.GetMois()<<"/"<<date.GetAnnee()<<endl;

		cout<<"INDICE ATMO : "<<indiceAtmo<<endl;
	

		cout<<"**********************"<<endl;
    }

	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
} //----- Fin de AfficherCapteursSimilaires

void Affichage::AfficherApresLabel()
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	//cout<<"\n\n  "<<Souligner("Resultats des moyennes journalieres des mesures")<<"\n\n";

		cout<<"**********************"<<endl;

		cout<<"DONNES FINIES DE LABELLISER : OK "<<endl;
	
		cout<<"**********************"<<endl;
    
	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
} //----- Fin de AfficherCapteursSimilaires


//------------------------------------------------- Surcharge d'opérateurs

Affichage & Affichage::operator = (const Affichage & unAffichage)
// Algorithme : Aucun
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Affichage::Affichage ()
// Algorithme : Aucun
//
:utilisateurConnecte(nullptr)
{
#ifdef MAP
	cout << "Appel au constructeur de <Affichage>" << endl;
#endif
} //----- Fin de Affichage


Affichage::~Affichage ()
// Algorithme : Aucun
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Affichage>" << endl;
#endif
} //----- Fin de ~Affichage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
