/*
Dinh nghia cau truc phan so: tu so (so nguyen), mau so (so nguyen).
1. Viet ham nhap phan so.
2. Ham xuat phan so. /
3. Ham cong phan so. /
4. Ham tru phan so. /
5. Ham nhan phan so. /
6. Ham chia phan so. /
7. Ham rut gon phan so
*/

#include <stdio.h>

struct PhanSo{
	int tuso;
	int mauso;
};
//Nhap phan so
void NhapPS(PhanSo &p) // truyen bang tham chieu/dia chi
{
	printf("Nhap tu so:");
	scanf("%d",&p.tuso);
	printf("Nhap mau so:");
	scanf("%d",&p.mauso);
}

//Xuat phan so
void XuatPS(PhanSo p)
{
	printf("\n%d/%d",p.tuso, p.mauso);
}
//  Ham cong phan so.
PhanSo CongPS(PhanSo p1, PhanSo p2)
{
	PhanSo p;
	p.tuso = p1.tuso*p2.mauso + p2.tuso*p1.mauso;
	p.mauso = p1.mauso * p2.mauso;
	return p;	
}
// Ham tru phan so.
PhanSo TruPS(PhanSo p1, PhanSo p2)
{
	PhanSo p;
	p.tuso = p1.tuso*p2.mauso - p2.tuso*p1.mauso;
	p.mauso = p1.mauso * p2.mauso;
	return p;	
	
}
// Ham nhan phan so.
PhanSo NhanPS( PhanSo p1,PhanSo p2)
{	
    PhanSo p;
	p.tuso = p1.tuso * p2.tuso;
	p.mauso = p1.mauso * p2.mauso;
	return p;	
	
}
// Ham chia phan so.
PhanSo ChiaPS( PhanSo p1,PhanSo p2)
{	
    PhanSo p;
	p.tuso = p1.tuso * p2.mauso;
	p.mauso = p1.mauso * p2.tuso;
	return p;		
}
// Ham rut gon



int main(void){
	PhanSo p, p1, p2;	
	NhapPS(p1);
	NhapPS(p2);
	p =  CongPS(p1,p2);
	XuatPS(p);
	p = TruPS(p1,p2);
	XuatPS(p);
	p = NhanPS(p1,p2);
	XuatPS(p);
	p = ChiaPS(p1,p2);
	XuatPS(p);
	
}
