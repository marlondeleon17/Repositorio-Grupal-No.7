//STEVEN ANDRE VASQUEZ CHAVEZ 9959 24 11528

#include "Facturacion.h"
#include <iostream>
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()
#include "encabezado.h"

using namespace std;
// Constructor de la clase Facturacion
Facturacion::Facturacion() {
    // Constructor vac�o
}

// Destructor de la clase Facturacion
Facturacion::~Facturacion() {
    // Destructor vac�o
}

// M�todo que despliega el men� de opciones para facturaci�n y gestiona la interacci�n con el usuario
// Recibe como par�metro una referencia a un objeto SistemaVentas que contiene los registros de ventas
void Facturacion::menuFacturacion(SistemaVentas& sistema) {
    int opcion;
    do {
        system("cls");  // Limpia la pantalla
        // Muestra el men� de opciones
        cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n"; //Marlon De Leon 5001
        cout << "\n\t\t\t----------------------------\n";
        cout << "\t\t\t |   SISTEMA DE FACTURACION  |\n";
        cout << "\t\t\t  ----------------------------\n";
        cout << "\t\t\t 1. GENERAR FACTURA\n";
        cout << "\t\t\t 2. REGRESAR AL MENU PRINCIPAL\n";
        cout << "\t\t\t-------------------------------\n";
        cout << "\t\t\tIngresa tu opcion: ";
        cin >> opcion;

        // Procesa la opci�n seleccionada por el usuario
        switch (opcion) {
            case 1:
                generarFactura(sistema);  // Llama al m�todo para generar la factura
                break;
            case 2:
                return;  // Regresa al men� principal
            default:
                cout << "\n\t\t\tOpcion invalida... Por favor intenta otra vez...\n";
                cin.ignore();
                cin.get();
        }
    } while (opcion != 3);  // Repite el ciclo hasta que se seleccione una opci�n v�lida
}

// M�todo para generar una factura
// Recibe como par�metro una referencia a un objeto SistemaVentas que contiene las ventas registradas
void Facturacion::generarFactura(SistemaVentas& sistema) {
    system("cls");
    cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n"; //Marlon De Leon 5001
    cout << "\n\t\t\t-------------------------\n";
    cout << "\t\t\t |   DATOS DE LA FACTURA  |\n";
    cout << "\t\t\t  -------------------------\n";

    string nit, codVenta;
    cout << "\t\t\tIngrese el NIT del cliente: ";
    cin >> nit;

    // Busca el cliente con el NIT ingresado
    Cliente* cliente = nullptr;
    for (auto& c : Cliente::obtenerClientes()) {
        if (c.nit == nit) {
            cliente = &c;
            break;
        }
    }

    if (!cliente) {
        cout << "\t\t\tCliente no encontrado.\n";
        system("pause");
        return;
    }

    cout << "\t\t\tIngrese el codigo de venta: ";
    cin >> codVenta;

    // Busca la venta con el c�digo ingresado
    Venta* venta = sistema.obtenerVentaPorCodigo(stoi(codVenta));
    if (!venta) {
        cout << "\t\t\tVenta no encontrada.\n";
        cout << "\t\t\tPresione Enter para regresar al menu de facturacion.\n";
        cin.ignore();
        cin.get();
        return;
    }

    mostrarFactura(cliente, venta);  // Muestra la factura con los datos encontrados
}

// M�todo para mostrar la factura con los detalles del cliente y la venta
// Recibe como par�metros un puntero a Cliente y a Venta
void Facturacion::mostrarFactura(Cliente* cliente, Venta* venta) {
    system("cls");
    cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n";//Marlon De Leon 5001
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|                                 FACTURA                                   |\n";
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|  NIT: " << cliente->nit << endl;
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|  Nombre del Cliente: " << cliente->nombre << endl;
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|  Codigo de Venta: " << venta->codigoVenta << endl;
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|  Productos comprados:\n";

    double totalFactura = 0.0;
    // Itera sobre los detalles de la venta (productos comprados)
    for (const auto& detalle : venta->productos) {
        double subtotal = detalle.cantidad * detalle.precioUnitario;
        cout << "\t\t\t| " << detalle.nombreProducto
             << " | Cantidad: " << detalle.cantidad
             << " | Precio unitario: Q" << detalle.precioUnitario
             << " | Subtotal: Q" << subtotal << endl;
        totalFactura += subtotal;
    }
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    cout << "\t\t\t|TOTAL: Q" << totalFactura << endl;
    cout << "\t\t\t|---------------------------------------------------------------------------|\n";
    system("pause");
}

// Inicializa el contador de facturas a 400 (primer c�digo de factura)
int Facturacion::contadorFactura = 400;

// M�todo para generar un nuevo c�digo de factura, incrementando el contador
int Facturacion::generarCodigoFactura() {
    return contadorFactura++;  // Devuelve el c�digo de la factura y luego incrementa el contador
}

// M�todo para buscar un cliente en el sistema por su c�digo
Cliente* SistemaVentas::buscarCliente(const string& codigo) {
    for (auto& cliente : Cliente::obtenerClientes()) {
        if (cliente.codigo == codigo) return &cliente;  // Retorna el cliente si el c�digo coincide
    }
    return nullptr;  // Retorna nullptr si no se encuentra el cliente
}
