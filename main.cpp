#include<string>
#include <iostream>
#include "rednacional.h"
#include "estacionservicio.h"
#include "puntosurtidor.h"
#include "isla.h"

using namespace std;

void gestionRed(RedNacional* rednacional) {
    int opcion;
    string nombre, gerente, region, codigo;
    unsigned int maxPuntosSurtidores;
    EstacionServicio* nuevaEstacion;

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
            float precioRegularN,precioPremiumN, precioEcoExtraN, precioRegularC,precioPremiumC, precioEcoExtraC,precioRegularS,precioPremiumS, precioEcoExtraS;
            // Fijar los precios del combustible para toda la red

            cout << "Region Norte"<<endl;
            cout << "-------------" << endl;
            cout << "Ingrese el precio del combustible regular: ";
            cin >> precioRegularN;
            cout << "Ingrese el precio del combustible premium: ";
            cin >> precioPremiumN;
            cout << "Ingrese el precio del combustible EcoExtra: ";
            cin >> precioEcoExtraN;
            rednacional->setPreciosCombustible(0,precioRegularN, precioPremiumN, precioEcoExtraN);

            cout << "Region Centro"<<endl;
            cout << "-------------" << endl;
            cout << "Ingrese el precio del combustible regular: ";
            cin >> precioRegularC;
            cout << "Ingrese el precio del combustible premium: ";
            cin >> precioPremiumC;
            cout << "Ingrese el precio del combustible EcoExtra: ";
            cin >> precioEcoExtraC;
            rednacional->setPreciosCombustible(1, precioRegularC,precioPremiumC, precioEcoExtraC);

            cout << "Region Sur"<<endl;
            cout << "-------------" << endl;
            cout << "Ingrese el precio del combustible regular: ";
            cin >> precioRegularS;
            cout << "Ingrese el precio del combustible premium: ";
            cin >> precioPremiumS;
            cout << "Ingrese el precio del combustible EcoExtra: ";
            cin >> precioEcoExtraS;
            rednacional->setPreciosCombustible(2, precioRegularS,precioPremiumS,precioEcoExtraS);

            cout << "Precios fijados exitosamente."<<endl;

            break;

        case 5:
            cout << "Volviendo al menu principal..." << endl;
            return;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }
    } while (opcion != 5);
}

void gestionEstaciones(RedNacional* rednacional) {

    if (rednacional->getNumEstaciones() == 0) {
        cout << "No hay estaciones en la red." << endl;
        return;
    }

    // Seleccionar la estacion de servicio
    cout << "Seleccione el numero de la estacion: " << endl;
    for (unsigned int i = 0; i < rednacional->getNumEstaciones(); ++i) {
        cout << i + 1 << ". " << rednacional->getEstacion(i)->getNombre() << endl;
    }
    unsigned int indiceEstacion;
    cin >> indiceEstacion;

    if (indiceEstacion < 1 || indiceEstacion > rednacional->getNumEstaciones()) {
        cout << "Numero de estacion no valido." << endl;
        return;
    }

    EstacionServicio* estacionSeleccionada = rednacional->getEstacion(indiceEstacion - 1);
    string modeloSurtidor;
    string region;
    int opcion;
    float total[3]={0.0, 0.0, 0.0};

    do {
        cout << "Gestion de estaciones de servicio" << endl;
        cout << "-------------" << endl;
        cout << "1. Agregar/eliminar un surtidor a una E/S" << endl;
        cout << "2. Activar/desactivar un surtidor de una E/S" << endl;
        cout << "3. Eliminar un surtidor de una E/S" << endl;
        cout << "4. Consultar el historico de transacciones de cada surtidor de la E/S" << endl;
        cout << "5. Reportar la cantidad de litros vendida segun cada categoria de combustible" << endl;
        cout << "6. Simular una venta de combustible" << endl;
        cout << "7. Asignar la capacidad del tanque de suministro" << endl;
        cout << "8. Volver al menu principal" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            // Solicitar al usuario que ingrese el modelo del nuevo surtidor
            cout << "Ingrese el modelo del nuevo surtidor: ";
            cin >> modeloSurtidor;

            // Crear el nuevo surtidor y agregarlo a la estación seleccionada
            estacionSeleccionada->agregarPuntoSurtidor(modeloSurtidor);

            break;
        case 2: {
            string codigoSurtidor;
            char accion;

            cout << "Ingrese el codigo del surtidor: ";
            cin >> codigoSurtidor;

            cout << "Desea activar (A) o desactivar (D) el surtidor? ";
            cin >> accion;

            accion = toupper(accion);

            if (accion == 'A') {
                estacionSeleccionada->activarPuntoSurtidor(codigoSurtidor);
            } else if (accion == 'D') {
                cout << "CODIGO SURTIDOR   " << codigoSurtidor << endl;
                estacionSeleccionada->desactivarPuntoSurtidor(codigoSurtidor);
            } else {
                cout << "Accion no valida. Ingrese 'A' para activar o 'D' para desactivar." << endl;
            }
            break;
        }
        case 3: {
            string codigoSurtidor;
            cout << "Ingrese el código del surtidor a eliminar: ";
            cin >> codigoSurtidor;

            //Llamar al método eliminarPuntoSurtidor de la estación seleccionada
            estacionSeleccionada->eliminarPuntoSurtidor(codigoSurtidor);
            break;
            }
        case 4:
            // Consultar el histOrico de transacciones de cada surtidor de la E/S
            break;
        case 5:
            // Reportar la cantidad de litros vendida segun cada categoria de combustible
            cout<< "Regular: " << total[0]<<endl<<"Premium: "<<total[1]<<endl<<"EcoExtra: "<<total[2]<<endl;
            break;
        case 6:
            // Simular una venta de combustible
            region=estacionSeleccionada->getRegion();
            estacionSeleccionada->simularVenta(region, total);
            break;
        case 7:
            // Asignar la capacidad del tanque de suministro
            //estacionSeleccionada->setCapacidadTanque();

            break;
        case 8:
            cout << endl << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 8);
}



void sistemaVerificacionFugas() {
    // Verificar fugas de combustible en una estación de servicio específica
}


int main() {
    RedNacional* rednacional = new RedNacional();
    int opcion;
    do {
        cout << "Menu principal" << endl;
        cout << "-------------" << endl;
        cout << "1. Gestion de la red" << endl;
        cout << "2. Gestion de estaciones de servicio" << endl;
        cout << "3. Sistema nacional de verificacion de fugas" << endl;
        //cout << "4. Simulacion de ventas" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
        case 1:
            gestionRed(rednacional);
            break;
        case 2:
            gestionEstaciones(rednacional);
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
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}
