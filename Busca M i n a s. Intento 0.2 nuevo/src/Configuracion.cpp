#include "Configuracion.h"

// Constructor de la clase Configuracion
// Inicializa los parámetros del juego con los valores proporcionados:
// - filas: número de filas en el tablero
// - columnas: número de columnas en el tablero
// - minas: cantidad de minas en el juego
// - vidas: número de vidas disponibles
// - modo: configuración del modo de juego
// - victorias y derrotas inicializadas en 0
Configuracion::Configuracion(int f, int c, int m, int v, int modo)
    : filas(f), columnas(c), minas(m), vidas(v), modo(modo), victorias(0), derrotas(0) {}

// Método para incrementar el contador de victorias
void Configuracion::aumentarVictoria() {
    this->victorias++;
}

// Método para incrementar el contador de derrotas
void Configuracion::aumentarDerrota() {
    this->derrotas++;
}
