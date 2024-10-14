#include "transaccion.h"

Transaccion::Transaccion(){}

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

//Metodo de despliegue
void Transaccion::mostrarTransaccion() const {

    cout << endl << endl << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "                              TERMAX                            " << endl;
    cout << "                      RECIBO DE TRANSACCION                     " << endl;
    cout << "----------------------------------------------------------------" << endl;

    unsigned int ancho = 40;
    cout << setw(ancho) << left << "   Tipo de combustible:" << tipoCombustible_ << endl;
    cout << setw(ancho) << left << "   Cantidad de combustible (litros):" << cantidadCombustible_ << endl;
    cout << setw(ancho) << left << "   Precio del combustible ($/litro): " << fixed << setprecision(2) << precioCombustible_ << endl;
    cout << setw(ancho) << left << "   Monto ($): " << fixed << setprecision(2) << monto_ << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << setw(ancho) << left << "   Forma de pago:" << formaPago_ << endl;
    cout << setw(ancho) << left << "   Documento del cliente:" << docCliente_ << endl;
    cout << setw(ancho) << left << "   Fecha y hora:" << fechahora_ << endl;
    cout << "----------------------------------------------------------------" << endl;
}
