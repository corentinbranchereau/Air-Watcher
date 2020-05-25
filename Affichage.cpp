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
#include "MesureUtilisateur.h"
#include "Horodatage.h"
#include "Mesure.h"

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
	else if(type=="début")
	{
		cout<<"Quelle "<<Souligner("date de début")<<" voulez vous ? : \n"<<endl;
	}
	else if(type=="fin")
	{
		cout<<"\nQuelle "<<Souligner("date de fin")<<" voulez vous ? : \n"<<endl;
	}
	
	cout<<"Quelle année ? ";
	int annee=SaisirChoix(2050);
	cout<<"Quel mois (entre 1 et 12) ? ";
	int mois=SaisirChoix(12);
	cout<<"Quel jour (entre 1 et 31) ?  ";
	int jour=SaisirChoix(31);

	Horodatage date(annee,mois,jour,0,0,0);

	return date;

} //----- Fin de SaisirDate

Zone Affichage::SaisirZone()
// Algorithme : Aucun
//
{
	cout<<"Définissez votre zone  : "<<endl;
	cout<<"Quelle latitude ? ";
	double latitude=SaisirDouble(-100,100);
    cout<<"Quelle longitude ? ";
    double longitude=SaisirDouble(-100,100);
	cout<<"Quel rayon de zone (km)? ";
	double rayon =SaisirDouble(0.000001,numeric_limits<double>::max());

	PointGeographique p(longitude,latitude);
	Zone zone(rayon,p);

	return zone;

} //----- Fin de SaisirZone

double Affichage::SaisirValeur(string attribut)
// Algorithme : Aucun
//
{
	cout<<"Saisissez la valeur pour la mesure de type : "<<attribut<<endl;
    double valeur=SaisirDouble(numeric_limits<double>::min(),numeric_limits<double>::max());
	return valeur;


}//----- Fin de SaisirValeur

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

void Affichage::AfficherConfirmation(string message)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	//cout<<"\n\n  "<<Souligner("Resultats des moyennes journalieres des mesures")<<"\n\n";

		cout<<"**********************"<<endl;

		cout<<message<< " : OK "<<endl;
	
		cout<<"**********************"<<endl;
    
	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();
} //----- Fin de AfficherConfirmation

void Affichage::AfficherDonnesUtilisateurPrive(Horodatage debut, Horodatage fin)
// Algorithme : Aucun
//
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Consultation de vos données entrées")<<"\n\n";

	UtilisateurPrive * uPrive = dynamic_cast<UtilisateurPrive*>(this->utilisateurConnecte);
	
	// /!\ on considère que les données sont pas groupe de 4 (une pour chaque attribut) /!\

	vector<MesureUtilisateur*>::iterator it;
	for(it=uPrive->ConsulterDonneesEntrees().begin();it<uPrive->ConsulterDonneesEntrees().end();++it)
	{
		// on affiche la mesure uniquement si elle est dans l'intervalle de temps donné
		bool apresDebut = ((*it)->getdateMesure().GetJour()>=debut.GetJour()) && ((*it)->getdateMesure().GetMois()>=debut.GetMois()) && ((*it)->getdateMesure().GetAnnee()>=debut.GetAnnee());
		bool avantFin = ((*it)->getdateMesure().GetJour()<=fin.GetJour()) && ((*it)->getdateMesure().GetMois()<=fin.GetMois()) && ((*it)->getdateMesure().GetAnnee()<=fin.GetAnnee());

		if(apresDebut && avantFin)
		{
			cout<<" "<<Souligner("Jour")<<" : "<<(*it)->getdateMesure().GetJour()<<"/"<<(*it)->getdateMesure().GetMois()<<"/"<<(*it)->getdateMesure().GetAnnee()<<endl;

			for(int n=0;n<4;n++)
			{
				cout<<" "<<(*it)->getTypeMesure()->getIdAttribut()<<" : "<<(*it)->getValeurAttribut()<<" "<<(*it)->getTypeMesure()->getUnite()<<endl;
				if(n!=3)
				{
					++it;
				}
			}
			cout<<"\n";
		}
	}

	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();

} //----- Fin de AfficherDonnesUtilisateurPrive

void Affichage::AfficherDonneesBrutes(Horodatage debut, Horodatage fin, vector<Mesure*> & mesures)
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Consultation des données brutes de l'application")<<"\n\n";

	// /!\ on considère que les données sont pas groupe de 4 (une pour chaque attribut) /!\

	vector<Mesure*>::iterator it;

	for(it=mesures.begin();it<mesures.end();++it)
	{
		// on affiche la mesure uniquement si elle est dans l'intervalle de temps donné
		bool apresDebut = ((*it)->getdateMesure().GetJour()>=debut.GetJour()) && ((*it)->getdateMesure().GetMois()>=debut.GetMois()) && ((*it)->getdateMesure().GetAnnee()>=debut.GetAnnee());
		bool avantFin = ((*it)->getdateMesure().GetJour()<=fin.GetJour()) && ((*it)->getdateMesure().GetMois()<=fin.GetMois()) && ((*it)->getdateMesure().GetAnnee()<=fin.GetAnnee());

		if(apresDebut && avantFin)
		{
			cout<<" "<<Souligner("Jour")<<" : "<<(*it)->getdateMesure().GetJour()<<"/"<<(*it)->getdateMesure().GetMois()<<"/"<<(*it)->getdateMesure().GetAnnee()<<endl;

			for(int n=0;n<4;n++)
			{
				cout<<" "<<(*it)->getTypeMesure()->getIdAttribut()<<" : "<<(*it)->getValeurAttribut()<<" "<<(*it)->getTypeMesure()->getUnite()<<endl;
				if(n!=3)
				{
					++it;
				}
			}
			cout<<"\n";
		}
	}

	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();

}

void Affichage::AfficherNettoyeursCompagnie(vector<NettoyeurAir *> & nettoyeurs, bool actif, bool inactif, bool fin)
//Algorithme : Aucun en particulier, uniquement de l'affichage
{
    bool needCheck = false;

    if(actif && inactif)
    {
        cout<<"  === "<<"Liste des nettoyeurs d'air de votre compagnie"<<" ===\n"<<endl;
    }
    else if(actif)
    {
        cout<<"  === "<<"Liste des nettoyeurs actifs de votre compagnie"<<" ===\n"<<endl;
        needCheck = true;
    }
    else if(inactif)
    {
        cout<<"  === "<<"Liste des nettoyeurs inactifs de votre compagnie"<<" ===\n"<<endl;
        needCheck = true;
    }


    vector<NettoyeurAir *>::iterator it;

    for(it=nettoyeurs.begin(); it<nettoyeurs.end(); ++it)
    {
        //On affiche le nettoyeur seulement s'il correspond bien à l'état voulu
        NettoyeurAir* net = (*it);

        if(needCheck)
        {
            if(actif && !net->getActif()) { continue; }
            else if(inactif && net->getActif()) { continue; }
        }

        string etat;
        if(net->getActif())
            etat = "actif";
        else
            etat = "inactif";

        cout << " * " << Souligner("ID") << " : " << net->getID();
        cout << " | " << Souligner ("Latitude") << " : " << net->getPosition().getLatitude();
        cout << " | " << Souligner ("Longitude") << " : " << net->getPosition().getLongitude();
        cout << " | " << Souligner ("Mise en service") << " : " << net->getDebutActivite().GetJour() << "/" << net->getDebutActivite().GetMois() << "/" << net->getDebutActivite().GetAnnee();
        cout << " | " << Souligner ("Etat") << " : " << etat << endl;
        cout << "\n";
    }
    cout<<"  === "<<"Fin de la liste"<<" ==="<<"\n\n";

    if(actif && inactif && fin)
    {
        cout << "\nAppuyez sur 'Entrée' pour revenir au " << Souligner("menu d'action");
        //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cin.ignore();
    }
} // ------ Fin de AfficherNettoyeursCompagnie

void Affichage:: AfficherRayonAction(double rayon, double rayonMax, string idNettoyeur)
//Algorithme : vérifie si rayon>rayonMax alors le rayon obtenu est le rayon maximum théorique
{
	NettoyerConsole();
	AfficherTitre();
	AfficherInformationsCompte();
	cout<<"\n\n  "<<Souligner("Affichage du rayon d'action d'un nettoyeur d'air")<<"\n\n";
	if(rayon<rayonMax)
	{
	cout << "\n Le nettoyeur " << idNettoyeur << " a un rayon d'action de "<< Souligner(to_string(rayon))<<" km"<<endl;
	}
	else
	{
		cout << "\n Le nettoyeur " << idNettoyeur << " a un rayon d'action inférieur à "<< Souligner(to_string(rayon-2*rayonMax))<<" km"<<endl;
		cout<<" \n Il manquait des mesures plus proches du nettoyeur pour être plus précis"<<endl;
	}


	cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
	//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	cin.ignore();

}
// ------ Fin de AfficherRayonAction

int Affichage::AfficherMenuAjoutSuppressionNettoyeur()
// Algorithme : Aucun
//
{
    cout<<"Que voulez-vous faire ?"<<endl;

    cout<<"	1) Ajouter un nettoyeur d'air.\n";
    cout<<"	2) Supprimer un nettoyeur d'air.\n";
    cout<<"	3) Retour au menu principal.\n";
    return SaisirChoix(3);
} //----- Fin de AfficherMenuAjoutSuppressionNettoyeur

int Affichage::AfficherMenuActiverDesactiverNettoyeur()
// Algorithme : Aucun
//
{
    cout<<"Que voulez-vous faire ?" <<endl;

    cout<<"	1) Activer un nettoyeur d'air.\n";
    cout<<"	2) Désactiver un nettoyeur d'air.\n";
    cout<<"	3) Retour au menu principal.\n";
    return SaisirChoix(3);
} //----- Fin de AfficherMenuAjoutSuppressionNettoyeur

void Affichage::AfficherAjouterNettoyeur(DataNettoyeurs & dataNettoyeurs, CompagnieFournisseur & compagnieFournisseur, PointGeographique & p)
// Algorithme : Aucun
//
{

    Horodatage debut(-1,-1,-1,-1,-1,-1);
    Horodatage fin(-1,-1,-1,-1,-1,-1);
    NettoyeurAir* newNettoyeur = new NettoyeurAir(false,0.0,debut,fin,"","",p);

    bool res = dataNettoyeurs.AjouterNettoyeur(*newNettoyeur,compagnieFournisseur);

    if(res)
        cout << "\nLe nettoyeur position [" << p.getLatitude() << "," << p.getLongitude() << "] à bien été ajouté !" <<endl;
    else
        cout << "\nERREUR ! Le nettoyeur position [" << p.getLatitude() << "," << p.getLongitude() << "] n'à pas pu être ajouté !" <<endl;

    cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
    //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    cin.ignore();
} // ---- Fin de AfficherAjoutNettoyeur

void Affichage::AfficherSupprimerNettoyeur(DataNettoyeurs & dataNettoyeurs, CompagnieFournisseur & compagnieFournisseur)
// Algorithme : Aucun
//
{
    string idSaisie;
    cout<<"Veuillez saisir l'ID du nettoyeur que vous voulez supprimer : ";
    cin>>idSaisie;

    bool res = dataNettoyeurs.SupprimerNettoyeur(idSaisie,compagnieFournisseur);

    if(res)
        cout << "\nLe nettoyeur d'ID " << idSaisie << " à bien été supprimé !" <<endl;
    else
        cout << "\nERREUR ! Le nettoyeur d'ID " << idSaisie << " n'à pas pu être supprimé !" <<endl;

    cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
    //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    cin.ignore();
} // ---- Fin de AfficherSupprimerNettoyeur

void Affichage::AfficherActiverNettoyeur(DataNettoyeurs & dataNettoyeurs)
// Algorithme : Aucun
//
{
    string idSaisie;
    cout<<"Veuillez saisir l'ID du nettoyeur que vous voulez activer : ";
    cin>>idSaisie;

    bool res = dataNettoyeurs.ActiverNettoyeur(idSaisie);

    if(res)
        cout << "\nLe nettoyeur d'ID " << idSaisie << " à bien été activé !" <<endl;
    else
        cout << "\nERREUR ! Le nettoyeur d'ID " << idSaisie << " n'à pas pu être activé !" <<endl;

    cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
    //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    cin.ignore();
} // ---- Fin de AfficherActiverNettoyeur

void Affichage::AfficherDesactiverNettoyeur(DataNettoyeurs & dataNettoyeurs)
// Algorithme : Aucun
//
{

    string idSaisie;
    cout<<"Veuillez saisir l'ID du nettoyeur que vous voulez désactiver : ";
    cin>>idSaisie;

    bool res = dataNettoyeurs.DesactiverNettoyeur(idSaisie);

    if(res)
        cout << "\nLe nettoyeur d'ID " << idSaisie << " à bien été désactivé !" <<endl;
    else
        cout << "\nERREUR ! Le nettoyeur d'ID " << idSaisie << " n'à pas pu être désactivé !" <<endl;

    cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
    //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    cin.ignore();
} // ---- Fin de AfficherDesactiverNettoyeur

 NettoyeurAir* Affichage::AfficherSaisieRayonNettoyeur(DataNettoyeurs & dataNettoyeurs,vector<NettoyeurAir*>& nettoyeursCompagnie)
// Algorithme : Aucun
//
{
    string idSaisie;
    cout<<"Veuillez saisir l'ID du nettoyeur dont vous voulez connaître le rayon d'action : ";
    cin>>idSaisie;

    NettoyeurAir* res = dataNettoyeurs.VerifierAppartenanceNettoyeur(idSaisie,nettoyeursCompagnie);

    if(res!=0)
	{
        cout << "\nDébut du calcul du rayon d'action pour le nettoyeur n° " << idSaisie <<endl;
		cin.clear();
	}
    else
	{
        cout << "\nERREUR ! Le nettoyeur d'ID " << idSaisie << " n'est pas valide !" <<endl;
		cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
		//on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cin.ignore();
	}

	return res;

    
} // ---- Fin de AfficherSaisieRayonNettoyeur

void Affichage::AfficherComptesEnAttente(vector<UtilisateurProfessionnel *> &comptesAttente, bool fin)
// Algorithme : Uniquement de l'affichage en castant dynamiquement pour obtenir le type de compte Professionnel
{

    cout<< "  === Liste des comptes en attente ==="<<endl<<endl;

    vector<UtilisateurProfessionnel *>::iterator it;
    int cpt = 1;
    for(it=comptesAttente.begin(); it!=comptesAttente.end(); ++it)
    {
        EmployeFournisseur * eFour = dynamic_cast<EmployeFournisseur*>(*(it));
        EmployeAgenceGouvernementale * eGouv = dynamic_cast<EmployeAgenceGouvernementale*>(*(it));

        if(eFour!=nullptr)
        {
            cout << "(" << cpt << ") Fournisseur => " << Souligner("Nom") << " : " << eFour->GetNom();
            cout << " | " << Souligner("Prenom") << " : " << eFour->GetPrenom();
            cout << " | " << Souligner("Adresse mail") << " : " << eFour->GetMail();
            cout << " | " << Souligner("Compagnie") << " : " << eFour->GetCompagnie()->getId() << endl;
        }
        else if(eGouv!= nullptr)
        {
            cout << "(" << cpt << ") Agence Gouvernementale => " << Souligner("Nom") << " : " << eGouv->GetNom();
            cout << " | " << Souligner("Prenom") << " : " << eGouv->GetPrenom();
            cout << " | " << Souligner("Adresse mail") << " : " << eGouv->GetMail() << endl;
        }
        else {
            cout << "\nUne erreur s'est produite lors de l'affichage des comptes" << endl;
            fin = true;
            break;
        }
        ++cpt;
    }

    cout << "\n  === Fin de la liste ===" << endl;

    if(fin)
    {
        cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
        //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cin.ignore();
    }
} // ------ Fin de AfficherComptesEnAttente

PointGeographique Affichage::SaisirPosition()
// Algorithme : Aucun
//
{
    cout<<"Définissez la position  : "<<endl;
    cout<<"Quelle latitude ? ";
    double latitude=SaisirDouble(-100,100);
    cout<<"Quelle longitude ? ";
    double longitude=SaisirDouble(-100,100);

    PointGeographique p(longitude,latitude);

    return p;

} //----- Fin de SaisirPosition

int Affichage::AfficherMenuValidationCompte()
// Algorithme : Aucun
//
{
    cout<<"\nQue voulez-vous faire ?"<<endl;

    cout<<"	1) Accepter un compte.\n";
    cout<<"	2) Refuser un compte.\n";
    cout<<"	3) Retour au menu principal.\n";
    return SaisirChoix(3);
} //----- Fin de AfficherMenuValidationCompte

void Affichage::AfficherValiderCompte(vector<UtilisateurProfessionnel *> &comptesAttente)
// Algorithme : Vient récupérer le numéro du compte à valider et appel la méthode associé à cet élément
//
{
    int idSaisie;
    cout<<"Veuillez saisir le numéro (dans la liste) du compte à valider : ";
    cin>>idSaisie;

    if(idSaisie > 0 && idSaisie <= comptesAttente.size())
    {
        comptesAttente[idSaisie-1]->setCompteValide(true);
        cout << "\nLe compte (" << idSaisie <<") à bien été valider ! " << endl;
    }
    else
    {
        cout << "\nERREUR ! Le compte saisie n'existe pas dans la liste ! " << endl;
    }

    cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
    //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin.ignore();

} // ---- Fin de AfficherValiderCompte

void Affichage::AfficherRefuserCompte(vector<UtilisateurProfessionnel *> &comptesAttente)
// Algorithme : Vient récupérer le numéro du compte à refuser et appel la méthode associé à cet élément
//
{
    int idSaisie;
    cout<<"Veuillez saisir le numéro (dans la liste) du compte à refuser : ";
    cin>>idSaisie;

    if(idSaisie > 0 && idSaisie <= comptesAttente.size())
    {
        comptesAttente[idSaisie-1]->setCompteValide(false);
        cout << "\nLe compte (" << idSaisie <<") à bien été refuser ! " << endl;
    }
    else
    {
        cout << "\nERREUR ! Le compte saisie n'existe pas dans la liste ! " << endl;
    }

    cout<<"\nAppuyez sur 'Entrée' pour revenir au "<<Souligner("menu d'action");
    //on vide le buffer de lecture pour être sûr de ne pas lire de caractères résiduels
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin.ignore();
} // ---- Fin de AfficherValiderCompte

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
