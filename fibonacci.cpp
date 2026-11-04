/* realice un programa que permita en calculo de la serie fibonacci hasta una interaccion que el usuario ingrese 
*/
#include <iostream>
using namespace std;
int main (){
	int n1,n2,resultado,n;
	char letra='s';
	
	while (letra=='s' || letra=='S'){
		n1=0;
		n2=1;
		cout<<"ingrese el numero de interaccion:"; cin>>n;
		
		for (int i=1; i<=n; i++){
		resultado= n1 + n2;
		n1=n2;
		n2=resultado;
		cout<<"\nlas interacciones son:"<<resultado;
	}
	cout<<"\ndesea continuar(s,S):\n"; cin>>letra;
	cout<<"\n----------\n";
	}
	
	return 0;
}
