#include "puntosurtidor.h"
#include "isla.h"

unsigned int PuntoSurtidor::contadorCodigo = 100;

PuntoSurtidor::PuntoSurtidor(string modelo, bool activado, unsigned int numTransacciones_):
    modelo_(modelo), activado_(activado), numTransacciones_(numTransacciones_) {
    transacciones_ = new Transaccion*[10];

    codigo_ = "PS-" + to_string(contadorCodigo++);
}

string PuntoSurtidor::getCodigo()const{
    return codigo_;
}

string PuntoSurtidor::getModelo(){
    return modelo_;
}

bool PuntoSurtidor::setEstado(){
    return this->activado_;
}

bool PuntoSurtidor::getEstado(){
    return this->activado_;
}

void PuntoSurtidor::realizarVenta(float precioCombustible) {

    if (activado_) {

        char categoriaCombustible;
        string tipoCombustible;
        float cantidadCombustible;
        char categoriaPago;
        string formaPago;
        string docCliente;
        float monto;

        cout << "Tipo de combustible: REGULAR(1), PREMIUM(2), ECOEXTRA(3): ";
        cin >> categoriaCombustible;
        if (categoriaCombustible == '1') {
            tipoCombustible = "REGULAR";
        }
        else if (categoriaCombustible == '2') {
            tipoCombustible = "PREMIUM";
        }
        else if (categoriaCombustible == '3') {
            tipoCombustible = "ECOEXTRA";
        } else {
            cout << "Opción no válida. Por favor, ingrese 1, 2 o 3." << endl;
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
            cout << "Opción no válida. Por favor, ingrese 1, 2 o 3." << endl;
        }

        cout << "Ingrese el documento del cliente: ";
        cin >> docCliente;

        float cantidadDisponible = Isla::getCantidadDisponible(tipoCombustible);

        if (cantidadCombustible > cantidadDisponible) {
            cantidadCombustible = cantidadDisponible;
            cout << "En este momento no disponemos de esa cantidad de combustible. " << endl;
            cout << "Se expedira y cobrara la cantidad disponible." << endl;
        }

        monto = cantidadCombustible * precioCombustible;

        // Crear nueva transacción
        Transaccion* nuevaTransaccion = new Transaccion(tipoCombustible, cantidadCombustible, formaPago,
                                                        docCliente, monto, precioCombustible);
        // Registrar la transacción
        transacciones_[numTransacciones_] = nuevaTransaccion;

        // Incrementar el contador
        numTransacciones_++;

        cout << "Venta realizada con exito." << endl;

        return;

    } else {
        cout << "El surtidor no esta activo." << endl;
    }
}

void PuntoSurtidor::registrarVenta(Transaccion* transaccion) {
    // Aumentar el tamaño del arreglo dinámico si es necesario
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

void PuntoSurtidor::mostrarHistorico() {
    cout << "Historial de transacciones:\n";

    if (numTransacciones_ == 0) {
        cout << "No hay transacciones registradas." << endl;
        return;
    }

    for (unsigned int i = 0; i < numTransacciones_; ++i) {
        transacciones_[i]->mostrarTransaccion(); //Imprimir el recibo de la transaccion
    }
}

PuntoSurtidor::~PuntoSurtidor() {
    for (unsigned int i = 0; i < numTransacciones_; ++i) {
        delete transacciones_[i];
    }
    delete[] transacciones_;
}
