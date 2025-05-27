#include <stdio.h>

void menu(){
    printf("\n----- NOTAS PROGRAMACION -----\n");
    printf("1. Subir notas\n");
    printf("2. Ver las notas\n");
    printf("3. Cambiar las notas\n");
    printf("4. Borrar las notas\n");
    printf("0. Salir\n\n");
    printf("Digite un opcion: ");
}

void menuCreate(){
    printf("\n------------------------------\n");
    printf("1. Ingresar todas las notas\n");
    printf("2. Ingresar una cantidad de notas\n");
    printf("3. Seguir Ingresando notas\n");
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

void crearNotas(float ProgramingNotes[]){
    int opcion,cantidad,agregar;
    opcion=1;
    while (opcion !=0 ){
        menuCreate();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<34; contador++){
                    printf("Ingrese la nota %d: ", contador+1);
                    scanf("%f", &ProgramingNotes[contador]);
                }
                break;
            case 2:
                printf("Ingrese la cantidad de notas que desea llenar: ");
                scanf("%d", &cantidad);
                for(int contador=0; contador<cantidad; contador++){
                    printf("Ingrese la nota %d: ", contador+1);
                    scanf("%f", &ProgramingNotes[contador]);
                }
                break;
            case 3:
                printf("Ingrese la cantidad de notas que desea llenar a partir del estudiante %d: ", cantidad);
                scanf("%d", &agregar);
                for(int contador=cantidad; contador<cantidad+agregar; contador++){
                    printf("Ingrese la nota %d: ", contador+1);
                    scanf("%f", &ProgramingNotes[contador]);
                }
                cantidad+=agregar;
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

void verNotas(float ProgramingNotes[]){
    int opcion,nota;
    opcion=1;
    while (opcion !=0 ){
        menuVer();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<34; contador++){
                    printf("La nota %d es: %.1f\n", contador+1, ProgramingNotes[contador]);
                }   
                break;
            case 2:
                printf("Ingrese la nota que quiere ver: ");
                scanf("%d", &nota);
                printf("La nota %d es: %.1f\n", nota, ProgramingNotes[nota-1]);
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

void cambiarNotas(float ProgramingNotes[]){
    int opcion,nota;
    opcion=1;
    while (opcion !=0 ){
        menuCambiar();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<34; contador++){
                    printf("Ingrese la nota %d: ", contador+1);
                    scanf("%f", &ProgramingNotes[contador]);
                }
                break;
            case 2:
                printf("Ingrese la nota que quiere cambiar: ");
                scanf("%d", &nota);
                printf("Ingrese la nueva nota %d: ", nota);
                nota=nota-1;
                scanf("%f", &ProgramingNotes[nota]);   
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

void eliminarNotas(float ProgramingNotes[]){
    int opcion,nota;
    opcion=1;
    while (opcion !=0 ){
        menuEliminar();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                for(int contador=0; contador<34;contador++){
                    ProgramingNotes[contador]=-1;
                }
                break;
            case 2:
                printf("ingrese la nota del estudiante que quiere eliminar: ");
                scanf("%d", &nota); 
                nota=nota-1;
                ProgramingNotes[nota]=-1;
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
    float ProgramingNotes[34];
    for(int contador=0; contador<34;contador++){
        ProgramingNotes[contador]=-1;
    }
    opcion=1;
    while (opcion !=0 ){
        menu();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                crearNotas(ProgramingNotes);
                break;
            case 2:
                verNotas(ProgramingNotes);
                break;
            case 3:
                cambiarNotas(ProgramingNotes);
                break;
            case 4:
                eliminarNotas(ProgramingNotes);
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