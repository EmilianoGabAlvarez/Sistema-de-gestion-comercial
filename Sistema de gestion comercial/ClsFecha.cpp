#include <iostream>
#include <ctime>
#include "ClsFecha.h"

Fecha::Fecha()
{
    time_t t = time(nullptr);
    tm* fS = localtime(&t);
    dia = fS -> tm_mday;
    mes = fS -> tm_mon + 1;
    anio = fS -> tm_year + 1900;

}

void Fecha::setDia(int x)
{
    dia = x;
}

void Fecha::setMes(int x)
{
    mes = x;
}

void Fecha::setAnio(int x)
{
    anio = x;
}

int Fecha::getDia()
{
    return dia;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getAnio()
{
    return anio;
}

bool Fecha::AnioBisiesto(int a)
{

    if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) return true;
    else return false;

}

bool Fecha::FechaValida(int d, int m, int a)
{

    if (a < 0 || m < 1 || m > 12 || d < 1 || d > 31)
    {
        std::cout << "ERROR: FECHA INVALIDA" << std::endl;
        return false;
        system("pause");

    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
    {
        std::cout << "ERROR: FECHA INVALIDA" << std::endl;
        return false;
        system("pause");

    }
    else if (m == 2 && AnioBisiesto(a) && d > 29)
    {
        std::cout << "ERROR: FECHA INVALIDA" << std::endl;
        return false;
        system("pause");

    }
    else if (m == 2 && !AnioBisiesto(a) && d > 28)
    {
        std::cout << "ERROR: FECHA INVALIDA" << std::endl;
        return false;
        system("pause");

    }
    else if (a > getAnio() || (a == getAnio() && m > getMes()) || (a == getAnio() && m == getMes() && d > getDia() ))
    {
        std::cout << "ERROR: FECHA INVALIDA" << std::endl;
        return false;
        system("pause");
    }
    else return true;
}

void Fecha::Cargar()
{

    int d, m, a;
    bool check = false;

    while(!check)
    {
        std::cout << "DIA: ";
        std::cin >> d;
        std::cout << "MES: ";
        std::cin >> m;
        std::cout << "ANIO: ";
        std::cin >> a;

        check = FechaValida(d, m, a);
    }

    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::Mostrar()
{
    std::cout << "FECHA: " << dia << "/" << mes << "/" << anio << "\t";
}
