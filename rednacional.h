#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include <iostream>
#include "preciocombustible.h"
#include "estacionservicio.h"

class RedNacional {
private:
    EstacionServicio** estaciones_; // Arreglo de punteros a EstacionServicio
    int numEstaciones_; // Numero de estaciones en la red
    PrecioCombustible preciosCombustible_; // Objeto de la clase PrecioCombustible

public:
    RedNacional(int maxEstaciones); // Constructor
    ~RedNacional(); // Destructor
    void agregarEstacionServicio(EstacionServicio* estacion); // Agregar estacion a la red
    void eliminarEstacionServicio(int indice); // Eliminar estacion de la red
    void calcularVentasTotales(); // Calcular ventas totales de la red
    void setPreciosCombustible(Region region, float precioRegular, float precioPremium, float precioEcoExtra); // Establecer precios de combustible
    float getPrecioCombustible(TipoCombustible tipo, Region region); // Obtener precio de combustible
};

#endif // REDNACIONAL_H
