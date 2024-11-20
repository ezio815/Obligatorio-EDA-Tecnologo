#ifndef PERSONAS_H
#define PERSONAS_H

#include "definiciones.h"
#include "persona.h"

typedef struct nodo_personas * Personas;

TipoRet CrearPersonas(Personas &c, Cadena ci, Cadena nombre);
// Crea personas

TipoRet EliminarPersonas(Personas &c);
// Eliminar personas

#endif