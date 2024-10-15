#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H

#include "tanque.h"
#include "isla.h"
#include "puntosurtidor.h"
#include "transaccion.h"

#include<string>
using namespace std;

class EstacionServicio{
private:
    string nombre_;
    static unsigned int contadorCodigo;
    string codigo_;
    string gerente_;
    string region_;
    float latitud_;
    float longitud_;
    Tanque* tanque_;
    Isla** islas_; // Arreglo dinámico de islas
    unsigned int numIslas_;        // Número actual de islas en la estación
    const unsigned int maxIslas_ = 3; // Capacidad máxima de islas
    unsigned int numPuntosSurtidores_ = 0;
    unsigned int maxPuntosSurtidores_;
    PuntoSurtidor** puntosSurtidores_;
    Transaccion** transacciones_;

    string setCoordenadasGPS(); //Genera aleatoriamente coordenadas


public:
    EstacionServicio();
    EstacionServicio(string& nombre, string& gerente, string& region, unsigned int maxPuntosSurtidores);
    ~EstacionServicio();

    string getNombre();
    void setNombre(const string& nombre);
    string getCodigo() const;
    void setCodigo(const string& codigo);
    string getGerente();
    void setGerente(const string& gerente);
    string getRegion();
    void setRegion(const string& region);
    string getCoordenadas();  //Retorna las coordenadas en formato string

    void agregarIsla(Isla* nuevaIsla);
    void agregarPuntoSurtidor(PuntoSurtidor* puntoSurtidor);
    void eliminarPuntoSurtidor(const string& codigo);
    void activarPuntoSurtidor(const string& codigo);
    void desactivarPuntoSurtidor(const string& codigo);
    void setCapacidadTanque();

    void simularVenta();
    void consultarTransaccionesPuntoSurtidor(const string& codigo);
    void reportarLitrosVendidos();
    void calcularVentasTotales();
    bool verificarFugas();

    unsigned int getNumIslas() const;  // Método para obtener el número de islas
    Isla* getIsla(unsigned int index) const;  // Método para obtener una isla por índice
};

#endif // ESTACIONSERVICIO_H
