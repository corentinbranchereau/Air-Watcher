CC=g++
CFLAGS= -g -Wall -Werror -ansi -pedantic -std=c++11
DFLAGS= -g

MAIN=AirWatcher
# SRCS= main.cpp Admin.cpp Affichage.cpp AgenceGouvernementale.cpp Capteur.cpp CompagnieFournisseur.cpp Controleur.cpp Data.cpp EmployeAgenceGouvernementale.cpp EmployeFournisseur.cpp Equipement.cpp Horodatage.cpp Mesure.cpp MesureUtilisateur.cpp NettoyeurAir.cpp PointGeographique.cpp TypeAttribut.cpp Utilisateur.cpp UtilisateurPrive.cpp UtilisateurProfessionnel.cpp Zone.cpp
SRCS=*.cpp
OBJS=$(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) $(DFLAGS) -o $(MAIN) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : launch
launch : $(MAIN)
	./$(MAIN)

.PHONY : clean
clean:
	rm -f $(MAIN) *.o core
