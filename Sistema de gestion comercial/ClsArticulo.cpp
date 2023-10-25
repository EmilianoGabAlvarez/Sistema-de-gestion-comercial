#include <iostream>
#include <cstring>

#include "GLOBALES.h"
#include "ClsArticulo.h"

void articulo::setCodigo(int codigo)
{
    _codigo = codigo;
}
void articulo::setNombre(const char *nombre)
{
    strcpy(_nombre,nombre);
}
void articulo::setPrecio(float precio)
{
    _precio = precio;
}

void articulo::setEstadoArt(bool estado)
{
    _estado = estado;
}

int articulo::getCodigo()
{
    return _codigo;
}

const char* articulo::getNombre()
{
    return _nombre;
}

float articulo::getPrecio()
{
    return _precio;
}
int articulo::getDisponibilidad()
{
    return _disponibilidad;
}
int articulo::getCapacidad()
{
    return _capacidad;
}
int articulo::getStock()
{
    return (_capacidad-_disponibilidad);
}
bool articulo::getEstadoArt()
{
    return _estado;
}
int articulo::getCantidad()
{
    return _cantidad;
}

void articulo::cargar()
{
    int cap,cant;
    float precio;

    std::cout << "Ingrese el nombre del articulo: " << '\t';
    cargarCadena(_nombre,29);

    std::cout << "Ingrese el precio del articulo: " << '\t';
    std::cin >> precio;
    setPrecio(precio);

    std::cout << "Ingrese la capacidad de almacenamiento : " << '\t';
    std::cin >> cap;
    setCapacidad(cap);

    std::cout << "Ingrese la cantidad de bultos del articulo a guardar " << '\t';
    std::cin >> cant;
    setCantidad(cant);
    setEstadoArt(true);
}


void articulo::mostrar()
{
    std::cout << "CODIGO:  " << getCodigo() << '\t';
    std::cout << "NOMBRE: " << getNombre() << '\t';
    std::cout << "PRECIO: " << getPrecio() << '\t';
    std::cout << "CAPACIDAD: " << getCapacidad() << '\t';
    std::cout << "STOCK DISPONIBILE: " << (getCapacidad()-getDisponibilidad()) << '\t';
    std::cout << std::endl;
}

int articulo::setCantidadVenta(int cantidad)    /// acà se ingresa la cantidad que se quiere guardar y
{
    bool flag = false;
    int s = 0;
    // cout<<"stock disponible: "<<getStock()<<endl;                       /// tambien guarda y modifica la disponibilidad
    do
    {
        if (cantidad > getStock())
        {
            std::cout << "La cantidad supera el limite de capacidad: " << std::endl;
            std::cout << "ingrese un monto menor al ingresado anteriormente " << std::endl;
            std::cin >> cantidad;
        }
        else flag = true;
    }
    while(flag == false);
    //  cout<< "valor seteado en funcion set total: "<< _stock<<endl;
    _stock = _capacidad - _disponibilidad;
    _stock = _stock - cantidad;
    //   cout<< "Despues: "<< _stock<<endl; ///porque no me lleva el nuevo stock al objeto articulo
    return _stock;
}


void articulo::setCantidad(int cantidad)    /// acà se ingresa la cantidad que se quiere guardar y
{
    bool flag = false;
    // cout<<"capacidad de deposito: "<<getCapacidad()<<endl;/// tambien guarda y modifica la disponibilidad
    do
    {
        if (cantidad > getCapacidad())
        {
            std::cout << "La cantidad supera el limite de capacidad: " << std::endl;
            std::cout << "ingrese un monto menor al ingresado anteriormente " << std::endl;
            std::cin >> cantidad;
        }
        else flag = true;
    }
    while(flag == false);
    _disponibilidad = _capacidad - cantidad;
    _stock = cantidad;

}

void articulo::setCapacidad(int capacidad)
{
    _capacidad = capacidad;
}

void articulo::setStock(int cant)
{
    _stock = cant;
}
