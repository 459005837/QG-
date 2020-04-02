#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;
//创建双向链表 
Status InitList_DuL(DuLinkedList L);
//销毁链表 
void DestroyList_DuL(DuLinkedList L);
//在表头插入数据 
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);
//在表尾插入数据 
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
//删除节点 
Status DeleteList_DuL(DuLNode *p, ElemType e);
//正向输出链表 
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)); 
//逆向输出链表 
void TraverseListBack_DuL(DuLinkedList L, void(*visit)(ElemType e));
//打印 
void Print(ElemType e);
//奇偶调换 
Status ReverseEvenList(DuLinkedList L);
 

#endif
