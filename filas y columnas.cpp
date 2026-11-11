#include <iostream>
#include <windows.h>
using namespace std;
 
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 void O (int x, int y, int n){
 	int i,j;
 	for (int i=0; i<n; i++){
 		for (int j=0; j<n; j++){
 			if (i==0 || j==0 || i==n-1|| j==n-1){
 			gotoxy (x+j, y+i);
 			cout<<"*";
		 }
		 }
	  
 }
}
void C (int x, int y, int n){
 	int i,j;
 	for (int i=0; i<n; i++){
 		for (int j=0; j<n; j++){
 			if (i==0 || i==n/2 ||j==0 || j==n-1 && i==n/2 || j==0 && i>n/2){
 			gotoxy (x+j, y+i);
 			cout<<"*";
		 }
		 }
	  
 }
}		 
void S (int x, int y, int n){
 	int i,j;
 	for (int i=0; i<n; i++){
 		for (int j=0; j<n; j++){
 			if (i==0 || j==0 || i==n-1 || j==n-1){
 			gotoxy (x+j, y+i);
 			cout<<"*";
		 }
		 }
	  
 }
}	  
void A (int x, int y, int n){
 	int i,j;
 	for (int i=0; i<n; i++){
 		for (int j=0; j<n; j++){
 			if (i==0 || j==0 || i==n-1 || j==n-1 || i==n/2){
 			gotoxy (x+j, y+i);
 			cout<<"*";
		 }
		 }
	  
 }
} 
 int main(){  
      
      C(2,5,5);
	  O(9,5,5);
	  S(16,5,5);
	  A(23,5,5);  
        
      return 0;  
 }  
