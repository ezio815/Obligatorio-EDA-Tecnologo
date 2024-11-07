#include "empresa.h"

struct nodo_empresa {
    Cadena nombre;
    Cargos raiz; 
};

TipoRet CrearOrg(Empresa &e, Cadena cargo) {
    if (e != NULL) {
        return ERROR; 
    }
    e = new(nodo_empresa);
    Cargos c = NULL;
    TipoRet retorno = CrearCargos(c, NULL, cargo);
    e->raiz = c;
    return retorno;
}

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo) {
    if (e->raiz == NULL) {
        return ERROR; 
    }
    return CrearCargos(e->raiz, cargoPadre, nuevoCargo);
}



TipoRet ListarCargosAlf(Empresa e) {

}


TipoRet ListarJerarquia(Empresa e) {
    if (e->raiz == NULL) {
        return ERROR; 
    }
    listarJerarquiaRecursiva(e.raiz, 0);
    return OK;
}


void eliminarCargosRecursivo(Cargos cargo) {
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
