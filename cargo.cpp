#include "cargo.h"

struct nodo_cargo {
    Cadena nombre;
    Personas personas;
};

TipoRet CrearCargo(Cargo &c, Cadena nombre) {
    c = new(nodo_cargo);
    strcpy(c->nombre, nombre);
    c->personas = NULL;
    return OK;
}

TipoRet EliminarCargo(Cargo &c) {
    if (EliminarPersonas(c->personas) == ERROR)
        return ERROR;
    delete(c);
    c = NULL;
    return OK;
}

Cadena NombreCargo(Cargo cargo) {
    return cargo->nombre;
}

bool cargoVacio(Cargo c) {
    return c == NULL;
}

TipoRet AñadirPersonaCargo(Cargo c, Cadena ci, Cadena nombre) {
    if (cargoVacio(c))
        return ERROR;
    return CrearPersonas(c->personas, ci, nombre);
}

TipoRet AsignarPersonaCargo(Cargo &c, Cadena nom, Cadena ci) {
    if (cargoVacio(c))
        return ERROR;
    return AsignarPersonaPersonas(c->personas, nom, ci);
}

TipoRet ListarPersonasCargo(Cargo c) {
    if (cargoVacio(c))
        return ERROR;
    ListarPersonasPersonas(c->personas);
}