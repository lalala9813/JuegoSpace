#include "juego.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

using namespace std;
//*********************************************************************************************************************************************************
void Vista::gotoxy(int x, int y)
{
    HANDLE hCon;  //Creando un identificador
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //Recuperar el identificador de la consola
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void Vista::OcultarCursor()
{
    HANDLE hCon;  //Creando un identificador
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //Recuperar el identificador de la consola
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}

void Vista::color(int X)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

void Vista::bordes()
{
    for(int i = 2; i<79 ; i++)
    {
        gotoxy(i,3); cout << (char)178;
        gotoxy(i,34); cout << (char)178;
    }

    for(int i = 4; i<34 ; i++)
    {
        gotoxy(2,i); cout << (char)186;
        gotoxy(78,i); cout << (char)186;
    }

    gotoxy(2,3); cout << (char)201;
    gotoxy(2,34); cout << (char)200;
    gotoxy(78,3); cout << (char)187;
    gotoxy(78,34); cout << (char)188;
}

//*********************************************************************************************************************************************************
Modelo::Nave::Nave(int _x, int _y, int _corazones, int _vidas)
{
        x = _x;
        y = _y;
        corazones = _corazones;
        vidas = _vidas;
}

int Modelo::Nave::X()
{
    return x;
}/*Metodos para acceder a la coordenada X*/

int Modelo::Nave::Y()
{
    return y;
}

int Modelo::Nave::VID()
{
    return vidas;
}

void Modelo::Nave::COR()
{
    corazones--;
}

void Modelo::Nave::dibujar()
{

    v1.color(13);
    v1.gotoxy(x,y);   cout << "  " << (char)30 << "  ";
    v1.gotoxy(x,y+1); cout << " " << (char)4 << (char)169 << (char)4 <<" ";
    v1.gotoxy(x,y+2); cout << (char)17 << (char)201 << " " << (char)187 << (char)16;
}

void Modelo::Nave::borrar()
{
    v1.gotoxy(x,y);   cout << "     ";
    v1.gotoxy(x,y+1); cout << "     ";
    v1.gotoxy(x,y+2); cout << "     ";
}

void Modelo::Nave::volar()
{
     if (_kbhit())//Revisa si una tecla pulsada está disponible
     {
        int velocidad = 3;
        char tecla = getch();
        borrar();
        if(tecla == IZQUIERDA && x > 4) x-= velocidad;
        if(tecla == DERECHA && x+5 < 76) x += velocidad;
        if(tecla == ARRIBA && y > 6) y -= velocidad;
        if(tecla == ABAJO && y+3 < 32) y += velocidad;
        pintarcorazones();

     }

    dibujar();
}

void Modelo::Nave::pintarcorazones()
{
    v1.color(14);
    v1.gotoxy(50,2); cout << "VIDAS -> " << vidas;
    v1.gotoxy(64,2); cout << "SALUD";
    v1.gotoxy(70,2); cout << "      ";
    for(int i = 0; i<corazones; i++)
    {

        v1.color(12);
        v1.gotoxy(70+i,2); cout << (char)3;
    }
}


void Modelo::Nave::morir()
{
    if(corazones == 0)
    {
        v1.color(12);
        borrar();
        v1.gotoxy(x,y);   cout << "  **  ";
        v1.gotoxy(x,y+1); cout << " **** ";
        v1.gotoxy(x,y+2); cout << "  **  ";
        Sleep(300);

        v1.color(14);
        borrar();
        v1.gotoxy(x,y);   cout << "  **  ";
        v1.gotoxy(x,y+1); cout << " **** ";
        v1.gotoxy(x,y+2); cout << "  **  ";
        Sleep(200);

        borrar();
        Modelo::Nave::vidas--;
        corazones = 3;
        pintarcorazones();
        dibujar();
    }

}

Modelo::Nave::~Nave(){}
//*********************************************************************************************************************************************************
Modelo::Ast::Ast(int _x, int _y)
{
    x = _x;
    y = _y;
}

//Destrucutor
Modelo::Ast::~Ast(){}

void Modelo::Ast::pintar()
{
    v2.color(11);
    v2.gotoxy(x,y); cout << (char)201 << (char)2 << (char)187 ;
}

void Modelo::Ast::mover()
{
    v2.gotoxy(x,y); cout << "   ";
    int velocidad = 2;
    y+= velocidad;
    if(y > 32)
    {
        x = rand()%71 + 4;//numero entre 0 + 4 y 71 + 4
        y = 4;
    }
    pintar();
}

void Modelo::Ast::choque(class Nave &nave)
{
    if(x >= nave.X()/*mas a la izquierda*/ && x < nave.X()+5/*mas a la derecha*/ && y >= nave.Y()/*mas arriba*/ && y <= nave.Y()+2/*mas abajo*/)
    {
        nave.COR();
        nave.dibujar();
        nave.pintarcorazones();
        x = rand()%71 + 4;//numero entre 0 + 4 y 71 + 4
        y = 4;

    }
}
using namespace std;
