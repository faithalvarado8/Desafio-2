#include "rednacional.h"
#include "isla.h"

RedNacional::RedNacional() {

    numEstaciones_ = 0;
    tamArregloEstaciones = 6; // Inicializar tamArregloEstaciones con un valor predeterminado
    estaciones_ = new EstacionServicio*[tamArregloEstaciones];

    // Precios región NORTE
    preciosCombustible_[0][0] = 4700; // Regular
    preciosCombustible_[0][1] = 4900; // Premium
    preciosCombustible_[0][2] = 5000; // EcoExtra

    // Precios región CENTRO
    preciosCombustible_[1][0] = 5000; // Regular
    preciosCombustible_[1][1] = 5500; // Premium
    preciosCombustible_[1][2] = 5800; // EcoExtra

    // Precios región SUR
    preciosCombustible_[2][0] = 4000; // Regular
    preciosCombustible_[2][1] = 4500; // Premium
    preciosCombustible_[2][2] = 4900; // EcoExtra
}

void RedNacional::setPreciosCombustible(int region, float precioRegular, float precioPremium, float precioEcoExtra) {
    preciosCombustible_[region][0] = precioRegular;
    preciosCombustible_[region][1] = precioPremium;
    preciosCombustible_[region][2] = precioEcoExtra;
}

RedNacional::~RedNacional() {
    for (unsigned int i = 0; i < numEstaciones_; i++) {
        delete estaciones_[i];  // Libera memoria de cada estación
    }
    delete[] estaciones_;  // Libera el arreglo de estaciones
}

void RedNacional::agregarEstacion(EstacionServicio* nuevaEstacion) {

    // Verificar si es necesario aumentar la capacidad del arreglo de estaciones
    if (numEstaciones_ >= tamArregloEstaciones) {
        // Aumentar la capacidad al doble del tamaño actual
        tamArregloEstaciones *= 2;

        // Reasignar la memoria con el nuevo tamaño
        estaciones_ = new EstacionServicio*[tamArregloEstaciones];

    }

    // Agregar la nueva estación y aumentar el contador
    estaciones_[numEstaciones_] = nuevaEstacion;
    cout << endl << "Estacion creada exitosamente" << endl;

    //Genera el codigo a la nueva estacion
    cout << nuevaEstacion->getCodigo() << endl;

    //Crea el tanque y asigna capacidad de los compartimientos aleatoriamente
    numEstaciones_++;

}


void RedNacional::eliminarEstacion(string codigoEstacion) {
    int indiceEstacion = -1;
    for (unsigned int i = 0; i < numEstaciones_; i++) {
        if (estaciones_[i]->getCodigo() == codigoEstacion) {
            indiceEstacion = i;
            break;
        }
    }

    if (indiceEstacion == -1) {
        cout << "Estacion no encontrada" << endl << endl;
        return;
    }

    // Verificar si todos los surtidores están inactivos
    EstacionServicio* estacion = estaciones_[indiceEstacion];
    bool todosInactivos = true;

    for (unsigned int j = 0; j < estacion->getNumIslas(); ++j) { 
        Isla* isla = estacion->getIsla(j);
        for (unsigned int k = 0; k < isla->getNumSurtidores(); ++k) {
            PuntoSurtidor* surtidor = isla->getPuntoSurtidor(k); // Obtener el surtidor
            if (surtidor->getEstado()) { // Verificar si el surtidor está activo
                todosInactivos = false;
                break;
            }
        }
    }

    if (!todosInactivos) {
        cout << "ERROR: Estacion de servicio con surtidores activos." << endl;
        return;
    }

    // Eliminar la estación
    delete estaciones_[indiceEstacion];
    for (unsigned int i = indiceEstacion; i < numEstaciones_ - 1; i++) {
        estaciones_[i] = estaciones_[i + 1];
    }

    numEstaciones_--;
    cout << "Estacion eliminada exitosamente" << endl << endl;
}
