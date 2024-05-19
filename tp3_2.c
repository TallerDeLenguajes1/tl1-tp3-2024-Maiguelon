#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int matriz[5][12];

void cargarMatriz(int matriz[5][12]);
void mostrarMatriz(int matriz[5][12]);
float promedioUltimo(int matriz[5][12]);
void maximoMinimo(int matriz[5][12]);


int main() {

    // Set time
    srand(time(NULL));

    // Cargo y muestro la matriz
    cargarMatriz(matriz);
    printf("\nMatriz de simulacion:\n\n");
    mostrarMatriz(matriz);

    // Cargo e imprimo el promedio
    float promedioUltimoAnio = promedioUltimo(matriz);
    printf("Promedio del ultimo anio: %.2f\n\n", promedioUltimoAnio);

    // Definir y mostrar maximo y minimo
    maximoMinimo(matriz);
}

void cargarMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = rand() %40000 + 10001;
        }   
    }
}

void mostrarMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%6d", matriz[i][j]);
        }   
        printf("\n");
    }
    printf("\n");
}

float promedioUltimo(int matriz[5][12])
{
    int promedio = 0;
    float promedioFinal;

    for (int i = 0; i < 12; i++) {
        promedio = promedio + matriz[4][i];
    }

    promedioFinal = promedio / 12.0;
    return promedioFinal;
}

void maximoMinimo(int matriz[5][12])
{
    int max = 9999;
    int min = 60000;
    int mesM;
    int anioM;
    int aniom;
    int mesm;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
                mesm = j;
                aniom = i;
            } 
            
             if (matriz[i][j] > max)
            {
                max = matriz[i][j];
                mesM = j;
                anioM = i;
            }   
        }
    }

    printf("El valor mas alto fue: %d\n", max);
    printf("Ocurrio en el anio %d, mes %d\n\n",anioM + 1, mesM + 1);

    printf("El valor mas bajo fue: %d\n", min);
    printf("Ocurrio en el anio %d, mes %d\n\n",aniom + 1, mesm + 1);
}
