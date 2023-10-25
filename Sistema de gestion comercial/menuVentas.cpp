#include <iostream>
#include "rlutil.h"
#include "menuVentas.h"
#include "ClsArchivoVentas.h"
#include "showItem.h"

void menuventa()
{
    ArchivoVentas ven("ventas.dat");

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||            MENU VENTAS            ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("              NUEVA VENTA              ", 40, 13, y == 0);
        showItem("      MOSTRAR VENTAS POR ARTICULO      ", 40, 14, y == 1);
        showItem("       MOSTRAR VENTAS POR CLIENTE      ", 40, 15, y == 2);
        showItem("      MOSTRAR CLIENTES CON DEUDAS      ", 40, 16, y == 3);
        showItem("       MOSTRAR TODAS LAS VENTAS        ", 40, 17, y == 4);
        showItem("            CANCELAR DEUDA             ", 40, 18, y == 5);
        rlutil::locate(40, 19);
        std::cout << "---------------------------------------" << std::endl;
        showItem("       VOLVER AL MENU PRINCIPAL        ", 40, 20, y == 6);

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

            if(y > 6)
            {
                y = 6;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                ven.Cargar();
                break;

            case 1:
                system("cls");
                ven.mostrarXarticulo();
                break;

            case 2:
                system("cls");
                ven.mostrarXcliente();
                break;

            case 3:
                system("cls");
                //
                break;

            case 4:
                system("cls");
                ven.Mostrar();
                break;

            case 5:
                system("cls");
                //
                break;

            case 6:
                op = 0;
                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}
