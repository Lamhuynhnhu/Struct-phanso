#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

/* Cau Truc NhanVien */
typedef struct {
	int maNV;
	char* hoTen;
	int luong;
}NhanVien;

/* Cau truc cua mot Node cho list kieu NhanVien */
typedef struct Node {
	NhanVien Info;   // Info: Chua thong tin cua Nhan Vien
	Node* pNext;	 // pNext: Con tro tro toi Node ke tiep
}Node;

/* Cau truc dinh nghia mot Danhsach lien ket kieu NVNode */
typedef struct 
{
	Node* pHead;  // Con tro chi Node dau tien cua list
	Node* pTail; // Con tro chi Node cuoi cung cua list
}LinkedList;


/* =========== Cac phuong thuc tren DSLK =============*/

/*Tao mot NhanVien moi voi 3 tham so */
NhanVien CreateNhanVien(int ms, char* hoten, int luong)
{
	NhanVien nv;
	
	nv.maNV = ms;
	nv.hoTen = hoten;
	nv.luong = luong;
		
	return nv;
}

/*Tao mot Node moi, voi thong tin la NhanVien (info) */
Node* CreateNode(NhanVien info) 
{
	Node* node = new Node; // Cap phat vung nho cho Node
	
	node->Info = info; // Gan thong tin cho Node
	node->pNext = NULL; // Cho duoi cua node chi ve NULL
	
	return node;
}

void PrintNode(Node* p)
{
	printf("%5d %20s %10d\n", p->Info.maNV, p->Info.hoTen, p->Info.luong );
}
/*Tao mot DSLK moi */
void CreateList(LinkedList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

/*Them mot Node new_ele vao DSLK l */
void AddFirst(LinkedList& l, Node* new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddLast(LinkedList &l, Node *new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void AddAfter(LinkedList &l, Node *q, Node *new_ele)
{
	if (l.pHead!=NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if(q == l.pTail)
		{
			l.pTail = new_ele;
		}		
	}
	else
	{
		AddFirst(l,new_ele);
	}
}

Node* SearchByMaNV(LinkedList l, int ma)
{
	Node *p = l.pHead;
	while ((p!=NULL)&&(p->Info.maNV != ma ) )
		p = p->pNext;
	return p;
}

/*Tim boi tu khoa trong ten 
Return: mot List moi
*/
LinkedList SearchByName(LinkedList l, char* searchKey)
{
	Node *p = l.pHead;
	char* found = NULL;
	
	LinkedList resultList ;
	CreateList(resultList);
	
	while ((p!=NULL))
	{
		found = strstr(p->Info.hoTen, searchKey); // Strstr: ham tim chuoi con trong chuoi me
		if (found)
		{		
			Node* newP = CreateNode(p->Info); // Tao node moi voi Info cua p ; Luu y khong duoc su dung p truc tiep
			
			AddFirst(resultList, newP);
			printf("Found\n");
		}
		p=p->pNext;
	}
	return resultList;
}

Node* SearchByExactName(LinkedList l, char* searchKey)
{	
	Node *p = l.pHead;
	while ((p!=NULL)&&(strcmp(searchKey, p->Info.hoTen)))
		p=p->pNext;
	return p;
}


/* In danh sach tu dau */
void PrintList(LinkedList &l)
{
	if (l.pHead ==NULL)
	{
		printf("Danh sach rong\n");
	}
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %20s %10d\n", p->Info.maNV, p->Info.hoTen, p->Info.luong );
			p = p->pNext;
		}		
	}
}
/* Enter new node from keyboard */
Node* EnterNewNode()
{
	printf("Nhap Nhan vien moi\n");
	int ma, l;
	
	char* ht; // Bien con tro kieu char de chua ten NhanVien
	ht = (char*)malloc(30* sizeof(char)); // Cap phat vung nho cho bien con tro
	
	printf("Ma so: "); 
	scanf("%d", &ma);
	
	printf("Ho ten: "); 
	fflush(stdin); 
	gets(ht);
	
	
	printf("Luong: "); 
	scanf("%d", &l);
	
	//printf("%10d%20s%10d", ma,ht,l);
	NhanVien n = CreateNhanVien(ma,ht,l);
	
	return CreateNode(n);		
}

int main()
{
	char* ht[] ={"Nguyen Van An", "Tran Thuy Ai", "Le Phuoc Loc", "Tran Thi Kim Ha", "Van Ngoc Tuong"};
	int ma[N] = {1,2,3,4,5};
	int l[N] = {1000, 1500, 2200, 1800, 1300};
	
	LinkedList myNhanViens;	 //Khai bao list
	CreateList(myNhanViens); //Khoi tao list
	NhanVien nvx;
	
	for (int i = 0; i <N ; i++)
	{
		nvx = CreateNhanVien(ma[i], ht[i], l[i]);
		Node* new_ele; //Khai bao node	
		new_ele = CreateNode(nvx);
		AddFirst(myNhanViens, new_ele); // Dua node vao dau list	
	}
	
	PrintList(myNhanViens);
	//printf("\n==========Cac thao tac tren Linked List=========\n");
	
	/*int ms = 3;
	printf("Tim kiem: Nhan vien co ma so %d la \n", ms);
	Node* p = SearchByMaNV(myNhanViens, ms);
	PrintNode(p);
	
	char* qName = "n";
	printf("\n\nTim kiem: Nhan vien co ten chua tu khoa %s la \n", qName);
	p = SearchByName(myNhanViens, qName ); */
	Node *new_ele, *p;
	LinkedList resultList;
	int key = 1;
	char q[30];
	while (key)
	{
		printf("\n\n===============MENU=================\n");
		printf("1. In danh sach\n");
		printf("2. Them phan tu dau danh sach\n");
		printf("3. Them phan tu cuoi danh sach\n");
		printf("4. Tim phan theo ten chinh xac\n");
		printf("5. Tim phan tu theo tu khoa trong ten\n");
		printf("6. Them phan tu tai sau nut vua tim\n");		
		printf("7. Xoa phan tu dau danh sach\n");
		printf("8. Xoa phan tu cuoi danh sach\n");
		printf("9. Xoa phan tu theo ten chinh xac\n");
		
		printf("0. Thoat\n");
		printf("\n=====================================\n");
		
		
		printf("Vui long chon thao tac ");
		scanf("%d",&key); 
		printf("Ban lua chon %d\n\n", key);
		switch (key)
		{
			case 0:				
				break;
				
			case 1:
				PrintList(myNhanViens);
				break;
				
			case 2:
				printf("---Nhap phan tu moi va them vao dau danh sach---\n");
								
				new_ele  = EnterNewNode();				
				AddFirst(myNhanViens, new_ele);
				
				printf("\n \n =======Danh Sach sau khi them phan tu ======\n");
				PrintList(myNhanViens);
				break;
			case 3:
				printf("---Nhap phan tu moi va them vao cuoi danh sach---\n");
								
				new_ele  = EnterNewNode();				
				AddLast(myNhanViens, new_ele);
				
				printf("\n \n =======Danh Sach sau khi them phan tu ======\n");
				PrintList(myNhanViens);
				break;
				
			case 4:
				printf("Tim phan tu theo ten\n")	;
				
				printf("Nhap ten nhan vien can tim kiem: ");
				fflush(stdin);
				gets(q);
				
				p = SearchByExactName(myNhanViens, q);
				if (p!=NULL)
				{
					PrintNode(p);
				}
				else
				{
					printf("Khong tim thay: %s \n", ht);
				}
				break;	
							
			case 5:				
				printf("Tim theo tu khoa trong ten\n");				
				printf("Nhap ten nhan vien can tim kiem: ");
				fflush(stdin);
				gets(q);
					
				resultList = SearchByName(myNhanViens, q);
				if (resultList.pHead!=NULL)					
					PrintList(resultList);
				else
					printf("Khong tim thay: %s \n", ht);					
				break;						
				
			default:
				printf("Chuc nang chua cai dat");
		}	
		
	}
	
	return 0;
	
	return 0;
}








