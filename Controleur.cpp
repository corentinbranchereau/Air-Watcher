
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
    ret = ret && donneesMesures.ChargerMesures(cheminFichierMesures,donneesCapteurs.GetMapCapteurUtilisateur(),donneesUtilisateurs.GetUtilisateurs());
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

            switch(choix)
            {
                case 1 : {
                    //Afficher la liste des comptes en attente
                    affichage.PreparationConsole("Consultation des comptes en attente - A FAIRE");
                } break;

                case 2 : {
                    //Valider/refuser la création d'un compte
                    affichage.PreparationConsole("Validation ou refus de création d'un compte - A FAIRE");
                } break;

                case 3 : {
                    //Gérer un compte
                    affichage.PreparationConsole("Gestion d'un compte - A FAIRE");
                } break;

                case 4 : {
                    //Ajouter un capteur à l'application
                    affichage.PreparationConsole("Ajout d'un capteur à l'application - A FAIRE");
                } break;

                case 5 : {
                    //Modifier un capteur de l'application
                    affichage.PreparationConsole("Modification d'un capteur de l'application - A FAIRE");
                } break;

                case 6 : {
                    //Modifier son compte
                    affichage.PreparationConsole("Modification de son compte - A FAIRE");
                } break;

                case 7 : {
                    //déconnexion
                } break;

            }

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

            switch(choix)
            {
                case 1: {
                    // consultation données
                    affichage.PreparationConsole("Consultation de vos données entrées");
                    Horodatage debut = affichage.SaisirDate("début");
                    Horodatage fin = affichage.SaisirDate("fin");
                    affichage.AfficherDonnesUtilisateurPrive(debut,fin);
                } break;

                case 2: {
                    // entrer une donnée
                    affichage.PreparationConsole("Entrée d'une nouvelle donnée - A FAIRE");
                } break;

                case 3: {
                    // modifier compte
                    affichage.PreparationConsole("Modification de son compte - A FAIRE");
                } break;

                case 4: {
                    // déconnexion
                } break;
            }
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

            vector<Mesure*>listMesureBonnes;

            while(choix!=9) // 9 = Déconnexion pour un employé d'agence
            {
                choix = affichage.AfficherMenuActionAgenceGouv();

                switch(choix)
                {
                    case 1: {
                        // liste des capteurs
                        affichage.PreparationConsole("Consultation de la liste des capteurs - A FAIRE");
                    } break;

                    case 2: {
                        // état des capteurs
                        affichage.PreparationConsole("Consultation de l'état des capteurs - A FAIRE");
                    } break;

                    case 3: {
                        // capteurs similaires
                        affichage.PreparationConsole("Consultation des capteurs similaires");
                        int nbClassesMini = affichage.CapteursSimilairesNbClassesMini(donneesCapteurs.GetCapteurs().size());
                        vector<vector<Capteur*>> resultatCapteurSimilaire = donneesMesures.IdentifierCapteursSimilaires(donneesCapteurs.GetCapteurs(),nbClassesMini);
                        affichage.AfficherCapteursSimilaires(resultatCapteurSimilaire);
                    } break;

                    case 4: {
                        // données brutes
                        affichage.PreparationConsole("Consultation des données brutes de l'application");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        affichage.AfficherDonneesBrutes(debut,fin,donneesMesures.GetMesures());
                    } break;

                    case 5: {
                        // moyenne données brutes d'une zone sur une période donnée
                        affichage.PreparationConsole("Consultation des moyennes journalières des données sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        Zone zone=affichage.SaisirZone();
                        listMesureBonnes=donneesMesures.ObtenirMesuresFiables();
                        Mesure** moyennesMesure=donneesMesures.ConsulterMoyenneDonneesPeriodePrecise(debut,fin,zone,listMesureBonnes,donneesCapteurs.GetCapteurs());
                        affichage.AfficherMoyennesPeriodePrecise(moyennesMesure);
                    } break;

                    case 6: {
                        
                        // moyenne qualité air d'une zone sur une période
                        affichage.PreparationConsole("Consultation des indices ATMO journaliers sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        Zone zone=affichage.SaisirZone();
                        vector<Mesure*> listMesureBonnesQualite=donneesMesures.ObtenirMesuresFiables();
                        map<Horodatage,int> moyennesIndices=donneesMesures.ConsulterQualitePeriodePrecise(debut,fin,zone,listMesureBonnesQualite,donneesCapteurs.GetCapteurs());
                        affichage.AfficherQualitePeriodePrecise(moyennesIndices);
                    } break;

                    case 7: {
                        // labelliser données
                        affichage.PreparationConsole("Labellisation des données des utilisateurs privés");
                        donneesMesures.LabeliserDonneesUtilisateur("Data/labels.csv",donneesCapteurs.GetCapteurs());
                        affichage.AfficherApresLabel();
                    } break;

                    case 8: {
                        // modifier compte
                        affichage.PreparationConsole("Modification de son compte - A FAIRE");
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

            vector<Mesure*>listMesureBonnes;

            while(choix!=9) // 9 = Déconnexion pour fournisseur
            {
                choix = affichage.AfficherMenuActionFournisseur();

                switch(choix)
                {
                    case 1 : {
                        //Ajouter ou supprimer un nettoyeur d'air
                        affichage.PreparationConsole("Ajout ou suppression d'un nettoyeur d'air - A FAIRE");
                        int choixFait = affichage.AfficherMenuAjoutSuppressionNettoyeur();
                        if(choixFait == 1) //Ajouter un nettoyeur
                        {
                            PointGeographique p = affichage.SaisirPosition();
                            affichage.AfficherAjouterNettoyeur();
                        } else if(choixFait == 2){ //Supprimer un nettoyeur
                            affichage.AfficherSupprimerNettoyeur();
                        }
                    } break;

                    case 2 : {
                        //Activer ou désactiver un nettoyeur d'air
                        affichage.PreparationConsole("Activation ou désactivation d'un nettoyeur d'air");
                        int choixFait = affichage.AfficherMenuActiverDesactiverNettoyeur();
                        if(choixFait == 1) //Activer un nettoyeur
                        {
                            affichage.AfficherNettoyeursCompagnie(uFournisseur->GetCompagnie()->getNettoyeurs(),false, true);
                            affichage.AfficherActiverNettoyeur(donneesNettoyeurs);
                        } else if(choixFait == 2){ //Désactiver un nettoyeur
                            affichage.AfficherNettoyeursCompagnie(uFournisseur->GetCompagnie()->getNettoyeurs(),true, false);
                            affichage.AfficherDesactiverNettoyeur(donneesNettoyeurs);
                        }
                    } break;

                    case 3 : {
                        //Afficher la liste des nettoyeurs d'air de la compagnie
                        affichage.PreparationConsole("Consultation de la liste des nettoyeurs d'air de la compagnie");
                        affichage.AfficherNettoyeursCompagnie(uFournisseur->GetCompagnie()->getNettoyeurs(),true, true);
                    } break;

                    case 4 : {
                        //Obtenir le rayon d'action d'un nettoyeur d'air
                        affichage.PreparationConsole("Obtenir le rayon d'action d'un nettoyeur d'air - A FAIRE");
                    } break;

                    case 5 : {
                        //Consulter les données brutes de l'application
                        affichage.PreparationConsole("Consultation des données brutes de l'application");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        affichage.AfficherDonneesBrutes(debut,fin,donneesMesures.GetMesures());
                    } break;

                    case 6 : {
                        //Obtenir la moyenne des données brutes d'une zone (circulaire)
                        affichage.PreparationConsole("Consultation des moyennes journalières des données sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        Zone zone=affichage.SaisirZone();
                        listMesureBonnes=donneesMesures.ObtenirMesuresFiables();
                        Mesure** moyennesMesure=donneesMesures.ConsulterMoyenneDonneesPeriodePrecise(debut,fin,zone,listMesureBonnes,donneesCapteurs.GetCapteurs());
                        affichage.AfficherMoyennesPeriodePrecise(moyennesMesure);
                    } break;

                    case 7 : {
                        //Obtenir la qualité d'air moyenne d'une zone (circulaire)
                        affichage.PreparationConsole("Consultation des indices ATMO journaliers sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        Zone zone=affichage.SaisirZone();
                        vector<Mesure*> listMesureBonnesQualite=donneesMesures.ObtenirMesuresFiables();
                        map<Horodatage,int> moyennesIndices=donneesMesures.ConsulterQualitePeriodePrecise(debut,fin,zone,listMesureBonnesQualite,donneesCapteurs.GetCapteurs());
                        affichage.AfficherQualitePeriodePrecise(moyennesIndices);
                    } break;

                    case 8 : {
                        //Modifier son compte
                        affichage.PreparationConsole("Modification de son compte - A FAIRE");
                    } break;

                    case 9 : {
                        //déconnexion
                    } break;
                }

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
        //donneesMesures.LabeliserDonneesUtilisateur("Data/labels.csv",donneesCapteurs.GetCapteurs());
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


            /*____TEST DATA NETTOYEURS______*/
            
        /*DataNettoyeurs* d=new DataNettoyeurs();
        cout << "chargement des données: " << d->ChargerNettoyeurs("Data/cleaners.csv");
        Horodatage debut(2010,2,3,4,5,6);
        Horodatage fin(2020,2,3,4,5,6);
        PointGeographique pGeo(0,0);
        string s=(string)"nettoyeur test";
        NettoyeurAir* n=new NettoyeurAir(true,100, debut,fin,"1",s, pGeo);
        cout << "ajout du nettoyeur :" << d->AjouterNettoyeur(*n)<< endl;
        cout << "activation du nettoyeur: " << d-> ActiverNettoyeur("1")<< endl;
        cout << "desaction du nettoyeur: " << d-> DesactiverNettoyeur("1") << endl;
        cout << "suppression du nettoyeur" << d-> SupprimerNettoyeur("1") <<endl;*/
            
        

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