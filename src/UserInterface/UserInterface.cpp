#include "UserInterface.hpp"
#include "SpriteForUI.hpp"
#include "drawable_for_ui.hpp"
#include "../case.hpp"
#include "../AffichableOnMap/marque.hpp"
#include "../AffichableOnMap/terrain.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"
#include "../utile.hpp"
#include  "../hud.hpp"
#include "../info_commande.hpp"


using namespace std;

UserInterface::UserInterface()   {
    // /!!! \ 
    // il ne faut pas que cette fonction utilise de Jeu::getInstance() car Jeu utilise UserInterface::getInstance() dans son constructeur
    // /!!!\ .
    


    position_camera_X = 10 ;
    position_camera_Y = 10 ;


    if (!DEBUG_UI) {
        window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"Jeu");
    }
    
    window->setFramerateLimit(FPS);

    loadRessources();
    for (int i = 0; i < NOMBRE_COUCHE_DRAWABLES; i++)
    {
        ensembleDrawables[i] = new std::set<DrawableForUI*>();
    }

    marqueSelect = nullptr;

    isMousePressed = false;

    infoCommande = nullptr;


        








};

const std::string UserInterface::TRANSPARENCY_TEXTURE_NAME="transparency.png";

UserInterface* UserInterface::m_instance = nullptr;

UserInterface& UserInterface::getInstance() {
    if (UserInterface::m_instance ==nullptr) {
        UserInterface::m_instance = new UserInterface();
    }
    return *UserInterface::m_instance;
}



Pixel UserInterface::case2pixel(int case_x, int case_y) const{
    //VERSION CARRE
    // pixel.i = (case_x-0.5)*width_case + WINDOW_WIDTH/2;
    // pixel.j = -(case_y+0.5)*height_case+ WINDOW_HEIGHT/2;


    Pixel pixel;
    
    //decalage alterne celon y%2 pour x
    //redimensionner avec largeur de la case
    pixel.i = (case_x +0.5*(case_y%2))*width_case*1.5 ; 
    pixel.j = -(case_y)*height_case/2 ; 

    //centrage du sprite de l'image
    pixel.i -= 0.5*width_case;
    pixel.j -= 0.5*height_case;

    //centrage du (0,0) au milieu de la fenetre
    pixel.i += WINDOW_WIDTH/2;
    pixel.j += WINDOW_HEIGHT/2;

    //reajustement en fonction de la position de la camera
    pixel.i -= position_camera_X;
    pixel.j += position_camera_Y;


    return pixel;
}


CasePosition UserInterface::pixel2case(int pixel_i, int pixel_j) const{
    double position_case_x = pixel_i;
    double position_case_y = pixel_j;

    position_case_x += position_camera_X;
    position_case_y -= position_camera_Y;

    position_case_x-= WINDOW_WIDTH/2;
    position_case_y-= WINDOW_HEIGHT/2;

    position_case_x/=width_case*1.5/2;
    position_case_y/=-height_case/2;

    //on est sous la forme ou quand on va en diagonal en haut a droite on ajout +1 a x et y 
    

    //position_reduite permet de determiner si on est dans la cas carre ou triangle 
    double position_reduite_x = fmod(position_case_x,2);
    if (position_reduite_x<0)
        position_reduite_x+=2;
    
    if (position_reduite_x < 0.5 || position_reduite_x>=1.5) {  // cas carre 
        position_case_y = floor(0.5+position_case_y/2)*2;
        position_case_x = floor((position_case_x+0.5)/2);
    }
    else{  // cas carre decale vers le haut
        position_case_y = floor(position_case_y/2)*2+1;
        position_case_x = floor((position_case_x-0.5)/2);
        if (position_case_y<=0) //jsp pas pourquoi
            position_case_x+=1;
    }



    /* VERSION COMPLETE
    if (position_reduite_x < 0.333 || position_reduite_x>=1.666) {  // cas carre 
        cout <<"cas carre "<<endl;
    }
    else if (position_reduite_x >= 0.333 && position_reduite_x<0.667) {  // cas triangle
        cout <<"cas triangle "<<endl;
    }
    else if (position_reduite_x >= 0.667 && position_reduite_x<1.333) {  // cas carre decale vers le haut
        cout << "position_case_x_reel "<<position_case_x<<" position_case_y_reel "<<position_case_y<<endl;
    }
    else {  // cas triangle inverse
        cout <<"cas triangle inverse "<<endl;
    }
    */

    CasePosition point(position_case_x,position_case_y);


    return point;




}





void UserInterface::loadRessources() {
    // Chargement textures
    for (const auto & entry : std::filesystem::directory_iterator(TEXTURES_PATH)) {
        Texture_ptr texture = make_shared<sf::Texture>(); 
        if (!texture->loadFromFile(entry.path()) ){
            cerr << "UserInterface::loadRessources() -> [!] impossible de charger le fichier " << entry.path() << endl;
            throw std::runtime_error("");
        }
        textures[entry.path()] = texture;
        cout << "texture chargee :  " <<  entry.path() << endl;
    }
    // Chargement fonts
    for (const auto & entry : std::filesystem::directory_iterator(FONTS_PATH)) {
        Font_ptr font = make_shared<sf::Font>(); 
        if (!font->loadFromFile(entry.path()) ){
            cerr << "UserInterface::loadRessources() -> [!] impossible de charger le fichier " << entry.path() << endl;
            throw std::runtime_error("");
        }
        fonts[entry.path()] = font;
        cout << "font chargee :  " <<  entry.path() << endl;
    }
    // Chargement sounds
    for (const auto & entry : std::filesystem::directory_iterator(SOUNDS_PATH)) {
        SoundBuffer_ptr sound = make_shared<sf::SoundBuffer>(); 
        if (!sound->loadFromFile(entry.path()) ){
            cerr << "UserInterface::loadRessources() -> [!] impossible de charger le fichier " << entry.path() << endl;
            throw std::runtime_error("");
        }
        sounds[entry.path()] = sound;
        cout << "soundBuffer chargee :  " <<  entry.path() << endl;
    }
}


Texture_ptr UserInterface::getTexture(std::string file_name) const {
    std::string path_file_name = TEXTURES_PATH +"/"+file_name;
    if (textures.find(path_file_name) == textures.end()) {
        string erreur = "UserInterface::getTexture -> chargement impossible de la texture "+file_name;
        throw runtime_error(erreur);
    }
    return textures.at(path_file_name);
}

Font_ptr UserInterface::getFont(std::string file_name) const {
    std::string path_file_name = FONTS_PATH+"/"+file_name;
    if (fonts.find(path_file_name) == fonts.end()) {
        string erreur = "UserInterface::getTexture -> chargement impossible de la texture "+file_name;
        throw runtime_error(erreur);
    }
    return fonts.at(path_file_name);
}

SoundBuffer_ptr UserInterface::getSoundBuffer(std::string file_name) const {
    std::string path_file_name = SOUNDS_PATH +"/"+file_name;
    if (sounds.find(path_file_name) == sounds.end()) {
        string erreur = "UserInterface::getTexture -> chargement impossible de la texture "+file_name;
        throw runtime_error(erreur);
    }
    return sounds.at(path_file_name);
}


void UserInterface::addDrawable(DrawableForUI* drawable ) {



    if (drawable->getCouche()>=NOMBRE_COUCHE_DRAWABLES ) {
        throw std::runtime_error("UserInterface::addSprite -> couche plus important que le nombre de couche pour afficher les drawables");
    }

    if (drawable->getCouche()<0) {
        throw std::runtime_error("UserInterface::addSprite -> couche negative pour afficher le drawable");
    }

    ensembleDrawables[drawable->getCouche()]->insert(drawable) ;


}

void UserInterface::removeDrawable(DrawableForUI* drawable) {
    ensembleDrawables[drawable->getCouche()]->erase(drawable);
}


void UserInterface::addCommande(Commande *commande) {
    ensembleCommandes.insert(commande);
}

void UserInterface::removeCommande(Commande *commande) {
    if(ensembleCommandes.erase(commande)!=1) {
        Utile::warning("UserInterface::removeCommande","le nombre d'element enleve n'est pas de 1");
    }
}


void UserInterface::updateWindow() {
    
    window->clear();

    // // [!] TESTE

    // // Declare and load a font
    // sf::Font font;
    // font.loadFromFile("Classica-Book.ttf");
    // // Create a text
    // sf::Text text("hello", font);
    // text.setCharacterSize(30);
    // text.setStyle(sf::Text::Bold);
    // text.setFillColor(sf::Color::Red);

    // window->draw(text);



    DrawableForUI* drawable;
    for (int i = 0; i < NOMBRE_COUCHE_DRAWABLES; i++)
    {
        for (auto it = ensembleDrawables[i]->begin(); it != ensembleDrawables[i]->end(); it++)
        {

            
            drawable = *it;
            drawable->updateFromCam();
            drawable->drawOn(*window);
            //window->draw(*sprite);
        }
    }
    window->display();
}



void UserInterface::runMainLoop(){


    
             
    initUI();
    while (window->isOpen())
    {




        // ---Gestion des événements---
        list_event_ptr listEvent =  getEvents();
        testQuit(listEvent);



        moveWindowWithMouse();


        updateWindow();


        Hud& hud = Jeu::getInstance().getHud();
        sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
        

        updateInfoCommande();




        if (!checkClikedCommandes() && !hud.pixelIsOn(localPosition.x,localPosition.y)) { //active selection case que si aucune commande active et pas sur le dashboard

            checkSelectCase();
        }


        updateOverMarque();






    }
	
}


void UserInterface::moveWindowWithMouse() {
        sf::Vector2i localPosition = sf::Mouse::getPosition(*window);

        double deplacementCameraExacte = ajoutDeplacementCamera/((float)FPS);

        //deplacement camera via souris
        
        // [!] TEMPORAIREMMENT ENLEVE
        // if (localPosition.x > WINDOW_WIDTH) {
        //     position_camera_X += deplacementCameraExacte;
        // }
        // if (localPosition.x < 0) {
        //     position_camera_X -= deplacementCameraExacte;
        // }
        // if (localPosition.y > WINDOW_HEIGHT) {
        //     position_camera_Y -= deplacementCameraExacte;
        // }
        // if (localPosition.y < 0) {
        //     position_camera_Y += deplacementCameraExacte;
        // }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            position_camera_X -= deplacementCameraExacte;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            position_camera_X += deplacementCameraExacte;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            position_camera_Y += deplacementCameraExacte;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            position_camera_Y -= deplacementCameraExacte;
        }

}


bool UserInterface::checkCommandes() {
    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
    bool uneCommandeActive = false;
    for (auto it = ensembleCommandes.begin(); it != ensembleCommandes.end() ; it++)
    {
        
        if ((*it)->pixelIsOn(localPosition.x,localPosition.y)) {
            (*it)->execute();
            uneCommandeActive = true;
            break; // permet d'activer une seul commande => evite bug si la commande fait un pushCommande
        }

    }
    return uneCommandeActive;
}

void UserInterface::updateInfoCommande() {
    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
    bool uneCommandeActive = false;
    Pixel position_commande;
    for (auto it = ensembleCommandes.begin(); it != ensembleCommandes.end() ; it++)
    {

        if ((*it)->pixelIsOn(localPosition.x,localPosition.y)) {
            uneCommandeActive = true;
            // [!] pas tres efficace
            int bois;
            int nourriture;
            int _or;
            (*it)->prix(bois,nourriture,_or);
            

            infoCommande->setInfo(bois,nourriture,_or,(*it)->getInfo());

            //position_commande = (*it)->getPosition();

            //infoCommande->setPosition(sf::Vector2f(position_commande.i+5,position_commande.j+5));
            break;
        }

    }
    if (!uneCommandeActive) {
        infoCommande->clear();
    }
}




bool UserInterface::checkClikedCommandes() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!isMousePressed)
        {
            isMousePressed = true;
            return checkCommandes();
        }
        isMousePressed = true;
    }
    else {
        isMousePressed = false;
    }
    return false;
}

void UserInterface::testQuit(list_event_ptr eventList) {
    for (auto it = eventList->begin(); it != eventList->end(); ++it) {
        sf::Event &event = *it;
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}


void UserInterface::compute_fps() {
    int num_frames = 0;
    auto start_time = std::chrono::high_resolution_clock::now();
    auto end_time = start_time;

    while (true) {
        // Do some computation or rendering here
        num_frames++;

        // Check if 100 ms have elapsed
        end_time = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        if (elapsed_time >= 100) {
            // Compute and print fps
            double fps = (double)num_frames / ((double)elapsed_time / 1000.0);
            std::cout << "FPS: " << fps << std::endl;

            // Reset counters and start time
            num_frames = 0;
            start_time = end_time;
        }
    }
}

void UserInterface::runComputeFps() {
    std::thread fps_thread(&UserInterface::compute_fps, this);
    fps_thread.detach();
}



Pixel &Pixel::operator=(const Pixel& other) {
    i=other.i;
    j=other.j;
    return *this;
}


list_event_ptr UserInterface::getEvents() {

    list_event_ptr eventList = std::make_shared<list<sf::Event>>();


    sf::Event event;
    while (window->pollEvent(event)) {
        // Stockage de l'événement dans la liste
        eventList->push_back(event);

    }

    return eventList;
}

void UserInterface::updateOverMarque() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    CasePosition position = pixel2case(mousePosition.x,mousePosition.y);
    if (Jeu::getInstance().getPlateau().inPlateau(position)) {
        marqueOver->moveToPosition(pixel2case(mousePosition.x,mousePosition.y));
    }
}



void UserInterface::initUI() {
    marqueOver = new Marque(Marque::OVER,Jeu::getInstance().getPlateau());
    infoCommande = new InfoCommande(COUCHE_INFO_COMMANDE);
}


void UserInterface::selectCase() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    CasePosition position = pixel2case(mousePosition.x,mousePosition.y);

    if (Jeu::getInstance().getPlateau().inPlateau(position)) {

        if (marqueSelect==nullptr) {
            marqueSelect = new Marque(Marque::SELECT,Jeu::getInstance().getPlateau());
        }

        CasePosition cp = pixel2case(mousePosition.x,mousePosition.y);
        Case_ptr case_ = Jeu::getInstance().getPlateau().getCaseAt(cp); 

        marqueSelect->moveToPosition(cp);


        selectedCase = cp;

        Jeu::getInstance().getJoueurActif()->whenSelectCase(case_);

                
    }


}



void UserInterface::deselectCase() {
    if (marqueSelect!=nullptr) {
        delete marqueSelect;
        marqueSelect = nullptr;
    }
    UserInterface::getInstance().clearCircle();
    Jeu::getInstance().getJoueurActif()->whenDeselectCase();
}


void UserInterface::checkSelectCase() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        selectCase();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        deselectCase();
    }
}


void UserInterface::drawCircle(float rayon, CasePosition centre) {
    CasePosition point(0,0);
    for (int x=centre.x-rayon*2; x<centre.x+rayon*2; x++) {
        for (int y = centre.y-rayon*2; y < centre.y+rayon*2; y++)
        {
            point.x =x; point.y=y;
            if (Jeu::getInstance().getPlateau().inPlateau(point) && Plateau::distance(point,centre)<=rayon) {
                Marque* marque= new Marque(Marque::CIRCLE,Jeu::getInstance().getPlateau());
                marque->moveToPosition(point);
                marquesCircle.insert(marque);

            }

            

        }
        
    }



}

void UserInterface::clearCircle() {
    for (auto it = marquesCircle.begin(); it!=marquesCircle.end();it++) {
        delete (*it);
    }
    marquesCircle.clear();
}


void UserInterface::goToJoueurActif() {
    Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
    CasePosition caseDepart = joueur_actif->getCaseDepart();
    goTo(caseDepart);
}

void UserInterface::goTo(CasePosition position) {
    int previsous_position_camera_X = position_camera_X;
    int previsous_position_camera_Y = position_camera_Y;

    Pixel ajout = case2pixel(position.x,-position.y);
    // permet d'annuler l'offset camera de la fonction case2pixel(),
    // et de la fenetre :
    position_camera_X=ajout.i+previsous_position_camera_X-WINDOW_WIDTH/2;
    position_camera_Y=ajout.j-previsous_position_camera_Y-WINDOW_HEIGHT/2;    
}



void UserInterface::nouveauTour() {
    goToJoueurActif();
    clearCircle();
}