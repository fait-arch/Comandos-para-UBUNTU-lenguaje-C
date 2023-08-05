
/*
    Programa para mostrar información del sistema:


*/
#include <stdio.h> // Incluir la biblioteca estándar de entrada/salida
#include <sys/utsname.h> // Incluir la biblioteca para obtener información del sistema

int main() {
    struct utsname buffer; // Crear una estructura para almacenar la información del sistema

    // Obtener la información del sistema y almacenarla en la estructura
    if (uname(&buffer) != 0) {
        perror("uname"); // Mostrar un mensaje de error si no se pudo obtener la información
        return 1; // Salir del programa con un código de error
    }

    // Mostrar la información del sistema
    printf("Sistema: %s\n", buffer.sysname);
    printf("Nombre del host: %s\n", buffer.nodename);
    printf("Versión del sistema: %s\n", buffer.release);
    printf("Versión del kernel: %s\n", buffer.version);
    printf("Arquitectura del procesador: %s\n", buffer.machine);

    return 0; // Salir del programa con éxito
}



/*
Programa para realizar operaciones matemáticas básicas:


*/

#include <stdio.h> // Incluir la biblioteca estándar de entrada/salida

int main() {
    double num1, num2; // Variables para almacenar los números a operar
    char operador; // Variable para almacenar el operador

    // Pedir al usuario que ingrese la operación
    printf("Ingresa la operación en el formato: num1 operador num2\n");
    scanf("%lf %c %lf", &num1, &operador, &num2); // Leer la operación desde el teclado

    // Realizar la operación según el operador ingresado
    switch (operador) {
        case '+': // Si el operador es +
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2); // Realizar la suma
            break;
        case '-': // Si el operador es -
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2); // Realizar la resta
            break;
        case '*': // Si el operador es *
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2); // Realizar la multiplicación
            break;
        case '/': // Si el operador es /
            if (num2 == 0) { // Si el segundo número es cero
                printf("Error: No se puede dividir entre cero.\n"); // Mostrar un mensaje de error
            } else { // Si el segundo número no es cero
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2); // Realizar la división
            }
            break;
        default: // Si el operador no es válido
            printf("Error: Operador no válido.\n"); // Mostrar un mensaje de error
            break;
    }

    return 0; // Salir del programa con éxito
}



/*
Programa para realizar operaciones de búsqueda y ordenamiento en una lista de números:

*/

#include <stdio.h> // Incluir la biblioteca estándar de entrada/salida
#include <stdlib.h> // Incluir la biblioteca estándar para usar qsort

// Función para comparar dos números (usada por qsort)
int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int lista[] = {5, 3, 7, 1, 9}; // Lista de números a ordenar
    int tamano = sizeof(lista) / sizeof(lista[0]); // Calcular el tamaño de la lista
    int i;

    // Ordenar la lista usando qsort
    qsort(lista, tamano, sizeof(int), compara);

    // Mostrar la lista ordenada
    printf("Lista ordenada:\n");
    for (i = 0; i < tamano; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0; // Salir del programa con éxito
}