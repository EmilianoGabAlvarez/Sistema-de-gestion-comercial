#include <iostream>
#include <cstring>
#include "ClsVentas.h"
#include "ClsArchivoArticulo.h"
#include "ClsArchivoCliente.h"


void Ventas::setNombre(const char *nombre)
{
    strcpy(Nombre, nombre);
}

void Ventas::setApellido(const char *apellido)
{
    strcpy(Apellido, apellido);
}

void Ventas::setCodigo(int cod)
{
    Codigo = cod;
}

void Ventas::setDni(int dni)
{
    Dni = dni;
}

void Ventas::setEstadoVen(bool estado)
{
    Estado = estado;
}

const char* Ventas::getNombre()
{
    return Nombre;
}

const char* Ventas::getApellido()
{
    return Apellido;
}

int Ventas::getCodigo()
{
    return Codigo;
}

int Ventas::getDni()
{
    return Dni;
}

int Ventas::getCant()
{
    return Cant;
}

float Ventas::getTotal()
{
    return Total;
}

bool Ventas::getEstadoVen()
{
    return Estado;
}

/*
void VentasXarticulo()
{

}
*/

void Ventas::setTotal()   //en esta funcion se modifica el archivo articulo dentro
{
    archivoArt art("articulos.dat");//de la funcion "ModificarStockArt"
    articulo articulos;

    int pos, cod, cant;

    std::cout << "Ingrese el codigo : " << '\t';
    std::cin >> cod;

    pos = art.BuscarArchivoArt(cod);

    std::cout << "que trae pos articulo: " << pos << std::endl;

    while(pos < 0)
    {
        std::cout << "No se encontro articulo con este codigo " << std::endl;
        std::cout << "ingrese un codigo distinto " << std::endl;
        std::cin >> cod;

        pos = art.BuscarArchivoArt(cod);
    }

    articulos = art.LeerArcArticulo(pos);
    articulos.mostrar();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "lugar libre" << (articulos.getDisponibilidad()) << std::endl;
    std::cout << std::endl;
    std::cout << "Ingrese la cantidad  : " << '\t';
    std::cin >> cant;
    std::cout << std::endl;

    while(cant > articulos.getDisponibilidad())
    {
        std::cout << "-SUPERA EL STOCK DISPONIBLE-" << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese nuevamente una cantidad menor al stock disponible" << std::endl;
        std::cin >> cant;
    }

    int s;

    s = articulos.setCantidadVenta(cant);
    art.ModificarStockArt(cod,s);/// Funcion que pide como parametro el codigo y stock
    /// a sobreescribir en "articulos.dat"
    pos = art.BuscarArchivoArt(cod);
    articulos = art.LeerArcArticulo(pos);     //nose si las necesito todavia
    Total = articulos.getPrecio()*cant;
    Cant = cant;
}

void Ventas::setDatos()
{
    archivoCli arC("clientes.dat");
    Cliente clientes;
    int pos,dni;

    std::cout << "Ingrese el dni: " << '\t';
    std::cin >> dni;

    pos = arC.BuscarClienteDni(dni);
    system("pause");

    while(pos < 0)
    {
        system("cls");

        std::cout << "NO SE ENCONTRARON COINCIDENCIAS PARA EL DNI INGRESADO" << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese nuevamente un numero de DNI: " << '\t';
        std::cin >> dni;

        pos = arC.BuscarClienteDni(dni);
        system("cls");
    }

    setDni(dni);
    clientes = arC.LeerArcCliente(pos);
    setNombre(clientes.getNombre());
    setApellido(clientes.getApellido());
    setEstadoVen(true);

}

/*
void Ventas::Cargar(){   // no creo neceitarla
int cant,dni,cod;
float imp;
            // cout<<"Ingrese el nombre del cliente "<<'\t';
            // cargarCadena(Nombre,29);
            // cout<<"Ingrese el apellido del cliente"<<'\t';
            // cargarCadena(Apellido,29);
        cout<<"Ingrese el numero de DNI"<<'\t';
        cin>>dni;
setDatos(dni);
fechaVenta.Cargar();
cout<<"Ingrese la cantidad"<<'\t';
cin>>cant;
cout<<"Ingrese el codigo"<<'\t';
cin>>cod;

setTotal(cant,cod);
setEstadoVen(true);
}


void Ventas::Cargar(){                          // no creo neceitarla
    archivoCli arCli("clientes.dat");
    Cliente clientes;
    int doc,dni,pos;
    cout<<"Ingrese el numero de documento del cliente:"<<'\t';
    cin>>doc;
    pos=arCli.BuscarClienteDni(doc);
    while (pos < 0){
        cout<<"-NO EXISTE CLIENTE CON ESTE DNI "<<endl;
        cout<<"Ingrese nuevamente un DNI: "<<'\t';
        cin>>doc;
        pos=arCli.BuscarClienteDni(doc);
        return;
    }
       clientes=arCli.LeerArcCliente(pos);
       clientes.mostrar();
}
*/

void Ventas::Mostrar()
{
    std::cout << "NOMBRE: " << getNombre() << '\t';
    std::cout << "APELLIDO: " << getApellido() << '\t';
    std::cout << "DNI: " << getDni() << '\t';
    fechaVenta.Mostrar();
    std::cout << "CODIGO: " << getCodigo() + 1 << '\t';
    std::cout << "CANTIDAD: " << getCant() << '\t';
    std::cout << "Total de la venta: " << "$" << getTotal() << '\t';
}
