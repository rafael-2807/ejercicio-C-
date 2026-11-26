#include <iostream>
using namespace std;

int main() {
    int numeros[10];
    int cont = 0;

    
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el numero " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    
    int mayor = numeros[0];
    int menor = numeros[0];

   
    for (int i = 0; i < 10; i++) {
        if (numeros[i] == 5) {
            cont++;
        }
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    
    cout << "\nCantidad de veces que se repite el 5: " << cont << endl;
    cout << "Numero mayor: " << mayor << endl;
    cout << "Numero menor: " << menor << endl;

    return 0;
}