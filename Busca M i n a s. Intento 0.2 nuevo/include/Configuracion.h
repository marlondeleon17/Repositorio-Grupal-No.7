#ifndef CONFIGURACION_H
#define CONFIGURACION_H

// Clase Configuracion
// Esta clase se encarga de almacenar y gestionar la configuración del juego,
// incluyendo el estado del jugador y las características del tablero.
class Configuracion {
public:
    // Atributos públicos de la clase
    int filas;      // Número de filas del tablero
    int columnas;   // Número de columnas del tablero
    int minas;      // Número de minas en el tablero
    int vidas;      // Número de vidas del jugador
    int modo;       // Modo de juego (puede indicar diferentes configuraciones de juego)
    int derrotas;   // Contador de derrotas del jugador
    int victorias;  // Contador de victorias del jugador

    // Constructor de la clase Configuracion
    // Inicializa los atributos de la configuración del juego.
    // Parámetros:
    // - f: número de filas del tablero
    // - c: número de columnas del tablero
    // - m: número de minas en el tablero
    // - v: número de vidas del jugador
    // - modo: modo de juego
    Configuracion(int f, int c, int m, int v, int modo);

    // Método para incrementar el contador de victorias en 1
    void aumentarVictoria();

    // Método para incrementar el contador de derrotas en 1
    void aumentarDerrota();
};

#endif // CONFIGURACION_H
