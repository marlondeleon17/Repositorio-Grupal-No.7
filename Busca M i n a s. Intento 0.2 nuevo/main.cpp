#include "Juego.h"
#include <iostream>

using namespace std;

// Función para mostrar el menú principal
// Presenta las opciones disponibles al usuario para modificar la configuración, jugar o salir.
void mostrarMenu() {
    cout << "\n--- MENU ----------------\n";
    cout << "1. Modificar configuración\n";
    cout << "2. Jugar directamente\n";
    cout << "3. Salir\n";
    cout << "Elija una opcion: ";
}

// Función para mostrar el menú de configuración
// Permite al usuario ingresar los parámetros del juego, como filas, columnas, minas, vidas y modo de juego.
void mostrarConfiguracionMenu() {
    cout << "\n----------- CONFIGURACION -------------\n";
    cout << "Ingrese el numero de filas (maximo 40): ";
    int filas;
    cin >> filas; // Solicita al usuario el número de filas
    if (filas > 40) filas = 40; // Limita el número de filas a 40

    cout << "Ingrese el numero de columnas (maximo 40): ";
    int columnas;
    cin >> columnas; // Solicita al usuario el número de columnas
    if (columnas > 40) columnas = 40; // Limita el número de columnas a 40

    cout << "Ingrese el numero de minas: ";
    int minas;
    cin >> minas; // Solicita al usuario el número de minas

    cout << "Ingrese el numero de vidas: ";
    int vidas;
    cin >> vidas; // Solicita al usuario el número de vidas

    int modo;
    cout << "Modo de juego (1: Jugador, 0: Administrador): ";
    cin >> modo; // Solicita al usuario el modo de juego

    // Configuración con los nuevos valores
    Configuracion config(filas, columnas, minas, vidas, modo); // Crea un objeto de configuración con los valores ingresados
    Juego juego(config); // Crea un objeto de juego con la configuración
    juego.iniciar(); // Inicia el juego
}

// Función principal del programa
int main() {
    string jugador; // Variable para almacenar el nombre del jugador
    cout << "Ingrese su nombre: ";
    cin >> jugador; // Solicita al usuario su nombre

    int opcion = 0; // Variable para almacenar la opción seleccionada por el usuario
    Configuracion config(6, 6, 5, 3, 1); // Configuración predeterminada del juego

    // Bucle principal que muestra el menú y gestiona las opciones seleccionadas
    do {
        mostrarMenu(); // Muestra el menú principal
        cin >> opcion; // Lee la opción seleccionada por el usuario

        switch (opcion) {
        case 1: {
            mostrarConfiguracionMenu(); // Muestra el menú de configuración
            break;
        }
        case 2: {
            Juego juego(config); // Crea un objeto de juego con la configuración actual
            juego.iniciar(); // Inicia el juego
            break;
        }
        case 3:
            cout << "Gracias por jugar, ¡hasta la proxima!\n"; // Mensaje de despedida
            break;
        default:
            cout << "Opción no válida, por favor elija una opcion entre 1 y 3.\n"; // Mensaje de error para opciones no válidas
            break;
        }
    } while (opcion != 3); // Continúa mostrando el menú hasta que el usuario elija salir

    return 0; // Finaliza el programa
}
