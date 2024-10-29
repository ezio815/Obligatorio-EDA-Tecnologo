#ifndef CARGOS_H
#define CARGOS_H

#include "definiciones.h"
#include "cargo.h"

typedef struct nodo_cargos * Cargos;

TipoRet CrearCargos(Cargos &c, Cadena nombrePadre, Cadena nombreCargo);
// Crea un cargo

TipoRet EliminarCargos(Cargos &c);
// Eliminar un cargo

#endif