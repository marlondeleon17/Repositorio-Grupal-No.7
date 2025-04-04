#include "Venta.h"

// Documentacion Steven Vasquez 

// Constructor de la clase Venta.
// Parámetros:
//   c (Cliente): El cliente que realiza la compra.
//   p (Producto): El producto que se está vendiendo.
//   cant (int): La cantidad del producto que se está comprando.
//
// Este constructor asigna estos valores a los atributos correspondientes del objeto actual.
Venta::Venta(Cliente c, Producto p, int cant) : cliente(c), producto(p), cantidad(cant) {}
