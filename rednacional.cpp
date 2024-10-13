#include "rednacional.h"

RedNacional::RedNacional(int maxEstaciones) : numEstaciones_(0) {
    estaciones_ = new EstacionServicio*[maxEstaciones];
}

RedNacional::~RedNacional() {
    for (int i = 0; i < numEstaciones_; ++i) {
        delete estaciones_[i]; // Liberar cada estación antes de liberar el arreglo
    }
    delete[] estaciones_;
}

void RedNacional::agregarEstacionServicio(EstacionServicio* estacion) {
    if (numEstaciones_ < maxEstaciones_) { // Usar maxEstaciones_
        estaciones_[numEstaciones_] = estacion;
        numEstaciones_++;
    } else {
        cerr << "Error: No se pueden agregar mas estaciones. Limite alcanzado." << endl;
    }
}

void RedNacional::eliminarEstacionServicio(int indice) {
    if (indice >= 0 && indice < numEstaciones_) {
        delete estaciones_[indice];
        for (int i = indice; i < numEstaciones_ - 1; i++) {
            estaciones_[i] = estaciones_[i + 1];
        }
        numEstaciones_--;
    } else {
        cerr << "Error: Indice invalido." << endl;
    }
}

void RedNacional::calcularVentasTotales() {
    float ventasTotales = 0.0;
    for (int i = 0; i < numEstaciones_; i++) {
        ventasTotales += estaciones_[i]->getVentasTotales();
    }
    cout << "Ventas totales de la red: " << ventasTotales << endl;
}

void RedNacional::setPreciosCombustible(Region region, float precioRegular, float precioPremium, float precioEcoExtra) {
    preciosCombustible_.setPrecio(region, "REGULAR", precioRegular);
    preciosCombustible_.setPrecio(region, "PREMIUM", precioPremium);
    preciosCombustible_.setPrecio(region, "ECOEXTRA", precioEcoExtra);
}

float RedNacional::getPrecioCombustible(TipoCombustible tipo, Region region) {
    return preciosCombustible_.getPrecio(region, tipo);
}
