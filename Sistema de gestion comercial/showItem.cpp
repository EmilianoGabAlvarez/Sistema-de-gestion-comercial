#include <iostream>
#include <cstdlib>

#include "rlutil.h"
#include "showItem.h"

void showItem(const std::string text, int posx, int posy, bool selected)
{
    if(selected)
    {
        setBackgroundColor(rlutil::BLUE);
        //locate(posx -4, posy);
        //cout << " " << text << " " << endl;
    }
    else
    {
        setBackgroundColor(rlutil::BLACK);
        //locate(posx -4, posy);
        //cout << " " << text << " " << endl;
    }

    rlutil::locate(posx, posy);
    std::cout << text << std::endl;
    setBackgroundColor(rlutil::BLACK);
}
