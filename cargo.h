#ifndef CARGO_H
#define CARGO_H

#include "definiciones.h"
#include "personas.h"

typedef struct nodo_cargo * Cargo;

TipoRet CrearCargo(Cargo &c, Cadena nombre);

TipoRet EliminarCargo(Cargo &c);

Cadena NombreCargo(Cargo cargo);

TipoRet AsignarPersonaCargo(Cargo &c, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

TipoRet ListarPersonasCargo(Cargo c);
// Lista todas las personas asignadas al cargo de nombre cargo.

#endif