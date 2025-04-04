#include "Producto.h"

// Constructor de la clase Producto.
// Este constructor inicializa un objeto de la clase Producto utilizando los parámetros proporcionados
//
// Parámetros:
//   n (std::string): El nombre del producto.
//   p (double): El precio del producto.
//
// Este constructor asigna estos valores a los atributos correspondientes del objeto actual.
Producto::Producto(std::string n, double p) : nombre(n), precio(p) {}
