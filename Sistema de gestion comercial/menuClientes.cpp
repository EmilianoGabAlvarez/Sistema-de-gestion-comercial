#include <iostream>
#include "rlutil.h"
#include "menuClientes.h"
#include "ClsArchivoCliente.h"
#include "showItem.h"

void menuClientes()
{
    archivoCli cl("clientes.dat");

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||           MENU CLIENTES           ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("            AGREGAR CLIENTE            ", 40, 13, y == 0);
        showItem("          BUSCAR CLIENTE POR DNI       ", 40, 14, y == 1);
        showItem("             MODIFICAR E-MAIL          ", 40, 15, y == 2);
        showItem("       MOSTRAR TODOS LOS CLIENTES      ", 40, 16, y == 3);
        showItem("         DAR DE BAJA UN CLIENTE        ", 40, 17, y == 4);
        rlutil::locate(40, 18);
        std::cout << "---------------------------------------" << std::endl;
        showItem("        VOLVER AL MENU PRINCIPAL       ", 40, 19, y == 5);

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

            if(y > 5)
            {
                y = 5;
            }
            break;

        case 1: //ENTER

            switch(y)
            {
            case 0:
                system("cls");
                cl.AgregarArchivoCli();
                break;

            case 1:
                system("cls");
                cl.MostrarClienteDni();
                break;

            case 2:
                system("cls");
                cl.ModificarEmail();
                break;

            case 3:
                system("cls");
                cl.MostrarArchivoCliente();
                break;

            case 4:
                system("cls");
                cl.BajaCliente();
                break;

            case 5:
                op = 0;
                break;
            }
        }
    }
    while(op != 0);

    system("cls");
    return;
}


