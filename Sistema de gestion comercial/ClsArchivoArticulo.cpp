#include <iostream>
#include <cstring>

#include "ClsArchivoArticulo.h"

archivoArt::archivoArt(const char *n)
{
    strcpy(nombre, n);
}

void archivoArt::AgregarArchivoArt()
{
    articulo art;
    FILE *pArt;
    pArt = fopen(nombre, "ab");

    if (pArt == NULL)
    {
        std::cout << "No se pudo abrir el archivo " << std::endl;
        return;
    }

    std::cout << "-- NUEVO ARTICULO --" << std::endl;
    std::cout << std::endl;

    int n;

    std::cout << "Ingrese el codigo del articulo: " << '\t';
    std::cin >> n;

    if (BuscarArchivoArt(n )>= 0)
    {
        system("cls");

        std::cout << "-- CODIGO DE ARTICULO REPETIDO --" << std::endl;
        std::cout << std::endl;

        return;
    }

    art.setCodigo(n);
    art.cargar();
    fwrite(&art,sizeof art, 1, pArt);
    system("pause");
    fclose(pArt);
}

int archivoArt::BuscarArchivoArt(int n)
{
    articulo art;
    FILE *pArt;

    int pos = 0;

    pArt = fopen(nombre, "rb");

    if (pArt == NULL)
    {
        std::cout << "No se pudo abrir el archivo1 " << std::endl;
        return pos = -2 ;
    }

    while(fread(&art, sizeof art, 1, pArt) == 1)
    {
        if(n == art.getCodigo())
        {
            return pos;
        }

        else pos++;
    }

    return pos = -1;
}

bool archivoArt::ModificarAlmacenamientoArt()  // Modifica la capacidad de almacenamiento del articulo
{
    articulo art;
    int cod, pos = 0, n;

    std::cout << "Ingrese el vodigo del producto a cambiar el tamaño de almacenamiento " << '\t';
    std::cin >> cod;

    pos = BuscarArchivoArt(cod);

    if(pos < 0)
    {
        std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS CON EL CODIGO INGRESADO --" << std::endl;
        std::cout << std::endl;
    }

    FILE *pArt;
    pArt = fopen(nombre, "rb+");

    if(pArt == NULL)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;
        return false;
    }

    art = LeerArcArticulo(pos);

    std::cout << "Ingrese el nuevo almacenamiento  :" << std::endl;
    std::cin >> n;

    art.setCapacidad(n);
    bool aux = sobreEscribirRegistro(art, pos);
    return aux;
    system ("cls");
}


articulo archivoArt::LeerArcArticulo(int pos) // Lee y devuelve el objeto del articulo
{
    articulo art;                             // correspondiente a la posicion.

    if(pos < 0)
    {
        art.setCodigo(-3);
        return art;
    }

    FILE *pArt;
    pArt = fopen(nombre, "rb");

    if(pArt == NULL)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;

        art.setCodigo(-2);
        return art;
    }

    fseek(pArt, sizeof art * pos, 0);

    int aux = fread(&art, sizeof art, 1, pArt);
    fclose(pArt);

    if(aux == 0)
    {
        art.setCodigo(-1);
        return art;
    }
    art.setEstadoArt(true);
    return art;
}


bool archivoArt::sobreEscribirRegistro(articulo art, int pos)
{
    FILE *pArt;
    pArt = fopen(nombre, "rb+");
    fseek(pArt, sizeof art * pos, 0);
    bool aux = fwrite(&art, sizeof art, 1, pArt);
    fclose(pArt);
    return aux;
}

bool archivoArt::bajaLogica()
{
    articulo art;
    int cod;

    std::cout << "Ingrese el codigo de el producto que quiere dar de baja " << std::endl;
    std::cin >> cod;

    int pos = BuscarArchivoArt(cod);

    if(pos == -2)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;
        return false;
    }
    else if(pos == -1)
    {
        std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS CON EL CODIGO INGRESADO --" << std::endl;
        std::cout << std::endl;
        return false;
    }

    art = LeerArcArticulo(pos);

    if(art.getEstadoArt() == false)
    {
        std::cout << "-- El ARTICULO YA SE ENCONTRABA DADO DE BAJA --" << std::endl;
        std::cout << std::endl;
        return false;
    }
    art.setEstadoArt(false);
    bool aux=sobreEscribirRegistro(art,pos);
    return aux;
}

bool archivoArt::ModificarStockArt(int cod,int stock)
{
    articulo art;
    int pos = 0;
    pos = BuscarArchivoArt(cod);

    if(pos == -2)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;
        return false;
    }
    else if(pos == -1)
    {
        std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS CON EL CODIGO INGRESADO --" << std::endl;
        std::cout << std::endl;
        return false;
    }

    art = LeerArcArticulo(pos);
    art.setCantidad(stock);
    bool aux = sobreEscribirRegistro(art, pos);
    return aux;
    system ("cls");
}

bool archivoArt::ModificarStockArt()
{
    articulo art;
    int cod;

    std::cout << "Ingrese el codigo de el producto a modificar el stock :" << '\t';
    std::cin >> cod;

    int pos = 0, stock;

    pos = BuscarArchivoArt(cod);

    if(pos == -2)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;
        return false;
    }
    else if(pos==-1)
    {
        std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS CON EL CODIGO INGRESADO --" << std::endl;
        std::cout << std::endl;
        return false;
    }

    art = LeerArcArticulo(pos);

    std::cout << "Ingrese el nuevo stock  :" << '\t';
    std::cin >> stock;

    art.setCantidad(stock);
    bool aux = sobreEscribirRegistro(art, pos);
    return aux;
    system ("cls");
}

void archivoArt::MostrarArticuloXcodigo()
{
    articulo art;
    int cod,pos;

    std::cout << "Ingrese el codigo de articulo a buscar " << '\t';
    std::cin >> cod;

    pos = BuscarArchivoArt(cod);

    if(pos >= 0)
    {
        art = LeerArcArticulo(pos);

        if(art.getEstadoArt() == true)
        {
            art.mostrar();
        }
        else
        {
            std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS CON EL CODIGO INGRESADO --" << std::endl;
            std::cout << std::endl;
            system("pause");
            return;
        }
    }
}

void archivoArt::MostrarArchivoArt()  // Muestra el objeto completo
{
    articulo art;
    FILE *pArt;
    pArt = fopen(nombre,"rb" );

    if(pArt == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;
        return;
    }

    while(fread(&art, sizeof art, 1, pArt) == 1)
    {
        if(art.getEstadoArt() == true)
        {
            art.mostrar();
        }
    }

    fclose(pArt);
}
