#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED

#include "ClsFecha.h"

class Ventas
{
private:
    char Nombre[30];
    char Apellido[30];
    int Dni;
    int Cant;
    int Codigo;
    float Total;
    Fecha fechaVenta;
    bool Estado;

public:
    void setNombre(const char *nombre);
    void setApellido(const char *apellido);
    void setCodigo(int cod);
    void setDni(int dni);
    void setDatos();
    void setTotal();
    void setEstadoVen(bool estado);
    const char *getNombre();
    const char *getApellido();
    int getCodigo();
    int getDni();
    int getCant();
    float getTotal();
    bool getEstadoVen();
    void Cargar();
    void Mostrar();
    void VentasXarticulo();
};

#endif // CLSVENTAS_H_INCLUDED
