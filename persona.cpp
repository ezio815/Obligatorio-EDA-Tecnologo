#include "persona.h"

typedef struct nodo_persona {
    Cadena ci;
    Cadena nombre;
};

Persona CrearPersona(Cadena ci, Cadena nombre) {
    Persona persona = new(nodo_persona);
    strcpy(persona->ci, ci);
    strcpy(persona->nombre, nombre);
    return persona;
}

bool personaVacia(Persona p) {
    return p == NULL;
}

TipoRet EliminarPersona(Persona &p) {
    if (personaVacia(p))
        return ERROR;
    delete(p);
    p = NULL;
    return OK;
}