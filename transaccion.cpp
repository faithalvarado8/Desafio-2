#include "transaccion.h"

Transaccion::Transaccion(const string& tipoCombustible, float cantidadCombustible,
                         const string& formaPago, const string& docCliente, float monto,
                         float precioCombustible):
    tipoCombustible_(tipoCombustible),
    cantidadCombustible_(cantidadCombustible),
    formaPago_(formaPago),
    docCliente_(docCliente),
    monto_(monto),
    precioCombustible_(precioCombustible){

    // Obtener la fecha y hora del sistema
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%d/%m/%Y - %H:%M:%S");
    fechahora_ = ss.str();
}

void Transaccion::mostrarTransaccion() const {

    cout << endl << endl << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "                        TERMAX                        " << endl;
    cout << "                 RECIBO DE TRANSACCION                " << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "   Tipo de combustible: " << tipoCombustible_ << endl;
    cout << "   Cantidad de combustible: " << cantidadCombustible_ << " litros" <<  endl;
    cout << "   Precio del combustible: " << "$" << precioCombustible_ << endl;
    cout << "   Monto: " << "$" << monto_ << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "   Forma de pago: " << formaPago_ << endl;
    cout << "   Documento del cliente: " << docCliente_ << endl;
    cout << "   Fecha y hora: " << fechahora_ << endl;
    cout << "------------------------------------------------------" << endl;
}
