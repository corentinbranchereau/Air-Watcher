
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
#include <math.h>
#include <time.h>

Affichage affichage;
int choix;
string* donneesSaisies;
DataUtilisateurs donneesUtilisateurs;
DataMesures donneesMesures;
DataCapteurs donneesCapteurs;
DataNettoyeurs donneesNettoyeurs;

string cheminFichierUtilisateursPerso = "./Data/ownUsers.csv";
string cheminFichierAttributs = "./Data/attributes.csv";
string cheminFichierLabels = "./Data/labels.csv";
string cheminFichierMesures = "./Data/measurements.csv";
string cheminFichierNettoyeurs = "./Data/cleaners.csv";
string cheminFichierFournisseurs = "./Data/providers.csv";
string cheminFichierCapteurs = "./Data/sensors.csv";
string cheminFichierUtilisateurs = "./Data/users.csv";

Utilisateur* utilisateurConnecte = nullptr;

clock_t debutBench;
clock_t finBench;
bool benchmarkActif = false;

bool chargementDonnees()
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
    ret = ret && donneesMesures.ChargerLabels(cheminFichierLabels,donneesCapteurs.GetMapCapteurUtilisateur());
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
                    affichage.PreparationConsole("Consultation des comptes en attente");
                    vector<UtilisateurProfessionnel*> comptesAttente = donneesUtilisateurs.ObtenirComptesEnAttente();
                    affichage.AfficherComptesEnAttente(comptesAttente,true);

                } break;

                case 2 : {
                    //Valider/refuser la création d'un compte
                    affichage.PreparationConsole("Validation ou refus de création d'un compte");
                    vector<UtilisateurProfessionnel*> comptesAttente = donneesUtilisateurs.ObtenirComptesEnAttente();
                    affichage.AfficherComptesEnAttente(comptesAttente,false);
                    int choixFait = affichage.AfficherMenuValidationCompte();
                    if(choixFait == 1) //Valider un compte
                    {
                        affichage.AfficherValiderCompte(comptesAttente);
                    } else if(choixFait == 2){ //Refuser un compte
                        affichage.AfficherRefuserCompte(comptesAttente);
                    }

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
                    while(!(fin>=debut)) {
                        cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                        fin = affichage.SaisirDate("fin");
                    }
                    affichage.AfficherDonnesUtilisateurPrive(debut,fin);
                } break;

                case 2: {
                    // entrer une donnée
                    affichage.PreparationConsole("Entrée d'une nouvelle donnée");
                    Horodatage date= affichage.SaisirDate();

                    PointGeographique p(0,0);

                    if(donneesMesures.CapteurNouveau(uPrive->GetIdentifiant(),donneesCapteurs.GetMapCapteurUtilisateur())==true)
                    {
                        p=affichage.SaisirPosition();
                    }
                    vector<double> ajouts;
                    ajouts.push_back(affichage.SaisirValeur("O3"));
                    ajouts.push_back(affichage.SaisirValeur("NO2"));
                    ajouts.push_back(affichage.SaisirValeur("SO2"));
                    ajouts.push_back(affichage.SaisirValeur("PM10"));

                    donneesMesures.EntrerDonnees(cheminFichierUtilisateurs,cheminFichierCapteurs,ajouts,date,p,*uPrive,donneesCapteurs.GetMapCapteurUtilisateur(),donneesCapteurs.GetCapteurs());
                    donneesMesures.SauvegarderMesuresAjoutees(cheminFichierMesures);

                    affichage.AfficherConfirmation("DONNES BIEN PRISES EN COMPTE");

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
            // on définit l'utilisateur dans l'affichage pour avoir ses infos
            affichage.DefinirUtilisateur(utilisateurConnecte,"Agence gouvernementale");

            affichage.AffichageFinConnexion("réussite");

            

            while(choix!=10) // 10 = Déconnexion pour un employé d'agence
            {
                choix = affichage.AfficherMenuActionAgenceGouv();

                switch(choix)
                {
                    case 1: {
                        // liste des capteurs
                        affichage.AfficherListeCapteur(donneesCapteurs.GetCapteurs());
                    } break;

                    case 2: {
                        // état des capteurs
                        affichage.PreparationConsole("Consultation de l'état des capteurs - A FAIRE");
                    } break;

                    case 3: {
                        // capteurs similaires
                        affichage.PreparationConsole("Consultation des capteurs similaires");
                        affichage.AfficherSaisirIdCapteur(donneesCapteurs.GetCapteurs(),donneesMesures,debutBench,finBench);
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Consultation des capteurs similaires");
                    } break;

                    case 4: {
                        // données brutes
                        affichage.PreparationConsole("Consultation des données brutes de l'application");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        while(!(fin>=debut)) {
                            cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                            fin = affichage.SaisirDate("fin");
                        }
                        affichage.AfficherDonneesBrutes(debut,fin,donneesMesures.GetMesures());
                    } break;

                    case 5: {
                        // moyenne données brutes d'une zone sur une période donnée
                        affichage.PreparationConsole("Consultation des moyennes journalières des données sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        while(!(fin>=debut)) {
                            cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                            fin = affichage.SaisirDate("fin");
                        }
                        Zone zone=affichage.SaisirZone();
                        debutBench = clock();
                        vector<Mesure*>listMesureBonnes=donneesMesures.ObtenirMesuresFiables(donneesCapteurs.GetMapCapteurUtilisateur(), donneesUtilisateurs.GetUtilisateurs(),cheminFichierUtilisateursPerso);
                        Mesure** moyennesMesure=donneesMesures.ConsulterMoyenneDonneesPeriodePrecise(debut,fin,zone,listMesureBonnes,donneesCapteurs.GetCapteurs());
                        finBench = clock();
                        affichage.AfficherMoyennesPeriodePrecise(moyennesMesure);

                        int nbMesures=moyennesMesure[0][0].getValeurAttribut();
                        for(int i=0;i<nbMesures+1;i++)
                        {
                            delete[] moyennesMesure[i];
                        }
                        
                        delete [] moyennesMesure; 
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Consultation des moyennes journalières des données sur une période et une zone choisie");
                    } break;

                    case 6: {
                        // moyenne qualité air d'une zone sur une période
                        affichage.PreparationConsole("Consultation des indices ATMO journaliers sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        while(!(fin>=debut)) {
                            cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                            fin = affichage.SaisirDate("fin");
                        }
                        Zone zone=affichage.SaisirZone();
                        debutBench = clock();
                        vector<Mesure*> listMesureBonnesQualite=donneesMesures.ObtenirMesuresFiables(donneesCapteurs.GetMapCapteurUtilisateur(), donneesUtilisateurs.GetUtilisateurs(),cheminFichierUtilisateursPerso);
                        map<Horodatage,int> moyennesIndices=donneesMesures.ConsulterQualitePeriodePrecise(debut,fin,zone,listMesureBonnesQualite,donneesCapteurs.GetCapteurs());
                        finBench = clock();
                        affichage.AfficherQualitePeriodePrecise(moyennesIndices);
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Consultation des indices ATMO journaliers sur une période et une zone choisie");
                    } break;

                    case 7: {
                        // labelliser données
                        affichage.PreparationConsole("Labellisation des données des utilisateurs privés");
                        cout<<"Labellisation en cours. Veuillez patienter ..."<<endl;
                        debutBench = clock();
                        donneesMesures.LabeliserDonneesUtilisateur(cheminFichierLabels,donneesCapteurs.GetCapteurs(),donneesCapteurs.GetMapCapteurUtilisateur(), donneesUtilisateurs.GetUtilisateurs(),cheminFichierUtilisateursPerso);
                        finBench = clock();
                        affichage.AfficherApresLabel();
                        affichage.AfficherStatLabel(donneesUtilisateurs.GetUtilisateurs());
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Labellisation des données des utilisateurs privés");
                    } 
                    break;

                    case 8: {
                        // cluster capteurs similaires
                        affichage.PreparationConsole("Consultation des clusters de capteurs similaires");
                        int nbClassesMini = affichage.ClustersCapteursNbClassesMini(donneesCapteurs.GetCapteurs().size());
                        debutBench = clock();
                        vector<vector<Capteur*>> resultatCapteurSimilaire = donneesMesures.IdentifierClusterCapteursSimilaires(donneesCapteurs.GetCapteurs(),nbClassesMini);
                        finBench = clock();
                        affichage.AfficherClusterCapteursSimilaires(resultatCapteurSimilaire);
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Consultation des clusters de capteurs similaires");
                    } break;

                    case 9: {
                        // modifier compte
                        affichage.PreparationConsole("Modification de son compte - A FAIRE");
                    } break;

                    case 10: {
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
                        affichage.PreparationConsole("Ajout ou suppression d'un nettoyeur d'air");
                        int choixFait = affichage.AfficherMenuAjoutSuppressionNettoyeur();
                        if(choixFait == 1) //Ajouter un nettoyeur
                        {
                            affichage.AfficherNettoyeursCompagnie(uFournisseur->GetCompagnie()->getNettoyeurs(),true, true,false);
                            PointGeographique p = affichage.SaisirPosition();
                            affichage.AfficherAjouterNettoyeur(donneesNettoyeurs,*uFournisseur->GetCompagnie(),p);
                        } else if(choixFait == 2){ //Supprimer un nettoyeur
                            affichage.AfficherNettoyeursCompagnie(uFournisseur->GetCompagnie()->getNettoyeurs(),true, true,false);
                            affichage.AfficherSupprimerNettoyeur(donneesNettoyeurs,*uFournisseur->GetCompagnie());
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
                        affichage.PreparationConsole("Obtenir le rayon d'action d'un nettoyeur d'air");
                        affichage.AfficherNettoyeursCompagnie(uFournisseur->GetCompagnie()->getNettoyeurs(),true, true,false);
                        NettoyeurAir* nettoyeur=affichage.AfficherSaisieRayonNettoyeur(donneesNettoyeurs,uFournisseur->GetCompagnie()->getNettoyeurs());
                     

                        if(nettoyeur!=0)
                        {
                            affichage.AfficherMessage("Veuillez saisir un pourcentage d'amélioration minimum de la qualité de l'air (entre 0 et 100)");
                            double epsilon=affichage.SaisirDouble(0,100);
                            debutBench = clock();
                            vector<Mesure*> listMesureBonnes=donneesMesures.ObtenirMesuresFiables(donneesCapteurs.GetMapCapteurUtilisateur(), donneesUtilisateurs.GetUtilisateurs(),cheminFichierUtilisateursPerso);
                            double rayonMax=1000;
                            vector<double>res=donneesNettoyeurs.ObtenirRayonActionNettoyeur(nettoyeur->getID(),donneesMesures,listMesureBonnes,donneesCapteurs.GetCapteurs(),2,epsilon/100.0,rayonMax);
                            finBench = clock();
                            affichage.AfficherRayonAction(res,rayonMax,nettoyeur->getID());
                            if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Obtenir le rayon d'action d'un nettoyeur d'air");
                        }

                    } break;

                    case 5 : {
                        //Consulter les données brutes de l'application
                        affichage.PreparationConsole("Consultation des données brutes de l'application");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        while(!(fin>=debut)) {
                            cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                            fin = affichage.SaisirDate("fin");
                        }
                        affichage.AfficherDonneesBrutes(debut,fin,donneesMesures.GetMesures());
                    } break;

                    case 6 : {
                        //Obtenir la moyenne des données brutes d'une zone (circulaire)
                        affichage.PreparationConsole("Consultation des moyennes journalières des données sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        while(!(fin>=debut)) {
                            cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                            fin = affichage.SaisirDate("fin");
                        }
                        Zone zone=affichage.SaisirZone();
                        debutBench = clock();
                        listMesureBonnes=donneesMesures.ObtenirMesuresFiables(donneesCapteurs.GetMapCapteurUtilisateur(), donneesUtilisateurs.GetUtilisateurs(),cheminFichierUtilisateursPerso);
                        Mesure** moyennesMesure=donneesMesures.ConsulterMoyenneDonneesPeriodePrecise(debut,fin,zone,listMesureBonnes,donneesCapteurs.GetCapteurs());
                        finBench = clock();
                        affichage.AfficherMoyennesPeriodePrecise(moyennesMesure);
                        
                        int nbMesures=moyennesMesure[0][0].getValeurAttribut();
                        for(int i=0;i<nbMesures+1;i++)
                        {
                            delete[] moyennesMesure[i];
                        }

                        delete [] moyennesMesure;
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Consultation des moyennes journalières des données sur une période et une zone choisie");
                    } break;

                    case 7 : {
                        //Obtenir la qualité d'air moyenne d'une zone (circulaire)
                        affichage.PreparationConsole("Consultation des indices ATMO journaliers sur une période et une zone choisie");
                        Horodatage debut=affichage.SaisirDate("début");
                        Horodatage fin=affichage.SaisirDate("fin");
                        while(!(fin>=debut)) {
                            cout<<"\n/ ! \\ Veuillez saisir une date de fin supérieure ou égale à la date de début ! / ! \\"<<endl;
                            fin = affichage.SaisirDate("fin");
                        }
                        Zone zone=affichage.SaisirZone();
                        debutBench = clock();
                        vector<Mesure*> listMesureBonnesQualite=donneesMesures.ObtenirMesuresFiables(donneesCapteurs.GetMapCapteurUtilisateur(), donneesUtilisateurs.GetUtilisateurs(),cheminFichierUtilisateursPerso);
                        map<Horodatage,int> moyennesIndices=donneesMesures.ConsulterQualitePeriodePrecise(debut,fin,zone,listMesureBonnesQualite,donneesCapteurs.GetCapteurs());
                        finBench = clock();
                        affichage.AfficherQualitePeriodePrecise(moyennesIndices);
                        if(benchmarkActif) affichage.AfficherBenchmark(debutBench,finBench,"Consultation des indices ATMO journaliers sur une période et une zone choisie");
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
    affichage.DefinirUtilisateur(nullptr,"");
    utilisateurConnecte = nullptr;
}

int main(void)
{   
    if(chargementDonnees())
    {   
        benchmarkActif = affichage.ChoixActivationBenchmark();
        while(true)
        {
            /*
            unordered_map<string,Capteur*>::iterator it;
            double distMin=100000;
            string capMin = "";
            for(it=donneesCapteurs.GetCapteurs().begin();it!=donneesCapteurs.GetCapteurs().end();++it) {
                double longCap = (*it).second->getPosition().getLongitude();
                double latCap = (*it).second->getPosition().getLatitude();
                double distance=acos(sin(M_PI/180*46.666667)*sin(M_PI/180*latCap)+cos(M_PI/180*46.666667)*cos(M_PI/180*latCap)*cos(M_PI/180*(longCap-3.666667)))*6371;
                cout<<"ID CAPTEUR : "<<(*it).second->getID()<<"  -  DISTANCE : "<<distance<<endl;
                if(distMin>distance) {
                    distMin = distance;
                    capMin = (*it).second->getID();
                }
            }
            cout<<"DIST MIN : "<<distMin<<"   -    ID MIN : "<<capMin<<endl;
            return 0;
            */
            
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

    return 0;
}