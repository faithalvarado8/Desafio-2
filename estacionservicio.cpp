#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>

#include "estacionservicio.h"

unsigned int EstacionServicio::contadorCodigo = 1000;

EstacionServicio::EstacionServicio() {}

EstacionServicio::EstacionServicio(string& nombre, string& gerente, string& region,
                                   unsigned int maxPuntosSurtidores)
                                   : nombre_(nombre), gerente_(gerente), region_(region),
                                   maxPuntosSurtidores_(maxPuntosSurtidores) {
    //Genera el codigo para la nueva instancia de estacion
    codigo_ = "EST-" + to_string(contadorCodigo++);

    // Inicializar el arreglo de puntos surtidores
    puntosSurtidores_ = new PuntoSurtidor*[maxPuntosSurtidores_];
    numPuntosSurtidores_ = 0;

    // Inicializar las coordenadas GPS
    setCoordenadasGPS();
}

string EstacionServicio::setCoordenadasGPS() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> latDist(-90.0, 90.0);
    uniform_real_distribution<> lonDist(-180.0, 180.0);

    latitud_ = latDist(gen);
    longitud_ = lonDist(gen);

    stringstream ss;
    ss << fixed << setprecision(6) << latitud_ << ", " << longitud_;
    return ss.str();
}

string EstacionServicio::getCoordenadas() {
    return setCoordenadasGPS();
}

// Métodos de acceso y modificación
string EstacionServicio::getNombre() {
    return nombre_;
}
void EstacionServicio::setNombre(const string& nombre) {
    nombre_ = nombre;
}

string EstacionServicio::getCodigo() const{
    return codigo_;
}
void EstacionServicio::setCodigo(const string& codigo) {
    codigo_ = codigo;
}

string EstacionServicio::getGerente() {
    return gerente_;
}
void EstacionServicio::setGerente(const string& gerente) {
    gerente_ = gerente;
}

string EstacionServicio::getRegion() {
    return region_;
}
void EstacionServicio::setRegion(const string& region) {
    region_ = region;
}

void EstacionServicio::agregarPuntoSurtidor(PuntoSurtidor* puntoSurtidor) {
    cout << "NUM " << numPuntosSurtidores_ << endl;
    if (numPuntosSurtidores_ < maxPuntosSurtidores_) {
        puntosSurtidores_[numPuntosSurtidores_++] = puntoSurtidor;
        cout << "Surtidor agregado correctamente." << endl;
    } else {
        cout << "Capacidad maxima de surtidores alcanzada." << endl;
    }
}

void EstacionServicio::eliminarPuntoSurtidor(const string& codigo) {
    bool encontrado = false;
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            delete puntosSurtidores_[i];
            // Mover los elementos restantes hacia la izquierda
            for (unsigned int j = i; j < numPuntosSurtidores_ - 1; j++) {
                puntosSurtidores_[j] = puntosSurtidores_[j + 1];
            }
            numPuntosSurtidores_--;  // Decrementar el contador
            cout << "Surtidor eliminado correctamente." << endl;
            encontrado = true;
            break;
        }
        else{
            cout << "Surtidor a eliminar no existe" << endl;
        }
    }
}

void EstacionServicio::activarPuntoSurtidor(const string& codigo) {
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            puntosSurtidores_[i]->getEstado();
            cout << "Surtidor activado." << endl;
            return;
        }
    }
    cout << "Surtidor con código " << codigo << " no encontrado." << endl;
}

void EstacionServicio::desactivarPuntoSurtidor(const string& codigo) {
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            puntosSurtidores_[i]->setEstado();
            cout << "Surtidor desactivado." << endl;
            return;
        }
    }
    cout << "Surtidor con código " << codigo << " no encontrado." << endl;
}

// Método de EstacionServicio para asignar capacidades
void EstacionServicio::setCapacidadTanque() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distRegular(100, 200);
    uniform_int_distribution<> distPremium(100, 200);
    uniform_int_distribution<> distEcoExtra(100, 200);

    float capacidadRegular = distRegular(gen);
    float capacidadPremium = distPremium(gen);
    float capacidadEcoExtra = distEcoExtra(gen);

    // Crear el tanque con las capacidades generadas
    tanque_ = new Tanque(capacidadRegular, capacidadPremium, capacidadEcoExtra);
    cout << "Capacidades asignadas - Regular: " << capacidadRegular
         << ", Premium: " << capacidadPremium
         << ", EcoExtra: " << capacidadEcoExtra << endl;
}


// Simular una venta
void EstacionServicio::simularVenta() {
    // Verificar si hay surtidores disponibles
    if (numPuntosSurtidores_ == 0) {
        cout << "No hay surtidores disponibles para realizar una venta." << endl;
        return;
    }

    // Contar surtidores activos
    unsigned int contadorActivos = 0;
    cout << "Verificando surtidor: " << puntosSurtidores_[i]->getCodigo() << " Estado: " << (puntosSurtidores_[i]->getEstado() ? "Activo" : "Desactivado") << endl;
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        cout << "Verificando surtidor: " << puntosSurtidores_[i]->getCodigo() << " Estado: " << (puntosSurtidores_[i]->getEstado() ? "Activo" : "Desactivado") << endl;
        if (puntosSurtidores_[i]->getEstado()) {  // Verificar si el surtidor está activo
            contadorActivos++;
        }
    }

    // Verificar si hay surtidores activos
    if (contadorActivos == 0) {
        cout << "No hay surtidores activos para realizar una venta." << endl;
        return;
    }

    // Crear un arreglo para almacenar índices de surtidores activos
    unsigned int* surtidoresActivos = new unsigned int[contadorActivos];
    unsigned int indice = 0;

    // Llenar el arreglo con índices de surtidores activos
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getEstado()) {
            surtidoresActivos[indice++] = i;  // Almacenar el índice del surtidor activo
        }
    }

    // Seleccionar un surtidor activo aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, contadorActivos - 1);
    int indexSurtidor = distr(gen);
    PuntoSurtidor* surtidorSeleccionado = puntosSurtidores_[surtidoresActivos[indexSurtidor]];

    // Generar una cantidad de combustible entre 3 y 20 litros
    uniform_int_distribution<> cantidadDist(3, 20);
    int cantidadCombustible = cantidadDist(gen);

    // Realizar la venta
    cout << "Realizando venta en el surtidor: " << surtidorSeleccionado->getCodigo() << endl;
    float precioCombustible = 1.5;  // Ejemplo de precio por litro
    surtidorSeleccionado->realizarVenta(precioCombustible);

    // Desplegar datos de la transacción
    cout << "Se han vendido " << cantidadCombustible << " litros de gasolina." << endl;
    surtidorSeleccionado->mostrarHistorico();  // Mostrar el historial de la transacción

    // Liberar memoria
    delete[] surtidoresActivos;  // Liberar el arreglo de surtidores activos
}


// Consultar transacciones de un surtidor específico
void EstacionServicio::consultarTransaccionesPuntoSurtidor(const string& codigo) {
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            puntosSurtidores_[i]->mostrarHistorico();
            return;
        }
    }
    cout << "Surtidor con código " << codigo << " no encontrado." << endl;
}

// Reportar la cantidad de litros vendidos por categoría de combustible
void EstacionServicio::reportarLitrosVendidos() {
    // Lógica para recorrer los surtidores y sumar los litros vendidos
    cout << "Reporte de litros vendidos por categoría..." << endl;
}

// Calcular las ventas totales en la estación
void EstacionServicio::calcularVentasTotales() {
    // Lógica para recorrer transacciones y calcular las ventas totales
    cout << "Cálculo de ventas totales..." << endl;
}

// Verificar fugas en el tanque (simulado)
bool EstacionServicio::verificarFugas() {
    cout << "Verificando fugas en el tanque..." << endl;
    // Lógica para verificar si hay inconsistencias entre lo vendido y lo almacenado
    return false;  // Supongamos que no hay fugas
}

EstacionServicio::~EstacionServicio() {
    // Liberar memoria asignada dinámicamente para el tanque
    delete tanque_;

    // Liberar el array de islas
    delete[] islas_;

    // Liberar el array dinámico de surtidores y transacciones
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        delete puntosSurtidores_[i];
        delete transacciones_[i];
    }
    delete[] puntosSurtidores_;
    delete[] transacciones_;
}
