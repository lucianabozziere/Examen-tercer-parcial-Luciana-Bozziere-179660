//obtiene la suma de las veces que aparece cada palabra, inicia en el email 660(fila 661) ya que mi id es 179660
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxcolumnas 3002
#define filas 50
#define longitudmax 60000
#define inicial 660
#define final 709

int main()
{
    FILE *file_csv = fopen("emails.csv", "r");
    if (!file_csv)
    {
        perror("Error al abrir file CSV");
        return 1;
    }

    char buffer[longitudmax];
    char *palabras[maxcolumnas];
    int conteo[maxcolumnas] = {0};

    if (fgets(buffer, sizeof(buffer), file_csv))
     {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < maxcolumnas)
        {
            palabras[columna] = strdup(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    for (int actual = 1; actual < inicial && fgets(buffer, sizeof(buffer), file_csv); ++actual)
    {
    }
    
    for (int actual = inicial; actual <= final && fgets(buffer, sizeof(buffer), file_csv); ++actual)
    {
        char *token = strtok(buffer, ",");
        int columna = 0;

        while (token && columna < maxcolumnas)
        {
            conteo[columna] += atoi(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(file_csv);

    FILE *file_s = fopen("179660.txt", "w");
    if (!file_s)
    {
        perror("Error al abrir file de salida");
        for (int i = 0; i < maxcolumnas; i++)
        {
            free(palabras[i]);
        }
         return 1;
    }

    for (int i = 0; i < maxcolumnas && palabras[i] != NULL; i++)
    {
        fprintf(file_s, "%s, %d\n", palabras[i], conteo[i]);
        free(palabras[i]);
    }

     fclose(file_s);
     printf("resultados en 179660.txt\n");

     return 0;
}

