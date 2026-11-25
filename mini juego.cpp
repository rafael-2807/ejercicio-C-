/* partiendo del codigo entregado en clase, completelo para crear un mini juego con un personaje que puede un caracter de su eleccion
que se mueva dentro del marco creado y que si choca con los bordes o los obstaculos, se muestre en pantalla "perdiste" por lo contrario, si llega
a la meta, que diga "ganaste", la meta debe estar randomizada, es decir en cada intento debe estar en una posicion diferente y debe haber como minimo
3 obstaculos 
*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = static_cast<SHORT>(x);
    coord.Y = static_cast<SHORT>(y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
}

void ocultarCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {
    const int Ancho = 50, Alto = 25;
    const int Esc = 27;
    const char PERSONAJE = '@';
    const char OBSTACULO = 'X';
    const char META = 'M';

    // Códigos de color de consola Windows
    const int COLOR_MARCO = 11;     // Cian brillante
    const int COLOR_OBSTACULO = 12; // Rojo brillante
    const int COLOR_META = 10;      // Verde brillante
    const int COLOR_PERSONAJE = 14; // Amarillo brillante
    const int COLOR_TEXTO = 15;     // Blanco brillante

    srand(static_cast<unsigned int>(time(0)));   
    ocultarCursor();

    int x = Ancho / 2, y = Alto / 2;
    int nx = x, ny = y;
    int tecla = 0;

    // Al menos 3 obstáculos (aquí usamos 4) dentro del marco
    const int numObstaculos = 4;
    int obsX[numObstaculos] = {12, 36, 18, 30};
    int obsY[numObstaculos] = {7, 17, 16, 8};

    // Generar posición aleatoria para la meta sin pisar inicio ni obstáculos
    int metaX = 0, metaY = 0;
    bool posicionValida = false;
    while (!posicionValida) {
        metaX = 1 + rand() % (Ancho - 2);
        metaY = 1 + rand() % (Alto - 2);

        posicionValida = !(metaX == x && metaY == y);
        for (int j = 0; j < numObstaculos && posicionValida; j++) {
            if (metaX == obsX[j] && metaY == obsY[j]) {
                posicionValida = false;
            }
        }
    }

    // Dibujar borde superior e inferior con color
    setColor(COLOR_MARCO);
    for (int i = 0; i < Ancho; i++) {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, Alto - 1);
        cout << "#";
    }

    // Dibujar borde izquierdo y derecho con color
    for (int i = 1; i < Alto - 1; i++) {
        gotoxy(0, i);
        cout << "#";
        gotoxy(Ancho - 1, i);
        cout << "#";
    }

    // Dibujar obstáculos con color
    setColor(COLOR_OBSTACULO);
    for (int j = 0; j < numObstaculos; j++) {
        gotoxy(obsX[j], obsY[j]);
        cout << OBSTACULO;
    }

    // Dibujar meta con color
    setColor(COLOR_META);
    gotoxy(metaX, metaY);
    cout << META;

    // Dibujar personaje inicial con color
    setColor(COLOR_PERSONAJE);
    gotoxy(x, y);
    cout << PERSONAJE;

    setColor(COLOR_TEXTO);
    gotoxy(0, Alto + 1);
    cout << "Controles: WASD o Flechas para moverte | ESC para salir";

    bool juegoTerminado = false;
    bool gano = false;

    while (!juegoTerminado) {
        tecla = _getch();

        // Las teclas de flecha en conio.h envían un prefijo (0 o 224) seguido del código
        if (tecla == 0 || tecla == 224) {
            tecla = _getch();
            if (tecla == 72) tecla = 'w';
            else if (tecla == 80) tecla = 's';
            else if (tecla == 75) tecla = 'a';
            else if (tecla == 77) tecla = 'd';
        }

        if (tecla == Esc) {
            break;
        }

        nx = x;
        ny = y;

        if (tecla == 'w' || tecla == 'W') ny--;
        else if (tecla == 's' || tecla == 'S') ny++;
        else if (tecla == 'a' || tecla == 'A') nx--;
        else if (tecla == 'd' || tecla == 'D') nx++;
        else continue;

        // Verificar choque con bordes
        if (nx <= 0 || nx >= Ancho - 1 || ny <= 0 || ny >= Alto - 1) {
            gano = false;
            juegoTerminado = true;
            break;
        }

        // Verificar choque con obstáculos
        for (int j = 0; j < numObstaculos; j++) {
            if (nx == obsX[j] && ny == obsY[j]) {
                gano = false;
                juegoTerminado = true;
                break;
            }
        }
        if (juegoTerminado) break;

        // Borrar posición anterior y mover personaje con color
        setColor(COLOR_TEXTO);
        gotoxy(x, y);
        cout << " ";

        x = nx;
        y = ny;

        setColor(COLOR_PERSONAJE);
        gotoxy(x, y);
        cout << PERSONAJE;

        // Verificar si llegó a la meta
        if (x == metaX && y == metaY) {
            gano = true;
            juegoTerminado = true;
        }
    }

    gotoxy(0, Alto + 3);
    if (juegoTerminado) {
        if (gano) {
            setColor(COLOR_META);
            cout << "ganaste" << endl;
        } else {
            setColor(COLOR_OBSTACULO);
            cout << "perdiste" << endl;
        }
    }

    setColor(COLOR_TEXTO);
    return 0;
}
