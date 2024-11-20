#include "cargos.h"
#include "cargo.h"
#include <iostream>
#include <strings.h>
#include <stdbool.h>

typedef struct nodo_arbol_cargos * ArbolCargos;
struct nodo_arbol_cargos {
    ArbolCargos primerHijo;
    ArbolCargos siguienteHermano;
    Cargo cargo;
};

typedef struct nodo_lista_cargos * ListaCargos;
struct nodo_lista_cargos {
    ListaCargos siguiente;
    Cargo cargo;
};

struct nodo_cargos {
    ArbolCargos arbol;
    ListaCargos lista;
};

bool arbolVacio(ArbolCargos arbol) {
    return arbol == NULL;
}

bool listaVacia(ListaCargos lista) {
    return lista == NULL;
}

bool cargosVacio(Cargos cargos) {
    return cargos == NULL;
}

ListaCargos buscarCargoLista(ListaCargos lista, Cadena nombreCargo) {
    if (listaVacia(lista))
        return NULL;
    int comparacion = strcasecmp(NombreCargo(lista->cargo), nombreCargo);

    if (comparacion == 0)
        return lista;
    if (comparacion < 0) {
        return buscarCargoLista(lista->siguiente, nombreCargo);
    }
    return NULL;
}

ArbolCargos buscarCargoArbol(ArbolCargos arbol, Cadena nombreCargo) {
    if (arbolVacio(arbol))
        return NULL;

    if (strcasecmp(NombreCargo(arbol->cargo), nombreCargo) == 0)
        return arbol;
    if (arbol->primerHijo != NULL) {
        ArbolCargos aux = (buscarCargoArbol(arbol->primerHijo, nombreCargo));
        if (aux != NULL)
            return aux;
    }
    if (arbol->siguienteHermano != NULL) {
        ArbolCargos aux =  (buscarCargoArbol(arbol->siguienteHermano, nombreCargo));
        if (aux != NULL)
            return aux;
    }
    return NULL;
}

void insertarEnLista(ListaCargos nuevaLista, ListaCargos &listaOriginal) {
    if (listaVacia(listaOriginal))
        listaOriginal = nuevaLista;
    int comparacion = strcasecmp(NombreCargo(nuevaLista->cargo), NombreCargo(listaOriginal->cargo));

    if (comparacion < 0) {
        Cargo aux = nuevaLista->cargo;
        nuevaLista->cargo = listaOriginal->cargo;
        nuevaLista->siguiente = listaOriginal->siguiente;
        listaOriginal->cargo = aux;
        listaOriginal->siguiente = nuevaLista;
    }
    if (comparacion > 0) {
        insertarEnLista(nuevaLista, listaOriginal->siguiente);
    }
}

TipoRet CrearCargos(Cargos &c, Cadena nombreCargo) {
    if (!cargosVacio(c))
        return ERROR;

    c = new(nodo_cargos);
    c->arbol = NULL;
    c->lista = NULL;

    ArbolCargos nuevoArbol = new(nodo_arbol_cargos);

    nuevoArbol->primerHijo = NULL;
    nuevoArbol->siguienteHermano = NULL;

    Cargo cargo = NULL;
    TipoRet retorno = CrearCargo(cargo, nombreCargo);
    nuevoArbol->cargo = cargo;

    ListaCargos nuevaLista = new(nodo_lista_cargos);
    nuevaLista->cargo = cargo;
    nuevaLista->siguiente = NULL;

    c->lista = nuevaLista;

    return retorno;
}

TipoRet NuevoCargos(Cargos &c, Cadena nombrePadre, Cadena nombreCargo) {
    if (cargosVacio(c)) 
        return ERROR;

    if (buscarCargoLista(c->lista, nombreCargo) != NULL) {
        return ERROR; 
    }

    ArbolCargos padre = buscarCargoArbol(c->arbol, nombrePadre);

    if (arbolVacio(padre))
        return ERROR;

    ArbolCargos nuevoArbol = new(nodo_arbol_cargos);

    nuevoArbol->primerHijo = NULL;

    nuevoArbol->siguienteHermano = padre->primerHijo;
    padre->primerHijo = nuevoArbol;

    Cargo cargo = NULL;
    TipoRet retorno = CrearCargo(cargo, nombreCargo);
    nuevoArbol->cargo = cargo;

    ListaCargos nuevaLista = new(nodo_lista_cargos);
    nuevaLista->cargo = cargo;
    nuevaLista->siguiente = NULL;

    insertarEnLista(nuevaLista, c->lista);

    return retorno;
}

void listarCargosAlfRecursiva(ListaCargos lista) {
    if (!listaVacia(lista)) {

        printf("%s\n", NombreCargo(lista->cargo));
        listarCargosAlfRecursiva(lista->siguiente);
    }
}

TipoRet ListarCargosAlfCargos(Cargos c) {
    if (cargosVacio(c) || listaVacia(c->lista))
        return ERROR;
    listarCargosAlfRecursiva(c->lista);
    return OK;
}

TipoRet buscarPersonaCargos(ListaCargos l, Cadena ci) {
    if (listaVacia(l))
        return OK;
    if (BuscarPersonaCargo(l->cargo, ci) == ERROR)
        return ERROR;
    return buscarPersonaCargos(l->siguiente, ci);
}

TipoRet AsignarPersonaCargos(Cargos &c, Cadena cargo, Cadena nom, Cadena ci) {
    if (cargosVacio(c) || listaVacia(c->lista))
        return ERROR;
    if (buscarPersonaCargos(c->lista, ci) == ERROR)
        return ERROR;
    ListaCargos lista = buscarCargoLista(c->lista, cargo);
    return AsignarPersonaCargo(lista->cargo, nom, ci);
}

TipoRet ListarPersonasCargos(Cargos c, Cadena cargo) {
    if (cargosVacio(c))
        return ERROR;
    ListaCargos lista = buscarCargoLista(c->lista, cargo);
    if (listaVacia(lista))
        return ERROR;
    return ListarPersonasCargo(lista->cargo);
}

TipoRet eliminarLista(ListaCargos &l) {
    if (!listaVacia(l)) {
        eliminarLista(l->siguiente);
        delete(l);
        l = NULL;
    }
    return OK;
}

TipoRet eliminarArbol(ArbolCargos &a) {
    if (!arbolVacio(a)) {
        eliminarArbol(a->siguienteHermano);
        eliminarArbol(a->primerHijo);
        if (EliminarCargoCargo(a->cargo) == ERROR)
            return ERROR;
        delete(a);
        a = NULL;
    }
    return OK;
}

TipoRet EliminarCargos(Cargos &c) {
    if (cargosVacio(c) || eliminarLista(c->lista) == ERROR)
        return ERROR;
    eliminarArbol(c->arbol);
    c = NULL;
    return OK;
}


TipoRet eliminarNodoArbol(ArbolCargos &a) {
    if (EliminarCargoCargo(a->cargo) == ERROR)
        return ERROR;
    if (eliminarArbol(a->primerHijo) == ERROR)
        return ERROR;
    ArbolCargos aux = a->siguienteHermano;
    if (!arbolVacio(aux)) {
        a->primerHijo = aux->primerHijo;
        a->siguienteHermano = aux->siguienteHermano;
        a->cargo;
        delete(aux);
    }
    else {
        delete(a);
        a = NULL;
    }
    return OK;
}

void eliminarNodosVaciosLista(ListaCargos &l) {
    if (!listaVacia(l)) {
        if (CargoVacio(l->cargo)) {
            ListaCargos aux = l->siguiente;
            l->cargo = aux->cargo;
            l->siguiente = aux->siguiente;
            delete(aux);
        }
    }
}

TipoRet EliminarCargoCargos(Cargos &c, Cadena cargo) {
    if (cargosVacio(c))
        return ERROR;
    if (listaVacia(buscarCargoLista(c->lista, cargo)))
        return ERROR;
    ArbolCargos arbol = buscarCargoArbol(c->arbol, cargo);
    if (eliminarNodoArbol(arbol) == ERROR)
        return ERROR;
    eliminarNodosVaciosLista(c->lista);
    return OK;
}

void listarJerarquiaRecursiva(ArbolCargos arbol, int nivel) {
    if (!arbolVacio(arbol)) {
        for (int i = 0; i < nivel; i++)
            printf("\t");
        printf("%s\n", NombreCargo(arbol->cargo));
        listarJerarquiaRecursiva(arbol->primerHijo, nivel + 1);
        listarJerarquiaRecursiva(arbol->siguienteHermano, nivel);
    }
}

TipoRet ListarJerarquiaCargos(Cargos c) {
    if (cargosVacio(c) || arbolVacio(c->arbol))
        return ERROR; 
    listarJerarquiaRecursiva(c->arbol, 0);
    return OK;
}