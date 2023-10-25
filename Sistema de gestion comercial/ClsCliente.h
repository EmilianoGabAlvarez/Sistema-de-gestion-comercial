#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

#include "ClsFecha.h"

class Cliente
{
private:
    Fecha fechaCli;
    char _nombre [30];
    char _apellido[30];
    int _dni;
    char _direccion [30];
    int _telefono;
    char _eMail [25];
    bool _estado;

public:
    void setFecha(Fecha i);
    void setNombre(const char *nombre);
    void setApellido(const char *apellido);
    void setDni(int dni);
    void setDireccion(const char *direc);
    void setTelefono(int tel);
    void setEmail(const char *email);
    void setEstado(bool estado);
    Fecha getfecha();
    const char *getNombre();
    const char *getApellido();
    const char *getEmail();
    int getDni();
    const char *getDireccion();
    int getTelefono();
    bool getEstado();
    void cargar();
    void mostrar();
};

#endif // CLSCLIENTE_H_INCLUDED
