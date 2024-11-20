#ifndef PERSONA_H
#define PERSONA_H

#include "definiciones.h"

// Estructura para representar a una persona
typedef struct nodo_persona * Persona;

Cadena NombrePersona(Persona p);

Cadena CiPersona(Persona p);

Persona CrearPersona(Cadena ci, Cadena nombre);

TipoRet EliminarPersona(Persona p);

#endif