/* realice un programa que permita simular una ruleta de opciones y que el usuario pueda elegir entre dos opciones, tres,4 o 10.
todas las opciones deben ser ingresadas y validadas por teclado, las opciones pueden ser palabras, numeros o simbolos especiales.
no puede usar funciones, estructuras, arreglos bidimencionales, punteros o listas. una vez listo su ejercicio, subalo a su repositorio
con una pequeña descripcion
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Códigos ANSI para colores y estilos en la terminal
#define RESET     "\033[0m"
#define NEGRITA   "\033[1m"
#define CYAN      "\033[36m"
#define VERDE     "\033[32m"
#define AMARILLO  "\033[33m"
#define MAGENTA   "\033[35m"
#define ROJO      "\033[31m"
#define FONDO_AZUL "\033[44m"

int main() {
    // Inicializar la semilla aleatoria
    srand(time(0));

    int numOpciones = 0;

    // --- ENCABEZADO Y VALIDACIÓN CENTRADOS ---
    do {
        cout << CYAN << "\n            ========================================================" << RESET << endl;
        cout << NEGRITA << MAGENTA << "                      * * *  SIMULADOR DE RULETA  * * *             " << RESET << endl;
        cout << CYAN << "            ========================================================" << RESET << endl;
        cout << AMARILLO << "        Ingrese la cantidad de opciones (2, 3, 4 ... hasta 10): " << RESET;
        cin >> numOpciones;

        if (numOpciones < 2 || numOpciones > 10) {
            cout << ROJO << "\n        [Error] Cantidad no valida. Ingrese un numero entre 2 y 10.\n" << RESET;
        }
    } while (numOpciones < 2 || numOpciones > 10);

    // Arreglo unidimensional estrictamente permitido
    string opciones[10];

    cout << CYAN << "\n            --------------------------------------------------------" << RESET << endl;
    cout << NEGRITA << VERDE << "                     INGRESO Y VALIDACION DE OPCIONES               " << RESET << endl;
    cout << CYAN << "            --------------------------------------------------------" << RESET << endl;
    
    for (int i = 0; i < numOpciones; i++) {
        bool opcionValida = false;
        do {
            cout << "            Opcion " << (i + 1) << " (palabra, numero o simbolo): ";
            cin >> opciones[i];

            if (opciones[i].length() > 0) {
                opcionValida = true;
            } else {
                cout << ROJO << "            [Error] La opcion no puede estar vacia. Intente de nuevo.\n" << RESET;
            }
        } while (!opcionValida);
    }

    // --- ANIMACIÓN DE GIRO Y SELECCIÓN ---
    int indiceGanador = rand() % numOpciones;

    cout << CYAN << "\n            ========================================================" << RESET << endl;
    cout << NEGRITA << FONDO_AZUL << "                         GIRANDO LA RULETA...                         " << RESET << endl;
    cout << CYAN << "            ========================================================" << RESET << endl;

    // Mostrar opciones registradas centradas
    cout << AMARILLO << "\n            Opciones participantes en la ruleta:" << RESET << endl;
    for (int i = 0; i < numOpciones; i++) {
        cout << "                [" << (i + 1) << "] --> " << VERDE << opciones[i] << RESET << endl;
    }

    // --- RESULTADO DESTACADO CENTRADO ---
    cout << CYAN << "\n            ========================================================" << RESET << endl;
    cout << NEGRITA << VERDE << "                 ¡EL RESULTADO GANADOR DE LA RULETA ES:             " << RESET << endl;
    cout << NEGRITA << AMARILLO << "                    *** [ " << opciones[indiceGanador] << " ] ***                    " << RESET << endl;
    cout << CYAN << "            ========================================================" << RESET << endl;

    return 0;
}
