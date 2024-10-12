#include "compartimiento.h"

//Constructor
Compartimiento::Compartimiento(float capacidad): capacidad_(capacidad), cantidadActual_(0.0) {}

//Getters
double Compartimiento::getCapacidad() const {
    return capacidad_;
}
double Compartimiento::getCantidadActual() const{
    return cantidadActual_;
}
//Setters
void Compartimiento::setCantidadActual(float cantidad){
    cantidadActual_ = cantidad;
}
