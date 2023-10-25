#ifndef CLSARCHIVOCLIENTE_H_INCLUDED
#define CLSARCHIVOCLIENTE_H_INCLUDED

#include "ClsCliente.h"

class archivoCli
{
private:
    char nombrecliente[30];
public:
    archivoCli(const char *n);
    void AgregarArchivoCli();
    void MostrarArchivoCliente();
    int BuscarClienteDni(int dni);
    void MostrarClienteDni();
    Cliente LeerArcCliente(int pos);
    bool ModificarEmail();
    bool sobreEscribirRegistro(Cliente Cli, int pos);
    bool BajaCliente();
};

#endif // CLSARCHIVOCLIENTE_H_INCLUDED
