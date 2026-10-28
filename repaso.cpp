/* realice un programa que permita separar en cifras numeros en un rango entre 10 y 999999.
Ademas de separar las cifras en pantalla, su programa debe ser capaz de identificar si el numero ingresado es
par, impar, primo o perfecto.
*/
#include <iostream>
using namespace std;
int main (){
	int numero,n,cont_par, cont_impar, cont_primo, cont_perfecto;
	
	cout<<"ingrese el numero:"; cin>>numero;
	cout<<"\ningrese el valor de n:"; cin>>n;
		
	if (numero==10 && numero==999999){
		for (int i=1; i<=n; i++){
		if (n%i==0)
		
		
		}
	} else {
		cout<<"\nerror, numero invalido";
	}
	
	
	if (i%2==0){
		cout<<"\nel numero es par";
	} else {
		cout<<"\nel numero es impar";
	}
	
	return 0;
}
