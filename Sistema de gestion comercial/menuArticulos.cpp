#include <iostream>
#include "rlutil.h"
#include "menuArticulos.h"
#include "ClsArchivoArticulo.h"
#include "showItem.h"

void menuArticulos()
{
    archivoArt art("articulos.dat");

    int op = 1, y = 0;

    do
    {
        rlutil::hidecursor();

        setColor(rlutil::WHITE);
        setBackgroundColor(rlutil::BLACK);

        rlutil::locate(40, 10);
        std::cout << "+=====================================+" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "||           MENU ARTICULOS          ||" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "+=====================================+" << std::endl;
        showItem("            AGREGAR ARTICULO           ", 40, 13, y == 0);
        showItem("       BUSCAR ARTICULO POR CODIGO      ", 40, 14, y == 1);
        showItem("      MODIFICAR STOCK POR ARTICULO     ", 40, 15, y == 2);
        showItem(" MODIFICAR ALMACENAMIENTO POR ARTICULO ", 40, 16, y == 3);
        showItem("      MOSTRAR TODOS LOS ARTICULOS      ", 40, 17, y == 4);
        showItem("              BAJA ARTICULO            ", 40, 18, y == 5);
        rlutil::locate(40, 19);
        std::cout << "---------------------------------------" << std::endl;
        showItem("         VOLVER AL MENU PRINCIPAL      ", 40, 20, y == 6);

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
                art.AgregarArchivoArt();
                break;

            case 1:
                system("cls");
                art.MostrarArticuloXcodigo();
                break;

            case 2:
                system("cls");
                if(art.ModificarStockArt())
                {
                    std::cout << " STOCK MODIFICADO " << std::endl;
                }
                else
                {
                    std::cout << " NO SE PUDO MODIFICAR EL STOCK " << std::endl;
                }
                break;

            case 3:
                system("cls");
                art.ModificarAlmacenamientoArt();
                break;

            case 4:
                system("cls");
                art.MostrarArchivoArt();
                break;

            case 5:
                system("cls");
                art.bajaLogica();
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
