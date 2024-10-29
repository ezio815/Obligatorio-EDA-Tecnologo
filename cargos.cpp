#include "cargos.h"

struct nodo_cargos {
    ArbolCargos arbol;
    ListaCargos lista;
};

struct nodo_arbol_cargos {
    Cargos padre;            
    Cargos primerHijo;        
    Cargos siguienteHermano;
    Cargo cargo;
};
typedef struct nodo_arbol_cargos * ArbolCargos;

struct nodo_lista_cargos {
    ListaCargos siguiente;
    Cargo cargo;
};
typedef struct nodo_lista_cargos * ListaCargos;

TipoRet CrearCargos(Cargos &c, Cadena nombrePadre, Cadena nombreCargo) {
    if (!cargoVacio(c)) {
        if (buscarCargo(c, nombreCargo) != NULL) {
            return ERROR; 
        }
    }

    Cargos padre = buscarCargo(c, nombrePadre);

    Cargos nuevoCargo = new(nodo_cargos);
    nuevoCargo->padre = padre;
    nuevoCargo->primerHijo = NULL;

    if (!cargoVacio(padre)) {
        nuevoCargo->siguienteHermano = padre->primerHijo;
        padre->primerHijo = nuevoCargo;
    }
    else
        nuevoCargo->siguienteHermano = NULL;

    Cargo cargo = NULL;
    TipoRet retorno = CrearCargo(cargo, nombreCargo);
    nuevoCargo->cargo = cargo;

    return retorno;
}

bool cargoVacio(Cargos cargo) {
    return cargo == NULL;
}

Cargos buscarCargoLista() {
    
}

Cargos buscarCargoArbol(Cargos cargos, Cadena nombreCargo) {
    if (cargos == NULL)
        return NULL;
    
    if (strcasecmp(NombreCargo(cargos->cargo), nombreCargo) == 0)
        return cargos;
    if (cargos->primerHijo != NULL) {
        Cargos aux = (buscarCargo(cargos->primerHijo, nombreCargo));
        if (aux != NULL)
            return aux;
    }
    if (cargos->siguienteHermano != NULL) {
        Cargos aux =  (buscarCargo(cargos->siguienteHermano, nombreCargo));
        if (aux != NULL)
            return aux;
    }
    return NULL;
}

TipoRet EliminarCargos(Cargos &c);
// Eliminar un cargo