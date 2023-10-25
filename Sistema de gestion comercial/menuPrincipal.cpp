#include <iostream>
//#include <cstdlib>
#include "rlutil.h"
#include "menuPrincipal.h"
#include "menuClientes.h"
#include "menuArticulos.h"
#include "menuVentas.h"
#include "showItem.h"

void menuPrincipal()
{
    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||          MENU PRINCIPAL           ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("             MENU CLIENTES             ", 40, 13, y == 0);
        showItem("             MENU ARTICULOS            ", 40, 14, y == 1);
        showItem("             MENU VENTAS               ", 40, 15, y == 2);
        showItem("             CONFIGURACION             ", 40, 16, y == 3);
        rlutil::locate(40, 17);
        std::cout << "---------------------------------------" << std::endl;
        showItem("                 SALIR                 ", 40, 18, y == 4);

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: //UP
            rlutil::locate(38,13 + y);
            std::cout << " " << std::endl;
            y--;

            if(y < 0)
            {
                y = 0;
            }
            break;

        case 15: //DOWN
            rlutil::locate(38,13 + y);
            std::cout << " " << std::endl;
            y++;

            if(y > 4)
            {
                y = 4;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                menuClientes();
                break;

            case 1:
                system("cls");
                menuArticulos();
                break;

            case 2:
                system("cls");
                menuventa();
                break;

            case 3://menuConfi();
                system("cls");
                break;

            case 4:
                op = 0;
                break;
            }
        }
    }

    while(op != 0);

    return;
}

