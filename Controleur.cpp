
#include "DataUtilisateurs.h"
#include "DataMesures.h"
#include "DataCapteurs.h"
#include "UtilisateurPrive.h"
#include "Admin.h"
#include "EmployeFournisseur.h"
#include "EmployeAgenceGouvernementale.h"
#include "Affichage.h"
#include "DataNettoyeurs.h"

#include <iostream>
#include "math.h"

Affichage affichage;
int choix;
string* donneesSaisies;
DataUtilisateurs donneesUtilisateurs;
DataMesures donneesMesures;
DataCapteurs donneesCapteurs;
DataNettoyeurs donneesNettoyeurs;

Utilisateur* utilisateurConnecte = nullptr;
string statutConnexion="déconnecté"; // variable qui va permettre de dire si un compte est connecté et son type

bool chargementDonnees(string cheminFichierNettoyeurs, string cheminFichierFournisseurs, string cheminFichierUtilisateurs, string cheminFichierMesures, string cheminFichierAttributs, string cheminFichierCapteurs, string cheminFichierUtilisateursPerso, string cheminFichierLabel)
// Cette méthode charge les données dans chaque objet Data
// et renvoie true si tous c'est bien passé. Si il y a eu une
// erreur à un endroit, renvoie false;
// Ordre de chargement : Nettoyeurs -> CompagnieFournisseur -> Capteurs -> Map<idCapteur, idUser> = fichier users.csv
// (+ écrire ces utilisateurs dans NOTRE fichier utilisateurs)
// -> Utilisateurs (notre fichier) -> TypeAttribut -> Mesures -> Fichier labels
{
    donneesNettoyeurs = DataNettoyeurs();
    donneesCapteurs = DataCapteurs();
    donneesMesures = DataMesures();
    donneesUtilisateurs = DataUtilisateurs();

    //Nettoyeurs
    bool ret = donneesNettoyeurs.ChargerNettoyeurs(cheminFichierNettoyeurs);
    if(ret){cout<<"Nettoyeurs OK\n";}

    //Compagnies
    ret = ret && donneesUtilisateurs.ChargerFournisseurs(cheminFichierFournisseurs,donneesNettoyeurs.GetNettoyeurs());
    if(ret){cout<<"Compagnies OK\n";}

    //Capteurs
    ret = ret && donneesCapteurs.ChargerCapteurs(cheminFichierCapteurs);
    if(ret){cout<<"Capteurs OK\n";}

    //Utilisateurs : users.csv (+écriture dans notre fichier)
    ret = ret && donneesCapteurs.ChargerCapteursPrives(cheminFichierUtilisateurs,cheminFichierUtilisateursPerso);
    if(ret){cout<<"users.csv OK\n";}

    //Utilisateurs : notre propre fichier
    ret = ret && donneesUtilisateurs.ChargerUtilisateurs(cheminFichierUtilisateursPerso);
    if(ret){cout<<"ownUsers.csv OK\n";}

    //TypeAttribut
    ret = ret && donneesMesures.ChargerAttributs(cheminFichierAttributs);
    if(ret){cout<<"Types attributs OK\n";}

    //Mesures
    ret = ret && donneesMesures.ChargerMesures(cheminFichierMesures,donneesCapteurs.GetMapCapteurUtilisateur());
    if(ret){cout<<"Mesures OK\n";}
    //Fichiers labels
    ret = ret && donneesMesures.ChargerLabels(cheminFichierLabel,donneesCapteurs.GetMapCapteurUtilisateur());
    if(ret){cout<<"Labels OK\n";}
    return (ret);
}

void menuAction()
// Cette méthode permet de boucler sur le menu d'action tant que l'utilisateur ne s'est pas déconnecté
{
    int choix = 0;

    // on tente de caster l'utilisateur pour trouver son type
    Admin* admin = dynamic_cast<Admin*>(utilisateurConnecte);
    UtilisateurPrive* uPrive = dynamic_cast<UtilisateurPrive*>(utilisateurConnecte);
    EmployeAgenceGouvernementale* uAgence = dynamic_cast<EmployeAgenceGouvernementale*>(utilisateurConnecte);
    EmployeFournisseur* uFournisseur = dynamic_cast<EmployeFournisseur*>(utilisateurConnecte);

    if(admin!=nullptr)
    {
        // c'est un admin
        statutConnexion = "admin";

        // on définit l'utilisateur dans l'affichage pour avoir ses infos
        affichage.DefinirUtilisateur(utilisateurConnecte,"Admin");

        affichage.AffichageFinConnexion("réussite");

        while(choix!=7) // 7 = Déconnexion pour un admin
        {
            choix = affichage.AfficherMenuActionAdmin();
        }
    }
    else if(uPrive!=nullptr)
    {
        // c'est un utilisateur privé
        statutConnexion = "privé";

        // on définit l'utilisateur dans l'affichage pour avoir ses infos
        affichage.DefinirUtilisateur(utilisateurConnecte,"Utilisateur privé");

        affichage.AffichageFinConnexion("réussite");

        while(choix!=4) // 4 = Déconnexion pour un utilisateur privé
        {
            choix = affichage.AfficherMenuActionPrive();
        }
    }
    else if(uAgence!=nullptr)
    {
        // c'est un employé de l'agence : on vérifie la validité du compte
        if(uAgence->GetCompteValide())
        {
            statutConnexion = "agence";

            // on définit l'utilisateur dans l'affichage pour avoir ses infos
            affichage.DefinirUtilisateur(utilisateurConnecte,"Agence gouvernementale");

            affichage.AffichageFinConnexion("réussite");

            while(choix!=9) // 9 = Déconnexion pour un employé d'agence
            {
                choix = affichage.AfficherMenuActionAgenceGouv();

                switch(choix)
                {
                    case 1: {
                        // liste des capteurs
                    } break;

                    case 2: {
                        // état des capteurs
                    } break;

                    case 3: {
                        // capteurs similaires
                        int nbClassesMini = affichage.CapteursSimilairesNbClassesMini(donneesCapteurs.GetCapteurs().size());
                        vector<vector<Capteur*>> resultatCapteurSimilaire = donneesMesures.IdentifierCapteursSimilaires(donneesCapteurs.GetCapteurs(),nbClassesMini);
                        affichage.AfficherCapteursSimilaires(resultatCapteurSimilaire);
                    } break;

                    case 4: {
                        // données brutes
                    } break;

                    case 5: {
                        // moyenne données brutes d'une zone sur une période donnée
                        affichage.AvantSaisieConsulterMoyenneDonnees();
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        Zone zone=affichage.SaisirZone();
                        vector<Mesure*>listMesureBonnes=donneesMesures.ObtenirMesuresFiables();
                        Mesure** moyennesMesure=donneesMesures.ConsulterMoyenneDonneesPeriodePrecise(debut,fin,zone,listMesureBonnes,donneesCapteurs.GetCapteurs());

                    } break;

                    case 6: {
                        
                        // moyenne qualité air d'une zone
                    } break;

                    case 7: {
                        // labelliser données
                    } break;

                    case 8: {
                        // modifier compte
                    } break;

                    case 9: {
                        // déconnexion
                    } break;
                }
            }
        }
        else
        {
            affichage.AffichageFinConnexion("attente");
        }

    }
    else if(uFournisseur!=nullptr)
    {
        // c'est un fournisseur : on vérifie la validité du compte
        if(uFournisseur->GetCompteValide())
        {
            statutConnexion = "fournisseur";

            // on définit l'utilisateur dans l'affichage pour avoir ses infos
            affichage.DefinirUtilisateur(utilisateurConnecte,"Fournisseur");

            affichage.AffichageFinConnexion("réussite");

            while(choix!=9) // 9 = Déconnexion pour fournisseur
            {
                choix = affichage.AfficherMenuActionFournisseur();
            }
        }
        else
        {
            affichage.AffichageFinConnexion("attente");
        }

    }

    statutConnexion = "déconnecté";
    affichage.DefinirUtilisateur(nullptr,"");
    utilisateurConnecte = nullptr;
}


void affichageCapteursSimilaires(vector<vector<Capteur*>> groupescapteurs)
//affiche les groupes de capteurs similaires
{
    for(int i=0;i<groupescapteurs.size();i++)
    {
        cout<<"CLASSE N° ";
        cout<<i+1;
        cout<<endl;

        for(int j=0;j<groupescapteurs[i].size();j++)
        {
            cout<<"CAPTEUR ID = ";
            cout<<(*(groupescapteurs[i][j])).getID();
            cout<<endl;
        }
    }
}


int main(void)
{
    if(chargementDonnees("./Data/cleaners.csv","./Data/providers.csv","./Data/users.csv","./Data/measurements.csv","./Data/attributes.csv","./Data/sensors.csv","./Data/ownUsers.csv","./Data/labels.csv"))
    {

        //vector<vector<Capteur*>> capteursSim=donneesMesures.IdentifierCapteursSimilaires(donneesCapteurs.GetCapteurs(),2);
        //affichageCapteursSimilaires(capteursSim);

       /* double longitude1=1.333333;
	    double  latitude1=45.333333;
	    double longitude2=3.2;
	    double latitude2=45.2;

        
        Horodatage h(2019,1,4,12,0,0);

        Horodatage h2(2019,1,20,12,0,0);

        TypeAttribut* type=new TypeAttribut("O3","µg/m3","concentration d'ozone");

        Mesure* m=new Mesure(type,400,"Sensor0",h);

        vector<Mesure*> listM=donneesMesures.GetMesures();
        unordered_map<string,Capteur*> mapL=donneesCapteurs.GetCapteurs();
        bool result=donneesMesures.LabelliserUneDonnee(listM,m,mapL);

        //double rayon=donneesNettoyeurs.ObtenirRayonActionNettoyeur("Cleaner0",donneesMesures,listM,mapL,0.2,0.1,500);
        PointGeographique p(-1,45.3);
        Zone z(100,p);
        Mesure** moyennesMesure=donneesMesures.ConsulterMoyenneDonneesPeriodePrecise(h,h2,z,listM,mapL);
        
        for(int a=1;a<moyennesMesure[0][0].getValeurAttribut()+1;a++)
        {
            for(int p=0;p<4;p++)
            {
            cout<<"MOYENNE  ="<< moyennesMesure[a][p].getValeurAttribut()<<endl;
            }
            cout<<"-----------------------------"<<endl;
        }
        //cout<<"Rayon="<<rayon<<endl;
        */
        

        while(true)
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