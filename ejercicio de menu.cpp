/* realice un programa que permita realizar las siguientes operaciones con dos valores: suma, resta, multiplicacion, division
, calculo de la raiz cuadrada, la potencia al cuadrado y potencia al cubo.
el programa debe permitir al usuario ejecutar mas de una operacion si lo desea
*/
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main (){
	int opcion;
	float numero1,numero2,resultado;
	char controlBucle;
	
	do{
	cout<<"ingrese el valor: "; cin>>numero1;
	cout<<"ingrese el valor: "; cin>>numero2;
	
	
			cout<<"\n----------menu----------\n";
		cout<<"\n1. suma";
		cout<<"\n2. resta";
		cout<<"\n3. multiplicacion";
		cout<<"\n4. division";
		cout<<"\n5. raiz cuadrada";
		cout<<"\n6. potencia al cuadrado";
		cout<<"\n7. potencia al cubo\n";
		cin>>opcion;
	
	switch (opcion){

		
		
		case 1:
		resultado=numero1+numero2;
		cout<<"\nel resultado es:"<<resultado;
		break;
		
		case 2:
		resultado=numero1-numero2;
		cout<<"\nel resultado es:"<<resultado;
		break;
		
		case 3:
		resultado=numero1*numero2;
		cout<<"\nel resultado es:"<<resultado;
		break;
		
		case 4:
		resultado=numero1/numero2;
		cout<<"\nel resultado es:"<<resultado;
		break;
		
		case 5:
		resultado= sqrt (numero1);
		cout<<"\nel resultado es:"<<resultado;
		break;
		
		case 6:
		resultado= numero1*numero1;
		cout<<"\nel resultado es:"<<resultado;
		break;
		
		case 7:
		resultado= numero1*numero1*numero1;
		cout<<"\nel resultado es:"<<resultado;
		break;
	}
	
	cout<<"\ndesea continuar con las operacion (s/n)"<<endl;
	controlBucle = getch();
	
	}while(controlBucle=='s' || controlBucle=='S');
	
	
	
	return 0;
}
