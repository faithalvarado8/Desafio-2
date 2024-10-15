#ifndef REDNACIONAL_H
#define REDNACIONAL_H

#include"estacionservicio.h"

class RedNacional{
private:
    EstacionServicio** estaciones_;
    unsigned int numEstaciones_;
    unsigned int tamArregloEstaciones;
    float preciosCombustible_[3][3];

public:
    RedNacional();
    ~RedNacional();
    void agregarEstacion(EstacionServicio* nuevaEstacion);
    void eliminarEstacion(string codigo);
    void calcularVentasTotales();
    void setPreciosCombustible(int region, float precioRegular, float precioPremium, float precioEcoExtra);
    float getPreciosCombustible(int region, int tipoCombustible);
};

#endif // REDNACIONAL_H
