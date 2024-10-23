#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* Cadena;

typedef enum {
    OK,
    ERROR,
    NO_IMPLEMENTADA
} TipoRet;

// Estructura para representar a una persona
typedef struct {
    Cadena ci;     
    Cadena nombre; 
} Persona;

#endif
