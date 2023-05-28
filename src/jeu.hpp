#ifndef JEU
#define JEU



#include <list>
#include <iostream>
#include <vector>

#include "plateau.hpp"


class Menu;
class Hud;
class Joueur;
class Dashboard;
typedef std::shared_ptr<Joueur> Joueur_ptr;




//singleton [!] il faudra le rendre thread safe si on utilise des thread
class Jeu{
	public :
			enum EtatPartie {MENU,EN_PARTIE};
	protected :


		// POUR LA PARTIE :


		EtatPartie etatPartie;


		const static int TAILLE_PLATEAU_X = 20;
		const static int TAILLE_PLATEAU_Y = 40;

		const static int NOMBRE_JOUEUR = 4; // pour les testes
		int nombreJoueurEnVie;

        std::vector<Joueur_ptr> joueurs;
        int indiceJoueurActif;

		static Jeu *m_instance;

		Plateau *plateau;

		Menu *menu;

		Hud *hud;

		// lance la partie : creation plateau, dashboard
		//void lancerPartie(std::vector<Joueur_ptr> &joueurs);
		
		// decharge tous les elements d'une partie (plateau, dashboard)
		// [!] A TESTER, peut faire segfault?
		void finPartie();


        Jeu();

		static void setInstance(Jeu* instance) {m_instance = instance;} //permet de setInstance avant l'assignation des attributs dans le constructeur (qui utilisent getInstance())

		// met a jour Hud et joueur actif pour un nouveau tour
		void updateNouveauTour();



	public :
		static Jeu &getInstance() ;
		void operator=(const Jeu &) = delete;
		Jeu(Jeu &other) = delete;

		Plateau& getPlateau();

		Hud& getHud();

		


        void commencer();

		Joueur_ptr &getJoueurActif();

		// passe au joueur suivant
		// si il reste seulement un joueur arrete la partie
		void changerJoueur();

		EtatPartie getEtatPartie() {return etatPartie;}

		void lancerPartie();

		void arretPartie();

		void decreaseNombreJoueurEnvie() {nombreJoueurEnVie--;}







};


#endif

