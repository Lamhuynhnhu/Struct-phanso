#include <stdio.h>
#include <conio.h>
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

Node* SearchByName(LinkedList l, char* searchKey)
{
	Node *p = l.pHead;
	char* found = NULL;
	while ((p!=NULL))
	{
		found = strstr(p->Info.hoTen, searchKey);
		if (found)		
			PrintNode(p);
		p=p->pNext;
	}
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
	printf("\n==========Cac thao tac tren Linked List=========\n");
	
	int ms = 3;
	printf("Tim kiem: Nhan vien co ma so %d la \n", ms);
	Node* p = SearchByMaNV(myNhanViens, ms);
	PrintNode(p);
	
	char* qName = "n";
	printf("\n\nTim kiem: Nhan vien co ten chua tu khoa %s la \n", qName);
	p = SearchByName(myNhanViens, qName );
	
	
	
	return 0;
}








