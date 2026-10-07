/*realice un programa que permita recibir un numero por teclado entre (100 y 999 y lo devuelva invertido, ademas diga si el numero es 
capicua). */
#include <iostream>
using namespace std;
int main (){
    int numero1, numero2, invertido=0, resto;
    
    cout<<"ingrese el numero: "; cin>>numero1;
    	numero2=numero1;
    if (numero1>=100 && numero1<=999){
    	while (numero1 != 0){
    		resto=numero1 % 10;
    		invertido= (invertido * 10) + resto;
    		numero1= numero1/10;
		}
		cout<<"\nel invertido es:"<<invertido;
		
	
		if (numero2==invertido){
		cout<<"\nel numero ingresado es capicua";
		} else {
		cout<<"\nel numero no es capicuao";
		}
	} else {
		cout<<"\nel numero debe estar entre 100 y 999";
	}
	
    return 0;
}
