#ifndef PERSONAS_H
#define PERSONAS_H

#include "definiciones.h"
#include "persona.h"

typedef struct nodo_personas * Personas;

TipoRet CrearPersonas(Personas &c, Cadena ci, Cadena nombre);
// Crea personas

TipoRet EliminarPersonas(Personas &p);
// Eliminar personas

TipoRet AsignarPersonaPersonas(Personas &p, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

void ListarPersonasPersonas(Personas p);

#endif