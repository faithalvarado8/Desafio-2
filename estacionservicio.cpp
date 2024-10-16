#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include "estacionservicio.h"

unsigned int EstacionServicio::contadorCodigo = 1000;

EstacionServicio::EstacionServicio() {}

EstacionServicio::EstacionServicio(string& nombre, string& gerente, string& region, unsigned int maxPuntosSurtidores)
    : nombre_(nombre), gerente_(gerente), region_(region), maxPuntosSurtidores_(maxPuntosSurtidores) {

    // Genera el código para la nueva instancia de estación
    codigo_ = "EST-" + to_string(contadorCodigo++);

    // Crear e inicializar el tanque con capacidades generadas aleatoriamente
    setCapacidadTanque();

    // Inicializar el arreglo dinámico de islas
    islas_ = new Isla*[3];  // Máximo 3 islas
    islas_[0] = new Isla("Isla 1", 4);  // Primera isla con 4 surtidores como máximo
    cout << "Isla creada exitosamente" << endl;

    // Crear 2 surtidores para la primera isla
    PuntoSurtidor* surtidor1 = new PuntoSurtidor("Modelo A", true, 0);
    PuntoSurtidor* surtidor2 = new PuntoSurtidor("Modelo B", true, 0);

    // Agregar los surtidores a la primera isla
    islas_[0]->agregarPuntoSurtidor(surtidor1);
    islas_[0]->agregarPuntoSurtidor(surtidor2);

    // Inicializar el arreglo de puntos surtidores
    puntosSurtidores_ = new PuntoSurtidor*[maxPuntosSurtidores_];

    // Agregar los surtidores al arreglo general
    puntosSurtidores_[0] = surtidor1;
    puntosSurtidores_[1] = surtidor2;
    numPuntosSurtidores_ = 2;  // Actualizar el contador

    numIslas_ = 1;  // Hemos agregado una isla
}

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
    cout << "Capacidades asignadas(litros) - Regular: " << tanque_->getRegular().getCapacidad()
         << ", Premium: " << tanque_->getPremium().getCapacidad()
         << ", EcoExtra: " << tanque_->getEcoExtra().getCapacidad() << endl;

    tanque_->getRegular().setCantidadActual(capacidadRegular);
    tanque_->getPremium().setCantidadActual(capacidadPremium);
    tanque_->getEcoExtra().setCantidadActual(capacidadEcoExtra);
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

string EstacionServicio::getCodigo() const {
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

void EstacionServicio::agregarPuntoSurtidor(string& modelo) {
    // Verifica si se ha alcanzado el máximo de 12 surtidores
    if (numPuntosSurtidores_ >= maxPuntosSurtidores_) {
        cout << "No se pueden agregar mas surtidores. Se ha alcanzado el maximo de 12 surtidores." << endl << endl;
        return;
    }

    // Verifica si la última isla tiene capacidad para más surtidores
    Isla* ultimaIsla = islas_[numIslas_ - 1];
    if (ultimaIsla->getNumSurtidores() < 4) {
        // Agrega el nuevo surtidor a la última isla
        ultimaIsla->agregarPuntoSurtidor(new PuntoSurtidor(modelo, true, 0));
    } else {
        // Si la última isla está llena y hay menos de 3 islas, se crea una nueva
        if (numIslas_ < 3) {
            islas_[numIslas_] = new Isla("Isla " + to_string(numIslas_ + 1), 4);  // Nueva isla
            numIslas_++;
            cout << "Nueva isla creada: Isla " << numIslas_ << endl << endl;
            islas_[numIslas_ - 1]->agregarPuntoSurtidor(new PuntoSurtidor(modelo, true, 0));
        } else {
            cout << "No se pueden agregar mas islas. Se ha alcanzado el maximo de 3 islas." << endl << endl;
            return;
        }
    }

    // Agrega el nuevo surtidor al arreglo general de surtidores
    puntosSurtidores_[numPuntosSurtidores_] = ultimaIsla->getPuntoSurtidor(ultimaIsla->getNumSurtidores() - 1);
    numPuntosSurtidores_++; // Incrementa el contador de surtidores

    cout << "Nuevo surtidor agregado correctamente con el modelo: " << modelo << endl;
    cout << "Total de surtidores: " << numPuntosSurtidores_ << endl << endl;
}

void EstacionServicio::eliminarPuntoSurtidor(const string& codigo) {
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            // Verificar si el surtidor está activado
            if (puntosSurtidores_[i]->getEstado()) {
                cout << "El surtidor con el codigo " << codigo << " debe estar desactivado para ser eliminado." << endl;
                return; // Salir del método si está activado
            }

            // Llamar al método de la isla para eliminar la referencia
            for (unsigned int j = 0; j < numIslas_; j++) {
                Isla* isla = islas_[j];
                isla->eliminarPuntoSurtidor(codigo); // Solo eliminar referencia
            }

            // Liberar memoria y eliminar del arreglo general
            delete puntosSurtidores_[i];
            for (unsigned int j = i; j < numPuntosSurtidores_ - 1; j++) {
                puntosSurtidores_[j] = puntosSurtidores_[j + 1];
            }
            numPuntosSurtidores_--;
            cout << "Surtidor eliminado correctamente." << endl << endl;
            return; // Salir del método
        }
    }
    cout << "Surtidor no encontrado." << endl << endl;
}
void EstacionServicio::activarPuntoSurtidor(const string& codigo) {
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            puntosSurtidores_[i]->setEstado(true);
            cout << "Surtidor activado." << endl;
            return;
        }
    }
    cout << "Surtidor no encontrado." << endl;
}

void EstacionServicio::desactivarPuntoSurtidor(const string& codigo) {
    bool encontrado = false;
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            if (puntosSurtidores_[i]->getEstado()) {
                puntosSurtidores_[i]->setEstado(false);
                cout << "Surtidor " << codigo << " desactivado correctamente." << endl<< endl;
            } else {
                cout << "Surtidor " << codigo << " ya esta desactivado." << endl<< endl;
            }
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Surtidor " << codigo << " no encontrado." << endl<< endl;
    }
}

// Simular una venta
void EstacionServicio::simularVenta(RedNacional* rednacional, string& region, float (&total)[3]) {
    if (numPuntosSurtidores_ == 0) {
        cout << "No hay surtidores disponibles para realizar una venta." << endl<< endl;
        return;
    }

    unsigned int contadorActivos = 0;
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getEstado()) {
            contadorActivos++;
        }
    }

    if (contadorActivos == 0) {
        cout << "No hay surtidores activos para realizar una venta." << endl<< endl;
        return;
    }

    unsigned int* surtidoresActivos = new unsigned int[contadorActivos];
    unsigned int indice = 0;

    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getEstado()) {
            surtidoresActivos[indice++] = i;
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, contadorActivos - 1);
    int indexSurtidor = distr(gen);
    PuntoSurtidor* surtidorSeleccionado = puntosSurtidores_[surtidoresActivos[indexSurtidor]];

    cout << "Realizando venta en el surtidor: " << surtidorSeleccionado->getCodigo() << endl;

    surtidorSeleccionado->realizarVenta(rednacional, region, total, this);

    surtidorSeleccionado->mostrarHistorico(true);

    delete[] surtidoresActivos;
}

// Consultar transacciones de un surtidor específico
void EstacionServicio::consultarTransaccionesPuntoSurtidor(const string& codigo) {
    for (unsigned int i = 0; i < numPuntosSurtidores_; i++) {
        if (puntosSurtidores_[i]->getCodigo() == codigo) {
            puntosSurtidores_[i]->mostrarHistorico(false);
            return;
        }
    }
    cout << "Surtidor no encontrado." << endl;
}

unsigned int EstacionServicio::getNumIslas() const {
    return numIslas_;
}

Isla* EstacionServicio::getIsla(unsigned int index) const {
    if (index < numIslas_) {
        return islas_[index];
    }
    return nullptr;
}

EstacionServicio::~EstacionServicio() {
    // Eliminar el tanque
    delete tanque_;

    // Eliminar las islas y sus surtidores
    for (unsigned int i = 0; i < numIslas_; i++) {
        delete islas_[i]; // Cada isla elimina sus propios surtidores
    }
    delete[] islas_; // Liberar el arreglo de islas
}

float EstacionServicio::getCantidadDisponible(const string& tipoCombustible) {
    return tanque_->getCantidadDisponible(tipoCombustible);
}

void EstacionServicio::reducirCombustible(const string& tipoCombustible, float cantidad) {
    tanque_->reducirCantidad(tipoCombustible, cantidad);
}

Tanque* EstacionServicio::getTanque() const {
    return tanque_; // Devuelve el puntero al tanque
}
