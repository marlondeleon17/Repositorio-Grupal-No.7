#include "Tablero.h"
#include <cstdlib>
#include <ctime>

// Constructor de la clase Tablero
// Inicializa un tablero con el número de filas y columnas especificadas.
// Parámetros:
// - f: número de filas del tablero
// - c: número de columnas del tablero
Tablero::Tablero(int f, int c) : filas(f), columnas(c) {
    // Redimensiona el vector de celdas para que tenga el tamaño adecuado
    this->celdas.resize(this->filas, vector<Celda>(this->columnas));
}

// Método para colocar minas en el tablero
// Coloca un número específico de minas en posiciones aleatorias del tablero.
// Parámetro:
// - minas: número de minas a colocar en el tablero
void Tablero::colocarMinas(int minas) {
    srand(time(0)); // Inicializa la semilla para la generación de números aleatorios
    int colocadas = 0; // Contador de minas colocadas
    while (colocadas < minas) {
        int fila = rand() % this->filas; // Genera una fila aleatoria
        int col = rand() % this->columnas; // Genera una columna aleatoria
        // Si la celda seleccionada no tiene una mina, se coloca una mina
        if (!this->celdas[fila][col].mina) {
            this->celdas[fila][col].mina = true; // Coloca la mina
            colocadas++; // Incrementa el contador de minas colocadas
        }
    }
}

// Método para mostrar el estado del tablero
// Muestra el tablero en la consola, revelando celdas según el modo de juego.
// Parámetro:
// - administrador: booleano que indica si se debe mostrar el tablero completo (true) o solo las celdas descubiertas (false)
void Tablero::mostrar(bool administrador) {
    cout << "\n    "; // Espacio para la numeración de columnas
    for (int j = 1; j <= this->columnas; j++) cout << j << " "; // Muestra los números de las columnas
    cout << "\n   ";
    for (int j = 0; j < this->columnas; j++) cout << "--"; // Dibuja una línea divisoria
    cout << "\n";
    for (int i = 0; i < this->filas; i++) {
        cout << i + 1 << " | "; // Muestra el número de la fila
        for (int j = 0; j < this->columnas; j++) {
            // Si es modo administrador y hay una mina, muestra un asterisco
            if (administrador && this->celdas[i][j].mina)
                cout << "* ";
            else
                // Muestra el estado de la celda: descubierta o no
                cout << (this->celdas[i][j].descubierta ? (this->celdas[i][j].mina ? "*" : "O") : "?") << " ";
        }
        cout << "|" << endl; // Cierra la fila
    }
}

// Método para descubrir una celda en el tablero
// Intenta descubrir la celda en la posición especificada.
// Parámetros:
// - fila: número de fila de la celda a descubrir (1-indexado)
// - col: número de columna de la celda a descubrir (1-indexado)
// Retorna:
// - true si se descubre una mina, false si la celda no tiene mina
bool Tablero::descubrir(int fila, int col) {
    // Verifica si las coordenadas están dentro de los límites del tablero
    if (fila < 1 || fila > this->filas || col < 1 || col > this->columnas) return false;
    // Verifica si la celda tiene una mina
    if (this->celdas[fila - 1][col - 1].mina) return true; // Retorna true si hay mina
    this->celdas[fila - 1][col - 1].descubierta = true; // Marca la celda como descubierta
    return false; // Retorna false si no hay mina
}
