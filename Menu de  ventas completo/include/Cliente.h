// Maria Celeste Mayen Ibarra 9959-23-3775

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include <string>
#include "Cliente.h"

// Clase que representa a un cliente dentro del sistema
class Cliente {
public:
    // Atributos p�blicos del cliente
    std::string nombre;     // Nombre del cliente
    std::string telefono;   // N�mero telef�nico del cliente
    std::string nit;        // N�mero de Identificaci�n Tributaria (NIT)
    std::string codigo;     // C�digo �nico del cliente

    // Constructor por defecto
    Cliente();

    // Constructor con par�metros para inicializar los datos del cliente
    Cliente(std::string n, std::string t, std::string nit, std::string cod);

    // Men� principal de opciones para gestionar clientes
    static void MenuClientes();

    // Funci�n para agregar un nuevo cliente
    static void AgregarCliente();

    // Funci�n para modificar los datos de un cliente existente
    static void ModificarCliente();

    // Funci�n para eliminar un cliente del registro
    static void EliminarCliente();

    // Funci�n para mostrar el listado completo de clientes
    static void MostrarClientes();

    // Retorna la lista completa de clientes registrados
    static std::vector<Cliente>& obtenerClientes();

private:
    // Lista est�tica que almacena todos los clientes registrados
    static std::vector<Cliente> clientes;

    // Contador est�tico utilizado para generar c�digos �nicos para los clientes
    static int contadorClientes;
};

#endif // CLIENTE_H
