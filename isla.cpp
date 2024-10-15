#include "isla.h"
#include <iostream>

// Constructor
Isla::Isla(string nombre, unsigned int capacidadInicial)
    : nombre_(nombre), numPuntosSurtidores(0), maxSurtidores(capacidadInicial) {
    // Inicializa el arreglo dinámico de puntos surtidores con capacidad inicial
    puntosSurtidores_ = new PuntoSurtidor*[maxSurtidores];
}

string Isla::getNombreIsla(){
    return nombre_;
}

PuntoSurtidor* Isla::getPuntoSurtidor(unsigned int indice) {
    if (indice < numPuntosSurtidores) {
        return puntosSurtidores_[indice]; // Retorna el surtidor si el índice es válido
    }
    return nullptr; // Retorna nullptr si el índice es inválido
}


// Método para agregar un surtidor dinámicamente
void Isla::agregarPuntoSurtidor(PuntoSurtidor* nuevoSurtidor) {
    // Verifica si se ha alcanzado la capacidad máxima
    if (numPuntosSurtidores == maxSurtidores) {
        // Duplica el tamaño del arreglo si ya está lleno (hasta un máximo de 4)
        unsigned int nuevoMax = maxSurtidores * 2;
        if (nuevoMax > 4) {
            cout << "Capacidad máxima de surtidores alcanzada." << endl;
            return;
        }

        // Crear un nuevo arreglo con mayor capacidad
        PuntoSurtidor** nuevoArreglo = new PuntoSurtidor*[nuevoMax];

        // Copiar los surtidores existentes al nuevo arreglo
        for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
            nuevoArreglo[i] = puntosSurtidores_[i];
        }

        // Liberar el arreglo anterior
        delete[] puntosSurtidores_;

        // Asignar el nuevo arreglo y actualizar la capacidad máxima
        puntosSurtidores_ = nuevoArreglo;
        maxSurtidores = nuevoMax;
    }

    // Agregar el nuevo surtidor
    puntosSurtidores_[numPuntosSurtidores++] = nuevoSurtidor;
    cout << "Surtidor agregado a la isla correctamente." << endl;
    cout << "Codigo: " << nuevoSurtidor->getCodigo() << endl;
}

// Método para listar los surtidores de la isla
void Isla::listarPuntosSurtidores() {
    if (numPuntosSurtidores == 0) {
        cout << "No hay puntos surtidores en esta isla." << endl;
        return;
    }

    cout << "Puntos Surtidores en la Isla " << nombre_ << ":\n";
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        cout << "Surtidor " << i + 1 << " - Codigo: " << puntosSurtidores_[i]->getCodigo()
             << ", Modelo: " << puntosSurtidores_[i]->getModelo() << endl;
    }
}

// Método para obtener el número actual de surtidores
unsigned int Isla::getNumSurtidores() {
    return numPuntosSurtidores;
}

// Implementación temporal del método estático para devolver una cantidad fija de combustible
float Isla::getCantidadDisponible(const string& tipoCombustible) {

    //PEDIR AL TANQUE

    if (tipoCombustible == "REGULAR") {
        return 100.0;  // Simulación: 100 litros de gasolina Regular disponibles
    } else if (tipoCombustible == "PREMIUM") {
        return 50.0;   // Simulación: 50 litros de gasolina Premium disponibles
    } else if (tipoCombustible == "ECOEXTRA") {
        return 75.0;   // Simulación: 75 litros de gasolina EcoExtra disponibles
    } else {
        return 0.0;    // Cualquier otro tipo de combustible no está disponible
    }
}

// Destructor
Isla::~Isla() {
    // Liberar la memoria del arreglo de surtidores
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        delete puntosSurtidores_[i];  // Liberar cada punto surtidor
    }
    delete[] puntosSurtidores_;  // Liberar el arreglo de punteros
}
