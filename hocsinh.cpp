#include<stdio.h>
- nhap 
- xuat 
-tinh diem trung binh 
- tinh diem hs co tb lon nhat
// dinh nghia kieu hoc sinh
struct HOCSINH
{
	char mshs[10];
	char hoten[20];
	float toan;
	float ly;
	float hoa;
};
void NhapHS(HOCSINH &hs)
{
	fflush (stdin);
	printf(" MSHS: ");
	gets (hs.mshs);
	printf(" HoTen: ");
	fflush (stdin);
	gets (hs.hoten);
	fflush (stdin);
	printf(" Nhap diem mon toan: ");
	scanf ("%f",&hs.toan);
	printf(" Nhap diem mon ly: ");
	scanf ("%f",&hs.ly);
	printf(" Nhap diem mon hoa: ");
	scanf ("%f",&hs.hoa);
}
void XuatHS(HOCSINH &hs)
   {
	printf ("\nMSHS: %s Hoten: %s Toan: %.2f Ly: %.2f Hoa: %.2f",hs.mshs ,hs.hoten, hs.toan, hs.ly, hs.hoa);
   }
void NhapDSHS(HOCSINH hs[100] , int siso)
{
for (int i=0; i<siso; i++)
	NhapHS(hs[i]);
}
void XuatDSHS(HOCSINH hs[100] , int siso)
    {
for (int i=0; i<siso; i++)
	XuatHS(hs[i]);
   } 
// toan lon nhat
float maxToan(HOCSINH hs[100], int siso)
{
	float max = hs[0].toan;
	for (int i=1; i<siso; i++)
	   if (max<hs[i].toan)
	      max=hs[i].toan;
	      return max;

}

float maxDTB(HOCSINH hs[100], int siso)
  {

float max = (hs[0].toan+ hs[0].ly+ hs[0].hoa)/3;
	for (int i=1; i<siso; i++)
	    if (max<(hs[i].toan+hs[i].ly+hs[i].hoa)/3)
	        max=(hs[i].toan + hs[i].ly + hs[i].hoa)/3;
    return max;
   }
int main(void)
{
	HOCSINH hs[100];
	int siso;
	printf(" Nhap so hoc sinh: ");
	scanf("%d",&siso);
	NhapDSHS(hs,siso);
    XuatDSHS(hs,siso);
// tinh diem hocsinh co TBLN 
printf(" \nMax DTB: %.2f", maxDTB(hs,siso));

// hoc sinh co dtb lon nhat
 for (int i=0; i<siso; i++)
	    if ((hs[i].toan + hs[i].ly + hs[i].hoa)/3 == maxDTB(hs, siso))
	       XuatHS(hs[i]);
}





