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

extern void Menus();//打印选择菜单

Status InitList(LinkedList L);//建立一个带有头节点的单链表 

void DestroyList(LinkedList L);//销毁链表 

Status InsertList(LNode *p, LNode *q);//插入节点 

Status DeleteList(LNode *p, ElemType e);//删除某个节点 

void Print(LinkedList L);//遍历链表 

Status SearchList(LinkedList L, ElemType e);//查找某个节点 

Status ReverseList(LinkedList L);//链表的逆置 

Status IsLoopList(LinkedList L);//是否成环 

Status ReverseEvenList(LinkedList L);//奇偶调换 

void FindMidNode(LinkedList L); //中间节点 

Status Sort(LinkedList L);//自动排序 

#endif
