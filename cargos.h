#ifndef CARGOS_H
#define CARGOS_H

#include "definiciones.h"

typedef struct nodo_cargos * Cargos;

TipoRet CrearCargos(Cargos &c, Cadena nombreCargo);
// Crea el primer cargo

TipoRet NuevoCargos(Cargos &c, Cadena nombrePadre, Cadena nombreCargo);
// Crea un cargo nuevo

TipoRet ListarCargosAlfCargos(Cargos c);
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 

TipoRet AsignarPersonaCargos(Cargos &c, Cadena cargo, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

TipoRet ListarPersonasCargos(Cargos c, Cadena cargo);
// Lista todas las personas asignadas al cargo de nombre cargo.

TipoRet EliminarCargos(Cargos &c);
// Eliminar un cargo

TipoRet EliminarCargoCargos(Cargos &c, Cadena cargo);
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.

TipoRet ListarJerarquiaCargos(Cargos c);

#endif