#include "cargo.h"
#include "personas.h"
#include <iostream>
#include <stdbool.h>
#include <string.h>

struct nodo_cargo {
    Cadena nombre;
    Personas personas;
};

TipoRet CrearCargo(Cargo &c, Cadena nombre) {
    c = new(nodo_cargo);
    c->nombre = new(char);
    strcpy(c->nombre, nombre);
    c->personas = NULL;
    return OK;
}

TipoRet EliminarCargoCargo(Cargo &c) {
    if (EliminarPersonas(c->personas) == ERROR)
        return ERROR;
    delete [] c->nombre;
    delete(c);
    c = NULL;
    return OK;
}

Cadena NombreCargo(Cargo cargo) {
    return cargo->nombre;
}

bool CargoVacio(Cargo c) {
    return c == NULL;
}

TipoRet BuscarPersonaCargo(Cargo c, Cadena ci) {
    if (CargoVacio(c))
        return ERROR;
    return BuscarPersonaPersonas(c->personas, ci);
}

TipoRet AsignarPersonaCargo(Cargo &c, Cadena nom, Cadena ci) {
    if (CargoVacio(c))
        return ERROR;
    return AsignarPersonaPersonas(c->personas, nom, ci);
}

TipoRet ListarPersonasCargo(Cargo c) {
    if (CargoVacio(c))
        return ERROR;
    ListarPersonasPersonas(c->personas);
    return OK;
}