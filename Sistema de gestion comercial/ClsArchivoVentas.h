#ifndef CLSARCHIVOVENTAS_H_INCLUDED
#define CLSARCHIVOVENTAS_H_INCLUDED
#include "ClsVentas.h"

class ArchivoVentas
{
private :
    char nombre[30];
public:
    ArchivoVentas(const char *n);
    void Cargar();
    void Mostrar();
    void mostrarXarticulo();
    void mostrarXcliente();
    bool sobreEscribirReg(Ventas ven,int pos);
};

/// Funcion cargar: guarda en el archivo "ventas.dat" las ventas realizadas
/// Set Total:pertenece a la clase ventas, dentro de esta funcion se abre
/// el archivo "articulos.dat" y sobreescribe el nuevo stock luego de ralizada la venta

#endif // CLSARCHIVOVENTAS_H_INCLUDED
