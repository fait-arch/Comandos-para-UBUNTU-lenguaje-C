/*

    omando “mycat”: Este comando muestra el 
    contenido de un archivo de texto. Debes especificar el nombre del archivo como argumento.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Verifica que se haya especificado el nombre del archivo como argumento
    if (argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    // Abre el archivo en modo lectura
    FILE *fp = fopen(argv[1], "r");
    // Verifica si se pudo abrir el archivo
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    // Lee cada carácter del archivo y lo muestra en pantalla
    int c;
    while ((c = fgetc(fp)) != EOF)
        putchar(c);

    // Cierra el archivo
    fclose(fp);
    return 0;
}