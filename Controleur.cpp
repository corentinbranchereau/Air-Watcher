#include "Affichage.h"
#include "DataUtilisateurs.h"
#include "DataMesures.h"
#include "DataCapteurs.h"
#include "UtilisateurPrive.h"
#include "Admin.h"
#include "EmployeFournisseur.h"
#include "EmployeAgenceGouvernementale.h"
#include <iostream>

Affichage affichage;
int choix;
string* donneesSaisies;
DataUtilisateurs donneesUtilisateurs;
DataMesures donneesMesures;
DataCapteurs donneesCapteurs;

Utilisateur* utilisateurConnecte = nullptr;
string statutConnexion="déconnecté"; // variable qui va permettre de dire si un compte est connecté et son type

bool chargementDonnees(string cheminFichierUtilisateurs, string cheminFichierMesures, string cheminFichierAttributs, string cheminFichierCapteurs)
// Cette méthode charge les données dans chaque objet Data
// et renvoie true si tous c'est bien passé. Si il y a eu une
// erreur à un endroit, renvoie false;
{
	//donneesUtilisateurs.ChargerUtilisateurs(cheminFichierUtilisateurs)&& donneesMesures.ChargerMesures(cheminFichierMesures)&&
	return (donneesCapteurs.ChargerCapteurs(cheminFichierCapteurs)&& donneesMesures.ChargerAttributs(cheminFichierAttributs) && donneesUtilisateurs.ChargerUtilisateurs(cheminFichierUtilisateurs)&& donneesMesures.ChargerMesures(cheminFichierMesures)); // && chargement autre données
}

void menuAction()
// Cette méthode permet de boucler sur le menu d'action tant que l'utilisateur ne s'est pas déconnecté
{
	int choix=0;


	// on tente de caster l'utilisateur pour trouver son type
	Admin* admin = dynamic_cast<Admin*>(utilisateurConnecte);
	UtilisateurPrive* uPrive = dynamic_cast<UtilisateurPrive*>(utilisateurConnecte);
	EmployeAgenceGouvernementale* uAgence = dynamic_cast<EmployeAgenceGouvernementale*>(utilisateurConnecte);
	EmployeFournisseur* uFournisseur = dynamic_cast<EmployeFournisseur*>(utilisateurConnecte);
	
	if(admin!=nullptr)
	{
		// c'est un admin
		statutConnexion = "admin";
		affichage.AffichageFinConnexion("réussite");
	}
	else if(uPrive!=nullptr)
	{
		// c'est un utilisateur privé
		statutConnexion = "privé";
		affichage.AffichageFinConnexion("réussite");

		while(choix!=4) // 4 = Déconnexion pour un utilisateur privé
		{
			choix = affichage.AfficherMenuActionPrive(uPrive);
		}
		statutConnexion = "déconnecté";
	}
	else if(uAgence!=nullptr)
	{
		// c'est un employé de l'agence : on vérifie la validité du compte
		if(uAgence->GetCompteValide())
		{
			statutConnexion = "agence";
			affichage.AffichageFinConnexion("réussite");
		}
		else
		{
			statutConnexion = "déconnecté";
			affichage.AffichageFinConnexion("attente");
		}
		
	}
	else if(uFournisseur!=nullptr)
	{
		// c'est un fournisseur : on vérifie la validité du compte
		if(uFournisseur->GetCompteValide())
		{
			statutConnexion = "fournisseur";
			affichage.AffichageFinConnexion("réussite");
		}
		else
		{
			statutConnexion = "déconnecté";
			affichage.AffichageFinConnexion("attente");
		}
		
	}
}

int main(void)
{
	if(chargementDonnees("utilisateurs.txt","data1.txt","AttributeType.csv","Sensors.csv"))
	{
		while(1)
		{
			if(statutConnexion=="déconnecté")
			{
				choix = affichage.AfficherMenuPrincipal();
				switch(choix)
				{
					case 1:
						donneesSaisies = affichage.AfficherCreationCompte();
						if(donneesUtilisateurs.SeCreerUnComptes(donneesSaisies))
						{
							// succès inscription
							affichage.AfficherFinCreationCompte(true);
						}
						else
						{
							// échec inscription
							affichage.AfficherFinCreationCompte(false);
						}
						
						delete[] donneesSaisies;
					break;

					case 2:
						donneesSaisies = affichage.AffichageConnexion();
						utilisateurConnecte = donneesUtilisateurs.SeConnecter(donneesSaisies[0],donneesSaisies[1]);
						if(utilisateurConnecte!=nullptr)
						{
							// un compte a été trouvé
							// on lance la méthode pour les menus d'actions 
							menuAction();
						}
						else
						{
							// aucun compte ne correspond
							statutConnexion="déconnecté";
							affichage.AffichageFinConnexion("échec");
						}
						delete[] donneesSaisies;
					break;

					case 3:
						return 0;
					break;
				}
			}
		}
	}
	return 0;
}