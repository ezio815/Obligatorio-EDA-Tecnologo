#ifndef PERSONA_H
#define PERSONA_H

#include "definiciones.h"

// Estructura para representar a una persona
typedef struct nodo_persona * Persona;

NombrePersona();

Persona CrearPersona(Cadena ci, Cadena nombre);

void EliminarPersona(Persona persona);

#endif