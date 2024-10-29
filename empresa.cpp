#include "empresa.h"

using namespace std;

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
    return CrearCargo(e->raiz, cargoPadre, nuevoCargo);
}

void listarJerarquiaRecursiva(Cargos cargo, int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("%s\n", cargo->nombre);
    for (int i = 0; i < cargo->numSubCargos; i++) {
        listarJerarquiaRecursiva(cargo->subCargos[i], nivel + 1);
    }
}

TipoRet ListarCargosAlf(Empresa e) {

}


TipoRet ListarJerarquia(Empresa e) {
    if (e.raiz == NULL) {
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
