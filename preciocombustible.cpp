#include "preciocombustible.h"

PrecioCombustible::PrecioCombustible(float precioNorteRegular, float precioNortePremium, float precioNorteEcoExtra,
                                     float precioCentroRegular, float precioCentroPremium, float precioCentroEcoExtra,
                                     float precioSurRegular, float precioSurPremium, float precioSurEcoExtra) {
    precios_[NORTE][REGULAR] = precioNorteRegular;
    precios_[NORTE][PREMIUM] = precioNortePremium;
    precios_[NORTE][ECOEXTRA] = precioNorteEcoExtra;
    precios_[CENTRO][REGULAR] = precioCentroRegular;
    precios_[CENTRO][PREMIUM] = precioCentroPremium;
    precios_[CENTRO][ECOEXTRA] = precioCentroEcoExtra;
    precios_[SUR][REGULAR] = precioSurRegular;
    precios_[SUR][PREMIUM] = precioSurPremium;
    precios_[SUR][ECOEXTRA] = precioSurEcoExtra;
}

float PrecioCombustible::getPrecio(Region region, TipoCombustible tipo) {
    return precios_[region][tipo];
}

void PrecioCombustible::setPrecio(Region region, TipoCombustible tipo, float precio) {
    precios_[region][tipo] = precio;
}
