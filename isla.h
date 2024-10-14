#ifndef ISLA_H
#define ISLA_H

#include <string>
#include "puntosurtidor.h"

using namespace std;

class Isla {
private:
    string nombre_;
    unsigned int numPuntosSurtidores_;
    unsigned int maxSurtidores_;
    PuntoSurtidor** puntosSurtidores;

public:
    Isla(string nombre, unsigned int capacidadMaxima);
    ~Isla();
    void listarPuntosSurtidores();
    unsigned int getNumSurtidores();
    // Método estático temporal que devuelve una cantidad de combustible disponible para pruebas
    static float getCantidadDisponible(const string& tipoCombustible);

    void agregarPuntoSurtidor(PuntoSurtidor* nuevoSurtidor);  // Método temporal para agregar surtidores

};

#endif // ISLA_H

