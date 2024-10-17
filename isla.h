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

    PuntoSurtidor* getPuntoSurtidor(unsigned int indice);  // Método para obtener un surtidor por índice
    unsigned int getNumSurtidores() const;

    string getNombreIsla();
    void listarPuntosSurtidores();
    void agregarPuntoSurtidor(PuntoSurtidor* nuevoSurtidor);  // Método para agregar surtidores
    // void eliminarPuntoSurtidor(unsigned int indice);
    void eliminarPuntoSurtidor(const string& codigo);

    // // Método estático temporal que devuelve una cantidad de combustible disponible para pruebas
    static float getCantidadDisponible(const string& tipoCombustible);
};

#endif // ISLA_H

