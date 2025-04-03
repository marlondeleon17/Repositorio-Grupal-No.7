#include "Juego.h"
#include <iostream>
#include <chrono>

using namespace std;

// Constructor de la clase Juego
// Inicializa el juego con la configuración proporcionada y crea un tablero
// basado en el número de filas y columnas especificadas en la configuración.
// Parámetro:
// - cfg: referencia a un objeto de tipo Configuracion que contiene los parámetros del juego.
Juego::Juego(Configuracion& cfg) : config(cfg), tablero(cfg.filas, cfg.columnas) {}

// Método para iniciar el juego
// Coloca las minas en el tablero y registra el tiempo de inicio del juego.
// Luego, llama al método jugar() para comenzar la partida.
void Juego::iniciar() {
    this->tablero.colocarMinas(this->config.minas); // Coloca las minas en el tablero
    this->inicio = chrono::steady_clock::now();    // Registra el tiempo de inicio
    this->jugar();                                  // Inicia el bucle de juego
}

// Método para gestionar la lógica del juego
// Permite al jugador descubrir celdas en el tablero hasta que se agoten las vidas.
// Muestra el estado del tablero y las vidas restantes, y maneja la lógica de perder o ganar.
void Juego::jugar() {
    int fila, columna;         // Variables para almacenar la fila y columna ingresadas por el jugador
    bool perdio = false;       // Bandera para indicar si el jugador ha perdido

    // Bucle principal del juego que se ejecuta mientras el jugador tenga vidas
    while (this->config.vidas > 0) {
        this->tablero.mostrar(this->config.modo == 0); // Muestra el tablero, mostrando minas si es modo administrador
        cout << "\nVidas restantes: " << this->config.vidas << "\nFila y columna: ";
        cin >> fila >> columna; // Solicita al jugador que ingrese la fila y columna

        // Intenta descubrir la celda en la posición especificada
        if (this->tablero.descubrir(fila, columna)) {
            cout << "\n¡Mina! Pierdes una vida.\n"; // Mensaje si se descubre una mina
            this->config.vidas--; // Decrementa el contador de vidas
        }

        // Verifica si el jugador ha perdido todas sus vidas
        if (this->config.vidas == 0) {
            cout << "¡Perdiste! Has agotado tus vidas.\n";
            this->config.aumentarDerrota(); // Incrementa el contador de derrotas
            perdio = true; // Marca que el jugador ha perdido
            break; // Sale del bucle
        }
    }

    // Si el jugador no ha perdido, se considera que ha ganado
    if (!perdio) {
        cout << "¡Felicidades, has ganado!\n";
        this->config.aumentarVictoria(); // Incrementa el contador de victorias
    }

    // Muestra el número de victorias y derrotas
    cout << "Victorias: " << this->config.victorias << " | Derrotas: " << this->config.derrotas << endl;

    // Mostrar tiempo jugado
    auto fin = chrono::steady_clock::now(); // Registra el tiempo al finalizar el juego
    auto duracion = chrono::duration_cast<chrono::seconds>(fin - this->inicio); // Calcula la duración del juego
    cout << "Tiempo jugado: " << duracion.count() << " segundos.\n"; // Muestra el tiempo jugado
}

