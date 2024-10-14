#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <string>
#include<iostream>
#include <chrono>
#include <iomanip>
using namespace std;

class Transaccion{
private:
    string tipoCombustible_;
    float cantidadCombustible_;
    string formaPago_;
    string docCliente_;
    float monto_;
    float precioCombustible_;
    string fechahora_;

public:
    Transaccion(const string& tipoCombustible, float cantidadCombustible,
                const string& formaPago, const string& docCliente, float monto,
                float precioCombustible);
    void mostrarTransaccion() const; //Metodo de despliegue
};

#endif // TRANSACCION_H
