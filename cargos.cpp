#include "cargos.h"
#include "cargo.h"
#include <strings.h>

typedef struct nodo_arbol_cargos * ArbolCargos;
struct nodo_arbol_cargos {
    ArbolCargos padre;            
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

bool cargoVacio(Cargos cargos) {
    return cargos == NULL;
}

ListaCargos buscarCargoLista(ListaCargos lista, Cadena nombreCargo) {
    if (!listaVacia(lista))
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
    if (!arbolVacio(arbol))
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

TipoRet CrearCargos(Cargos &c, Cadena nombrePadre, Cadena nombreCargo) {
    if (!cargoVacio(c)) {
        if (buscarCargoLista(c->lista, nombreCargo) != NULL) {
            return ERROR; 
        }
    }

    ArbolCargos padre = buscarCargoArbol(c->arbol, nombrePadre);

    ArbolCargos nuevoArbol = new(nodo_arbol_cargos);

    nuevoArbol->padre = padre;
    nuevoArbol->primerHijo = NULL;

    if (!arbolVacio(padre)) {
        nuevoArbol->siguienteHermano = padre->primerHijo;
        padre->primerHijo = nuevoArbol;
    }
    else
        nuevoArbol->siguienteHermano = NULL;

    Cargo cargo = NULL;
    TipoRet retorno = CrearCargo(cargo, nombreCargo);
    nuevoArbol->cargo = cargo;

    ListaCargos nuevaLista = new(nodo_lista_cargos);
    nuevaLista->cargo = cargo;
    nuevaLista->siguiente = NULL;

    insertarEnLista(nuevaLista, c->lista);

    return retorno;
}



TipoRet EliminarCargos(Cargos &c);
// Eliminar un cargo

void listarCargosAlfRecursiva(ListaCargos lista) {
    if (!listaVacia(lista)) {
        printf("s\n", NombreCargo(lista->cargo));
        listarCargosAlfRecursiva(lista->siguiente);
    }
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

TipoRet ListarCargosAlfCargos(Cargos c) {
    if (cargoVacio(c) || listaVacia(c->lista))
        return ERROR;
    listarCargosAlfRecursiva(c->lista);
    return OK;
}


TipoRet ListarJerarquiaCargos(Cargos c) {
    if (cargoVacio(c) || arbolVacio(c->arbol))
        return ERROR; 
    listarJerarquiaRecursiva(c->arbol, 0);
    return OK;
}