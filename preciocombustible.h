#ifndef PRECIOCOMBUSTIBLE_H
#define PRECIOCOMBUSTIBLE_H
#include <string>

using namespace std;

class PrecioCombustible
{
public:
    enum Region { NORTE, CENTRO, SUR };
    enum TipoCombustible { REGULAR, PREMIUM, ECOEXTRA };
    PrecioCombustible(float precioNorteRegular, float precioNortePremium, float precioNorteEcoExtra,
                      float precioCentroRegular, float precioCentroPremium, float precioCentroEcoExtra,
                      float precioSurRegular, float precioSurPremium, float precioSurEcoExtra);

    float getPrecio(Region region, TipoCombustible tipo);
    void setPrecio(Region region, TipoCombustible tipo, float precio);

private:
    float precios_[3][3];
};

#endif // PRECIOCOMBUSTIBLE_H
