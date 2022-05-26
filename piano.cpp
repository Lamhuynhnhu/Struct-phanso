#include <windows.h>
#include <stdio.h>
#include <conio.h>
   int main (void){
  printf ("nhap vao ki tu : a, b ,c , d ,e ");
  char key ;
  
  do{
  	 key = getch();
  	 switch(key){
  	 	case 'a': Beep(460,500);break;
  	 	case 'b': Beep(850,500);break;
  	 	case 'c': Beep(490,500);break;
  	 	case 'd': Beep(480,500);break;
  	 	case 'e': Beep(450,500);break;
	   }
   }while (key!=27);
}
