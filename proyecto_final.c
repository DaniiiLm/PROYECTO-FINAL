#include <stdio.h>
//Estructuras
typedef struct{
    int codigo;
    char nombre[30];
    char apellido[30];
    int doc_identidad;
} ESTUDIANTE;

typedef struct{
    char nombre_materia[30];
    float nota;
} ASIGNATURA;

typedef struct{
    int dia;
    int mes;
    int anyo;
} Date;

typedef struct{
    ASIGNATURA materia;
    ESTUDIANTEestudiantes[50];
    int periodo;
} GRADO;

//funciones

ESTUDIANTE crear_estudiante(){
    ESTUDIANTE estudiante;
    printf("Ingrese nombre del estudiante: ");
    scanf(" %s", &ESTUDIANTE.nombre);
    printf("Ingrese apellido del estudiante: ");
    scanf(" %s", &ESTUDIANTE.apellido);
    printf("Ingrese codigo del estudiante: ");
    scanf(" %s", &ESTUDIANTE.codigo);
    printf("Ingrese T.I del estudiante: ");
    scanf(" %s", &ESTUDIANTE.doc_identidad);
    return estudiante;
}
void mostrar_estudiante(ESTUDIANTE estudiante){
    printf("Nombre: %s | Apellido: %s | Codigo: %d | Doc Identidad: %d |",ESTUDIANTE.nombre, ESTUDIANTE.apellido, ESTUDIANTE.codigo,ESTUDIANTE.doc_identidad);
}
ESTUDIANTE modificar_estudiante(ESTUDIANTE estudiante){
    printf("Que dato quiere modificar");
    int opcion = 0;
    scanf("%d",&opcion);
    switch(opcion){
    case 1:
        printf("Ingrese nombre del estudiante: ");
        scanf(" %s", &ESTUDIANTE.nombre);
        break;
    case 2:
        printf("Ingrese apellido del estudiante: ");
        scanf(" %s", &ESTUDIANTE.apellido);
        break;
    case 3:
        printf("Ingrese codigo del estudiante: ");
        scanf(" %s", &ESTUDIANTE.codigo);
        break;
     case 4:
        printf("Ingrese T.I del estudiante: ");
        scanf(" %s", &ESTUDIANTE.doc_identidad);
    }
    return estudiante;
}
ESTUDIANTE eliminar_estudiante(){
    printf("Que dato quiere eliminar");
    int opcion = 0;
    scanf("%d",&opcion);
    switch(opcion){
    case 1:
        printf("Ingrese nombre del estudiante: ");
        scanf(" %s", &ESTUDIANTE.nombre);
        break;
    case 2:
        printf("Ingrese apellido del estudiante: ");
        scanf(" %s", &ESTUDIANTE.apellido);
        break;
    case 3:
        printf("Ingrese codigo del estudiante: ");
        scanf(" %s", &ESTUDIANTE.codigo);
        break;
     case 4:
        printf("Ingrese T.I del estudiante: ");
        scanf(" %s", &ESTUDIANTE.doc_identidad);
    }
    return estudiante;

}



