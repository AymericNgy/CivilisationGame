#ifndef INTERACT_WITH_UI
#define INTERACT_WITH_UI

#include <string>
using namespace std;



/*
classe abstraite
*/
class InteractWithUI {
public :
    virtual string textureFileName() =0;
    virtual void actionForRighClick(int mousePositionX, int mousePositionY)=0;
    virtual void getPosition(double &x, double &y)=0;
};




#endif 