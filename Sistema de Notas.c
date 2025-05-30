#include <stdio.h>
#include <stdlib.h>
#define maxEstudiantes 30

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
    char nombre[30];
    char apellido[30];
    int docIdentidad;
    ASIGNATURAS asignaturas;
} ESTUDIANTE;

typedef struct{
    FECHA fechaCorte;
    ASIGNATURAS notas;
    float promedio;
} INFORME;

typedef enum{
    sinNota=-1
} NOTA;


//MENUS
void menuPrincipal(){
    printf("1. Estudiante\n");
    printf("2. Asignaturas y Notas\n");
    printf("0. Salir del programa\n\n");
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
void menuEstudiantes(){
    printf("1. Crear estudiante\n");
    printf("2. Ver estudiantes\n");
    printf("3. Cambiar datos del estudiante\n");
    printf("4. Eliminar estudiantes\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}


//MENU NOTAS
void menuAsignaturas(){
    printf("1. Programacion\n");
    printf("2. Matematicas\n");
    printf("3. Pensamiento Logico\n");
    printf("4. Introduccion a las TICS\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
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


//MENU ESTUDIANTES
void menuCambiarEstudiante(){
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Documento de identidad\n");
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
void crearNotas(ASIGNATURAS *asignaturas){
    int opcion=1,opcion2=1;
    while (opcion !=0 ){
        menuCrear();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                printf("Ingrese la nota de 0 a 5\n");
                printf("Programacion: ");
                asignaturas->programacion=validarNotas();
                printf("Matematicas: ");
                asignaturas->matematicas=validarNotas();
                printf("Pensamiento Logico: ");
                asignaturas->logica=validarNotas();
                printf("Introduccion a las TICS: ");
                asignaturas->tics=validarNotas();
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
                        asignaturas->programacion=validarNotas();
                        system("cls");
                        break;
                    case 2:
                        printf("Ingrese la nota de Matematicas: ");
                        asignaturas->matematicas=validarNotas();
                        system("cls");
                        break;   
                    case 3:
                        printf("Ingrese la nota de Pensamiento Logico: ");
                        asignaturas->logica=validarNotas();
                        system("cls");
                        break;
                    case 4:
                        printf("Ingrese la nota de Introduccion a las TICS: ");
                        asignaturas->tics=validarNotas();
                        system("cls");
                        break;   
                    case 0:
                        break;
                    default:
                        printf("La opcion no es valida!\n\n");
                        break;
                    }
                    break;
            case 0:
                break;
            default:
                printf("La opcion no es valida!\n\n");
                break;
        }
    }  
}
void mostrarNotas(ASIGNATURAS asignaturas){
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
                        printf("La opcion no es valida!\n\n");
                        break;
                }
            case 0:
                break;
            default:
                printf("La opcion no es valida!\n\n");
                break;
        }
    }     
}
void modificarNotas(ASIGNATURAS *asignaturas){
    int opcion=1, opcion2=1;
    while(opcion !=0 ){
        menuCambiar();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                printf("Ingrese la nota de 0 a 5\n");
                printf("Programacion: ");
                asignaturas->programacion=validarNotas();
                printf("Matematicas: ");
                asignaturas->matematicas=validarNotas();
                printf("Pensamiento Logico: ");
                asignaturas->logica=validarNotas();
                printf("Introduccion a las TICS: ");
                asignaturas->tics=validarNotas();
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
                        asignaturas->programacion=validarNotas();
                        system("cls");
                        break;
                    case 2:
                        printf("Ingrese la nota de Matematicas: ");
                        asignaturas->matematicas=validarNotas();
                        system("cls");
                        break;   
                    case 3:
                        printf("Ingrese la nota de Pensamiento Logico: ");
                        asignaturas->logica=validarNotas();
                        system("cls");
                        break;
                    case 4:
                        printf("Ingrese la nota de Introduccion a las TICS: ");
                        asignaturas->tics=validarNotas();
                        system("cls");
                        break;   
                    case 0:
                        break;
                    default:
                        printf("La opcion no es valida!\n\n");
                        break;
                    }
                    break;
            case 0:
                printf("\n");
                break;
            default:
                printf("La opcion no es valida!\n\n");
                break;
        }
    }  
}
void eliminarNotas(ASIGNATURAS *asignaturas){
    int opcion=1,opcion2=1;
    opcion=1;
    while (opcion!=0){
        menuEliminar();
        scanf("%d", &opcion);
        system("cls");
        switch (opcion){
            case 1:
                asignaturas->programacion=sinNota;
                asignaturas->matematicas=sinNota;
                asignaturas->logica=sinNota;
                asignaturas->tics=sinNota;
                printf("Todas las notas han sido eliminadas.\n");
                break;
            case 2:
                printf("Seleccione la asignatura:\n");
                menuAsignaturas();
                scanf("%d", &opcion2);
                system("cls");
                switch (opcion2){
                    case 1:
                        asignaturas->programacion=sinNota;
                        printf("La nota de Programacion ha sido eliminada...\n\n");
                        break;
                    case 2:
                        asignaturas->matematicas=sinNota;
                        printf("La nota de Matematicas ha sido eliminada...\n\n");
                        break;   
                    case 3:
                        asignaturas->logica=sinNota;
                        printf("La nota de Pensamiento Logico ha sido eliminada...\n\n");
                        break;
                    case 4:
                        asignaturas->tics=sinNota;
                        printf("La nota de Introduccion a las TICS ha sido eliminada...\n\n");
                        break;   
                    case 0:
                        break;
                    default:
                        printf("La opcion no es valida!\n\n");
                        break;
                    }
                    break;
                break;
            case 0:
                break;
            default:
                printf("La opcion no es valida!\n\n");
                break;
        }
    }
}
//CRUD ESTUDIANTES
void crearEstudiante(ESTUDIANTE estudiantes[], int *cantidad){
    if (*cantidad >= maxEstudiantes) {
        printf("No se pueden agregar mas estudiantes.\n\n");
        return;
    }
    printf("Ingrese nombre del estudiante: ");
    scanf(" %29s", estudiantes[*cantidad].nombre);  // %29s es para evitar desborde
    printf("Ingrese apellido del estudiante: ");
    scanf(" %29s", estudiantes[*cantidad].apellido);
    printf("Ingrese documento de identidad del estudiante: ");
    scanf("%d", &estudiantes[*cantidad].docIdentidad);


    // Inicializamos sinNota por defecto
    estudiantes[*cantidad].asignaturas.programacion = sinNota;
    estudiantes[*cantidad].asignaturas.matematicas = sinNota;
    estudiantes[*cantidad].asignaturas.logica = sinNota;
    estudiantes[*cantidad].asignaturas.tics = sinNota;

    (*cantidad)++;
    system("cls");
    printf("\nEstudiante creado correctamente.\n\n");
}
void mostrarEstudiante(ESTUDIANTE estudiantes[], int cantidad){
    if(cantidad==0){
        printf("No hay estudiantes registrados.\n\n");
        return;
    }

    for(int cont=0; cont<cantidad; cont++){
        printf("[%d] %s %s | Documento: %d\n", cont+1, estudiantes[cont].nombre, estudiantes[cont].apellido, estudiantes[cont].docIdentidad);
    }
    printf("\n");
}
void modificarEstudiante(ESTUDIANTE estudiantes[], int cantidad){
    int opcion, indice;
    if(cantidad==0){
        printf("No hay estudiantes registrados.\n\n");
        return;
    }
    mostrarEstudiante(estudiantes, cantidad);
    printf("Ingrese el indice del estudiante a modificar (1 - %d): ", cantidad);
    scanf("%d", &indice);
    while(indice<1 || indice>cantidad) {
        printf("Indice invalido o fuera de rango! (1 - %d): ", cantidad);
        scanf("%d", &indice);
    }
    system("cls");
    printf("Dato a modificar: \n");
    menuCambiarEstudiante();
    scanf("%d",&opcion);
    system("cls");
    switch(opcion){
        case 1:
            printf("Nombre actual: %s\n", estudiantes[indice-1].nombre);
            printf("Nuevo nombre: ");
            scanf(" %s", &estudiantes[indice-1].nombre);
            break;
        case 2:
            printf("Apellido actual: %s\n", estudiantes[indice-1].apellido);
            printf("Nuevo apellido: ");
            scanf(" %s", &estudiantes[indice-1].apellido);
            break;
        case 3:
            printf("Documento actual: %d\n", estudiantes[indice-1].docIdentidad);
            printf("Nuevo documento: ");
            scanf(" %d", &estudiantes[indice-1].docIdentidad);
        }
}
void eliminarEstudiante(ESTUDIANTE estudiantes[], int *cantidad){
    int eliminar;
    if(*cantidad==0){
        printf("No hay estudiantes para eliminar.\n\n");
        return;
    }
    while(1){
        mostrarEstudiante(estudiantes, *cantidad);
        printf("\nIngrese el indice del estudiante que desea eliminar: ");
        scanf("%d", &eliminar);
        eliminar--;
        system("cls");
        if(eliminar>=0 && eliminar < *cantidad){
                for(int cont=eliminar; cont<*cantidad-1; cont++){
                    estudiantes[cont] = estudiantes[cont+1]; //reemplazar posicion vacia del vector con la siguiente
                }
                (*cantidad)--;
                printf("Estudiante eliminado correctamente.\n");
                break;
            } else {
                printf("Posicion invalida! intentelo nuevamente.\n\n");
        }
    }  
}


//MAIN
void main(){
    system("cls");
    int opcion1=1,opcion2,opcion3;
    ESTUDIANTE estudiantes[maxEstudiantes];
    int cantidad=0; // Numero actual de estudiantes guardados
    ASIGNATURAS asignaturas={sinNota, sinNota, sinNota, sinNota};
    while(opcion1!=0){
        menuPrincipal();
        scanf("%d", &opcion1);
        system("cls");
        switch (opcion1){
            case 1:
                opcion2=1;
                while(opcion2!=0){
                    menuEstudiantes();
                    scanf("%d", &opcion2);
                    system("cls");
                    switch (opcion2){
                        case 1:
                            crearEstudiante(estudiantes, &cantidad);
                            break;
                        case 2:
                            mostrarEstudiante(estudiantes, cantidad);
                            break;
                        case 3:
                            modificarEstudiante(estudiantes, cantidad);
                            break;
                        case 4:
                            eliminarEstudiante(estudiantes, &cantidad);
                            break;
                        case 0:
                            break;
                        default:
                            printf("La opcion no es valida!\n\n");
                            break;
                        }
                    }
                    break;
            case 2:
                opcion3=1;    
                while(opcion3!=0){
                    menuNotas();
                    scanf("%d", &opcion3);
                    system("cls");
                    switch (opcion3){
                        case 1:
                            crearNotas(&asignaturas);
                            break;
                        case 2:
                            mostrarNotas(asignaturas);
                            break;
                        case 3:
                            modificarNotas(&asignaturas);
                            break;
                        case 4:
                            eliminarNotas(&asignaturas);
                            break;
                        case 0:
                            break;
                        default:
                            printf("La opcion no es valida!\n\n");
                            break;
                        }
                    }
                    break;
            case 0:
                printf("\nHas salido del programa, Adios!");
                break;
            default:
                printf("La opcion no es valida!\n\n");
                break;
        }
    }  
}

/*git add .
git commit -m "Agrego archivos .c"
git push origin main*/