#ifndef TANQUE_H
#define TANQUE_H
#include "compartimiento.h"
#include <string>
using namespace std;

class Tanque{
private:
    Compartimiento regular_;
    Compartimiento premium_;
    Compartimiento ecoExtra_;

public:
    //Constructor
    Tanque(float capacidadRegular, float capacidadPremium, float capacidadEcoExtra);

    //Getters
    Compartimiento& getRegular();
    Compartimiento& getPremium();
    Compartimiento& getEcoExtra();

    //Setters
    Compartimiento& setRegular();
    Compartimiento& setPremium();
    Compartimiento& setEcoExtra();

    float getCantidadDisponible(const string& tipoCombustible) const;
    void reducirCantidad(const string& tipoCombustible, float cantidad);

};

#endif // TANQUE_H
