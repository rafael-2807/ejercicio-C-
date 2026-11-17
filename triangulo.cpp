/*realice un programa que  permita al usuario ingresar los lados de un triangulo
y que automaticamente se muestre en pantalla que tipo de triangulo es, su area y 
previamente si es un triangulo, debe usar funciones para el calculo del area, la 
identicacion del triangulo y la validacion de la entrada por teclado, elprograma debe
permitir que se repita la ejecucion si es el usuario lo desea*/
#include <iostream>
#include <cmath>

using namespace std;

// Función para calcular el área usando la fórmula de Herón
float AreaTriangulo(float x, float y, float z) {
    float s = (x + y + z) / 2.0;
    return sqrt(s * (s - x) * (s - y) * (s - z));
}

int main() {
    float a, b, c, resultado;
    char continuar; // Variable para almacenar la respuesta del usuario

    do {
        cout << "\n--- CALCULADORA DE TRIANGULOS ---\n";
        cout << "Ingrese el lado a: "; cin >> a;
        cout << "Ingrese el lado b: "; cin >> b;
        cout << "Ingrese el lado c: "; cin >> c;

        // Validar que los valores sean positivos
        if (a <= 0 || b <= 0 || c <= 0) {
            cout << "\nError: Ingrese valores positivos mayores a cero.\n";
        } else {
            // Validar la desigualdad triangular
            if ((a + b > c) && (b + c > a) && (c + a > b)) {
                cout << "\nEs un triangulo valido.\n";
                
                // Calcular y mostrar área
                resultado = AreaTriangulo(a, b, c);
                cout << "El area del triangulo es: " << resultado << "\n";
                
                // Clasificar el triángulo
                if (a == b && b == c) {
                    cout << "El triangulo es equilatero.\n";
                } else if (a == b || b == c || a == c) {
                    cout << "El triangulo es isosceles.\n";
                } else {
                    cout << "El triangulo es escaleno.\n";
                }
                
            } else {
                cout << "\nNo es un triangulo valido (no cumple con la desigualdad).\n";
            }
        }

        // Preguntar si desea continuar
        cout << "\n¿Desea ingresar otro triangulo? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nPrograma finalizado. ¡Hasta luego!\n";

    return 0;
}
