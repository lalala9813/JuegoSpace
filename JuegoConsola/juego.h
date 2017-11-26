#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

class Vista
{
    public:
        void gotoxy(int x, int y);
        void OcultarCursor();
        void color(int X);
        void bordes();
};
//*********************************************************************************************************************************************************
class Modelo
{
    public:
    class Nave
{
    private:
        int x,y;
        int corazones;
        int vidas;
    public:
        Nave(int _x, int _y, int _corazones, int _vidas); //CONSTRUCTOR
        ~Nave();//Destructor
        Vista v1;
        int X();/*Metodos para acceder a la coordenada X*/
        int Y();/*Metodos para acceder a la coordenada Y*/
        int VID();
        void COR();/*Funcion que hace que corazones disminuya */
        void dibujar();
        void borrar();
        void volar();
        void pintarcorazones();
        void morir();
};
//*********************************************************************************************************************************************************
class Ast
{
    private:
        int x,y;
    public:
        Ast(int _x, int _y);
        ~Ast();
        Vista v2;
        void pintar();
        void mover();
        /*Detecta la coordenada de cada uno de los asterorides con la nave de acuerdo a la posicion*/
        void choque(class Nave &nave);/*Se pasa por referencia porque se van a estar modificando los valores*/
        /* Le pasamos un objeto para acceder a sus metodos*/
};
};
//*********************************************************************************************************************************************************


#endif // JUEGO_H_INCLUDED
