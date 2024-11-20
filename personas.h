#ifndef PERSONAS_H
#define PERSONAS_H

#include "definiciones.h"

typedef struct nodo_personas * Personas;

TipoRet EliminarPersonas(Personas &p);
// Eliminar personas

TipoRet BuscarPersonaPersonas(Personas p, Cadena ci);

TipoRet AsignarPersonaPersonas(Personas &p, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

void ListarPersonasPersonas(Personas p);

#endif