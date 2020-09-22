#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    off=0,
    on=1
} estados;

typedef struct {
    int i;
    int i_set;
    int delta_i;
} intensidad;

//funciones de lectura de archivo de configuracion

char *getkey(char *);
intensidad f_config(char *);

//funciones de maquina de estado

intensidad f_setting (void);//carga los datos seteados en el archivo de configuracion
estados f_on (intensidad);//enciende las luces y regula la intensidad con un dimmer
estados f_off(intensidad);//mantiene las luces apagadas

//funciones de simulacion de funcionamiento

char read_i(void);//simula la informacion del sensor de luz
void working(intensidad,estados);//nos muestra que es lo que esta ejecutando la maquina

#include "../funciones/funciones_secundarias.cpp"
#include "../funciones/funciones_de_estado.cpp"


#endif
