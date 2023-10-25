#ifndef CLSARCHIVOARTICULO_H_INCLUDED
#define CLSARCHIVOARTICULO_H_INCLUDED

#include "ClsArticulo.h"

class archivoArt
{
private:
    char nombre[30];
public:
    archivoArt(const char *n);
    void AgregarArchivoArt();
    void MostrarArchivoArt();
    void MostrarArticuloXcodigo();
    int BuscarArchivoArt(int n);
    articulo LeerArcArticulo(int pos);
    bool ModificarStockArt();
    bool SetStockArt(int cod,int stock);
    bool ModificarAlmacenamientoArt();
    bool sobreEscribirRegistro(articulo art, int pos);
    bool ModificarStockArt(int cod,int stock);
    bool bajaLogica();
};

#endif // CLSARCHIVOARTICULO_H_INCLUDED
