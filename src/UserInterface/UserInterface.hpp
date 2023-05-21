#ifndef USER_INTERFACE
#define USER_INTERFACE

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <tgmath.h>
#include <map>
#include <memory>
#include <string>
#include <filesystem>
#include <thread>
#include <set>
#include "../case.hpp"
#include "../Commande/commande.hpp"
#include <list>
#include <SFML/Audio.hpp>

#define DEBUG_UI false // quand active empeche de genere une fenetre







namespace fs = std::filesystem;

class SpriteForUI;
class DrawableForUI;
typedef std::shared_ptr<SpriteForUI> SpriteForUI_ptr;
class Marque;
class InfoCommande;







class Pixel {

	public:

		int i;
		int j;

        Pixel() : Pixel(0,0) {};

		Pixel(int i, int j) {
				this->i = i;
				this->j = j;
			}
	
		Pixel &operator=(const Pixel& other);
	
};

typedef struct Point_
{
	int x;
	int y;
}Point;






typedef std::shared_ptr<sf::Texture> Texture_ptr;
typedef std::shared_ptr<sf::Font> Font_ptr;
typedef std::shared_ptr<sf::SoundBuffer> SoundBuffer_ptr;




typedef std::shared_ptr<sf::Sprite> Sprite_ptr; //[!] A enlever
typedef std::shared_ptr<std::list<sf::Event>> list_event_ptr;




// singleton [!] il faudra le rendre thread safe si on utilise des thread
// permet de gerer l'affichage des SpritesForUI, les commandes, la selection de cases et le deplacement de la camera
// ne s'occupe pas de crééer les choses à afficher mais uniquement que l'affichage soit possible (à l'exception de la selection de cases)
class UserInterface{
	public :

		// ---CONSTANTES---

		static const int NOMBRE_COUCHE_DRAWABLES = 40; // nombre de couche de drawable pour ordre d'affichage
		static const std::string TRANSPARENCY_TEXTURE_NAME;


		

	private :


		// ---SINGLETON PATERN ----

		UserInterface() ;



		static UserInterface *m_instance;
		
		// ---CONSTANTES---

		static const int FPS = 60;

		static const int COUCHE_INFO_COMMANDE = 35;

		static const std::string MUSIC_FILE_NAME;


		// --- VARIABLES ---



		//camera
		double position_camera_X; //en pxl
		double position_camera_Y; //en pxl
		const int width_case = 135; //en pixel 
		const int height_case = 80; //en pixel 
		const double inclinaison_camera = ((double)height_case)/((double)width_case); //de 1 (au dessus) à 0 non compris  (de cote) 
		//defini l'increment de la camera a chaque iteration
		const double ajoutDeplacementCamera=500;  //en pxl par seconde


		const std::string MUSICS_PATH = "Ressources/Musics";
		const int musicVolume = 15;

		const std::string TEXTURES_PATH = "Ressources/Textures";
		std::map<std::string,Texture_ptr> textures;
		const std::string FONTS_PATH = "Ressources/Fonts";
		std::map<std::string,Font_ptr> fonts;
		const std::string SOUNDS_PATH = "Ressources/Sounds";
		std::map<std::string,SoundBuffer_ptr> sounds;



		
		
		// tous les drawables du jeu
		// par couche puis par numero de serie
		std::set<DrawableForUI*> *ensembleDrawables[NOMBRE_COUCHE_DRAWABLES];

		std::set<Commande*> ensembleCommandes;

		sf::RenderWindow *window;


		CasePosition selectedCase;



		// marques :

		// marque qui est au dessus de la case pointe par la souris
		// oblige d'etre un pointeur sinon impossible a cause de dependance circulaire entre .h
		Marque *marqueOver;

		// marque qui est au dessus de la case selectionne
		Marque *marqueSelect;

		// Marque pour faire des cercle
		std::set<Marque*> marquesCircle; 

		bool isMousePressed; //permet de faire en sorte qu'il faut reclicker pour faire une deuxieme action

		bool isCaseSelect; //permet de faire en sorte qu'il faut reclicker pour selectionner a nouveau une case

		InfoCommande *infoCommande;

		// permet de jouer la musique du jeu
		sf::Music music;

		// permet a UserInterface::playSound() d'y charger une musique et de la jouer
		sf::Sound sound;


		// ---FONCTIONS---


		void updateWindow();

		// [!] pas optimise on parcours plusieurs fois la liste quand on utilise
		// renvoie les envenement dans window.pollEvent
		list_event_ptr getEvents();


		// quite si croix clické
		void testQuit(list_event_ptr eventList);


		void loadRessources();

		void compute_fps();

		// /!!!\ dangereux /!!!\
		// singleton pas thread safe => peut poser des problèmes
		// SEMBLE NE PAS MARCHER
		void runComputeFps();

		void moveWindowWithMouse();
		

		// active les commandes qui ont la souris dessus 
		// renvoie si une commande a ete active
		// à appeler quand on click avec la souris
		bool checkCommandes();

		// active les commandes qui ont la souris dessus quand on click avec la souris
		// renvoie si une commande a ete active
		// gere le faite qu'il faut reclacher puis reclicker pour faire une nouvelle action
		bool checkClikedCommandes();

		// met infoCommande sur la commande active quand la souris passe dessus
		void updateInfoCommande();

		// [!] pas trop optimise -> place a chaque fois
		// met le marqueur over a la bonne position
		void updateOverMarque();

		// initialisation à faire apres le construceteur, mise dans runMainLoop
		// permet d'utiliser jeu::getInstance()
		// permet d'utiliser UserInterface::getInstance()
		void initUI();


		

		// ENDROIT OU SE FAIT LA DISTINCTION DU JOUEUR ACTIF :
		// selectionne la case sur laquelle la souris est, mis dans selectedCase
		// appelle whenSelectCase() de Joueur actif
		void selectCase();

		// deselctionne selectedCase
		// appelle whenDeselectCase() de joueur actif
		void deselectCase();

		// appelle selectCase() si click gauche, appelle deselectCase() si click droit
		void checkSelectCase();

		// met la camera a une certaine position
		void goTo(CasePosition position);


		// met la camera sur la case de depart du joueur actif
		void goToJoueurActif();


	public :





		// ---SINGLETON PATERN---
		static UserInterface &getInstance() ;
		void operator=(const UserInterface &) = delete;
		UserInterface(UserInterface &other) = delete;

		// ---CONSTANTES---

		static const int WINDOW_HEIGHT =  1080-40; // [!] permet d'avoir la bordure en haut, a modifier?
		static const int WINDOW_WIDTH = 1920;


		// ---FONCTIONS---

		//transforme une positon de case en la position du pixel en haut à gauche de la case correspondant
		Pixel case2pixel(int case_x, int case_y) const;
		//transforme un pixel en la position de la case correspondante
		CasePosition pixel2case(int pixel_i, int pixel_j) const;



		
		Texture_ptr getTexture(std::string file_name) const;
		Font_ptr getFont(std::string file_name) const;
		SoundBuffer_ptr getSoundBuffer(std::string file_name) const;

		// si file_name = "" ne joue acun son 
		void playSound(std::string file_name);


		void addDrawable(DrawableForUI* drawable);

		void removeDrawable(DrawableForUI* drawable);

		void addCommande(Commande *commande);

		void removeCommande(Commande *commande);



		// [!] devra etre remplace par un systeme de thread
		// [!] a n'appeler qu'une seule fois
        void runMainLoop();
		


		std::string get_TEXTURES_PATH() const { return TEXTURES_PATH;}


		void drawCircle(float rayon, CasePosition centre);

		void clearCircle();

		CasePosition getSelectedCase() {return selectedCase;}

		// appele par le jeu lors d'un nouveau tour
		// met la camera sur la caseDepart du joueur actif
		// efface le cercle 
		void nouveauTour();



		







};




#endif


