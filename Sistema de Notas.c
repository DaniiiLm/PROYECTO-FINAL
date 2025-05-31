#include <stdio.h>
#include <stdlib.h>
#define maxEstudiantes 30
#define anchoNombreCompleto 45
#define anchoDocumento 12

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
    char nombre[15];
    char nombre2[15];
    char apellido[15];
    char apellido2[15];
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
    system("cls");
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
    printf("2. Segundo nombre\n");
    printf("3. Apellido\n");
    printf("4. Segundo pellido\n");
    printf("5. Documento de identidad\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}



//FUNCIONES
void limpiarBuffer() {
    int c = getchar();
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}
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
void leerLinea(char *buffer, int tamano) {
    if(fgets(buffer, tamano, stdin)) {
        for(int cont=0; cont<tamano; cont++) {
            if(buffer[cont]=='\n'){  
                buffer[cont]='\0';     
                break;                
            }
        }
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
    conNota("Programacion", asignaturas.programacion);
    conNota("Matematicas", asignaturas.matematicas);
    conNota("Pensamiento Logico", asignaturas.logica);
    conNota("Introduccion a las TICS", asignaturas.tics);
    printf("\n");    
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
    printf("Ingrese nombre(s) del estudiante: ");
    leerLinea(estudiantes[*cantidad].nombre, sizeof(estudiantes[*cantidad].nombre));

    printf("Ingrese segundo nombre (Presione Enter si no tiene): ");
    leerLinea(estudiantes[*cantidad].nombre2, sizeof(estudiantes[*cantidad].nombre2));

    printf("Ingrese primer apellido del estudiante: ");
    leerLinea(estudiantes[*cantidad].apellido, sizeof(estudiantes[*cantidad].apellido));

    printf("Ingrese segundo apellido del estudiante: ");
    leerLinea(estudiantes[*cantidad].apellido2, sizeof(estudiantes[*cantidad].apellido2));

    printf("Ingrese documento de identidad del estudiante: ");
    scanf("%d", &estudiantes[*cantidad].docIdentidad);
    limpiarBuffer();


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
    printf("Indice | %-*s | %-*s\n", anchoNombreCompleto, "Nombre completo", anchoDocumento, "Documento");
    printf("------------------------------------------------------------------\n");
    for(int cont=0; cont<cantidad; cont++){
        char nombreCompleto[anchoNombreCompleto+1];
        if(estudiantes[cont].nombre2[0] != '\0'){   //valida la primera posicon del vector, si hay o no caracteres
            snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s %s %s",estudiantes[cont].nombre,estudiantes[cont].nombre2,estudiantes[cont].apellido,estudiantes[cont].apellido2);
        } else {
            snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s %s", estudiantes[cont].nombre, estudiantes[cont].apellido, estudiantes[cont].apellido2);
        }
        printf("[%2d]   | %-*s | %-*d\n", cont+1, anchoNombreCompleto, nombreCompleto, anchoDocumento, estudiantes[cont].docIdentidad);    
    }
    printf("\n");
}
void modificarEstudiante(ESTUDIANTE estudiantes[], int cantidad){
    int opcion=1, indice, salirModificar=0;
    if(cantidad==0){
        printf("No hay estudiantes registrados.\n\n");
        return;
    }
    while(!salirModificar){
        mostrarEstudiante(estudiantes, cantidad);
        printf("Ingrese 0 para salir o\nIngrese el indice del estudiante a modificar (1 - %d): ", cantidad);
        scanf("%d", &indice);
        limpiarBuffer();
        if(indice==0) {
            salirModificar=1;
            break;
        }
        while(indice<1 || indice>cantidad) {
            printf("Indice invalido o fuera de rango! (1 - %d): ", cantidad);
            scanf("%d", &indice);
            limpiarBuffer();   
        }
        system("cls");
        while(opcion!=0){
            printf("Dato a modificar: \n");
            menuCambiarEstudiante();
            scanf("%d",&opcion);
            limpiarBuffer();
            system("cls");
            switch(opcion){
                case 1:
                    printf("Primer nombre actual: %s\n", estudiantes[indice-1].nombre);
                    printf("Nuevo nombre: ");
                    leerLinea(estudiantes[indice-1].nombre, sizeof(estudiantes[indice-1].nombre));
                    system("cls");
                    break;
                case 2:
                    printf("Segundo nombre actual: %s\n", estudiantes[indice-1].nombre2);
                    printf("Nuevo segundo nombre: ");
                    leerLinea(estudiantes[indice-1].nombre2, sizeof(estudiantes[indice-1].nombre2));
                    system("cls");
                    break;
                case 3:
                    printf("Primer apellido actual: %s\n", estudiantes[indice-1].apellido);
                    printf("Nuevo apellido: ");
                    leerLinea(estudiantes[indice-1].apellido, sizeof(estudiantes[indice-1].apellido));
                    system("cls");
                    break;
                case 4:
                    printf("Segundo apellido actual: %s\n", estudiantes[indice-1].apellido2);
                    printf("Nuevo segundo apellido: ");
                    leerLinea(estudiantes[indice-1].apellido2, sizeof(estudiantes[indice-1].apellido2));
                    system("cls");
                    break;
                case 5:
                    printf("Documento actual: %d\n", estudiantes[indice-1].docIdentidad);
                    printf("Nuevo documento: ");
                    scanf(" %d", &estudiantes[indice-1].docIdentidad);
                    system("cls");
                    limpiarBuffer();
                    break;
                case 0:
                    break;
                default:
                    printf("La opcion no es valida!\n\n");
            }
        }
        
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
    int opcion1=1,opcion2,opcion3,opcionEstudiante,salirNotas;
    ESTUDIANTE estudiantes[maxEstudiantes]; 
    int cantidad=0; // Numero actual de estudiantes guardados
    while(opcion1!=0){
        menuPrincipal();
        scanf("%d", &opcion1);
        limpiarBuffer();
        system("cls");
        switch (opcion1){
            case 1:
                opcion2=1;
                while(opcion2!=0){
                    menuEstudiantes();
                    scanf("%d", &opcion2);
                    limpiarBuffer();
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
                salirNotas=0;     
                if(cantidad==0){
                printf("Primero debes crear estudiantes.\n\n");
                break;
                }
                while(!salirNotas){
                    mostrarEstudiante(estudiantes, cantidad);
                    printf("Ingrese 0 para volver al menu principal o\nSeleccione un estudiante (1 - %d): ", cantidad);
                    scanf("%d", &opcionEstudiante);
                    limpiarBuffer();
                    if(opcionEstudiante==0){
                    salirNotas = 1;
                    break;
                    }  
                    while (opcionEstudiante < 1 || opcionEstudiante > cantidad){
                        printf("Indice invalido. Ingrese un valor entre 1 y %d: ", cantidad);
                        scanf("%d", &opcionEstudiante);
                        limpiarBuffer();
                        }
                    system("cls");
                    opcion3=1;
                    while(opcion3!=0){
                        menuNotas();
                        scanf("%d", &opcion3);
                        limpiarBuffer();
                        system("cls");
                        switch (opcion3){
                            case 1:
                                crearNotas(&estudiantes[opcionEstudiante-1].asignaturas);
                                break;
                            case 2:
                                mostrarNotas(estudiantes[opcionEstudiante-1].asignaturas);
                                break;
                            case 3:
                                modificarNotas(&estudiantes[opcionEstudiante-1].asignaturas);
                                break;
                            case 4:
                                eliminarNotas(&estudiantes[opcionEstudiante-1].asignaturas);
                                break;
                            case 0:
                                break;
                            default:
                                printf("La opcion no es valida!\n\n");
                                break;
                            }
                        }
                        system("cls");
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