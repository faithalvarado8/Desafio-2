#include "preciocombustible.h"
#include <iostream>

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

float PrecioCombustible::getPrecio(const string& region, const string& tipoCombustible) {
    Region reg;
    TipoCombustible tipo;

    if (region == "NORTE") reg = NORTE;
    else if (region == "CENTRO") reg = CENTRO;
    else if (region == "SUR") reg = SUR;
    else throw invalid_argument("Region no valida");

    if (tipoCombustible == "REGULAR") tipo = REGULAR;
    else if (tipoCombustible == "PREMIUM") tipo = PREMIUM;
    else if (tipoCombustible == "ECOEXTRA") tipo = ECOEXTRA;
    else throw invalid_argument("Tipo de combustible no valido");

    return precios_[reg][tipo];
}

void PrecioCombustible::setPrecio(const string& region, const string& tipoCombustible, float precio) {
    Region reg;
    TipoCombustible tipo;

    if (region == "NORTE") reg = NORTE;
    else if (region == "CENTRO") reg = CENTRO;
    else if (region == "SUR") reg = SUR;
    else throw invalid_argument("Region no valida");

    if (tipoCombustible == "REGULAR") tipo = REGULAR;
    else if (tipoCombustible == "PREMIUM") tipo = PREMIUM;
    else if (tipoCombustible == "ECOEXTRA") tipo = ECOEXTRA;
    else throw invalid_argument("Tipo de combustible no valido");

    precios_[reg][tipo] = precio;
}
