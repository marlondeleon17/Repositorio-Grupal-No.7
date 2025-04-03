#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Configuracion.h"
#include <chrono>

// Clase Juego
// Esta clase gestiona la lógica del juego, incluyendo la interacción con el tablero
// y la configuración del juego. Permite iniciar el juego y manejar el flujo de la partida.
class Juego {
private:
    Tablero tablero;                          // Objeto que representa el tablero del juego
    Configuracion& config;                    // Referencia a la configuración del juego
    std::chrono::steady_clock::time_point inicio; // Marca de tiempo para registrar el inicio del juego

public:
    // Constructor de la clase Juego
    // Inicializa el juego con la configuración proporcionada.
    // Parámetro:
    // - cfg: referencia a un objeto de tipo Configuracion que contiene los parámetros del juego.
    Juego(Configuracion& cfg);

    // Método para iniciar el juego
    // Coloca las minas en el tablero y comienza la partida.
    void iniciar();

    // Método para gestionar la lógica del juego
    // Permite al jugador descubrir celdas en el tablero y maneja la lógica de ganar o perder.
    void jugar();
};

#endif // JUEGO_H
