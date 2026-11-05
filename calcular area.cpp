/* realice un programa que permita calcular el area de un circulo, un cuadrado, un rectangulo y un tirangulo equilatero,
procure usar al menos tres sequencias de escape para dar formato a sus mensajes, considere que su menu de opciones
sea facil de entender y agradable a la vista
*/
#include <iostream>
using namespace std;
float AreaRectangulo (float x, float y){
	return x * y;
}
int main (){
	int radio ,longitud,base,altura,opcion,numero;
	float area, pi=3.14;
	
	cout<<"\n----------menu----------\n";
	cout<<"seleccione una de las opciones mostradas:";
	cout<<"\n1. area de un circulo";
	cout<<"\n2. area de un cuadrado";
	cout<<"\n3. area de un rectangulo";
	cout<<"\n4. area de un triangulo equilatero\n";
	cin>>opcion;
	
	switch (opcion){
		case 1:
		cout<<"ingrese el radio:"; cin>>radio;
		area= pi * (radio*radio);
		cout<<"\nel area es:"<<area;
		break;
		
		case 2:
		cout<<"\ningrese la longitud:"; cin>>longitud;	
		area= longitud*longitud;
		cout<<"\nel area es:"<<area;
		break;
		
		case 3:
		cout<<"\ningrese la base:"; cin>>base;
		cout<<"\ningrse la altura:"; cin>>altura;
		area= AreaRectangulo (base, altura);
		cout<<"\nel area es:"<<area;
		break;
		
		case 4:
		cout<<"\ningrese la base:"; cin>>base;
		cout<<"\ningrse la altura:"; cin>>altura;
		area= (base * altura)/2;
		cout<<"\nel area es:"<<area;
		break;	
	}
	
	return 0;
}
