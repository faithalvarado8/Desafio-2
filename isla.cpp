#include "isla.h"
#include <iostream>

using namespace std;

// Constructor
Isla::Isla(string nombre, unsigned int capacidadInicial)
    : nombre_(nombre), numPuntosSurtidores(0), maxSurtidores(capacidadInicial) {
    // Inicializa el arreglo dinámico de puntos surtidores
    puntosSurtidores_ = new PuntoSurtidor*[maxSurtidores];
}

// Método para obtener el nombre de la isla
string Isla::getNombreIsla() {
    return nombre_;
}

// Método para obtener un surtidor por su índice
PuntoSurtidor* Isla::getPuntoSurtidor(unsigned int indice) {
    if (indice < numPuntosSurtidores) {
        return puntosSurtidores_[indice];
    }
    return nullptr;
}

// Método para agregar un surtidor dinámicamente
void Isla::agregarPuntoSurtidor(PuntoSurtidor* nuevoSurtidor) {
    if (numPuntosSurtidores == maxSurtidores) {
        // Duplica el tamaño del arreglo si ya esta lleno (hasta un maximo de 4)
        unsigned int nuevoMax = maxSurtidores * 2;
        if (nuevoMax > 4) {
            cout << "Capacidad maxima de surtidores alcanzada." << endl;
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

// Metodo para listar los surtidores de la isla
void Isla::listarPuntosSurtidores() {
    if (numPuntosSurtidores == 0) {
        cout << "No hay puntos surtidores en esta isla." << endl;
        return;
    }

    cout << "Puntos Surtidores en la Isla " << nombre_ << ":\n";
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        cout << "Surtidor " << i + 1 << " - Codigo: "
             << puntosSurtidores_[i]->getCodigo()
             << ", Modelo: " << puntosSurtidores_[i]->getModelo() << endl;
    }
}

// Metodo para eliminar un surtidor de la isla
void Isla::eliminarPuntoSurtidor(const string& codigo) {
    bool encontrado = false;
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            delete puntosSurtidores_[i];  // Liberar memoria del surtidor

            // Mover los elementos restantes hacia la izquierda
            for (unsigned int j = i; j < numPuntosSurtidores - 1; ++j) {
                puntosSurtidores_[j] = puntosSurtidores_[j + 1];
            }

            numPuntosSurtidores--;
            cout << "Surtidor eliminado correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Surtidor con codigo " << codigo << " no encontrado." << endl;
    }
}

// Metodo para obtener el numero actual de surtidores
unsigned int Isla::getNumSurtidores() const {
    return numPuntosSurtidores;
}

// Metodo para obtener la cantidad disponible de combustible
float Isla::getCantidadDisponible(const string& tipoCombustible) {
    // Implementacion temporal
    if (tipoCombustible == "REGULAR") {
        return 100.0;
    } else if (tipoCombustible == "PREMIUM") {
        return 50.0;
    } else if (tipoCombustible == "ECOEXTRA") {
        return 75.0;
    } else {
        return 0.0;
    }
}

// Destructor
Isla::~Isla() {
    // Liberar la memoria de los puntos surtidores
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        delete puntosSurtidores_[i];
    }
    delete[] puntosSurtidores_;  // Liberar el arreglo de punteros
}
