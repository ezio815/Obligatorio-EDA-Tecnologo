#include "personas.h"

#include <strings.h>

struct nodo_personas {
    Personas sig;
    Persona persona;               
};

bool listaVacia(ListaCargos lista) {
    return lista == NULL;
}

void insertarEnLista(Personas nuevaLista, Personas &listaOriginal) {
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

TipoRet CrearPersonas(Personas &c, Cadena ci, Cadena nombre) {
    Personas nuevo = new(nodo_personas);
    nuevo->persona = CrearPersona(ci, nombre);
    
}

TipoRet EliminarPersonas(Personas &c);