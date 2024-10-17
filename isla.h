#ifndef ISLA_H
#define ISLA_H

#include <string>
#include "puntosurtidor.h"

using namespace std;

class Isla {
private:
    string nombre_;
    unsigned int numPuntosSurtidores;
    unsigned int maxSurtidores;
    PuntoSurtidor** puntosSurtidores_;

public:
    Isla(string nombre, unsigned int capacidadMaxima = 2);
    ~Isla();

    PuntoSurtidor* getPuntoSurtidor(unsigned int indice);  // Metodo para obtener un surtidor por indice
    unsigned int getNumSurtidores() const;

    string getNombreIsla();

    void listarPuntosSurtidores();
    void agregarPuntoSurtidor(PuntoSurtidor* nuevoSurtidor);  // Metodo para agregar surtidores
    void eliminarPuntoSurtidor(const string& codigo);

    // // Metodo estatico temporal que devuelve una cantidad de combustible disponible para pruebas
    static float getCantidadDisponible(const string& tipoCombustible);
};

#endif // ISLA_H
