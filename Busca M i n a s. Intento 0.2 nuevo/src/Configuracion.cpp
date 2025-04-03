#include "Configuracion.h"

// Constructor de la clase Configuracion
// Inicializa los atributos de la configuración del juego.
// Parámetros:
// - f: número de filas del tablero
// - c: número de columnas del tablero
// - m: número de minas en el tablero
// - v: número de vidas del jugador
// - modo: modo de juego (puede ser un valor que indique diferentes configuraciones de juego)
Configuracion::Configuracion(int f, int c, int m, int v, int modo)
    : filas(f), columnas(c), minas(m), vidas(v), modo(modo), victorias(0), derrotas(0) {}

// Incrementa el contador de victorias en 1
void Configuracion::aumentarVictoria() {
    this->victorias++;
}

// Incrementa el contador de derrotas en 1
void Configuracion::aumentarDerrota() {
    this->derrotas++;
}
