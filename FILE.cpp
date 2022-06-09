#include<stdio.h>
 // tao file
 int main()
 {
 	FILE*fptr;
 	// mo file 
 	fptr = fopen ("D:\\Lam Huynh Nhu 110121263 Da21ttc\\Array.txt ","r");
 	if (fptr== NULL)
 	{
 	printf(" Loi file");
 	return 0;	
	}
	// co the thay 
 	/*char hoten[50];
 	printf ("Ho va ten ");
 	gets(hoten);
 	fprintf(fptr,"%s\n",hoten);
 	fflush(stdin);
 	int tuoi;
 	printf ("Tuoi");
 	scanf("%d",&tuoi);
 	fprintf(fptr,"%d",tuoi);*/
 	
 	                           // doc file tung cai
 	int n;
 	fscanf(fptr,"%d",&n);
	printf("%d\n",n);
 	
 	int x;
 	for (int i=1; i<=n; i++)
 	{
 		fscanf(fptr, "%d",&x);
 		printf("%d\n",x);
	 }
                                // doc toan bo file
//  int t;
//  while (fscanf(fptr,"%d",&t)!=EOF)
//  printf("%d\n",t);                              
//                             
 	// dong file 
 	fclose (fptr);
 	return 0;
 	
 }
