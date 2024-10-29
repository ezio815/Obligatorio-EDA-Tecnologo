#ifndef PERSONAS_H
#define PERSONAS_H

#include "definiciones.h"

typedef struct nodo_personas * Personas;
struct nodo_personas {
    Personas sig;
    Persona persona;               
};

TipoRet CrearPersonas(Personas &c);
// Crea un cargo

TipoRet EliminarPersonas(Personas &c);
// Eliminar un cargo

#endif