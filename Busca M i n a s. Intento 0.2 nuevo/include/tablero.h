#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include "Celda.h"

using namespace std;

// Clase Tablero
// Esta clase representa el tablero del juego, que consiste en una matriz de celdas.
// Proporciona métodos para colocar minas, mostrar el estado del tablero y descubrir celdas.
class Tablero {
private:
    vector<vector<Celda>> celdas; // Matriz de celdas que componen el tablero
    int filas;                     // Número de filas del tablero
    int columnas;                  // Número de columnas del tablero

public:
    // Constructor de la clase Tablero
    // Inicializa un tablero con el número de filas y columnas especificadas.
    // Parámetros:
    // - f: número de filas del tablero
    // - c: número de columnas del tablero
    Tablero(int f, int c);

    // Método para colocar minas en el tablero
    // Coloca un número específico de minas en posiciones aleatorias del tablero.
    // Parámetro:
    // - minas: número de minas a colocar en el tablero
    void colocarMinas(int minas);

    // Método para mostrar el estado del tablero
    // Muestra el tablero en la consola, revelando celdas según el modo de juego.
    // Parámetro:
    // - administrador: booleano que indica si se debe mostrar el tablero completo (true) o solo las celdas descubiertas (false)
    void mostrar(bool administrador);

    // Método para descubrir una celda en el tablero
    // Intenta descubrir la celda en la posición especificada.
    // Parámetros:
    // - fila: número de fila de la celda a descubrir (1-indexado)
    // - col: número de columna de la celda a descubrir (1-indexado)
    // Retorna:
    // - true si se descubre una mina, false si la celda no tiene mina
    bool descubrir(int fila, int col);
};

#endif // TABLERO_H

