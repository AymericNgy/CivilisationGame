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






/**
 * \class Pixel
 * \brief position d'un pixel sur l'ecran
*/
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

/**
 * \class Point
 * \brief position d'un point sur l'ecran
*/
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




/**
 * \class UserInterface
 * \brief permet de gerer l'affichage des DrawblesForUI, les commandes, la selection de cases et le deplacement de la camera
 * ne s'occupe pas de crééer les choses à afficher mais uniquement que l'affichage soit possible (à l'exception de la selection de cases)
 */
class UserInterface{
	public :

		// ---CONSTANTES---

		/**
		 * \brief nombre de couche de drawable pour ordre d'affichage
		*/
		static const int NOMBRE_COUCHE_DRAWABLES = 40;

		/**
		 * \brief nom de la texture transaprante
		 * permet de faire des transparantes sans apparances
		*/
		static const std::string TRANSPARENCY_TEXTURE_NAME;


		

	private :


		// ---SINGLETON PATERN ----

		/**
		 * \brief constructeur par defaut
		 * \details initialise la fenetre, les marques, les textures, les fonts, les sons
		*/
		UserInterface() ;


		/**
		 * \brief instance unique de UserInterface
		*/
		static UserInterface *m_instance;
		
		// ---CONSTANTES---

		/**
		 * \brief nombre de FPS
		*/
		static const int FPS = 60;

		/**
		 * \brief couche de l'info commande
		*/
		static const int COUCHE_INFO_COMMANDE = 35;

		/**
		 * \brief nom du fichier de la musique
		*/
		static const std::string MUSIC_FILE_NAME;


		// --- VARIABLES ---



		//camera
		/**
		 * \brief position de la camera en pixel
		*/
		double position_camera_X; 

		/**
		 * \brief position de la camera en pixel
		*/
		double position_camera_Y; 

		/**
		 * \brief largeur de la case en pixel
		*/
		const int width_case = 135; 

		/**
		 * \brief hauteur de la case en pixel
		*/
		const int height_case = 80; 

		/**
		 * \brief inclinaison de la camera
		 * \details de 1 (au dessus) à 0 non compris  (de cote)
		*/
		const double inclinaison_camera = ((double)height_case)/((double)width_case); 


		//defini l'increment de la camera a chaque iteration
		/**
		 * \brief increment de la camera en pixel en pxl par seconde
		*/
		const double ajoutDeplacementCamera=500;  

		/**
		 * chemin vers le dossier des musiques
		*/
		const std::string MUSICS_PATH = "Ressources/Musics";

		/**
		 * \brief volume de la musique sur 100
		*/
		const int musicVolume = 15;

		/**
		 * chemin vers le dossier des textures
		*/
		const std::string TEXTURES_PATH = "Ressources/Textures";

		/**
		 * \brief textures chargees
		*/
		std::map<std::string,Texture_ptr> textures;

		/**
		 * chemin vers le dossier des fonts
		*/
		const std::string FONTS_PATH = "Ressources/Fonts";

		/**
		 * \brief fonts chargees
		*/
		std::map<std::string,Font_ptr> fonts;

		/**
		 * chemin vers le dossier des sons
		*/
		const std::string SOUNDS_PATH = "Ressources/Sounds";

		/**
		 * \brief sons chargees
		*/
		std::map<std::string,SoundBuffer_ptr> sounds;



		
		
		/**
		 * \brief ensemble des drawables du jeu
		 * \details par couche 
		*/
		std::set<DrawableForUI*> *ensembleDrawables[NOMBRE_COUCHE_DRAWABLES];

		/**
		 * \brief ensemble des commandes du jeu
		*/
		std::set<Commande*> ensembleCommandes;

		/**
		 * \brief fenetre du jeu
		*/
		sf::RenderWindow *window;

		/**
		 * \brief case selectionnee par le joueur
		*/
		CasePosition selectedCase;



		// marques :


		/**
		 * \brief marque qui est au dessus de la case pointe par la souris \n
		*/
		Marque *marqueOver;


		/**
		 * \brief marque qui est au dessus de la case selectionne
		*/
		Marque *marqueSelect;



		/**
		 * \brief maque pour faire des cercles
		*/
		std::set<Marque*> marquesCircle; 


		/**
		 * \brief permet de faire en sorte qu'il faut reclicker pour faire une deuxieme action
		*/
		bool isMousePressed; 


		/**
		 * \brief permet de faire en sorte qu'il faut reclicker pour selectionner a nouveau une case
		*/
		bool isCaseSelect; 

		/**
		 * \brief info de la commande survollée par la souris
		*/
		InfoCommande *infoCommande;


		/**
		 * \brief musique du jeu
		*/
		sf::Music music;


		/**
		 * \brief permet a UserInterface::playSound() d'y charger une musique et de la jouer
		*/
		sf::Sound sound;


		// ---FONCTIONS---

		/**
		 * \brief met a jour la fenetre avec les drawables
		*/ 
		void updateWindow();



		/**
		 * \brief renvoie les envenement dans window.pollEvent
		*/
		list_event_ptr getEvents();



		/**
		 * \brief quite si la croix est clické
		*/
		void testQuit(list_event_ptr eventList);

		/**
		 * \brief charges les textures, les fonts, les musiques \n
		 * met un message d'erreur si existe pas
		*/
		void loadRessources();





		/**
		 * \brief deplace la camera avec les touches du clavier : bas gauche droite haut
		*/
		void moveWindowWithMouse();
		


		/**
		 * \brief active les commandes qui ont la souris dessus \n
		 * renvoie si une commande a ete active \n
		 * à appeler quand on click avec la souris
		*/
		bool checkCommandes();


		/**
		 * \brief active les commandes qui ont la souris dessus quand on click avec la souris \n
		 * renvoie si une commande a ete active \n
		 * gere le faite qu'il faut reclacher puis reclicker pour faire une nouvelle action
		*/
		bool checkClikedCommandes();


		/**
		 * \brief met infoCommande sur la commande active quand la souris passe dessus
		*/
		void updateInfoCommande();


		/**
		 * \brief met le marqueur over a la bonne position
		*/
		void updateOverMarque();


		/**
		 * \brief initialisation a faire apres le construceteur, mise dans runMainLoop \n
		 * permet d'utiliser jeu::getInstance() \n
		 * permet d'utiliser UserInterface::getInstance()
		*/
		void initUI();




		



		/**
		 * \brief ENDROIT OU SE FAIT LA DISTINCTION DU JOUEUR ACTIF :
		 * selectionne la case sur laquelle la souris est, mis dans selectedCase \n
		 * appelle whenSelectCase() de Joueur actif
		*/
		void selectCase();


		/**
		 * \brief deselctionne selectedCase \n
		 * appelle whenDeselectCase() de joueur actif
		*/
		void deselectCase();



		/**
		 * \brief appelle selectCase() si click gauche, appelle deselectCase() si click droit
		*/
		void checkSelectCase();


		/**
		 * \brief met la camera a une certaine position
		*/
		void goTo(CasePosition position);



		/**
		 * \brief met la camera sur la case de depart du joueur actif
		*/
		void goToJoueurActif();


	public :





		// ---SINGLETON PATERN---
		static UserInterface &getInstance() ;
		void operator=(const UserInterface &) = delete;
		UserInterface(UserInterface &other) = delete;

		// ---CONSTANTES---


		static const int WINDOW_HEIGHT =  1080-40; 
		static const int WINDOW_WIDTH = 1920;


		// ---FONCTIONS---


		/**
		 * \brief transforme une positon de case en la position du pixel en haut à gauche de la case correspondant
		*/
		Pixel case2pixel(int case_x, int case_y) const;


		/**
		 * \brief transforme une positon de pixel en la position de la case correspondante
		*/
		CasePosition pixel2case(int pixel_i, int pixel_j) const;



		/**
		 * \brief renvoie la texture de nom file_name \n
		 * erreur si existe pas
		 * \param file_name nom du fichier
		*/
		Texture_ptr getTexture(std::string file_name) const;

		/**
		 * \brief renvoie la font de nom file_name \n
		 * erreur si existe pas
		 * \param file_name nom du fichier
		*/
		Font_ptr getFont(std::string file_name) const;


		/**
		 * \brief renvoie le ssoundBuffer de nom file_name \n
		 * erreur si existe pas
		 * \param file_name nom du fichier
		*/
		SoundBuffer_ptr getSoundBuffer(std::string file_name) const;


		/**
		 * \brief joue le son de nom file_name \n
		 * si file_name = "" ne joue acun son \n
		*/
		void playSound(std::string file_name);

		/**
		 * \brief ajoute un drawable a la liste des drawables
		 * /!\ doit etre fait uniquement par \sa DrawableForUI::addToUI()
		*/
		void addDrawable(DrawableForUI* drawable);

		/**
		 * \brief enleve un drawable a la liste des drawables
		 * /!\ doit etre fait uniquement par \sa DrawableForUI::removeFromUI()
		*/
		void removeDrawable(DrawableForUI* drawable);

		/**
		 * \brief ajoute une commande a la liste des commandes
		 * /!\ doit etre fait uniquement par \sa Commande::Commande()
		*/
		void addCommande(Commande *commande);

		/**
		 * \brief enleve une commande a la liste des commandes
		 * /!\ doit etre fait uniquement par \sa ~Commande::Commande()
		*/
		void removeCommande(Commande *commande);




		/**
		 * \brief lance la boucle principale de l'interface utilisateur \n
		 * /!\ ne doit etre appelé qu'une seule fois
		*/
        void runMainLoop();
		

		/**
		 * \brief renvoie le chemin vers le dossier des textures
		*/
		std::string get_TEXTURES_PATH() const { return TEXTURES_PATH;}

		/**
		 * \brief dessine un cercle de rayon rayon et de centre centre
		 * \param rayon rayon du cercle
		 * \param centre centre du cercle
		*/
		void drawCircle(float rayon, CasePosition centre);

		/**
		 * \brief efface le cercle dessiné par drawCircle()
		*/
		void clearCircle();

		/**
		 * \brief renvoie la case selectionnée par la souris
		*/
		CasePosition getSelectedCase() {return selectedCase;}



		/**
		 * \brief appele par le jeu lors d'un nouveau tour \n
		 * met la camera sur la caseDepart du joueur actif \n
		 * efface le cercle si il est dessine
		*/
		void nouveauTour();



		/**
		 * \brief cree les marque lorsque que l'on est en partie
		*/
		void initUIForPartie();


		/**
		 * \brief detruit les marque lorsque la partie est finie
		*/
		void finishUIForEndPartie();







};




#endif


