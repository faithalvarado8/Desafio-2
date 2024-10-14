#ifndef PUNTOSURTIDOR_H
#define PUNTOSURTIDOR_H

#include <iostream>
#include <string>
#include "transaccion.h"

using namespace std;

class PuntoSurtidor {
private:
    bool activado_;
    string codigo_;
    string modelo_;
    Transaccion** transacciones_;
    unsigned int numTransacciones_; //Para establecer el tamaño del arreglo

public:
    PuntoSurtidor(string codigo, string modelo, bool activado, unsigned int numTransacciones_);
    string getCodigo();
    string getModelo();
    bool getEstado();
    void realizarVenta(float precioCombustible);
    void registrarVenta(Transaccion* venta);

    void mostrarHistorico();

    ~PuntoSurtidor();

    //void actualizarVentasRealizadas(Transaccion transaccion);
};

#endif // PUNTOSURTIDOR_H
