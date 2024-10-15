#include "compartimiento.h"

//Constructor
Compartimiento::Compartimiento(float capacidad): capacidad_(capacidad), cantidadActual_(0.0) {
}

//Getters
float Compartimiento::getCapacidad() const {
    return capacidad_;
}
float Compartimiento::getCantidadActual() const{
    return cantidadActual_;
}

void Compartimiento::setCantidadActual(float cantidad){
    cantidadActual_ = cantidad;
}
