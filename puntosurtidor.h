#ifndef PUNTOSURTIDOR_H
#define PUNTOSURTIDOR_H

#include <iostream>
#include <string>
#include "transaccion.h"

class RedNacional;

class EstacionServicio;

using namespace std;

class PuntoSurtidor {
private:
    bool activado_;
    static unsigned int contadorCodigo;
    string codigo_;
    string modelo_;
    EstacionServicio* estacion;
    Transaccion** transacciones_;
    unsigned int numTransacciones_; //Para establecer el tamaño del arreglo
    RedNacional* rednacional;

public:
    PuntoSurtidor(string modelo, bool activado, unsigned int numTransacciones_);
    string getCodigo() const;
    void setCodigo(const string& codigo);
    string getModelo();
    bool setEstado(bool estado);
    bool getEstado() const;
    void realizarVenta(RedNacional* rednacional, string& region, float (&total)[3], EstacionServicio* estacion);
    void registrarVenta(Transaccion* venta);

    void mostrarHistorico(bool mostrarUltima);

    unsigned int getNumTransacciones() const; // Metodo para obtener el numero de transacciones
    Transaccion* getTransaccion(unsigned int index) const; // Método para obtener una transaccion por indice

    ~PuntoSurtidor();
};

#endif // PUNTOSURTIDOR_H
