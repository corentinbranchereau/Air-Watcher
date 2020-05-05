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
//------------------------------------------------------ Include personnel
#include "Affichage.h"
#include "UtilisateurPrive.h"
#include "EmployeFournisseur.h"

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

void Affichage::AfficherInformationsCompte(string type, Utilisateur* utilisateur)
// Algorithme : Aucun
//
{
	cout<<"	"<<Souligner("Utilisateur")<<" : "<<utilisateur->GetPrenom()<<" "<<utilisateur->GetNom();
	cout<<"   "<<Souligner("Compte de type")<<" : "<<type<<endl;
	if(type=="Utilisateur privé")
	{
		UtilisateurPrive* uPrive = dynamic_cast<UtilisateurPrive*>(utilisateur);
		cout<<"\n	"<<Souligner("Nombre de points")<<" : "<<uPrive->ObtenirPoints()<<endl;
	}
	else if(type=="Fournisseur")
	{
		EmployeFournisseur* uFournisseur = dynamic_cast<EmployeFournisseur*>(utilisateur);
		cout<<"\n	"<<Souligner("Compagnie")<<" : "<<endl;			// A COMPLETER -------------
	}
} //----- Fin de AfficherInformationsCompte

int Affichage::AfficherMenuActionPrive(UtilisateurPrive* utilisateur)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte("Utilisateur privé",utilisateur);
	cout<<"\n\n  "<<Souligner("Menu d'action")<<"\n\n";
	cout<<"	1) Consulter mes données rentrées.\n";
	cout<<"	2) Entrer une nouvelle donnée.\n";
	cout<<"\n	3) Modifier mon compte.\n";
	cout<<"	4) Me déconnecter.\n";
	return SaisirChoix(4);
} //----- Fin de AfficherMenuActionPrive


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
