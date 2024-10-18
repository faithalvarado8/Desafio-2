#include "tanque.h"
#include "compartimiento.h"
using namespace std;
#include <iostream>

Tanque::Tanque(float capacidadRegular, float capacidadPremium, float capacidadEcoExtra): regular_(capacidadRegular), premium_(capacidadPremium), ecoExtra_(capacidadEcoExtra){
}

Compartimiento& Tanque::getRegular(){
    return regular_;
}
Compartimiento& Tanque::getPremium(){
    return premium_;
}
Compartimiento& Tanque::getEcoExtra(){
    return ecoExtra_;
}

float Tanque::getCantidadDisponible(const string& tipoCombustible) const {
    if (tipoCombustible == "REGULAR") {
        return regular_.getCantidadActual();
    } else if (tipoCombustible == "PREMIUM") {
        return premium_.getCantidadActual();
    } else if (tipoCombustible == "ECOEXTRA") {
        return ecoExtra_.getCantidadActual();
    }
    return 0.0;
}

void Tanque::reducirCantidad(const string& tipoCombustible, float cantidad) {

    if (tipoCombustible == "REGULAR") {

        float actual = regular_.getCantidadActual();
        cout<<"Actual: "<<actual<<endl;
        regular_.setCantidadActual(actual - cantidad);
        cout<<"Actual: "<<actual-cantidad<<endl;

    } else if (tipoCombustible == "PREMIUM") {
        float actual = premium_.getCantidadActual();
        premium_.setCantidadActual(actual - cantidad);
    } else if (tipoCombustible == "ECOEXTRA") {
        float actual = ecoExtra_.getCantidadActual();
        ecoExtra_.setCantidadActual(actual - cantidad);
    }
}
