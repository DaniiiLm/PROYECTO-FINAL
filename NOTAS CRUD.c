#include <stdio.h>
#include <stdlib.h>

//ESTRUCTURAS
typedef struct{
    int dia;
    int mes;
    int anyo;
} FECHA;

typedef struct{
    float programacion;
    float matematicas;
    float logica;
    float tics;
} ASIGNATURAS;

typedef struct{
    FECHA fechaCorte;
    //ESTUDIANTE Estudiante;
    ASIGNATURAS notas;
    float promedio;
} INFORME;

typedef enum{
    sinNota=-1
} NOTA;


//MENUS
void menuPrincipal(){
    printf("1. Estudiante\n");
    printf("0. Asignaturas y Notas\n\n");
    printf("Digite un opcion: ");
}
void menuNotas(){
    printf("1. Subir notas\n");
    printf("2. Ver las notas\n");
    printf("3. Cambiar las notas\n");
    printf("4. Borrar las notas\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuAsignaturas(){
    printf("1. Programacion\n");
    printf("2. Matematicas\n");
    printf("3. Pensamiento Logico\n");
    printf("4. Introduccion a las TICS\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}


//MENU CRUD NOTAS
void menuCrear(){
    printf("1. Ingresar todas las notas\n");
    printf("2. Ingresar ciertas notas\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuVer(){
    printf("1. Ver todas las notas\n");
    printf("2. Ver una nota especifica\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuCambiar(){
    printf("1. Cambiar todas las notas\n");
    printf("2. Cambiar ciertas notas\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuEliminar(){
    printf("1. Eliminar todas las notas\n");
    printf("2. Eliminar una nota\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}


//FUNCIONES
float validarNotas(){
    float nota;
    scanf("%f", &nota);
    while(nota<0.0 || nota>5.0){
        printf("Error. Ingrese una nota valida (0 a 5): ");
        scanf("%f", &nota);
    }
    return nota;
}
void conNota(char* nombreAsignatura, float nota){
    if(nota == sinNota){
        printf("%s: Sin nota\n", nombreAsignatura);
    } else {
        printf("%s: %.1f\n", nombreAsignatura, nota);
    }
}


//CRUD NOTAS
ASIGNATURAS crearNotas(){
    int opcion=1,opcion2=1;
    ASIGNATURAS asignaturas={sinNota, sinNota, sinNota, sinNota};
    while (opcion !=0 ){
        menuCrear();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                printf("Ingrese la nota de 0 a 5\n");
                printf("Programacion: ");
                asignaturas.programacion=validarNotas();
                printf("Matematicas: ");
                asignaturas.matematicas=validarNotas();
                printf("Pensamiento Logico: ");
                asignaturas.logica=validarNotas();
                printf("Introduccion a las TICS: ");
                asignaturas.tics=validarNotas();
                system("cls");
                break;
            case 2:
                printf("Seleccione la asignatura:\n");
                menuAsignaturas();
                scanf("%d", &opcion2);
                system("cls");
                switch (opcion2){
                    case 1:
                        printf("Ingrese la nota de Programacion: ");
                        asignaturas.programacion=validarNotas();
                        system("cls");
                        break;
                    case 2:
                        printf("Ingrese la nota de Matematicas: ");
                        asignaturas.matematicas=validarNotas();
                        system("cls");
                        break;   
                    case 3:
                        printf("Ingrese la nota de Pensamiento Logico: ");
                        asignaturas.logica=validarNotas();
                        system("cls");
                        break;
                    case 4:
                        printf("Ingrese la nota de Introduccion a las TICS: ");
                        asignaturas.tics=validarNotas();
                        system("cls");
                        break;   
                    case 0:
                        break;
                    default:
                        printf("¡La opcion no es valida!");
                        break;
                    }
                    break;
            case 0:
                break;
            default:
                printf("¡La opcion no es valida!");
                break;
        }
    }
    return asignaturas;   
}
void verNotas(ASIGNATURAS asignaturas){
    int opcion=1, opcion2=1;
    while (opcion !=0 ){
        menuVer();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                conNota("Programacion", asignaturas.programacion);
                conNota("Matematicas", asignaturas.matematicas);
                conNota("Pensamiento Logico", asignaturas.logica);
                conNota("Introduccion a las TICS", asignaturas.tics);
                printf("\n");
                break;
            case 2:
                printf("Seleccione la asignatura:\n");
                menuAsignaturas();
                scanf("%d", &opcion2);
                system("cls");
                switch (opcion2){
                    case 1:
                        conNota("Programacion", asignaturas.programacion);
                        printf("\n");
                        break;
                    case 2:
                        conNota("Matematicas", asignaturas.matematicas);
                        printf("\n");
                        break;
                    case 3:
                        conNota("Pensamiento Logico", asignaturas.logica);
                        printf("\n");
                        break;
                    case 4:
                        conNota("Introduccion a las TICS", asignaturas.tics);
                        printf("\n");
                        break;
                    case 0:
                        break;
                    default:
                        printf("¡La opcion no es valida!");
                        break;
                }
            case 0:
                break;
            default:
                printf("¡La opcion no es valida!");
                break;
        }
    }     
}
ASIGNATURAS cambiarNotas(ASIGNATURAS asignaturas){
    int opcion=1, opcion2=1;
    while(opcion !=0 ){
        menuCambiar();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                printf("Ingrese la nota de 0 a 5\n");
                printf("Programacion: ");
                asignaturas.programacion=validarNotas();
                printf("Matematicas: ");
                asignaturas.matematicas=validarNotas();
                printf("Pensamiento Logico: ");
                asignaturas.logica=validarNotas();
                printf("Introduccion a las TICS: ");
                asignaturas.tics=validarNotas();
                system("cls");
                break;
            case 2:
                printf("Seleccione la asignatura:\n");
                menuAsignaturas();
                scanf("%d", &opcion2);
                system("cls");
                switch (opcion2){
                    case 1:
                        printf("Ingrese la nota de Programacion: ");
                        asignaturas.programacion=validarNotas();
                        system("cls");
                        break;
                    case 2:
                        printf("Ingrese la nota de Matematicas: ");
                        asignaturas.matematicas=validarNotas();
                        system("cls");
                        break;   
                    case 3:
                        printf("Ingrese la nota de Pensamiento Logico: ");
                        asignaturas.logica=validarNotas();
                        system("cls");
                        break;
                    case 4:
                        printf("Ingrese la nota de Introduccion a las TICS: ");
                        asignaturas.tics=validarNotas();
                        system("cls");
                        break;   
                    case 0:
                        break;
                    default:
                        printf("¡La opcion no es valida!");
                        break;
                    }
                    break;
            case 0:
                printf("\n");
                break;
            default:
                printf("¡La opcion no es valida!");
                break;
        }
    }  
}
ASIGNATURAS eliminarNotas(ASIGNATURAS asignaturas){
    int opcion=1,opcion2=1;
    ASIGNATURAS vaciar={sinNota, sinNota, sinNota, sinNota};
    opcion=1;
    while (opcion!=0){
        menuEliminar();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                return vaciar;
            case 2:
                printf("Seleccione la asignatura:\n");
                menuAsignaturas();
                scanf("%d", &opcion2);
                system("cls");
                switch (opcion2){
                    case 1:
                        asignaturas.programacion=sinNota;
                        printf("La nota de Programacion ha sido eliminada...\n");
                        break;
                    case 2:
                        asignaturas.matematicas=sinNota;
                        printf("La nota de Matematicas ha sido eliminada...\n");
                        break;   
                    case 3:
                        asignaturas.logica=sinNota;
                        printf("La nota de Pensamiento Logico ha sido eliminada...\n");
                        break;
                    case 4:
                        asignaturas.tics=sinNota;
                        printf("La nota de Introduccion a las TICS ha sido eliminada...\n");
                        break;   
                    case 0:
                        break;
                    default:
                        printf("¡La opcion no es valida!");
                        break;
                    }
                    break;
                break;
            case 0:
                printf("\n");
                break;
            default:
                printf("¡La opcion no es valida!");
                break;
        }
    }
}

void main(){
    int opcion=1;
    ASIGNATURAS asignaturas={sinNota, sinNota, sinNota, sinNota};
    while (opcion !=0 ){
        menuNotas();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                asignaturas=crearNotas();
                break;
            case 2:
                verNotas(asignaturas);
                break;
            case 3:
                cambiarNotas(asignaturas);
                break;
            case 4:
                eliminarNotas(asignaturas);
                break;
            case 0:
                printf("\nHas salido del programa, Adios!");
                break;
            default:
                printf("¡La opcion no es valida!");
                break;
        }
    }  
}
