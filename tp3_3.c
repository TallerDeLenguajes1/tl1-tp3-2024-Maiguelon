#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMA 5

void main() {
    char *vector[TAMA];
    char *nombre;
    char *apellido;
    char *buff = (char *)malloc(sizeof(char)*120);

    for (int i = 0; i < TAMA; i++)
    {
        printf("Ingrese el nombre: ");
        gets(buff);
        
        nombre = (char *)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(nombre, buff);

        printf("\nIngrese el apellido: ");
        gets(buff);
        
        apellido = (char *)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(apellido, buff);

        vector[i] = (char *)malloc(sizeof(char)*(strlen(nombre)+strlen(apellido)+3));
        strcpy(vector[i], apellido);
        strcat(vector[i], ", ");
        strcat(vector[i], nombre);

        free(nombre);
        free(apellido);
    }
    free(buff);
    for (int i = 0; i < TAMA; i++)
    {
        printf("Persona %d: %s", i+1, vector[i]);
        free(vector[i]);
    }
    
}