#include <stdio.h>

typedef struct{
    int DIA;
    int MES;
    int ANYO;
} FECHA;

typedef struct{
    float PROGRAMACION;
    float MATEMATICAS;
    float LOGICA;
    float TICS;
} ASIGNATURAS;

typedef struct{
    FECHA fechaCorte;
    //ESTUDIANTE Estudiante;
    ASIGNATURAS notas;
    float promedio;

} INFORME;




void menu(){
    printf("\n----- NOTAS PROGRAMACION -----\n");
    printf("1. Subir notas\n");
    printf("2. Ver las notas\n");
    printf("3. Cambiar las notas\n");
    printf("4. Borrar las notas\n");
    printf("0. Salir\n\n");
    printf("Digite un opcion: ");
}
void menuAsignaturas(){
    printf("1. Programacion\n");
    printf("2. Matematicas\n");
    printf("3. Desarrollo del Pensamiento Logico\n");
    printf("4. Introduccion a las TICS\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}

void menuCrear(){
    printf("\n------------------------------\n");
    printf("1. Ingresar todas las notas\n");
    printf("2. Ingresar ciertas notas\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}

void menuVer(){
    printf("\n------------------------------\n");
    printf("1. Ver todas las notas\n");
    printf("2. Ver una nota especifica\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}

void menuCambiar(){
    printf("\n------------------------------\n");
    printf("1. Cambiar todas las notas\n");
    printf("2. Cambiar ciertas notas\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}

void menuEliminar(){
    printf("\n------------------------------\n");
    printf("1. Eliminar todas las notas\n");
    printf("2. Eliminar una nota\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}

void crearNotas(){
    int opcion=1,opcion2=1;
    ASIGNATURAS asignaturas;
    while (opcion !=0 ){
        menuCrear();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                printf("Programacion: ");
                scanf("%f", &asignaturas.PROGRAMACION);
                printf("Matematicas: ");
                scanf("%f", &asignaturas.MATEMATICAS);
                printf("Desarrollo del Pensamiento Logico: ");
                scanf("%f", &asignaturas.LOGICA);
                printf("Introduccion a las TICS: ");
                scanf("%f", &asignaturas.TICS);
                break;
            case 2:
                printf("Seleccione la asignatura:\n");
                menuAsignaturas();
                scanf("%d", &opcion2);
                switch (opcion2){
                    case 1:
                        printf("Ingrese la nota de Programacion:: ");
                        scanf("%f", &asignaturas.PROGRAMACION);
                        break;
                    case 2:
                        printf("Ingrese la nota de Matematicas:: ");
                        scanf("%f", &asignaturas.MATEMATICAS);
                        break;   
                    case 3:
                        printf("Ingrese la nota de Pensamiento Logico:: ");
                        scanf("%f", &asignaturas.LOGICA);
                        break;
                    case 4:
                        printf("Ingrese la nota de Introduccion a las TICS:: ");
                        scanf("%f", &asignaturas.TICS);
                        break;   
                    case 0:
                        printf("\n");
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

void verNotas(){
    int opcion,nota;
    char notas[1];
    opcion=1;
    while (opcion !=0 ){
        menuVer();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<1; contador++){
                    printf("La nota %d es: %.1f\n", contador+1, notas[contador]);
                }   
                break;
            case 2:
                printf("Ingrese la nota que quiere ver: ");
                scanf("%d", &nota);
                printf("La nota %d es: %.1f\n", nota, notas[nota-1]);
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

void cambiarNotas(){
    int opcion,nota;
    char notas[1];
    opcion=1;
    while (opcion !=0 ){
        menuCambiar();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<1; contador++){
                    printf("Ingrese la nota %d: ", contador+1);
                    scanf("%f", &notas[contador]);
                }
                break;
            case 2:
                printf("Ingrese la nota que quiere cambiar: ");
                scanf("%d", &nota);
                printf("Ingrese la nueva nota %d: ", nota);
                nota=nota-1;
                scanf("%f", &notas[nota]);   
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

void eliminarNotas(){
    int opcion,nota;
    char notas[1];
    opcion=1;
    while (opcion !=0 ){
        menuEliminar();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<1;contador++){
                    notas[contador]=-1;
                }
                break;
            case 2:
                printf("ingrese la nota del estudiante que quiere eliminar: ");
                scanf("%d", &nota); 
                nota=nota-1;
                notas[nota]=-1;
                printf("La nota ha sido eliminada...");
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
    int opcion;
    opcion=1;
    while (opcion !=0 ){
        menu();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                crearNotas();
                break;
            case 2:
                verNotas();
                break;
            case 3:
                cambiarNotas();
                break;
            case 4:
                eliminarNotas();
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