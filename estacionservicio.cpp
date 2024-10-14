#include "estacionservicio.h"
using namespace std;

EstacionServicio::EstacionServicio(string& nombre, string& codigo,string& gerente, Region region, CoordenadaGPS coordenadaGPS)
    : nombre_(nombre), codigo_(codigo), gerente_(gerente), region_(region), coordenadaGPS_(coordenadaGPS), numIslas_(0), numMaquinasSurtidoras_(0), numTransacciones_(0) {
    maquinasSurtidoras_ = new MaquinaSurtidora*[12];
    historicoTransacciones_ = new Transaccion*[100];
    precioCombustible_ = PrecioCombustible(10000.0, 12000.0, 14000.0 , 9500.0, 11500.0, 13500.0, 10500.0, 12500.0, 14500.0); // Inicializado con valores predeterminados
}

EstacionServicio::~EstacionServicio() {
    delete[] maquinasSurtidoras_;
    delete[] historicoTransacciones_;
}

string EstacionServicio::getNombre() {
    return nombre_;
}

void EstacionServicio::setNombre(string& nombre) {
    nombre_ = nombre;
}

string EstacionServicio::getCodigo() {
    return codigo_;
}

void EstacionServicio::setCodigo(string& codigo) {
    codigo_ = codigo;
}

string EstacionServicio::getGerente() {
    return gerente_;
}

void EstacionServicio::setGerente(string& gerente) {
    gerente_ = gerente;
}

Region EstacionServicio::getRegion() {
    return region_;
}

void EstacionServicio::setRegion(Region region) {
    region_ = region;
}

CoordenadaGPS EstacionServicio::getCoordenadaGPS() {
    return coordenadaGPS_;
}

void EstacionServicio::setCoordenadaGPS(const CoordenadaGPS& coordenadaGPS) {
    coordenadaGPS_ = coordenadaGPS;
}

float EstacionServicio::getPrecioCombustible(enum TipoCombustible tipo) {
    return precioCombustible_.getPrecio(region_,tipo);
}

void EstacionServicio::agregarMaquinaSurtidora(MaquinaSurtidora* maquinaSurtidora) {
    if (numMaquinasSurtidoras_ < 12) {
        maquinasSurtidoras_[numMaquinasSurtidoras_] = maquinaSurtidora;
        numMaquinasSurtidoras_++;
    }
}

void EstacionServicio::activarMaquinaSurtidora(MaquinaSurtidora* maquinaSurtidora) {
    maquinaSurtidora->activar();
}

void EstacionServicio::desactivarMaquinaSurtidora(MaquinaSurtidora* maquinaSurtidora) {
    maquinaSurtidora->desactivar();
}

Transaccion* const* EstacionServicio::getHistorico() const {
    // Devuelve el puntero constante a la lista de transacciones
    return historicoTransacciones_;

void EstacionServicio::simularVenta(PuntoSurtidor* puntoSurtidor, enum TipoCombustible tipo, double litros) {
    // Simular la venta y agregar la transacción al historico
    Transaccion* transaccion = new Transaccion(puntoSurtidor, tipo, litros);
    historicoTransacciones_[numTransacciones_] = transaccion;
    numTransacciones_++;
}

void EstacionServicio::setCapacidadCompartimiento(int capacidad) {
    tanque_.setCapacidadCompartimiento(capacidad);
}
}
