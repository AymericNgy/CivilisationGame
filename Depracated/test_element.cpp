#include "test_element.hpp"
#include <iostream>


using namespace std;

string TestElement::textureFileName() const{
    return this->m_TextureFileName;
}



void actionForRighClick(int mousePositionX, int mousePositionY) {
    cout << "la souris est en X " << mousePositionX << " et en Y "<< mousePositionY <<"lors de mon clique droit"<<endl;
}


void TestElement::getPosition(double &x, double &y) const{
    x=m_positionX;
    y=m_positionY;
}






