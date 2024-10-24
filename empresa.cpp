#include "empresa.h"

using namespace std;

TipoRet CrearOrg(Empresa &e, Cadena cargo) {
    if (e != NULL) {
        return ERROR; 
    }
    e = new(nodo_empresa);

    Cargo nuevoCargo = new(nodo_cargo);
    nuevoCargo->nombre = cargo;
    nuevoCargo->padre = NULL;
    nuevoCargo->primerHijo = NULL;
    nuevoCargo->siguienteHermano = NULL;
    nuevoCargo->personas = NULL;
    nuevoCargo->numPersonas = 0;

    e->raiz = nuevoCargo;
    return OK;
}

Cargo buscarCargo(Cargo cargo, Cadena nombreCargo) {
    if (cargo == NULL)
        return NULL;
    if (strcasecmp(cargo->nombre, nombreCargo) == 0)
        return cargo;
    if (cargo->primerHijo != NULL) {
        Cargo aux = (buscarCargo(cargo->primerHijo, nombreCargo));
        if (aux != NULL)
            return aux;
    }
    if (cargo->siguienteHermano != NULL) {
        Cargo aux =  (buscarCargo(cargo->siguienteHermano, nombreCargo));
        if (aux != NULL)
            return aux;
    }
    return NULL;
}

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo) {
    if (e->raiz == NULL) {
        return ERROR; 
    }

    if (buscarCargo(e->raiz, nuevoCargo) != NULL) {
        return ERROR; 
    }

    Cargo padre = buscarCargo(e->raiz, cargoPadre);
    if (padre == NULL) {
        return ERROR; 
    }

    Cargo nuevo = new(nodo_cargo);
    nuevo->nombre = nuevoCargo;
    nuevo->padre = padre;
    nuevo->primerHijo = NULL;
    nuevo->siguienteHermano = NULL;
    nuevo->personas = NULL;
    nuevo->numPersonas = 0;

    padre->primerHijo = nuevo;

    return OK;
}


void listarJerarquiaRecursiva(Cargo* cargo, int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("%s\n", cargo->nombre);
    for (int i = 0; i < cargo->numSubCargos; i++) {
        listarJerarquiaRecursiva(cargo->subCargos[i], nivel + 1);
    }
}


TipoRet ListarJerarquia(Empresa e) {
    if (e.raiz == NULL) {
        return ERROR; 
    }
    listarJerarquiaRecursiva(e.raiz, 0);
    return OK;
}


void eliminarCargosRecursivo(Cargo* cargo) {
    for (int i = 0; i < cargo->numSubCargos; i++) {
        eliminarCargosRecursivo(cargo->subCargos[i]);
    }
    free(cargo->subCargos);
    free(cargo->personas);
    free(cargo);
}

TipoRet EliminarOrg(Empresa *e) {
    if (e->raiz == NULL) {
        return ERROR; 
    }
    eliminarCargosRecursivo(e->raiz);
    e->raiz = NULL;
    return OK;
}
