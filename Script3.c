/*
    Comando “mycp”: Este comando copia un archivo a otro lugar. Debes especificar el    
    nombre del archivo de origen y el nombre del archivo de destino como argumentos.

*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Verifica que se hayan especificado los nombres de los archivos como argumentos
    if (argc != 3) {
        printf("Uso: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        return 1;
    }

    // Abre el archivo de origen en modo lectura
    FILE *src = fopen(argv[1], "r");
    // Verifica si se pudo abrir el archivo de origen
    if (src == NULL) {
        printf("No se pudo abrir el archivo de origen\n");
        return 1;
    }

    // Abre el archivo de destino en modo escritura
    FILE *dst = fopen(argv[2], "w");
    // Verifica si se pudo abrir el archivo de destino
    if (dst == NULL) {
        printf("No se pudo abrir el archivo de destino\n");
        fclose(src);
        return 1;
    }

    // Copia cada carácter del archivo de origen al archivo de destino
    int c;
    while ((c = fgetc(src)) != EOF)
        fputc(c, dst);

    // Cierra los archivos
    fclose(src);
    fclose(dst);
    return 0;
}