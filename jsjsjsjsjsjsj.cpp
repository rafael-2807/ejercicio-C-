/* realice un programa que reciba la estutura de un individuo en Cm y su peso en Kg y calcule el IMC.
Con la clasificacion de la OMS (degadez severa<16, moderada 16-16.99,aceptable 17-18.49, normal 18.5-24.99, 
sobrepeso 25-29.99, obeso tipo I 30-34.99, tipo II 35-40, tipo III>40)
*/ 
#include <iostream>
using namespace std;
int main (){
	float IMC, peso, estatura;
	
	cout<<"ingrese su peso(kg): "; cin>>peso;
	cout<<"ingrese su estatura(Cm): "; cin>>estatura;
	
	while (peso <= 0 && estatura<=0){
		cout<<"error, ingrese valores mas altos\n";
		cin>>peso; cin>>estatura;
	}
	estatura= estatura/100;
	IMC= peso/(estatura*estatura);
	cout<<"\nla estatura en metros es:"<<estatura;
	cout<<"\nel IMC del individuo es:"<<IMC;
	
	if (IMC<16){
		cout<<" \ntienes delgadez severa";
	} else if(IMC==16 && IMC==16.99){
		cout<<"\ntienes un IMC moderado";
	} else if(IMC==17 && IMC==18.49){
		cout<<"\ntienes un IMC aceptable";
	} else if (IMC>=18.5 && IMC<=24.99){
		cout<<"\ntienes un IMC normal";
	} else if (IMC==25 && IMC<=29.99){
		cout<<"\n eres gordo, deja las hamburguesas";
	} else if (IMC>=30 && IMC<=34.99){
		cout<<"\n eres gordo, ponte a entrenar";
	} else if (IMC>=35 && IMC<=40){
		cout<<"\n busca manera de rebajar esa manteca";
	} else if (IMC>=40){
		cout<<"\n te jodiste, tienes sobrepeso de tipo III";
	}
	
	return 0;
}
