#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Longitud máxima de la cadena de estudiantes

int main() {
    char students[MAX_LENGTH];
    int last_angry = -1; // Índice del último estudiante que se vuelve enojado
    int time_between_changes = 0; // Tiempo entre cambios
    int students_between_changes = 0; // Número de estudiantes entre cambios

    // Leer la cadena de estudiantes
    printf("Ingrese la cadena de estudiantes (solo 'A' y 'P'): ");
    scanf("%s", students);

    int length = strlen(students);

    // Recorrer la cadena de estudiantes de derecha a izquierda
    for (int i = length - 1; i >= 0; i--) {
        // Si el estudiante actual está enojado
        if (students[i] == 'A') {
            // Calcular el tiempo entre cambios si ya se encontró al menos un estudiante enojado
            if (last_angry != -1) {
                time_between_changes += last_angry - i;
            }
            // Actualizar el índice del último estudiante enojado
            last_angry = i;
        }
        // Si el estudiante actual está paciente y hay un estudiante enojado detrás de él
        else if (students[i] == 'P' && last_angry != -1) {
            // Marcar al estudiante actual como enojado
            students[i] = 'A';
            // Actualizar el índice del último estudiante enojado
            last_angry = i;
        }
        // Contar el número de estudiantes entre cambios
        if (last_angry != -1) {
            students_between_changes++;
        }
    }

    // Imprimir la cadena de estudiantes final
    printf("Cadena de estudiantes final: %s\n", students);
    printf("Último estudiante enojado: %d\n", last_angry);
    printf("Tiempo entre cambios: %d\n", time_between_changes);
    printf("Número de estudiantes entre cambios: %d\n", students_between_changes);

    return 0;
}

