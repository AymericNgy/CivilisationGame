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


/**
 * \class Jeu
 * \brief Permet de lancer une partie. \n
 * Permet d'acceder au joueur actif, au plateau et au hud
 * 
 *
 * Description détaillée de la classe Jeu.
 */
class Jeu{
	public :
			/**
			 * \enum EtatPartie
			 * \brief Permet de savoir si on est dans le menu ou en partie
			*/
			enum EtatPartie {MENU,EN_PARTIE};
	protected :
	
		// ---ATTRIBUTS---


		// POUR LA PARTIE :

		/**
		 * \brief Permet de savoir si on est dans le menu ou en partie
		*/
		EtatPartie etatPartie;

		// dimensions du plateau
		const static int TAILLE_PLATEAU_X = 20;
		const static int TAILLE_PLATEAU_Y = 40;


		const static int NOMBRE_JOUEUR = 4; 
		int nombreJoueurEnVie;

		// liste des joueurs
        std::vector<Joueur_ptr> joueurs;
        int indiceJoueurActif;

		/**
		 * \brief attribut static permettant d'acceder a l'instance de Jeu (singleton)
		*/
		static Jeu *m_instance;

		// plateau de jeu
		Plateau *plateau;

		// menu de jeu
		Menu *menu;

		// hud de jeu
		Hud *hud;

		// ---METHODES---
		
		/** 
		 * \brief decharge tous les elements d'une partie (plateau, hud, joueurs)
		 */
		void finPartie();

		/**
		 * \brief constructeur de Jeu
		 * */
        Jeu();




		/**
		 * \brief met a jour Hud et joueur actif pour un nouveau tour
		*/
		void updateNouveauTour();




	public :
		static Jeu &getInstance() ;
		void operator=(const Jeu &) = delete;
		Jeu(Jeu &other) = delete;


		Plateau& getPlateau();

		Hud& getHud();

		

		/**
		 * \brief lance la boucle de l'interface graphique,
		 * permet d'utiliser le jeu
		*/
        void commencer();

		/**
		 * \brief Permet d'acceder au joueur actif
		*/
		Joueur_ptr &getJoueurActif();

		/**
		 * \brief passe au joueur suivant,
		 * si il reste seulement un joueur arrete la partie
		*/
		void changerJoueur();

		/**
		 * \brief Permet de savoir si on est dans le menu ou en partie
		 * 
		 * \return EtatPartie
		*/
		EtatPartie getEtatPartie() {return etatPartie;}

		/**
		 * \brief Permet de lancer une partie.
		 * Lance une partie avec 4 joueurs
		 * Cree un plateau, un hud
		 * */		
		void lancerPartie();

		/**
		 * \brief arrete la partie
		 * supprime les joueurs, le plateau, le hud
		*/
		void arretPartie();

		void decreaseNombreJoueurEnvie() {nombreJoueurEnVie--;}









};


#endif

