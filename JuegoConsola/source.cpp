#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include "juego.h"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

using namespace std;



int main()
{
    sf::Music music;
    if (!music.openFromFile("msc.ogg"))
    return -1;
    music.play();

    Vista v;
    v.OcultarCursor();
    v.color(10);
    v.bordes();
    Modelo::Nave n(37,30,3,3);
    n.dibujar();
    n.pintarcorazones();
    int puntos = 0;
    string nombre;

    Modelo::Ast a(10,4), a2(20,8), a3(50,6), a4(70,5), a5(30,5);

    bool finJuego = false;
    while(!finJuego)
    {

        v.color(14);
        v.gotoxy(3,2);
        puntos += 1;
        cout << "PUNTAJE --> " << puntos;

        a.mover();
        a.choque(n);
        a2.mover();
        a2.choque(n);
        a3.mover();
        a3.choque(n);
        a4.mover();
        a4.choque(n);
        a5.mover();
        a5.choque(n);


        if(n.VID() == 0)
        {
            finJuego = true;
            puntos +=0;
            system("cls");
            music.pause();
            cout <<  "\n\n" <<"Tu nombre --> ";
            cin >> nombre;
            //Crenado archivo para guardar puntajes
            ofstream puntajes;
            puntajes.open("puntajes.txt",ios::app);//Abriendo el archivo
            puntajes << "\n" <<nombre << " -------> " << puntos;
            puntajes.close();//Cerrando el archivo
        }

        n.morir();
        n.volar();
        Sleep(30);
    }
    system("cls");
    system("color 0A");
    v.gotoxy(32,2);
    cout << nombre << " " << puntos << "\n\n";

    v.gotoxy(20,4);
    cout << "PERDISTE HERMANO SUERTE A LA PROXIMA \n";
    v.gotoxy(20,5);
    cout << "PERDISTE HERMANO SUERTE A LA PROXIMA \n";
    v.gotoxy(20,6);
    cout << "PERDISTE HERMANO SUERTE A LA PROXIMA \n";
    v.gotoxy(20,7);
    cout << "PERDISTE HERMANO SUERTE A LA PROXIMA \n";
    v.gotoxy(20,8);
    cout << "PERDISTE HERMANO SUERTE A LA PROXIMA \n";
    return 0;
}


