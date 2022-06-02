#include<stdio.h>


// dinh nghia kieu hoc sinh
struct HOCSINH
{
	char mshs[4];
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
int main(void)
{
	HOCSINH hs[100];
	int siso;
	printf(" Nhap so hoc sinh: ");
	scanf("%d",&siso);
	for (int i=0; i<siso; i++)
	NhapHS(hs[i]);
	for (int i=0; i<siso; i++)
    XuatHS(hs[i]);

}



