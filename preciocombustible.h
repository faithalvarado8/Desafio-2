#ifndef PRECIOCOMBUSTIBLE_H
#define PRECIOCOMBUSTIBLE_H
#include <string>

using namespace std;

enum Region { NORTE, CENTRO, SUR };
enum TipoCombustible { REGULAR, PREMIUM, ECOEXTRA };

class PrecioCombustible
{
public:
    PrecioCombustible(float precioNorteRegular, float precioNortePremium, float precioNorteEcoExtra,
                      float precioCentroRegular, float precioCentroPremium, float precioCentroEcoExtra,
                      float precioSurRegular, float precioSurPremium, float precioSurEcoExtra);

    float getPrecio(const string& region, const string& tipoCombustible);
    void setPrecio(const string& region, const string& tipoCombustible, float precio);

private:
    float precios_[3][3];
};

#endif // PRECIOCOMBUSTIBLE_H
