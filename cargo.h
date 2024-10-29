#ifndef CARGO_H
#define CARGO_H

#include "definiciones.h"
#include "personas.h"

typedef struct nodo_cargo * Cargo;

TipoRet CrearCargo(Cargo &c, Cadena nombre);

TipoRet EliminarCargo(Cargo &c);

Cadena NombreCargo(Cargo cargo);

#endif