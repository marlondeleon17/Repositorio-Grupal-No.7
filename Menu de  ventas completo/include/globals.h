#ifndef GLOBALS_H
#define GLOBALS_H
#include <string>
#include "globals.h"

class globals
{
    public:
        globals();
        virtual ~globals();
        // Declaraci�n global del usuario actual
        // Definici�n real de la variable global
        std::string usuarioActual = "INVITADO"; // Puedes cambiar esto luego desde el login
    protected:

    private:
};

#endif // GLOBALS_H
