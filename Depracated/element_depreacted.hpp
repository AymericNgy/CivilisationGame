// // [!] classe désué comportement remplacé par affichableOnMap

// #ifndef ELEMENT
// #define ELEMENT

// #include <string>
// #include <list>
// #include <set>
// #include "../Commande/commande_affichable_on_map.hpp"
// #include <memory>

// class Joueur;



// class Element {
//     protected:
//         std::string m_TextureFileName;
//         double m_positionX, m_positionY;
        

//         virtual void setTextureFileName()=0;

//     public:
//         Element() : m_positionX(0), m_positionY(0) {this->setTextureFileName();};
//         virtual std::string getTextureFileName() const;
//         virtual void getPosition(double &x, double &y) const {x = m_positionX; y = m_positionY;};
//         virtual void setPosition(double x, double y){ m_positionX = x; m_positionY = y;};
//         virtual std::list<CommandeAffichableOnMap_ptr> getActionPossible(Joueur &joueur)=0;

// };

// typedef std::shared_ptr<Element> Element_ptr;







// #endif