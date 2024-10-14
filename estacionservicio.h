#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H

#include <string>
#include "preciocombustible.h"
#include "maquinasurtidora.h"
#include "puntosurtidor.h"
#include "coordenadagps.h"
#include "tanque.h"
using namespace std;

class EstacionServicio {
private:
    string nombre_;
    string codigo_;
    string gerente_;
    enum Region {NORTE, CENTRO, SUR} region_;
    CoordenadaGPS coordenadaGPS_;
    Tanque tanque_;
    Isla* islas_[6];
    int numIslas_;
    PuntoSurtidor puntoSurtidor_;
    MaquinaSurtidora** maquinasSurtidoras_;
    int numMaquinasSurtidoras_;
    Transaccion** historicoTransacciones_;
    int numTransacciones_;
    PrecioCombustible precioCombustible_;

public:
    EstacionServicio(string& nombre, string& codigo, string& gerente, Region region, CoordenadaGPS coordenadaGPS);
    ~EstacionServicio();
    string getNombre();
    void setNombre(string& nombre);
    string getCodigo();
    void setCodigo(string& codigo);
    string getGerente();
    void setGerente(string& gerente);
    Region getRegion();
    void setRegion(Region region);
    CoordenadaGPS getCoordenadaGPS();
    void setCoordenadaGPS(const CoordenadaGPS& coordenadaGPS);
    float getPrecioCombustible(enum TipoCombustible tipo);
    void agregarMaquinaSurtidora(MaquinaSurtidora* maquinaSurtidora);
    void activarMaquinaSurtidora(MaquinaSurtidora* maquinaSurtidora);
    void desactivarMaquinaSurtidora(MaquinaSurtidora* maquinaSurtidora);
    Transaccion* const* getHistorico() const;
    void simularVenta(PuntoSurtidor* puntoSurtidor, enum TipoCombustible tipo, float litros);
    void setCapacidadCompartimiento(int capacidad);
};

#endif // ESTACIONSERVICIO_H
