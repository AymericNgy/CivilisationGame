#ifndef INFO_COMMAND
#define INFO_COMMAND


#include "UserInterface/text_for_ui.hpp"
#include "UserInterface/rectangle_for_ui.hpp"
#include "AffichableOnPanel/dashboard.hpp"

class InfoCommande {
    private :
        const static sf::Color COLOR_RECTANGLE;
        const static sf::Color COLOR_TEXT;

    static const int CHARACTER_SIZE = 18;
    static const int POSITION_X = Dashboard::POSITION_X;
    static const int POSITION_Y = Dashboard::POSITION_Y;


        RectangleForUI rectangle;
        TextForUI info;

    
    public :

        InfoCommande(int couche);
        
        void clear();

        void setInfo(int prix_bois, int prix_nourriture, int prix_or,const sf::String &info);

        void setPosition(const sf::Vector2f &position);
        




};







#endif
