#ifndef TEST_ELEMENT
#define TEST_ELEMENT

#include "interact_with_ui.hpp"


class TestElement : public InteractWithUI{
private:
    string m_TextureFileName;
    double m_positionX, m_positionY;

public:
    TestElement(string textureFileName) : TestElement(0,0,textureFileName) {};
    TestElement(double positionX, double positionY, string textureFileName) : m_positionX(positionX),m_positionY(positionX),m_TextureFileName(textureFileName) {}
    string textureFileName() const;
    void actionForRighClick(int mousePositionX, int mousePositionY);
    void getPosition(double &x, double &y) const;
};






#endif