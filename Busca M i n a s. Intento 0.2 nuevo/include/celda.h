#ifndef CELDA_H
#define CELDA_H

// Clase Celda
// Esta clase representa una celda en el tablero del juego.
// Cada celda puede contener una mina y puede ser descubierta o no.
class Celda {
public:
    // Atributos públicos de la clase
    bool mina;         // Indica si la celda contiene una mina (true) o no (false)
    bool descubierta;  // Indica si la celda ha sido descubierta (true) o no (false)

    // Constructor de la clase Celda
    // Inicializa una nueva celda con los siguientes valores:
    // - mina: false (indica que la celda no contiene una mina)
    // - descubierta: false (indica que la celda no ha sido descubierta)
    Celda();
};

#endif // CELDA_H
