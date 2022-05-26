//tinh sin(x)
#include<conio.h>
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
 
int main()
{
    int k = 1;
    float x;
    double kq, tg; // tg la bien trung gian
   
    printf("Nhap x(radian)= ");
    scanf("%f", &x);
    // gan cac gia tri ban dau
    kq = tg = x;
   
    while(kq +=tg*=-x*x/(2*k)/(2*k+++1),fabs(tg)> EPSILON);
   
    printf("Ket qua tinh bang cong thuc\tsin(%f) = %f\nKet qua tinh theo ham sin\tsin(%f) = %f",
    x,kq,x,sin(x));
    getch();
    return 0;
}
