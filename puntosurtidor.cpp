#include "puntosurtidor.h"
#include "isla.h"
#include "rednacional.h"
#include "estacionservicio.h"

unsigned int PuntoSurtidor::contadorCodigo = 100;

PuntoSurtidor::PuntoSurtidor(string modelo, bool activado, unsigned int numTransacciones_):
    activado_(activado), modelo_(modelo), numTransacciones_(numTransacciones_) {
    transacciones_ = new Transaccion*[10];

    codigo_ = "PS-" + to_string(contadorCodigo++);
}

string PuntoSurtidor::getCodigo()const{
    return codigo_;
}

string PuntoSurtidor::getModelo(){
    return modelo_;
}

bool PuntoSurtidor::setEstado(bool estado) {
    activado_ = estado; // Cambia el estado del surtidor
    return activado_; // Retorna el nuevo estado
}

bool PuntoSurtidor::getEstado() const {
    return activado_; // Retorna el estado actual del surtidor
}

void PuntoSurtidor::realizarVenta(string& region, float (&total)[3]) {

    if (activado_) {

        int categoriaCombustible;
        string tipoCombustible;
        float cantidadCombustible;
        char categoriaPago;
        string formaPago;
        string docCliente;
        float monto;
        float precioCombustible;
        int numregion=0;

        if (region=="NORTE"){
            numregion=0;
        }
        else if (region=="CENTRO"){
            numregion=1;
        }
        else if (region=="SUR"){
            numregion=2;
        }

        cout << "Tipo de combustible: REGULAR(1), PREMIUM(2), ECOEXTRA(3): ";
        cin >> categoriaCombustible;
        if (categoriaCombustible == 1) {
            tipoCombustible = "REGULAR";
        }
        else if (categoriaCombustible == 2) {
            tipoCombustible = "PREMIUM";
        }
        else if (categoriaCombustible == 3) {
            tipoCombustible = "ECOEXTRA";

        } else {
            cout << "Opcion no valida. Por favor, ingrese 1, 2 o 3." << endl;
        }

        cout << "Ingrese la cantidad de combustible a expender (litros): ";
        cin >> cantidadCombustible;

        cout << "Forma de pago: EFECTIVO(1), T.DEBITO(2), T.CREDITO(3): ";
        cin >> categoriaPago;
        if (categoriaPago == '1') {
            formaPago = "EFECTIVO";
        }
        else if (categoriaPago == '2') {
            formaPago = "T.DEBITO";
        }
        else if (categoriaPago == '3') {
            formaPago = "T.CREDITO";
        } else {
            cout << "Opcion no valida. Por favor, ingrese 1, 2 o 3." << endl;
        }

        cout << "Ingrese el documento del cliente: ";
        cin >> docCliente;

        float cantidadDisponible = Isla::getCantidadDisponible(tipoCombustible);

        if (cantidadCombustible > cantidadDisponible) {
            cantidadCombustible = cantidadDisponible;
            cout << "En este momento no disponemos de esa cantidad de combustible. " << endl;
            cout << "Se expedira y cobrara la cantidad disponible." << endl;
        }

        if (categoriaCombustible == 1) {
            total[0]+=cantidadCombustible;
        }
        else if (categoriaCombustible == 2) {
            total[1]+=cantidadCombustible;
        }
        else if (categoriaCombustible == 3) {
            total[2]+=cantidadCombustible;
        }

        RedNacional* precios = new RedNacional();
        precioCombustible=precios->getPreciosCombustible(numregion, categoriaCombustible-1);

        monto = cantidadCombustible * precioCombustible;

        // Crear nueva transaccion
        Transaccion* nuevaTransaccion = new Transaccion(tipoCombustible, cantidadCombustible, formaPago,
                                                        docCliente, monto, precioCombustible);
        // Registrar la transacción
        transacciones_[numTransacciones_] = nuevaTransaccion;

        // Incrementar el contador
        numTransacciones_++;

        cout << "Venta realizada con exito." << endl;
        delete precios;

        return;

    } else {
        cout << "El surtidor no esta activo." << endl;
        return;
    }
}

void PuntoSurtidor::registrarVenta(Transaccion* transaccion) {
    // Aumentar el tamaño del arreglo dinamico si es necesario
    if (this->numTransacciones_ == 10) {
        // Crear un nuevo arreglo de punteros a Transaccion con mayor tamaño
        Transaccion** temp = new Transaccion*[20];

        for (unsigned int i = 0; i < this->numTransacciones_; i++) {
            temp[i] = this->transacciones_[i]; // Copiar puntero, no objeto
        }

        // Liberar el arreglo antiguo
        delete[] this->transacciones_;
        this->transacciones_ = temp; // Asignar el nuevo arreglo
    }

    // Registrar la nueva transacción
    this->transacciones_[this->numTransacciones_] = transaccion; // Asignar el puntero de la nueva transacción
    this->numTransacciones_++; // Incrementar el contador de transacciones
}

void PuntoSurtidor::mostrarHistorico(bool mostrarUltima) {

    if (numTransacciones_ == 0) {
        cout << "No hay transacciones registradas." << endl;
        return;
    }

    if (mostrarUltima){
        transacciones_[numTransacciones_-1]->mostrarTransaccion();
    }
    else{
        for (unsigned int i = 0; i < numTransacciones_; ++i) {
            transacciones_[i]->mostrarTransaccion(); //Imprimir el recibo de la transaccion
        }
    }
}

PuntoSurtidor::~PuntoSurtidor() {
    for (unsigned int i = 0; i < numTransacciones_; ++i) {
        delete transacciones_[i];
    }
    delete[] transacciones_;
}

unsigned int PuntoSurtidor::getNumTransacciones() const {
    return numTransacciones_; // Retorna el número de transacciones registradas
}

Transaccion* PuntoSurtidor::getTransaccion(unsigned int index) const {
    if (index < numTransacciones_) {
        return transacciones_[index]; // Retorna la transacción en el índice especificado
    }
    return nullptr; // Retorna nullptr si el índice es inválido
}
