#include "puntosurtidor.h"
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

void PuntoSurtidor::realizarVenta(RedNacional* rednacional,string& region, float (&total)[3], EstacionServicio* estacion) {

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
        do{
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
        }while (categoriaCombustible!=1 && categoriaCombustible!=2 && categoriaCombustible!=3);

        // Obtener el precio del combustible de la instancia de RedNacional
        precioCombustible = rednacional->getPreciosCombustible(numregion, categoriaCombustible - 1);

        cout << "Ingrese la cantidad de combustible a expender (litros): ";

        do{
            cin >> cantidadCombustible;
            if (categoriaCombustible<3 || cantidadCombustible>20){
            cout << "Cantidad invalida. Ingrese nuevamente la cantidad de combustible a expender (litros): ";
            }
        }while (cantidadCombustible<3 || cantidadCombustible>20);

        // Verificar si hay suficiente combustible disponible en el tanque de la estación
        float cantidadDisponible = estacion->getCantidadDisponible(tipoCombustible);
        if (cantidadCombustible > cantidadDisponible) {
            cout << "En este momento no disponemos de esa cantidad de combustible. " << endl;
            cout << "Se expedira y cobrara la cantidad disponible." << endl;
            cantidadCombustible=cantidadDisponible;
        }

        cout << "Forma de pago: EFECTIVO(1), T.DEBITO(2), T.CREDITO(3): ";
        do{
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
        } while(categoriaPago!='1' && categoriaPago!='2' && categoriaPago!='3');

        cout << "Ingrese el documento del cliente: ";
        cin >> docCliente;

        // Realiza el calculo del monto y registra la transaccion
        monto = cantidadCombustible * precioCombustible;

        // Crear nueva transaccion
        Transaccion* nuevaTransaccion = new Transaccion(tipoCombustible, cantidadCombustible, formaPago,
                                                        docCliente, monto, precioCombustible);
        // Registrar la transacción
        transacciones_[numTransacciones_] = nuevaTransaccion;
        numTransacciones_++;

        // Reducir la cantidad de combustible en el tanque
        estacion->reducirCombustible(tipoCombustible, cantidadCombustible);

        // Actualizar el total
        if (categoriaCombustible == 1) {
            total[0]+=cantidadCombustible;
        }
        else if (categoriaCombustible == 2) {
            total[1]+=cantidadCombustible;
        }
        else if (categoriaCombustible == 3) {
            total[2]+=cantidadCombustible;
        }

        cout << "Venta realizada con exito." << endl;

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
