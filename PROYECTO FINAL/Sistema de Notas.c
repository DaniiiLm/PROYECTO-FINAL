#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define maxEstudiantes 30
#define maxAsignaturas 4
#define maxInformes 50
#define anchoNombreCompleto 80
#define anchoDocumento 12
#define notaInforme(n) if(n==sinNota)printf("Sin nota"); else printf("%.1f", n);

//DISENO
void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(consoleHandle, position);
}
void recuadro(int xs, int ys, int xi, int yi){
    int cont;
    for(cont=xs;cont<=xi;cont++){
        gotoxy(cont, ys);printf("%c",196);
        gotoxy(cont, yi);printf("%c",196);
    }
    for(cont=ys;cont<=yi;cont++){
        gotoxy(xs, cont);printf("%c",179);
        gotoxy(xi, cont);printf("%c",179);
    }
    gotoxy(xs,ys);printf("%c",218);
    gotoxy(xi,yi);printf("%c",217);
    gotoxy(xi,ys);printf("%c",191);
    gotoxy(xs,yi);printf("%c",192);
}
void recuadro2(int xs, int ys, int xi, int yi){
    int cont;
    for(cont=xs;cont<=xi;cont++){
        gotoxy(cont, ys);printf("%c",205);
        gotoxy(cont, yi);printf("%c",205);
    }
    for(cont=ys;cont<=yi;cont++){
        gotoxy(xs, cont);printf("%c",186);
        gotoxy(xi, cont);printf("%c",186);
    }
    gotoxy(xs,ys);printf("%c",201);
    gotoxy(xi,yi);printf("%c",188);
    gotoxy(xi,ys);printf("%c",187);
    gotoxy(xs,yi);printf("%c",200);
}
void centrarTexto(char *texto, int y){
    int longitud=strlen(texto);
    gotoxy(40-(longitud/2),y);printf(texto);
}



//ESTRUCTURAS
typedef struct{
    float programacion;
    float matematicas;
    float logica;
    float tics;
    float promedio;
} ASIGNATURAS;
typedef struct{
    char nombre[20];
    char nombre2[20];
    char apellido[20];
    char apellido2[20];
    int docIdentidad;
    ASIGNATURAS asignaturas;
} ESTUDIANTE;
typedef struct{
    int numeroEstudiante;
    char fecha[11];
    char observaciones[52];
    ESTUDIANTE estudiantes;
} INFORME;
typedef enum{
    sinNota=-1
} NOTA;

//Variables Globales
INFORME informes[maxInformes];
int cantidadInformes=0;

//MENUS
void menuPrincipal(){
    printf("1. Estudiante\n");
    printf("2. Asignaturas y Notas\n");
    printf("3. Informes\n");
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
//MENU INFORMES
void menuInformes(){
    printf("1. Crear informes\n");
    printf("2. Ver informes\n");
    printf("3. Eliminar Informes\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuCrearInformes(){
    printf("1. Crear todos los informes (Sin observaciones)\n");
    printf("2. Crear un informe especifico\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuMostrarInformes(){
    printf("1. Ver todos los informes\n");
    printf("2. Ver un informe especifico\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}
void menuEliminarInformes(){
    printf("1. ELiminar todos los informes (CUIDADO)\n");
    printf("2. ELiminar un informe\n");
    printf("0. Volver atras\n\n");
    printf("Digite un opcion: ");
}



//FUNCIONES
void guardarEstudiantes(ESTUDIANTE *estudiantes, int cantidad){
    FILE *archivoEstudiantes = fopen("estudiantes.bat","wb");
    if (archivoEstudiantes == NULL){
        printf("Error al abrir el archivo.\n");
        return;
    }
    fwrite(estudiantes, sizeof(ESTUDIANTE), cantidad, archivoEstudiantes);
    fclose(archivoEstudiantes);
    printf("guardado correctamente.\n\n");
}
int leerArchivoEstudiantes(ESTUDIANTE *estudiantes){
    FILE *archivoEstudiantes = fopen("estudiantes.bat","rb");
    int cantidad = 0;
    if (archivoEstudiantes == NULL){
        printf("Error al abrir el archivo.\n");
        return 0;
    } 
    while(fread(&estudiantes[cantidad], sizeof(ESTUDIANTE), 1, archivoEstudiantes)){
        cantidad++;
    }
    
    fclose(archivoEstudiantes);
    printf("Se cargaron %d estudiantes desde el archivo.\n", cantidad);
    return cantidad;
}
void guardarInformes(){
    FILE *archivoInformes = fopen("informes.bat","wb");
    if (archivoInformes == NULL){
        printf("Error al abrir el archivo.\n");
        return;
    }
    fwrite(informes, sizeof(INFORME), cantidadInformes, archivoInformes);
    fclose(archivoInformes);
    printf("guardado correctamente.\n\n");
}
int leerInformes(){
    FILE *archivoInformes = fopen("informes.bat","rb");
    int cantidad = 0;
    if (archivoInformes == NULL){
        printf("Error al abrir el archivo.\n\n");
        return 0;
    } 
    while(fread(&informes[cantidad], sizeof(INFORME), 1, archivoInformes)){
        cantidad++;
    }
    fclose(archivoInformes);
    printf("Se cargaron %d informes desde el archivo.\n\n", cantidad);
    return cantidad;
}
void guardarInformesTXT(){
    const char *nombresMaterias[] = {
        "Programacion",
        "Matematicas",
        "Pensamiento Logico",
        "Introduccion a las TICS"
    };

    FILE *archivoInformes = fopen("informesTXT.txt", "w"); // modo escritura
    if (archivoInformes == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < cantidadInformes; i++) {
        fprintf(archivoInformes, "Informe #%d\n", i + 1);
        fprintf(archivoInformes, "Fecha: %s\n", informes[i].fecha);
        fprintf(archivoInformes, "Estudiante: %s %s %s %s\n",
                informes[i].estudiantes.nombre,
                informes[i].estudiantes.nombre2,
                informes[i].estudiantes.apellido,
                informes[i].estudiantes.apellido2);

        if (strlen(informes[i].observaciones) > 0)
            fprintf(archivoInformes, "Observaciones: %s\n", informes[i].observaciones);
        else
            fprintf(archivoInformes, "Observaciones: Ninguna\n");

        fprintf(archivoInformes, "Asignaturas y Notas:\n");

        float notas[] = {
            informes[i].estudiantes.asignaturas.programacion,
            informes[i].estudiantes.asignaturas.matematicas,
            informes[i].estudiantes.asignaturas.logica,
            informes[i].estudiantes.asignaturas.tics
        };

        for (int j = 0; j < 4; j++) {
            if (notas[j] == sinNota)
                fprintf(archivoInformes, "  - %s: Sin nota\n", nombresMaterias[j]);
            else
                fprintf(archivoInformes, "  - %s: %.1f\n", nombresMaterias[j], notas[j]);
        }

        fprintf(archivoInformes, "----------------------------\n\n");
    }

    fclose(archivoInformes);
    printf("Informes guardados correctamente en informesTXT.txt\n");
}

void limpiarBuffer() {
    int basura = getchar();
    while(basura != '\n' && basura != EOF){
        basura = getchar();
    }
}
float validarNotas(){
    char caracter;
    float nota;
    while(1){
        if(scanf("%f%c", &nota, &caracter) != 2 || caracter != '\n' || nota < 0 || nota > 5){
            printf("Nota invalida. Intente de nuevo: ");
            limpiarBuffer();
        }else{
            return nota;
        }
    }
}
void conNota(char *nombreAsignatura, float nota){
    if(nota == sinNota){
        printf("%s: Sin nota\n", nombreAsignatura);
    } else {
        printf("%s: %.1f\n", nombreAsignatura, nota);
    }
}
float obtenerNotas(ASIGNATURAS asignaturas, int indice) {
    switch(indice){
        case 1: return asignaturas.programacion;
        case 2: return asignaturas.matematicas;
        case 3: return asignaturas.logica;
        case 4: return asignaturas.tics;
        default: return -1;
    }
}
float sumarNotas(ASIGNATURAS asignaturas, int indice){
    float nota;
    if(indice > maxAsignaturas){
        return 0;

    }
    nota = obtenerNotas(asignaturas, indice); //Llamamos a obtener notas
    if(nota == -1){
        return sumarNotas(asignaturas, indice + 1); //Si es -1 (Sin nota) solo retornamos el indice + 1 y no operamos
    } else {
        return nota + sumarNotas(asignaturas, indice + 1); //En caso contrario devolvemos nota + recursiva de sumar notas y vuelve y empieza
    }
}
float calcularPromedio(ASIGNATURAS asignaturas) {
    int contador = 0;
    for(int cont = 1; cont <= maxAsignaturas; cont++){
        if(obtenerNotas(asignaturas, cont) != sinNota){
            contador++;
        }
    }

    if (contador == 0){
        return sinNota; // No hay notas
    }else{
        return sumarNotas(asignaturas, 1) / contador;
    }       
}
void leerLinea(char *texto, int tamano) {
    if(fgets(texto, tamano, stdin)){
        for(int cont=0; cont<tamano; cont++) {
            if(texto[cont]=='\n'){  
                texto[cont]='\0';     
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
                //Calculamos promedio
                asignaturas->promedio = calcularPromedio(*asignaturas);
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
                asignaturas->promedio = calcularPromedio(*asignaturas);
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
    if(asignaturas.promedio == sinNota){
        printf("Promedio: Sin promedio\n");
    } else {
        printf("Promedio: %.1f\n", asignaturas.promedio);
    }
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
                asignaturas->promedio = calcularPromedio(*asignaturas);
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
                    asignaturas->promedio = calcularPromedio(*asignaturas);
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
                asignaturas->promedio = calcularPromedio(*asignaturas);
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
                asignaturas->promedio = calcularPromedio(*asignaturas);
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
void crearEstudiante(ESTUDIANTE estudiantes[], int *cantidadEstudiantes){
    if (*cantidadEstudiantes >= maxEstudiantes) {
        printf("No se pueden agregar mas estudiantes.\n\n");
        return;
    }
    printf("Ingrese nombre del estudiante: ");
    leerLinea(estudiantes[*cantidadEstudiantes].nombre, sizeof(estudiantes[*cantidadEstudiantes].nombre));

    printf("Ingrese segundo nombre (Presione Enter si no tiene): ");
    leerLinea(estudiantes[*cantidadEstudiantes].nombre2, sizeof(estudiantes[*cantidadEstudiantes].nombre2));

    printf("Ingrese primer apellido del estudiante: ");
    leerLinea(estudiantes[*cantidadEstudiantes].apellido, sizeof(estudiantes[*cantidadEstudiantes].apellido));

    printf("Ingrese segundo apellido del estudiante: ");
    leerLinea(estudiantes[*cantidadEstudiantes].apellido2, sizeof(estudiantes[*cantidadEstudiantes].apellido2));

    printf("Ingrese documento de identidad del estudiante: ");
    scanf("%d", &estudiantes[*cantidadEstudiantes].docIdentidad);
    limpiarBuffer();


    // Inicializamos sinNota por defecto
    estudiantes[*cantidadEstudiantes].asignaturas.programacion = sinNota;
    estudiantes[*cantidadEstudiantes].asignaturas.matematicas = sinNota;
    estudiantes[*cantidadEstudiantes].asignaturas.logica = sinNota;
    estudiantes[*cantidadEstudiantes].asignaturas.tics = sinNota;

    (*cantidadEstudiantes)++;
    system("cls");
    printf("\nEstudiante creado y ");
}
void mostrarEstudiante(ESTUDIANTE estudiantes[], int cantidadEstudiantes){
    if(cantidadEstudiantes==0){
        printf("No hay estudiantes registrados.\n\n");
        return;
    }
    printf("Indice | %-*s | %-*s |\n", anchoNombreCompleto, "Nombre completo", anchoDocumento, "Documento"); 
    printf("------------------------------------------------------------------------------------------------\n");
    
    for(int cont=0; cont<cantidadEstudiantes; cont++){
        char nombreCompleto[anchoNombreCompleto+1];
        if(estudiantes[cont].nombre2[0] != '\0'){   //valida la primera posicon del vector, si hay o no caracteres
            snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s %s %s",estudiantes[cont].nombre,estudiantes[cont].nombre2,estudiantes[cont].apellido,estudiantes[cont].apellido2);
        }else{
            snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s %s", estudiantes[cont].nombre, estudiantes[cont].apellido, estudiantes[cont].apellido2);
        }
        printf("[%2d]   | %-*s | %-*d |\n", cont+1, anchoNombreCompleto, nombreCompleto, anchoDocumento, estudiantes[cont].docIdentidad);    
    }
    printf("\n");
}
void modificarEstudiante(ESTUDIANTE estudiantes[], int cantidadEstudiantes){
    int opcion=1, indice, salirModificar=0;
    if(cantidadEstudiantes==0){
        printf("No hay estudiantes registrados.\n\n");
        return;
    }
    while(!salirModificar){
        system("cls");
        mostrarEstudiante(estudiantes, cantidadEstudiantes);
        printf("Ingrese 0 para salir o\nIngrese el indice del estudiante a modificar (1 - %d): ", cantidadEstudiantes);
        scanf("%d", &indice);
        limpiarBuffer();
        if(indice==0) {
            salirModificar=1;
            system("cls");
            break;
        }
        while(indice<1 || indice>cantidadEstudiantes) {
            printf("Indice invalido o fuera de rango! (1 - %d): ", cantidadEstudiantes);
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
void eliminarEstudiante(ESTUDIANTE estudiantes[], int *cantidadEstudiantes){
    int eliminar;
    if(*cantidadEstudiantes==0){
        printf("No hay estudiantes para eliminar.\n\n");
        return;
    }
    while(1){
        system("cls");
        mostrarEstudiante(estudiantes, *cantidadEstudiantes);
        printf("\nIngrese el indice del estudiante que desea eliminar: ");
        scanf("%d", &eliminar);
        eliminar--;
        system("cls");
        if(eliminar>=0 && eliminar < *cantidadEstudiantes){
                for(int cont=eliminar; cont<*cantidadEstudiantes-1; cont++){
                    estudiantes[cont] = estudiantes[cont+1]; //reemplazar posicion actual del vector con la siguiente
                }
                (*cantidadEstudiantes)--;
                printf("Estudiante eliminado correctamente.\n");
                break;
            } else {
                printf("Posicion invalida! intentelo nuevamente.\n\n");
        }
    }  
}
//CRUD INFORMES
void crearInformes(ESTUDIANTE estudiantes[], int cantidadEstudiantes) {
    int opcion, indice;
    char observacion[52];
    char fecha[11];
    while (1) {
        system("cls");
        menuCrearInformes();
        scanf("%d", &opcion);
        limpiarBuffer();
        system("cls");
        if(opcion == 0){
            break;
        }
        switch(opcion){
            case 1: // Crear todos los informes
                printf("Ingrese la fecha del informe (dd/mm/aaaa): ");
                leerLinea(fecha, sizeof(fecha));
                for(int cont=0; cont<cantidadEstudiantes && cantidadInformes<maxInformes; cont++){
                    INFORME nuevo;
                    nuevo.numeroEstudiante = cont + 1;
                    nuevo.estudiantes = estudiantes[cont];
                    strcpy(nuevo.fecha, fecha);
                    informes[cantidadInformes++] = nuevo;
                    printf("Informe creado para %s %s.\n\n", estudiantes[cont].nombre, estudiantes[cont].apellido);
                }
                if(cantidadInformes >= maxInformes){
                    printf("Limite maximo de informes alcanzado.\n");
                }
                system("pause");
                break;
            case 2: // Crear uno específico
                system("cls");
                mostrarEstudiante(estudiantes, cantidadEstudiantes);
                printf("Ingrese el indice del estudiante (1 - %d): ", cantidadEstudiantes);
                scanf("%d", &indice);
                limpiarBuffer();

                while(indice < 1 || indice > cantidadEstudiantes){
                    printf("Indice invalido! Ingrese un numero entre 1 y %d: ", cantidadEstudiantes);
                    scanf("%d", &indice);
                    limpiarBuffer();
                }
                if(indice==0){
                    system("cls");
                    break;
                }
                if(cantidadInformes >= maxInformes){
                    printf("Limite maximo de informes alcanzado.\n");
                    system("pause");
                    break;
                }
                system("cls");
                INFORME nuevo;
                nuevo.numeroEstudiante = indice;
                printf("Fecha del informe (dd/mm/yyyy): ");
                leerLinea(fecha, sizeof(fecha));
                limpiarBuffer();
                strcpy(nuevo.fecha, fecha);
                printf("Observaciones(Presione Enter si no tiene): ");
                leerLinea(observacion, sizeof(observacion));
                strcpy(nuevo.observaciones, observacion);
                nuevo.estudiantes = estudiantes[indice - 1];
                informes[cantidadInformes++] = nuevo;
                system("cls");
                printf("Informe creado para %s %s.\n\n", estudiantes[indice - 1].nombre, estudiantes[indice - 1].apellido);
                system("pause");
                break;

            default:
                printf("La opcion no es valida!\n\n");
                system("pause");
        }
    }
}
void mostrarInformes(int indice){
    char nombreCompleto[39];
    int bordeIzquierdo=14, bordeDerecho=66;
    system("cls");
    recuadro(bordeIzquierdo,2,bordeDerecho,4);
    centrarTexto("INFORME NOTAS",3);
    //Apartado infromacion del estudiante
    if(informes[indice].estudiantes.nombre2[0] != '\0'){
        snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s %s %s",informes[indice].estudiantes.nombre, informes[indice].estudiantes.nombre2,informes[indice].estudiantes.apellido,informes[indice].estudiantes.apellido2);
    }else{
        snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s %s", informes[indice].estudiantes.nombre, informes[indice].estudiantes.apellido, informes[indice].estudiantes.apellido2);
    }
    recuadro(bordeIzquierdo,4,bordeDerecho,8);
    gotoxy(bordeIzquierdo+2,5);printf("Estudiante: %s", nombreCompleto);
    gotoxy(bordeIzquierdo+2,6);printf("Grupo: 402");
    gotoxy(bordeIzquierdo+2,7);printf("Fecha informe: %s",informes[indice].fecha);
    //Apartado asignatura y nota final
    recuadro(bordeIzquierdo,8,bordeDerecho,10);
    gotoxy(bordeIzquierdo+2,9);printf("ASIGNATURA: ");
    recuadro(40,8,bordeDerecho,15);gotoxy(42,9);printf("NOTA FINAL: ");
    //Apartado 
    recuadro(bordeIzquierdo,10,bordeDerecho,15);
    gotoxy(bordeIzquierdo+2,11);printf("Programacion"); gotoxy(42,11);notaInforme(informes[indice].estudiantes.asignaturas.programacion);
    gotoxy(bordeIzquierdo+2,12);printf("Matematicas"); gotoxy(42,12);notaInforme(informes[indice].estudiantes.asignaturas.matematicas);
    gotoxy(bordeIzquierdo+2,13);printf("Pensamiento Logico"); gotoxy(42,13);notaInforme(informes[indice].estudiantes.asignaturas.logica);
    gotoxy(bordeIzquierdo+2,14);printf("Introduccion a las TICS"); gotoxy(42,14);notaInforme(informes[indice].estudiantes.asignaturas.tics);
    //Apartado promedio
    recuadro(bordeIzquierdo,15,40,17);
    recuadro(40,15,bordeDerecho,17);
    gotoxy(bordeIzquierdo+2,16);printf("Promedio general"); gotoxy(42,16);notaInforme(informes[indice].estudiantes.asignaturas.promedio);
    //Observaciones
    recuadro(bordeIzquierdo,17,bordeDerecho,22);
    gotoxy(bordeIzquierdo+2,18);printf("Observaciones: ");
    gotoxy(bordeIzquierdo+2,19);printf("%s", informes[indice].observaciones);
    //Bordes
    recuadro2(bordeIzquierdo,2,bordeDerecho,22);
    gotoxy(bordeIzquierdo,8);printf("%c",186);
    gotoxy(40,8);printf("%c",194);
    gotoxy(40,10);printf("%c",197); 
    gotoxy(40,15);printf("%c",197); 
    gotoxy(40,17);printf("%c",193);
    gotoxy(1,24);system("pause");
}
void eliminarInformes(){
    int opcion, indice;
    while(1){
        system("cls");
        menuEliminarInformes();
        scanf("%d", &opcion);
        limpiarBuffer();
        switch (opcion) {
            case 1: // Eliminar todos
                if(cantidadInformes == 0){
                    system("cls");
                    printf("\nNo hay informes para eliminar.\n\n");
                    system("pause");
                }else{
                    cantidadInformes=0;
                    system("cls");
                    printf("\nTodos los informes han sido eliminados...\n\n");
                    system("pause");
                }
                break;

            case 2: // Eliminar uno
                if(cantidadInformes == 0){
                    system("cls");
                    printf("\nNo hay informes para eliminar.\n\n");
                    system("pause");
                    break;
                }
                system("cls");
                printf("\nHay %d informes creados:\n", cantidadInformes);
                for(int cont=0; cont<cantidadInformes; cont++){
                    printf("%d. Informe #%d - %s %s\n", cont+1, cont+1, informes[cont].estudiantes.nombre, informes[cont].estudiantes.apellido);
                }
                printf("\nSeleccione el informe a eliminar (1 - %d): ", cantidadInformes);
                scanf("%d", &indice);
                limpiarBuffer();
                if(indice < 1 || indice > cantidadInformes){
                    printf("indice invalido!\n");
                }else{
                    for(int cont=indice-1; cont<cantidadInformes-1; cont++){
                        informes[cont] = informes[cont + 1];
                    }
                    cantidadInformes--;
                    system("cls");
                    printf("\nInforme eliminado correctamente...\n\n");
                    system("pause");
                }
                break;
            case 0:
                system("cls");
                return;
            default:
                printf("La opcion no es valida!\n\n");
                system("pause");
                break;
        }
    }
}
//MAIN
int main(){
    system("cls");
    system("mode con: cols=80 lines=25");
    int opcion1=1,opcion2,opcion3,opcion4, opcionEstudiante, salirNotas, opcionInformes;
    ESTUDIANTE estudiantes[maxEstudiantes]; 
    int cantidadEstudiantes = leerArchivoEstudiantes(estudiantes);
    cantidadInformes=leerInformes(); // Numero actual de estudiantes guardados
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
                            crearEstudiante(estudiantes, &cantidadEstudiantes); 
                            guardarEstudiantes(estudiantes, cantidadEstudiantes);
                            break;
                        case 2:
                            mostrarEstudiante(estudiantes, cantidadEstudiantes);
                            system("pause");
                            system("cls");
                            break;
                        case 3: 
                            modificarEstudiante(estudiantes, cantidadEstudiantes); 
                            guardarEstudiantes(estudiantes, cantidadEstudiantes);
                            break;
                        case 4: 
                            eliminarEstudiante(estudiantes, &cantidadEstudiantes);
                            guardarEstudiantes(estudiantes, cantidadEstudiantes);
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
                if(cantidadEstudiantes==0){
                printf("Primero debes crear estudiantes.\n\n");
                break;
                }
                while(!salirNotas){
                    system("cls");
                    mostrarEstudiante(estudiantes, cantidadEstudiantes);
                    printf("Ingrese 0 para volver al menu principal o\nSeleccione un estudiante (1 - %d): ", cantidadEstudiantes);
                    scanf("%d", &opcionEstudiante);
                    limpiarBuffer();
                    if(opcionEstudiante==0){
                        salirNotas = 1;
                        system("cls");
                        break;
                    }  
                    while (opcionEstudiante < 1 || opcionEstudiante > cantidadEstudiantes){
                        printf("Indice invalido. Ingrese un valor entre 1 y %d: ", cantidadEstudiantes);
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
                                guardarEstudiantes(estudiantes, cantidadEstudiantes);
                                break;
                            case 2: 
                                mostrarNotas(estudiantes[opcionEstudiante-1].asignaturas);
                                system("pause");
                                system("cls");
                                break;
                            case 3: 
                                modificarNotas(&estudiantes[opcionEstudiante-1].asignaturas);
                                guardarEstudiantes(estudiantes, cantidadEstudiantes);
                                break;
                            case 4: 
                                eliminarNotas(&estudiantes[opcionEstudiante-1].asignaturas);
                                guardarEstudiantes(estudiantes, cantidadEstudiantes);
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
            case 3:
                system("cls");
                opcion4=1;
                while(opcion4!=0){
                    menuInformes();
                    scanf("%d", &opcion4);
                    limpiarBuffer();
                    system("cls");
                    switch (opcion4){
                        case 1: 
                            crearInformes(estudiantes, cantidadEstudiantes);
                            guardarInformes();
                            guardarInformesTXT();
                            break;
                        case 2:
                            if (cantidadInformes == 0) {
                                printf("No hay informes creados.\n");
                                system("pause");
                                system("cls");
                                break;
                            }
                            opcionInformes=1;
                            menuMostrarInformes();
                            scanf("%d", &opcionInformes);
                            limpiarBuffer();
                            system("cls");
                            switch(opcionInformes){
                                case 1:  // Mostrar todos los informes
                                    for (int cont = 0; cont < cantidadInformes; cont++) {
                                        system("cls");
                                        mostrarInformes(cont);
                                    }
                                    system("cls");
                                    break;
                                case 2:  // Mostrar un informe específico
                                    int indiceInforme;
                                    system("cls");
                                    printf("\nHay %d informes creados:\n", cantidadInformes);
                                    for(int cont=0; cont<cantidadInformes; cont++){
                                        printf("%d. Informe #%d - %s %s\n", cont+1, cont+1, informes[cont].estudiantes.nombre, informes[cont].estudiantes.apellido);
                                    }
                                    printf("\nIngrese el numero del informe (1 - %d): ", cantidadInformes);
                                    scanf("%d", &indiceInforme);
                                    limpiarBuffer();
                                    while (indiceInforme < 1 || indiceInforme > cantidadInformes) {
                                        printf("Numero invalido! Ingrese un numero entre 1 y %d: ", cantidadInformes);
                                        scanf("%d", &indiceInforme);
                                        limpiarBuffer();
                                    }
                                    system("cls");
                                    mostrarInformes(indiceInforme - 1);
                                    system("cls");
                                    break;
                                case 0:
                                    break;
                                default:
                                    printf("La opcion no es valida!\n");
                                    break;
                            }
                            break;
                        case 3:
                            eliminarInformes();
                            guardarInformes();
                            break;
                        case 0: 
                            break;
                        default:
                            printf("La opcion no es valida!\n\n"); 
                            break;
                    }
                }
                break;  
            case 0: printf("\nHas salido del programa, Adios!"); break;
            default: printf("La opcion no es valida!\n\n"); break;
        }
    }
    return 0; 
}

/*git add .
git commit -m "Agrego archivos .c"
git push origin main*/