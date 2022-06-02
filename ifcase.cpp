#include<stdio.h>

 int main (void){
 	int thang , nam ;
 	printf ("nhap vao thang ");
 	scanf ("%d",&thang);
 	printf("nhap vao nam ");
 	scanf ("%d",&nam);
 	switch(thang)
 	{
	 
 	case 1:
 		printf ("thang %d nam %d co 31 ngay ", thang, nam );
 		break ;
 	case 3:
 		printf ("thang %d nam %d co 31 ngay ", thang, nam );
 		break ;
    case 5:
 		printf ("thang %d nam %d co 31 ngay ",thang , nam);
 		break ;
	case 7:
 		printf ("thang %d nam %d co 31 ngay ",thang , nam);
 		break ;
	case 8:
 		printf ("thang %d nam %d co 31 ngay ",thang , nam);
 		break ;	
	case 10:
 		printf ("thang %d nam %d co 31 ngay ",thang , nam);
 		break ;
	case 12:
 		printf ("thang %d nam %d co 31 ngay ",thang , nam);
 		break ;	 
 	case 4:
 		printf ("thang %d nam %d co 30 ngay ",thang , nam);
 		break ;
	case 6:
 		printf ("thang %d nam %d co 30 ngay ",thang , nam);
 		break ;
	case 9:
 		printf ("thang %d nam %d co 30 ngay ",thang , nam);
 		break ;
	case 11:
 		printf ("thang %d nam %d co 30 ngay ",thang ,nam);
 		break ;	
	case 2:
	  if(nam%4==0){
	  	printf ("thang %d nam %d co 29 ngay ",thang , nam);
	  	break ;
	  }
      else
	  {
	  	printf ("thang %d nam %d co 28 ngay ", thang , nam);
	  	break ;
      }
    default: printf ("nhap sai thang hoac nam ");
}
		 
		 	  	 	
 		
 	
 	
 	
 	
 }




