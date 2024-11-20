#include "empresa.h"

struct nodo_empresa {
    Cargos cabezal;
};

bool empresaVacia(Empresa e) {
    return e == NULL;
}

TipoRet CrearOrg(Empresa &e, Cadena cargo) {
    if (!empresaVacia(e)) {
        return ERROR; 
    }
    e = new(nodo_empresa);
    Cargos c = NULL;
    TipoRet retorno = CrearCargos(c, cargo);
    e->cabezal = c;
    return retorno;
}

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo) {
    if (e->cabezal == NULL) {
        return ERROR; 
    }
    return NuevoCargos(e->cabezal, cargoPadre, nuevoCargo);
}

TipoRet ListarCargosAlf(Empresa e) {
    if (empresaVacia(e))
        return ERROR;
    return ListarCargosAlfCargos(e->cabezal);
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci) {
    if (empresaVacia(e))
        return ERROR;
    return AsignarPersonaCargos(e->cabezal, cargo, nom, ci);
}

TipoRet ListarPersonas(Empresa e, Cadena cargo) {
    if (empresaVacia(e))
        return ERROR;
    return ListarPersonasCargos(e->cabezal, cargo);
}

TipoRet EliminarOrg(Empresa &e) {
    if (empresaVacia(e))
        return ERROR;
    if (EliminarCargos(e->cabezal) == ERROR)
        return ERROR;
    delete(e);
    e = NULL;
    return OK;
}

TipoRet EliminarCargo(Empresa &e, Cadena cargo) {
    if (empresaVacia(e))
        return ERROR;
    return EliminarCargoCargos(e->cabezal, cargo);
}

TipoRet ListarJerarquia(Empresa e) {
    if (e->cabezal == NULL) {
        return ERROR; 
    }
    return ListarJerarquiaCargos(e->cabezal);
}

