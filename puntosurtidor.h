#ifndef PUNTOSURTIDOR_H
#define PUNTOSURTIDOR_H

#include <iostream>
#include <string>
#include "transaccion.h"

using namespace std;

class PuntoSurtidor {
private:
    bool activado_;
    static unsigned int contadorCodigo;
    string codigo_;
    string modelo_;
    Transaccion** transacciones_;
    unsigned int numTransacciones_; //Para establecer el tamaño del arreglo

public:
    PuntoSurtidor(string modelo, bool activado, unsigned int numTransacciones_);
    string getCodigo() const;
    void setCodigo(const string& codigo);
    string getModelo();
    bool setEstado(bool estado);
    bool getEstado() const;
    void realizarVenta(float precioCombustible);
    void registrarVenta(Transaccion* venta);

    void mostrarHistorico();

    ~PuntoSurtidor();
};

#endif // PUNTOSURTIDOR_H
