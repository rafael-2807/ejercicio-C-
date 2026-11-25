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
 
 void C (int x, int y, int n){
int i, j;

for (i = 0; i<n ; i++){
	
	for (j = 0; j<n ; j++){
		
		if (i == 0 || j == 0 || i == n-1){
			gotoxy (x+j , y+i);
			cout << "*";
		}
	}
}
 	
 }
 
void O (int x, int y, int n){
int i, j;

for (i = 0; i<n ; i++){
	
	for (j = 0; j<n ; j++){
		
		if (i == 0 || j == 0 || i == n-1 || j == n-1) {
			gotoxy (x+j , y+i);
			cout << "*";
		}
	}
}

}


void S (int x, int y, int n){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            
            // Condiciones para formar la S
            if ( (i == 0) ||                     // 1. Línea superior
                 (i < n/2 && j == 0) ||          // 2. Lado izquierdo superior
                 (i == n/2) ||                   // 3. Línea del medio
                 (i > n/2 && j == n-1) ||        // 4. Lado derecho inferior
                 (i == n-1) )                    // 5. Línea inferior
            {
                gotoxy(x + j, y + i);
                cout << "*";
            }
        }
    }
}

 void Dos (int x, int y, int n){
int i, j;

for (i = 0; i<n ; i++){
	
	for (j = 0; j<n ; j++){
		
		if (i == 0 || j == n-1 && i<=n/2 || (i == n/2) ||j == 0 && i>=n/2 || i == n-1){
			gotoxy (x+j , y+i);
			cout << "*";
		}
	}
}
 	
 }
 
 
 
 
 
 int main(){  
      Dos(5, 10, 10);
	  O(30,10,10);    
	  O(55,10,10);
	  S(80,10,10); 
	  Dos(80, 10, 10);
      return 0;  
 }  