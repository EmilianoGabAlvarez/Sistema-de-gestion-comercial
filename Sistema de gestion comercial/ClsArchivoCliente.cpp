#include <iostream>
#include <cstring>

#include "ClsArchivoCliente.h"

archivoCli::archivoCli(const char *n)
{
    strcpy(nombrecliente, n);
}

void archivoCli::AgregarArchivoCli()
{
    Cliente cli;
    FILE *pCli;
    pCli = fopen(nombrecliente,"ab");

    if (pCli == NULL)
    {
        std::cout << "No se pudo abrir el archivo " << std::endl;
        return;
    }

    std::cout << "-- NUEVO CLIENTE --" << std::endl;
    std::cout << std::endl;

    int dni;
    std::cout << "ingrese DNI: " << '\t';
    std::cin >> dni;

    if (BuscarClienteDni(dni) >= 0)
    {
        system("cls");
        std::cout << "-- EL DNI YA EXISTE -- " << std::endl;
        std::cout << std::endl;
        return;
    }

    cli.setDni(dni);
    cli.cargar();
    fwrite(&cli, sizeof cli, 1, pCli);

    std::cout << "-- CLIENTE CARGADO EXITOSAMENTE --" << std::endl;
    std::cout << std::endl;

    system("pause");
    fclose(pCli);

    system("cls");
}

void archivoCli::MostrarArchivoCliente()  ///MUESTRA EL LISTADO ENTERO
{
    Cliente cli;
    FILE *pCli;
    pCli = fopen(nombrecliente,"rb" );

    if (pCli == NULL)
    {
        std::cout << "-- NO SE PUDO MOSTRAR EL ARCHIVO --" << std::endl;
        std::cout << std::endl;
        return;
    }
    while (fread(&cli, sizeof cli, 1, pCli) == 1)
    {
        if (cli.getEstado() == true)
        {
            cli.mostrar();
            std::cout << std::endl;
        }
    }
    fclose(pCli);
}

int archivoCli::BuscarClienteDni(int n)
{
    Cliente Cli;
    FILE *pCli;
    int pos = 0;
    pCli = fopen(nombrecliente,"rb");
    if (pCli == NULL)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" <<std::endl;
        return pos =- 2;
    }
    while(fread(&Cli,sizeof Cli,1,pCli) == 1)
    {
        if (n==Cli.getDni())
        {
            return pos;
        }
        else pos++;
    }
    return pos = -1;
}

void archivoCli::MostrarClienteDni()
{
    Cliente Cli;
    int dni;
    std::cout << "Ingrese el numero de DNI a buscar " << '\t';
    std::cin >> dni;

    int pos = BuscarClienteDni(dni);

    if(pos >= 0)
    {
        Cli = LeerArcCliente(pos);
        if (Cli.getEstado() == true)
        {
            Cli.mostrar();
        }
        std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS --" << std::endl;
        std::cout << std::endl;
        return;
    }
}

Cliente archivoCli::LeerArcCliente(int pos)
{
    Cliente Cli;

    if(pos < 0)
    {
        Cli.setDni(-3);
        return Cli;
    }

    FILE *pCli;
    pCli = fopen(nombrecliente,"rb");

    if (pCli == NULL)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        Cli.setDni(-2);
        return Cli;
    }

    fseek(pCli, sizeof Cli * pos,0);
    int aux = fread(&Cli, sizeof Cli, 1, pCli);
    fclose(pCli);

    if (aux == 0)
    {
        Cli.setDni(-1);
        return Cli;
    }
    Cli.setEstado(true);
    return Cli;
}

bool archivoCli::sobreEscribirRegistro(Cliente Cli, int pos)
{
    FILE *pCli;
    pCli = fopen(nombrecliente, "rb+");
    fseek(pCli, sizeof Cli * pos, 0);
    bool aux = fwrite(&Cli, sizeof Cli, 1, pCli);
    fclose(pCli);
    return aux;
}

bool archivoCli::ModificarEmail()
{
    Cliente Cli;
    int dni;
    char email[30];
    std::cout << "Ingrese el DNI del cliente a modificar e-Mail " << '\t';
    std::cin >> dni;
    int pos = BuscarClienteDni(dni);

    if(pos == -2)
    {
        return false;
    }
    else if (pos == 1)
    {
        std::cout << "-- NO SE ENCONTRARON COINCIDENCIAS CON EL DNI INGRESADO --" << std::endl;
        return false;
    }

    Cli = LeerArcCliente(pos);

    std::cout << "Ingrese el nuevo e-Mail " << '\t';
    std::cin >> email;

    Cli.setEmail(email);
    int aux = sobreEscribirRegistro(Cli,pos);
    return aux;
    system ("cls");

}

bool archivoCli::BajaCliente()
{
    Cliente Cli;
    int dni;

    std::cout << "Ingrese el dni de el cliente que quiere dar de baja " << std::endl;
    std::cin >> dni;

    int pos = BuscarClienteDni(dni);
    if (pos == -2)
    {
        std::cout << "-- NO SE PUDO ABRIR EL ARCHIVO --" << std::endl;
        return false;
    }
    else if (pos == -1)
    {
        std::cout << "-- NO SE ENCONTRO MUSICO CON ESE DNI --" << std::endl;
        return false;
    }

    Cli = LeerArcCliente(pos);

    if (Cli.getEstado() == false)
    {
        std::cout << "-- El articuo ya se encontraba dado de baja anteriormente --" << std::endl;
        return false;
    }
    Cli.setEstado(false);
    bool aux = sobreEscribirRegistro(Cli,pos);
    return aux;

}
