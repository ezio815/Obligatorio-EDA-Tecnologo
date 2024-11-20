#include "persona.h"

typedef struct nodo_persona {
    Cadena ci;
    Cadena nombre;
};

Persona CrearPersona(Cadena ci, Cadena nombre) {
    Persona persona = new(nodo_persona);
    persona->ci = ci;
    persona->nombre = nombre;
    return persona;
}

void EliminarPersona(Persona persona) {
    
}