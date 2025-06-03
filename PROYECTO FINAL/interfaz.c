#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

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
void main(){
    int bordeIzquierdo=14, bordeDerecho=66;
    system("cls");
    system("mode con: cols=80 lines=25");
    recuadro(0,0,79,24);
    recuadro(bordeIzquierdo,2,bordeDerecho,4);
    centrarTexto("INFORME NOTAS",3);
    //Apartado infromacion del estudiante
    recuadro(bordeIzquierdo,4,bordeDerecho,8);
    gotoxy(bordeIzquierdo+2,5);printf("Estudiante: Cristian Gomez Arenas");
    gotoxy(bordeIzquierdo+2,6);printf("Grupo: 402");
    gotoxy(bordeIzquierdo+2,7);printf("Fecha informe: 2/06/2025 ");
    //Apartado asignatura y nota final
    recuadro(bordeIzquierdo,8,bordeDerecho,10);
    gotoxy(bordeIzquierdo+2,9);printf("ASIGNATURA: ");
    recuadro(40,8,bordeDerecho,15);gotoxy(42,9);printf("NOTA FINAL: ");
    //Apartado 
    recuadro(bordeIzquierdo,10,bordeDerecho,15);
    gotoxy(bordeIzquierdo+2,11);printf("Programacion"); gotoxy(42,11);printf("nota...");
    gotoxy(bordeIzquierdo+2,12);printf("Matematicas"); gotoxy(42,12);printf("nota...");
    gotoxy(bordeIzquierdo+2,13);printf("Pensamiento Logico"); gotoxy(42,13);printf("nota...");
    gotoxy(bordeIzquierdo+2,14);printf("Introduccion a las TICS"); gotoxy(42,14);printf("nota...");
    //Apartado promedio
    recuadro(bordeIzquierdo,15,40,17);
    recuadro(40,15,bordeDerecho,17);
    gotoxy(bordeIzquierdo+2,16);printf("Promedio general"); gotoxy(42,16);printf("promedio...");
    //Observaciones
    recuadro(bordeIzquierdo,17,bordeDerecho,22);
    gotoxy(bordeIzquierdo+2,18);printf("Observaciones: ");
    //Bordes
    recuadro2(bordeIzquierdo,2,bordeDerecho,22);
    gotoxy(bordeIzquierdo,8);printf("%c",186);
    gotoxy(40,8);printf("%c",194); // ┬
    gotoxy(40,10);printf("%c",197); // ┼
    gotoxy(40,15);printf("%c",197); // ┼
    gotoxy(40,17);printf("%c",193); // ┴
    gotoxy(1,23);system("pause");
}