#include <iostream>
#include <cstring>

#include "ClsCliente.h"
#include "GLOBALES.h"

void Cliente::setFecha(Fecha i)
{
    fechaCli = i;
}

void Cliente::setNombre(const char *nombre)
{
    strcpy(_nombre, nombre);
}

void Cliente::setApellido(const char *apellido)
{
    strcpy(_apellido, apellido);
}

void Cliente::setDni(int dni)
{
    _dni = dni;
}

void Cliente::setDireccion(const char *direc)
{
    strcpy(_direccion,direc);
}

void Cliente::setTelefono(int tel)
{
    _telefono = tel;
}

void Cliente::setEmail(const char *email)
{
    strcpy(_eMail,email);
}

void Cliente::setEstado(bool estado)
{
    _estado = estado;
}

Fecha Cliente::getfecha()
{
    return fechaCli;
}

const char* Cliente::getNombre()
{
    return _nombre;
}

const char* Cliente::getApellido()
{
    return _apellido;
}

const char* Cliente::getEmail()
{
    return _eMail;
}

int Cliente::getDni()
{
    return _dni;
}

const char* Cliente::getDireccion()
{
    return _direccion;
}

int Cliente::getTelefono()
{
    return _telefono;
}

bool Cliente::getEstado()
{
    return _estado;
}

void Cliente::cargar()
{
    char e[30];
    int tel = 0;

    std::cout << "Ingrese el nombre del cliente :" << '\t';
    cargarCadena(_nombre,29);

    std::cout << "Ingrese el apellido: " << '\t';
    cargarCadena(_apellido,29);
    fechaCli.Cargar();

    std::cout << "Ingrese la direccion: " << '\t';
    cargarCadena(_direccion,29);

    std::cout << "Ingrese el Nro. de telefono:" << '\t';
    std::cin >> tel;
    setTelefono(tel);

    std::cout << "Ingrese un e-Mail: " << '\t';
    std::cin >> e;
    setEmail(e);
    setEstado(true);
}

void Cliente::mostrar()
{
    std::cout << "NOMBRE: " << getNombre() << "\t";
    std::cout << "APELLIDO: " << getApellido() << "\t";
    fechaCli.Mostrar();
    std::cout << "DNI: " << getDni() << "\t";
    std::cout << "e-Mail :" << getEmail() << "\t";
}
