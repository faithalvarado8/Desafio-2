#ifndef TANQUE_H
#define TANQUE_H
#include "compartimiento.h"

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
};

#endif // TANQUE_H
