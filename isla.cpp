// #include "maquinasurtidora.h"

// MaquinaSurtidora::MaquinaSurtidora() {}

#include "isla.h"

Isla::Isla(string nombre, unsigned int capacidadMaxima)
    : nombre_(nombre), maxSurtidores(capacidadMaxima), numPuntosSurtidores(0) {
    // Inicializa el arreglo dinámico de puntos surtidores
    puntosSurtidores = new PuntoSurtidor*[maxSurtidores];
}

void Isla::listarPuntosSurtidores() {
    if (numPuntosSurtidores == 0) {
        cout << "No hay puntos surtidores en esta isla." << endl;
        return;
    }

    cout << "Puntos Surtidores en la Isla " << nombre_ << ":\n";
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        cout << "Surtidor " << i + 1 << " - Codigo: " << puntosSurtidores[i]->getCodigo() << ", Modelo: " << puntosSurtidores[i]->getModelo() << endl;
    }
}

// Método temporal para agregar surtidores
void Isla::agregarPuntoSurtidor(PuntoSurtidor* nuevoSurtidor) {
    if (numPuntosSurtidores < maxSurtidores) {
        puntosSurtidores[numPuntosSurtidores++] = nuevoSurtidor;
        cout << "Surtidor agregado correctamente." << endl;
    } else {
        cout << "Capacidad máxima de surtidores alcanzada." << endl;
    }
}

unsigned int Isla::getNumSurtidores() {
    return numPuntosSurtidores;
}

// Implementación temporal del método estático para devolver una cantidad fija de combustible
float Isla::getCantidadDisponible(const string& tipoCombustible) {
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

Isla::~Isla() {
    // Liberar la memoria del arreglo de surtidores
    for (unsigned int i = 0; i < numPuntosSurtidores; ++i) {
        delete puntosSurtidores[i];  // Liberar cada punto surtidor
    }
    delete[] puntosSurtidores;  // Liberar el arreglo de punteros
}
