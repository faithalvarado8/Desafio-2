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

unsigned int RedNacional::getNumEstaciones() const {
    return numEstaciones_;
}

EstacionServicio* RedNacional::getEstacion(unsigned int index) const {
    if (index < numEstaciones_) {
        return estaciones_[index]; // Retorna la estación si el índice es válido
    }
    return nullptr; // Retorna nullptr si el índice es inválido
}

void RedNacional::setPreciosCombustible(int region, float precioRegular, float precioPremium, float precioEcoExtra) {
    preciosCombustible_[region][0] = precioRegular;
    preciosCombustible_[region][1] = precioPremium;
    preciosCombustible_[region][2] = precioEcoExtra;
}

float RedNacional::getPreciosCombustible(int region, int tipoCombustible){
    return preciosCombustible_[region][tipoCombustible];
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

        // Crear un nuevo arreglo con mayor capacidad
        EstacionServicio** nuevoArreglo = new EstacionServicio*[tamArregloEstaciones];

        // Copiar las estaciones existentes al nuevo arreglo
        for (unsigned int i = 0; i < numEstaciones_; ++i) {
            nuevoArreglo[i] = estaciones_[i];
        }

        // Liberar el arreglo anterior
        delete[] estaciones_;

        // Asignar el nuevo arreglo
        estaciones_ = nuevoArreglo;
    }

    // Agregar la nueva estación y aumentar el contador
    estaciones_[numEstaciones_] = nuevaEstacion;
    cout << endl << "Estacion creada exitosamente" << endl;

    //Genera el código a la nueva estación
    cout << nuevaEstacion->getCodigo() << endl;

    numEstaciones_++;
}

void RedNacional::eliminarEstacion(string codigoEstacion) {
    cout << "Eliminando estacion..." << endl;
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

    for (unsigned int j = 0; j < estacion->getNumIslas(); ++j) { // Asegúrate de usar el método getNumIslas
        Isla* isla = estacion->getIsla(j);
        for (unsigned int k = 0; k < isla->getNumSurtidores(); ++k) {
            PuntoSurtidor* surtidor = isla->getPuntoSurtidor(k); // Obtener el surtidor
            if (surtidor->getEstado()) { // Verificar si el surtidor está activo
                cout << "ERROR: Estacion de servicio con surtidores activos." << endl;
                return;
            }
        }
    }

    // Eliminar la estacion y liberar memoria correctamente
    delete estaciones_[indiceEstacion]; // Elimina la estación y todos sus recursos

    // Reorganizar el arreglo de estaciones
    for (unsigned int i = indiceEstacion; i < numEstaciones_ - 1; i++) {
        estaciones_[i] = estaciones_[i + 1];
    }

    numEstaciones_--;
    cout << "Estacion eliminada exitosamente" << endl << endl;
}
