#include "cargos.h"

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
    delete(c);
    c = NULL;
    return OK;
}

Cadena NombreCargo(Cargo cargo) {
    return cargo->nombre;
}