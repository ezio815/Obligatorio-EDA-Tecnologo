#include "personas.h"
#include "persona.h"
#include <iostream>
#include <strings.h>
#include <stdbool.h>

struct nodo_personas {
    Personas siguiente;
    Persona persona;               
};

bool listaVacia(Personas lista) {
    return lista == NULL;
}

void insertarAlInicio(Personas nuevaLista, Personas &listaOriginal) {
    if (listaVacia(listaOriginal))
        listaOriginal = nuevaLista;
    else {
        Persona aux = nuevaLista->persona;
        nuevaLista->persona = listaOriginal->persona;
        nuevaLista->siguiente = listaOriginal->siguiente;
        listaOriginal->persona = aux;
        listaOriginal->siguiente = nuevaLista;
    }
}

bool personaVacia(Personas p) {
    return p == NULL;
}

TipoRet BuscarPersonaPersonas(Personas p, Cadena ci) {
    if (personaVacia(p))
        return OK;
    int comparacion = strcasecmp(CiPersona(p->persona), ci);
    if (comparacion == 0)
        return ERROR;
    return BuscarPersonaPersonas(p->siguiente, ci);
}

TipoRet AsignarPersonaPersonas(Personas &p, Cadena nom, Cadena ci) {
    Personas nuevaLista = new(nodo_personas);
    nuevaLista->persona = CrearPersona(ci, nom);
    insertarAlInicio(nuevaLista, p);
    return OK;
}


void ListarPersonasPersonas(Personas p) {
    if (!personaVacia(p)) {
        ListarPersonasPersonas(p->siguiente);
        printf("%s\n", NombrePersona(p->persona));
    }
}

TipoRet eliminarLista(Personas &p) {
    if (!listaVacia(p)) {
        eliminarLista(p->siguiente);
        if (EliminarPersona(p->persona) == ERROR)
            return ERROR;
        delete(p);
        p = NULL;
        return OK;
    }
}

TipoRet EliminarPersonas(Personas &p) {
    if (listaVacia(p) || eliminarLista(p) == ERROR)
        return ERROR;
    p = NULL;
    return OK;
}