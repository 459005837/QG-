#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#define OVERFLOW -1

// define element type
typedef int ElemType;
// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

extern void Menus();//��ӡѡ��˵�

Status InitList(LinkedList L);//����һ������ͷ�ڵ�ĵ����� 

void DestroyList(LinkedList L);//�������� 

Status InsertList(LNode *p, LNode *q);//����ڵ� 

Status DeleteList(LNode *p, ElemType e);//ɾ��ĳ���ڵ� 

void Print(LinkedList L);//�������� 

Status SearchList(LinkedList L, ElemType e);//����ĳ���ڵ� 

Status ReverseList(LinkedList L);//��������� 

Status IsLoopList(LinkedList L);//�Ƿ�ɻ� 

Status ReverseEvenList(LinkedList L);//��ż���� 

void FindMidNode(LinkedList L); //�м�ڵ� 

Status Sort(LinkedList L);//�Զ����� 

#endif
