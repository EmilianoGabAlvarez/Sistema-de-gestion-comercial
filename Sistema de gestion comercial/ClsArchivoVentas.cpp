#include <iostream>
#include <cstring>
#include "ClsArchivoVentas.h"
#include "ClsArchivoArticulo.h"
#include "ClsArchivoCliente.h"

ArchivoVentas::ArchivoVentas(const char *n)
{
    strcpy(nombre, n);
}

void ArchivoVentas::Cargar()
{
    Ventas ven;
    archivoArt art("articulos.dat");
    FILE *pVen;

    int cod,n;

    pVen = fopen(nombre, "ab");

    if(pVen == NULL)
    {
        std::cout << "-- NO SE PUDO CREAR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;

        return;
    }

    std::cout << "-- NUEVA VENTA --" << std::endl;
    std::cout << std::endl;

    ven.setDatos();// dni nombre y apellido
    ven.setTotal();//esta funcion modifica el stock en "articulos.dat"
    fwrite(&ven, sizeof ven, 1, pVen);

    std::cout << "-- VENTA REALIZADA EXITOSAMENTE --" << std::endl;
    std::cout << std::endl;

    system("pause");
    fclose(pVen);
    system("cls");
}

void ArchivoVentas::Mostrar()
{
    Ventas ven;
    FILE *pVen;
    pVen = fopen(nombre, "rb");

    if(pVen == NULL)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;

        return;
    }

    while(fread(&ven, sizeof ven, 1, pVen) == 1)
    {
        if(ven.getEstadoVen() == true)
        {
            ven.Mostrar();
            std::cout << std::endl;
        }
    }

    fclose(pVen);
}

void ArchivoVentas::mostrarXarticulo()
{
    archivoArt art("articulos.dat");
    Ventas ven;
    FILE *pVen;
    int cod,pos;

    std::cout << "Ingrese el codigo a buscar " << '\t';
    std::cin >> cod;

    pos = art.BuscarArchivoArt(cod);

    while(pos < 0)
    {
        std::cout << "CODIGO INCORRECTO - (Ingrese un codigo valido)" << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese el codigo a buscar " << '\t';
        std::cin >> cod;

        pos = art.BuscarArchivoArt(cod);
    }

    pVen = fopen(nombre, "rb");

    if(pVen == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;

        return;
    }

    while(fread(&ven, sizeof ven, 1, pVen) == 1)
    {
        if(ven.getCodigo() == cod)
        {
            ven.Mostrar();
            std::cout << std::endl;
        }
    }
}

bool ArchivoVentas::sobreEscribirReg(Ventas ven, int pos)
{
    FILE *pVen;
    pVen = fopen(nombre, "rb+");
    fseek(pVen, sizeof ven * pos, 0);
    bool aux = fwrite(&ven, sizeof ven, 1, pVen);
    fclose(pVen);
    return aux;
}


void ArchivoVentas::mostrarXcliente()
{
    archivoCli Cli("clientes.dat");
    ArchivoVentas ventas("ventas.dat");
    Cliente clientes;
    Ventas ven;
    FILE *pVen;
    pVen = fopen(nombre,"rb");

    int dni,pos;

    std::cout << "Ingrese el dni de el cliente a buscar: " << '\t';
    std::cin >> dni;

    pos = Cli.BuscarClienteDni(dni);
    clientes = Cli.LeerArcCliente(pos);

    std::cout << "que trae clientes: " << pos << std::endl;

    while(pos < 0)
    {
        std::cout << " --DNI INCORRECTO-- " << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese nuevamente un DNI: " << '\t';
        std::cin >> dni;

        pos = Cli.BuscarClienteDni(dni);
        clientes = Cli.LeerArcCliente(pos);
    }

    if(pVen == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;
        return;
    }

    while(fread(&ven, sizeof ven, 1, pVen) == 1)
    {
        if(ven.getDni() == dni)
        {
            ven.Mostrar();
            std::cout << std::endl;
        }
    }
}
