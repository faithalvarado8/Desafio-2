#include<string>
#include <iostream>
#include "rednacional.h"
#include "estacionservicio.h"
#include "puntosurtidor.h"
#include "isla.h"

using namespace std;




void gestionRed() {
    RedNacional* rednacional = new RedNacional(); // Declarar la variable rednacional

    int opcion;
    string nombre, gerente, region, codigo;
    unsigned int maxPuntosSurtidores;
    EstacionServicio* nuevaEstacion; // Declarar la variable nuevaEstacion aquí

    do {
        cout << "Gestion de la red" << endl;
        cout << "-------------" << endl;
        cout << "1. Agregar una E/S de la red nacional" << endl;
        cout << "2. Eliminar una E/S de la red nacional" << endl;
        cout << "3. Calcular ventas en cada E/S" << endl;
        cout << "4. Fijar precios del combustible de la red" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            // Solicitar al usuario que ingrese la información necesaria
            cout << "Ingrese el nombre de la estacion: ";
            cin >> nombre;
            cout << "Ingrese el nombre del gerente: ";
            cin >> gerente;
            cout << "Ingrese la region: ";
            cin >> region;
            cout << "Ingrese el numero maximo de puntos surtidores: ";
            cin >> maxPuntosSurtidores;
            cout << endl << endl;

            // Crear una nueva instancia de EstacionServicio con la información ingresada
            nuevaEstacion = new EstacionServicio(nombre, gerente, region, maxPuntosSurtidores);

            // Agregar la estación de servicio a la red nacional
            rednacional->agregarEstacion(nuevaEstacion);
            break;
        case 2:
            cout << "Ingrese codigo E/S a eliminar(Formato: EST-codigo): ";
            cin >> codigo;
            rednacional->eliminarEstacion(codigo);
            break;
        case 3:
            // Calcular el monto total de las ventas en cada E/S del país
            break;
        case 4:
            // Fijar los precios del combustible para toda la red
            break;
        case 5:
            // cout << "Volviendo al menú principal..." << endl;
            break;
        default:
            ;// cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);
}

void gestionEstaciones() {
    int opcion;
    do {
        cout << "Gestion de estaciones de servicio" << endl;
        cout << "-------------" << endl;
        cout << "1. Agregar/eliminar un surtidor a una E/S" << endl;
        cout << "2. Activar/desactivar un surtidor de una E/S" << endl;
        cout << "3. Consultar el historico de transacciones de cada surtidor de la E/S" << endl;
        cout << "4. Reportar la cantidad de litros vendida segun cada categoria de combustible" << endl;
        cout << "5. Simular una venta de combustible" << endl;
        cout << "6. Asignar la capacidad del tanque de suministro" << endl;
        cout << "7. Volver al menu principal" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            // Agregar/eliminar un surtidor a una E/S
            break;
        case 2:
            // Activar/desactivar un surtidor de una E/S
            break;
        case 3:
            // Consultar el histórico de transacciones de cada surtidor de la E/S
            break;
        case 4:
            // Reportar la cantidad de litros vendida según cada categoría de combustible
            break;
        case 5:
            // Simular una venta de combustible
            break;
        case 6:
            // Asignar la capacidad del tanque de suministro
            break;
        case 7:
            cout << endl << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 7);
}

void sistemaVerificacionFugas() {
    // Verificar fugas de combustible en una estación de servicio específica
}

void simulacionVentas() {
    // Simular una venta de combustible en una estación

}


int main() {
    int opcion;
    do {
        cout << "Menu principal" << endl;
        cout << "-------------" << endl;
        cout << "1. Gestion de la red" << endl;
        cout << "2. Gestion de estaciones de servicio" << endl;
        cout << "3. Sistema nacional de verificacion de fugas" << endl;
        cout << "4. Simulacion de ventas" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            gestionRed();
            break;
        case 2:
            //gestionEstaciones();
            break;
        case 3:
            //sistemaVerificacionFugas();
            break;
        case 4:
            //simulacionVentas();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}

// void mostrarMenu(){
//     cout << "---------- Menu de Estacion de Servicio ----------" << endl;
//     cout << "1. Asignar capacidades al tanque" << endl;
//     cout << "----------------" << endl;
//     cout << "2. Agregar surtidor" << endl;
//     cout << "3. Eliminar surtidor" << endl;
//     cout << "4. Activar surtidor" << endl;
//     cout << "5. Desactivar surtidor" << endl;
//     cout << "----------------" << endl;
//     cout << "6. Simular venta" << endl;
//     cout << "7. Consultar transacciones de surtidor" << endl;
//     cout << "----------------" << endl;
//     cout << "8. Reportar litros vendidos" << endl;
//     cout << "9. Verificar fugas" << endl;
//     cout << "----------------" << endl;
//     cout << "10. Salir" << endl;
//     cout << "---------------------------------------------------" << endl;
// }

// int main() {
//     string nombre, gerente, region;
//     unsigned int maxSurtidores;

//     cout << "Ingrese el nombre de la estacion: ";
//     cin >> nombre;
//     cout << "Ingrese el nombre del gerente: ";
//     cin >> gerente;
//     cout << "Ingrese la region: ";
//     cin >> region;
//     cout << "Ingrese la cantidad maxima de surtidores: ";
//     cin >> maxSurtidores;

//     // Crear la estación
//     EstacionServicio estacion(nombre, gerente, region, maxSurtidores);
//     cout << "Estacion creada con el codigo: " << estacion.getCodigo() << endl;


//     int opcion;
//     do {
//         mostrarMenu();
//         cout << "Seleccione una opcion: ";
//         cin >> opcion;

//         switch (opcion) {
//         case 1:
//             estacion.setCapacidadTanque();
//             break;

//         case 2: {  // Agregar punto surtidor
//             string modelo;
//             cout << "Ingrese el modelo del surtidor: ";
//             cin >> modelo;
//             PuntoSurtidor* surtidor = new PuntoSurtidor(modelo, true, 0);
//             estacion.agregarPuntoSurtidor(surtidor);
//             cout << "Surtidor creado con el codigo: " << surtidor->getCodigo() << endl;
//             break;
//         }

//         case 3: {  // Eliminar surtidor
//             string codigoSurtidor;
//             cout << "Ingrese el codigo del surtidor: ";
//             cin >> codigoSurtidor;
//             estacion.eliminarPuntoSurtidor(codigoSurtidor);
//             break;
//         }

//         case 4: { // Activar surtidor
//             string codigo;
//             cout << "Ingrese el codigo del surtidor a activar: ";
//             cin >> codigo;
//             estacion.activarPuntoSurtidor(codigo);
//             break;
//         }

//         case 5: {
//             string codigo;
//             cout << "Ingrese el codigo del surtidor a desactivar: ";
//             cin >> codigo;
//             estacion.desactivarPuntoSurtidor(codigo);
//             break;
//         }

//         case 6:
//             estacion.simularVenta();
//             break;

//         case 7: {
//             string codigo;
//             cout << "Ingrese el código del surtidor para consultar transacciones: ";
//             cin >> codigo;
//             estacion.consultarTransaccionesPuntoSurtidor(codigo);
//             break;
//         }

//         case 8:
//             estacion.reportarLitrosVendidos();
//             break;

//         case 9:
//             estacion.verificarFugas();
//             break;

//         case 10:
//             cout << "Saliendo del programa." << endl;
//             break;

//         default:
//             cout << "Opción no válida." << endl;
//             break;
//         }

//         cout << endl; // Espacio para legibilidad

//     } while (opcion != 10); // Termina cuando el usuario elige salir

//     return 0; // Fin del programa
// }
