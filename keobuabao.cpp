#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 int main (void){
 	
 	printf ("Ban chon?\n");
 	printf ("1: Keo\n");
 	printf ("2: Bao\n");
 	printf ("3: Bua\n");
 	
 	int nguoi ;
 	printf ("Ban chon: ");
 	scanf ("%d",&nguoi);
 	int may ;
 	
 	srand(time(NULL));
 	may = rand();
 	may = may%3 + 1 ;
 	printf ("may chon %d\n",may);
 	switch(may){
 		case 1:
 			switch(nguoi){
 				case 1:printf ("Hoa!"); break;
 				case 2:printf ("Thua!");break;
 				case 3:printf ("Thang!");break;
 				default:printf("Ban choi sai luat -> THUA!");
 			}
 			break;
		case 2:
		    switch(may){
 				case 1:printf ("Thang!"); break;
 				case 2:printf ("Hoa!");break;
 				case 3:printf ("Thua!");break;
 				default:printf("Ban choi sai luat -> THUA!");	
			}	 	
			break; 
 		case 3:
 			switch(nguoi){
 				case 1: printf ("Thua!");break;
				case 2: printf ("Thang!");break;
				case 3: printf ("Hoa!");break;
				default:printf("Ban choi sai luat -> THUA!"); 			 
			}
 			break;
 		
	 }
 	
 	
 }
