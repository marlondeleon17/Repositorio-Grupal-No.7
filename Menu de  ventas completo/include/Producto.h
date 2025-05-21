//STEVEN ANDRE VASQUEZ CHAVEZ 9959 24 11528

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>
using namespace std;

// Estructura que define la informaci�n de un producto
struct ProductoInfo {
    string nombre;  // Nombre del producto
    int cantidad;   // Cantidad disponible en inventario
    float precio;   // Precio unitario del producto
    int codigo;     // C�digo �nico que identifica al producto
};

// Clase Producto que maneja las operaciones relacionadas con los productos
class Producto {
public:
    // Constructor de la clase Producto
    Producto();

    // Men� principal para la gesti�n de productos
    void MenuProducto();

    // M�todo para agregar un nuevo producto
    void NuevoProducto();

    // M�todo para mostrar la lista de productos existentes
    void MostrarProductos();

    // M�todo para eliminar un producto de la lista
    void EliminarProducto();

    // M�todo est�tico que obtiene la lista de productos
    static std::vector<ProductoInfo>& obtenerProductos();  // Nuevo m�todo para obtener los productos

private:
    // Lista est�tica que almacena todos los productos
    static std::vector<ProductoInfo> productos;  // Vector est�tico para contener los productos

    // M�todo privado para generar un c�digo aleatorio �nico para los productos
    int generarCodigoAleatorio();
};

#endif // PRODUCTO_H
