#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha
{
private:
    int dia, mes, anio;
public:
    ///constructor
    Fecha();
    ///metodos
    bool FechaValida(int d, int m, int a);
    bool AnioBisiesto(int a);
    void Cargar();
    void Mostrar();
    ///sets
    void setDia(int x);
    void setMes(int x);
    void setAnio(int x);
    ///gets
    int getDia();
    int getMes();
    int getAnio();
};

#endif // CLSFECHA_H_INCLUDED
