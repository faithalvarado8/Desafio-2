#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H

#include "tanque.h"
#include "isla.h"
#include "puntosurtidor.h"
#include "transaccion.h"

#include<string>
using namespace std;
class RedNacional;

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
    unsigned int maxPuntosSurtidores_= 12;
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
    void eliminarIsla(unsigned int indice);

    void agregarPuntoSurtidor(string& modelo);
    void eliminarPuntoSurtidor(const string& codigo);
    void activarPuntoSurtidor(const string& codigo);
    void desactivarPuntoSurtidor(const string& codigo);

    void setCapacidadTanque();

    void simularVenta(RedNacional* rednacional, string& region, float (&total)[3]);
    void consultarTransaccionesPuntoSurtidor(const string& codigo);

    unsigned int getNumIslas() const;  // Metodo para obtener el número de islas
    Isla* getIsla(unsigned int index) const;  // Mrtodo para obtener una isla por índice

    float getCantidadDisponible(const string& tipoCombustible);
    void reducirCombustible(const string& tipoCombustible, float cantidad);

    Tanque* getTanque() const;
};

#endif // ESTACIONSERVICIO_H
