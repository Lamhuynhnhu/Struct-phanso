#include <stdio.h>
#include <string.h>
/*
Dinh nghia kieu HOCSINH gom 5 thanh phan:
- mshs: ma so hoc sinh (chuoi)
- hoten: kieu chuoi
- diem toan, ly, hoa: so thuc
1. Nhap thong tin 1 hoc sinh
2. xuat thong tin 1 hoc sinh
3. Nhap n hoc sinh, tim hoc sinh co diem trung binh lon nhat
4. Sap xep danh sach hoc sinh theo thu tu tang dan cua diem toan
5. Sap xep danh sach hoc sinh theo thu tu tang dan cua diem TB (viet ham tinh diem trung binh cua 1 hoc sinh
6. Tim kiem hoc sinh theo ma so hoc sinh
*/

//Dinh nghia kieu hoc sinh
struct HOCSINH {
	char mshs[10]; //nhap ms so hoc sinh toi da 3 ky tu
	char hoten[20];
	float toan;
	float hoa;
	float ly;
};

void NhapHS(HOCSINH &hs)
{
	fflush(stdin);
	printf("MSHS: ");
	gets(hs.mshs);
	printf("Ho ten: ");
	fflush(stdin);  
	gets(hs.hoten);
	fflush(stdin);

	printf("Nhap diem Toan: ");
	scanf("%f",&hs.toan);
	printf("Nhap diem Ly: ");
	scanf("%f", &hs.ly);
	printf("Nhap diem Hoa: ");
	scanf("%f",&hs.hoa);
}

void XuatHS(HOCSINH hs)
{
	
	printf("\nMSHS: %s  Ho ten: %s  Toan: %.2f  Ly: %.2f  Hoa: %.2f", hs.mshs, hs.hoten, hs.toan, hs.ly, hs.hoa);

}

void NhapDSHS(HOCSINH hs[100], int siso){
	for(int i = 0; i<siso; i++)
		NhapHS(hs[i]);
}

void XuatDSHS(HOCSINH hs[100], int siso){
	for(int i = 0; i<siso; i++)
		XuatHS(hs[i]);
}

float maxToan(HOCSINH hs[100], int siso)
{
	//tinh diem Toan loan nhat
	float max = hs[0].toan;
	for(int i=1; i<siso; i++)
		if(max<hs[i].toan)
			max = hs[i].toan;
	return max;
}

float maxDTB(HOCSINH hs[100], int siso)
{
	//tinh diem Toan loan nhat
	float max = (hs[0].toan + hs[0].ly+ hs[0].hoa)/3;
	for(int i=1; i<siso; i++)
		if(max<(hs[i].toan + hs[i].ly+ hs[i].hoa)/3)
			max = (hs[i].toan + hs[i].ly+ hs[i
			].hoa)/3;
	return max;
}

void sapXepToan(HOCSINH hs[100], int siso){
	for(int i=0; i<siso-1; i++)
		for(int j=i+1; j<siso; j++)
			if(hs[i].toan>hs[j].toan)
			{
				HOCSINH t = hs[i];
				hs[i] =  hs[j];
				hs[j] = t;
			}
}

//tinh dien trung binh cua 1 hoc sinh
float diemTB(HOCSINH hs){
	return ((hs.toan+hs.ly+hs.hoa)/3);
}

void sapXepDTB(HOCSINH hs[100], int siso){
	for(int i=0; i<siso-1; i++)
		for(int j=i+1; j<siso; j++)
			if(diemTB(hs[i])>diemTB(hs[j]))
			{
				HOCSINH t = hs[i];
				hs[i] =  hs[j];
				hs[j] = t;
			}
}

//ham tiem kiem theo ten -> in thong tin hoc sinh duoc tim thay
void timHS(HOCSINH hs[100], int siso, char mstim[4]){
	for(int i=0; i<siso; i++)
		if(strcmp(hs[i].mshs, mstim)==0)
			XuatHS(hs[i]);
}

int main(void){
	HOCSINH hs[100];
	int siso;
	printf("Nhap so hoc sinh:");
	scanf("%d", &siso);
	NhapDSHS(hs,siso);
	XuatDSHS(hs,siso);
	
	//tinh diem Toan loan nhat
	printf("\nMax DTB: %.2f",maxDTB(hs,siso));
	
	// Hoc sinh co diem trung binh lon nhat
	for(int i=0;i<siso; i++)
		if((hs[i].toan+hs[i].ly+hs[i].hoa)/3 == maxDTB(hs, siso))
			XuatHS(hs[i]);

	sapXepToan(hs, siso);
	printf("\nDanh sach tang dan theo diem Toan: \n");
	XuatDSHS(hs,siso); //xuat sau khi sap xep
	
	sapXepDTB(hs, siso);
	printf("\nDanh sach tang dan theo diem trung binh: \n");
	XuatDSHS(hs,siso); //xuat sau khi sap xep
	char mstim[4];
	printf("\nNhap ma so hoc sinh can tim:");
	fflush(stdin);
	gets(mstim);
	timHS(hs, siso, mstim);
	
	
}



