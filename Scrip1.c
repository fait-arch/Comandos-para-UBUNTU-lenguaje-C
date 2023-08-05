
/*
    Comando “myls”: Este comando muestra el contenido de un directorio. 
    Puedes especificar el directorio como argumento o, si no se especifica, 
    se mostrará el contenido del directorio actual.

*/
#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv) {
    // Declaración de variables
    struct dirent *de;
    // Abre el directorio especificado como argumento o el directorio actual si no se especifica
    DIR *dr = opendir(argc > 1 ? argv[1] : ".");

    // Verifica si se pudo abrir el directorio
    if (dr == NULL) {
        printf("No se pudo abrir el directorio\n");
        return 0;
    }

    // Lee cada entrada del directorio y la muestra en pantalla
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    // Cierra el directorio
    closedir(dr);
    return 0;
}