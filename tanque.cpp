#include "tanque.h"
#include "compartimiento.h"

Tanque::Tanque(float capacidadRegular, float capacidadPremium, float capacidadEcoExtra): regular_(capacidadRegular), premium_(capacidadPremium), ecoExtra_(capacidadEcoExtra){}

Compartimiento& Tanque::getRegular(){
    return regular_;
}
Compartimiento& Tanque::getPremium(){
    return premium_;
}
Compartimiento& Tanque::getEcoExtra(){
    return ecoExtra_;
}
