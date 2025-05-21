// Maria Celeste Mayen Ibarra 9959-23-3775

#include "Cliente.h"
#include <iostream>
#include <iomanip>  // Para formatear la salida en columnas
#include <cstdlib>  // Para usar system("cls") y limpiar pantalla
#include "encabezado.h" //Marlon De Leon 5001
using namespace std;



// Inicializaci�n de la lista est�tica de clientes
vector<Cliente> Cliente::clientes;

// Inicializaci�n del contador para generar c�digos �nicos de cliente
int Cliente::contadorClientes = 1;

// Constructor por defecto
Cliente::Cliente() {}

// Constructor que recibe los datos del cliente
Cliente::Cliente(string n, string t, string nit, string cod)
    : nombre(n), telefono(t), nit(nit), codigo(cod) {}

// M�todo para obtener la lista de clientes
std::vector<Cliente>& Cliente::obtenerClientes() {
    return clientes;
}

// Men� principal del sistema de clientes
void Cliente::MenuClientes() {
    int opcion;
    do {
        system("cls");  // Limpia la pantalla
        cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual; //Marlon De Leon 5001
        cout << "\n\t\t\t---------------------------\n";
        cout << "\t\t\t |   SISTEMA DE CLIENTES  |\n";
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t\t 1. NUEVO CLIENTE\n";
        cout << "\t\t\t 2. MODIFICAR CLIENTE\n";
        cout << "\t\t\t 3. ELIMINAR CLIENTE\n";
        cout << "\t\t\t 4. SALIR\n";
        cout << "\t\t\t-------------------------------\n";
        cout << "\t\t\tIngresa tu opci�n: ";
        cin >> opcion;

        // Ejecuta la opci�n seleccionada
        switch (opcion) {
            case 1:
                AgregarCliente();     // Agrega un nuevo cliente
                break;
            case 2:
                ModificarCliente();   // Modifica un cliente existente
                break;
            case 3:
                EliminarCliente();    // Elimina un cliente
                break;
            case 4:
                return;               // Sale del men�
            default:
                // Opci�n inv�lida
                cout << "\n\t\t\t Opci�n inv�lida...Por favor intenta otra vez...\n";
                cin.ignore();
                cin.get();
        }
    } while (opcion != 4);
}

// Funci�n para agregar un nuevo cliente
void Cliente::AgregarCliente() {
    system("cls");
    cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n"; //Marlon De Leon 5001
    cout << "\t\t\t---------------------\n";
    cout << "\t\t\t |   NUEVO CLIENTE   |\n";
    cout << "\t\t\t----------------------\n";

    string nombre, telefono, nit;
    string codigo = to_string(contadorClientes++);  // Genera c�digo �nico autom�ticamente

    // Solicita datos del cliente
    cout << "\t\t\tIngrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "\t\t\tIngrese el numero telefonico del cliente: ";
    cin >> telefono;
    cout << "\t\t\tIngrese el numero de NIT del cliente: ";
    cin >> nit;

    // Agrega el nuevo cliente a la lista
    clientes.push_back(Cliente(nombre, telefono, nit, codigo));
    cout << "\t\t\tCliente agregado exitosamente.\n";

    // Espera que el usuario presione ENTER para continuar
    cout << "\nPresione ENTER para regresar al men�...";
    cin.ignore();
    cin.get();
}

// Funci�n para modificar los datos de un cliente existente
void Cliente::ModificarCliente() {
    system("cls");
    cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n"; //Marlon De Leon 5001
    cout << "\t\t\t--------------------------\n";
    cout << "\t\t\t |   MODIFICAR CLIENTE   |\n";
    cout << "\t\t\t--------------------------\n";

    string codigoBuscado;
    cout << "\t\t\tIngrese el codigo del cliente a modificar: ";
    cin >> codigoBuscado;

    // Busca al cliente por su c�digo
    for (auto& cliente : clientes) {
        if (cliente.codigo == codigoBuscado) {
            // Muestra los datos actuales del cliente
            cout << "\t\t\tCliente encontrado:\n";
            cout << "\t\t\tNombre: " << cliente.nombre << "\n";
            cout << "\t\t\tTelefono: " << cliente.telefono << "\n";
            cout << "\t\t\tNIT: " << cliente.nit << "\n";

            // Solicita al usuario qu� desea modificar
            cout << "\t\t\t�Que desea modificar?\n";
            cout << "\t\t\t1. Telefono\n";
            cout << "\t\t\t2. NIT\n";
            int opcion;
            cin >> opcion;

            // Realiza la modificaci�n correspondiente
            if (opcion == 1) {
                cout << "\t\t\tIngrese nuevo n�mero telefonico: ";
                cin >> cliente.telefono;
            } else if (opcion == 2) {
                cout << "\t\t\tIngrese nuevo NIT: ";
                cin >> cliente.nit;
            } else {
                cout << "\t\t\tOpcion inv�lida.\n";
            }

            cout << "\t\t\tCliente modificado exitosamente.\n";
            break;
        }
    }

    // Espera que el usuario presione ENTER para continuar
    cout << "\t\t\tPresione ENTER para regresar al men�...";
    cin.ignore();
    cin.get();
}

// Funci�n para eliminar un cliente
void Cliente::EliminarCliente() {
    system("cls");
    cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n"; //Marlon De Leon 5001
    cout << "\t\t\t-------------------------\n";
    cout << "\t\t\t |   ELIMINAR CLIENTE   |\n";
    cout << "\t\t\t-------------------------\n";

    string codigoBuscado;
    cout << "\t\t\tIngrese el codigo del cliente a eliminar: ";
    cin >> codigoBuscado;

    // Busca al cliente por su c�digo y lo elimina
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->codigo == codigoBuscado) {
            clientes.erase(it);
            cout << "\t\t\tCliente eliminado exitosamente.\n";
            break;
        }
    }

    // Espera que el usuario presione ENTER para continuar
    cout << "\t\t\tPresione ENTER para regresar al menu...";
    cin.ignore();
    cin.get();
}

// Funci�n para mostrar el listado de clientes registrados
void Cliente::MostrarClientes() {
    system("cls");
    cout << "\n\t\t\t USUARIO ACTUAL: " << usuarioActual << "\n"; //Marlon De Leon 5001
    cout << "\t\t\t----------------------------\n";
    cout << "\t\t\t |   REGISTRO DE CLIENTE   |\n";
    cout << "\t\t\t----------------------------\n";

    // Si no hay clientes, informa al usuario
    if (clientes.empty()) {
        cout << "\t\t\tNo hay clientes registrados.\n";
    } else {
        // Imprime encabezados de la tabla
        cout << left << setw(10) << "Codigo" << setw(20) << "Nombre"
             << setw(15) << "Telefono" << setw(15) << "NIT" << "\n";
        cout << "-------------------------------------------------------------\n";

        // Imprime los datos de cada cliente
        for (const auto& cliente : clientes) {
            cout << left << setw(10) << cliente.codigo
                 << setw(20) << cliente.nombre
                 << setw(15) << cliente.telefono
                 << setw(15) << cliente.nit << "\n";
        }
    }

    // Espera que el usuario presione ENTER para continuar
    cout << "\t\t\tPresione ENTER para regresar al menu...";
    cin.ignore();
    cin.get();
}

