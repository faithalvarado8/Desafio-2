#include<string>
#include <iostream>
#include "estacionservicio.h"
#include "puntosurtidor.h"
#include "isla.h"

using namespace std;

void mostrarMenu(){
    cout << "---------- Menu de Estacion de Servicio ----------" << endl;
    cout << "1. Asignar capacidades al tanque" << endl;
    cout << "----------------" << endl;
    cout << "2. Agregar surtidor" << endl;
    cout << "3. Eliminar surtidor" << endl;
    cout << "4. Activar surtidor" << endl;
    cout << "5. Desactivar surtidor" << endl;
    cout << "----------------" << endl;
    cout << "6. Simular venta" << endl;
    cout << "7. Consultar transacciones de surtidor" << endl;
    cout << "----------------" << endl;
    cout << "8. Reportar litros vendidos" << endl;
    cout << "9. Verificar fugas" << endl;
    cout << "----------------" << endl;
    cout << "10. Salir" << endl;
    cout << "---------------------------------------------------" << endl;
}

int main() {
    string nombre, gerente, region;
    unsigned int maxSurtidores;

    cout << "Ingrese el nombre de la estacion: ";
    cin >> nombre;
    cout << "Ingrese el nombre del gerente: ";
    cin >> gerente;
    cout << "Ingrese la region: ";
    cin >> region;
    cout << "Ingrese la cantidad maxima de surtidores: ";
    cin >> maxSurtidores;

    // Crear la estación
    EstacionServicio estacion(nombre, gerente, region, maxSurtidores);
    cout << "Estacion creada con el codigo: " << estacion.getCodigo() << endl;


    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            estacion.setCapacidadTanque();
            break;

        case 2: {  // Agregar punto surtidor
            string modelo;
            cout << "Ingrese el modelo del surtidor: ";
            cin >> modelo;
            PuntoSurtidor* surtidor = new PuntoSurtidor(modelo, true, 0);
            estacion.agregarPuntoSurtidor(surtidor);
            cout << "Surtidor creado con el codigo: " << surtidor->getCodigo() << endl;
            break;
        }

        case 3: {  // Eliminar surtidor
            string codigoSurtidor;
            cout << "Ingrese el codigo del surtidor: ";
            cin >> codigoSurtidor;
            estacion.eliminarPuntoSurtidor(codigoSurtidor);
            break;
        }

        case 4: { // Activar surtidor
            string codigo;
            cout << "Ingrese el codigo del surtidor a activar: ";
            cin >> codigo;
            estacion.activarPuntoSurtidor(codigo);
            break;
        }

        case 5: {
            string codigo;
            cout << "Ingrese el codigo del surtidor a desactivar: ";
            cin >> codigo;
            estacion.desactivarPuntoSurtidor(codigo);
            break;
        }

        case 6:
            estacion.simularVenta();
            break;

        case 7: {
            string codigo;
            cout << "Ingrese el código del surtidor para consultar transacciones: ";
            cin >> codigo;
            estacion.consultarTransaccionesPuntoSurtidor(codigo);
            break;
        }

        case 8:
            estacion.reportarLitrosVendidos();
            break;

        case 9:
            estacion.verificarFugas();
            break;

        case 10:
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opción no válida." << endl;
            break;
        }

        cout << endl; // Espacio para legibilidad

    } while (opcion != 10); // Termina cuando el usuario elige salir

    return 0; // Fin del programa
}

