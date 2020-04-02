#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

void Menus(){
printf("\n");
printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
printf(" + ��ѡ�����¹��ܣ�                                      + \n");
printf(" + 1.����˫����        2.��������      3.����ǰ����ڵ�  + \n"); 
printf(" + 4.��������ڵ�    5.��ż����      6.ɾ���ڵ�        + \n"); 
printf(" + 7.�������          8.�������                        + \n"); 
printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
} 

Status InitList_DuL(DuLinkedList L)   {
	if(L==NULL){
		L = (DuLinkedList)malloc(sizeof(DuLNode));
		L -> next = NULL;
		L->prior=NULL;
	} 
	//p������ p1���ڵ� 
	DuLinkedList p , p1;
	int x, msg,n,i=1;
	p = L;
	printf("����������ĳ��ȣ�");
		msg = scanf("%d",&n);
	fflush(stdin);

	if(msg!=1||n==0){
		printf("�벻Ҫ����Ц��\n");
	}else{
		while(n)
		{
			p1=(DuLinkedList)malloc(sizeof(DuLNode));
			printf("�������%d����: ",i);
			i++; 
			msg=scanf("%d", &p1->data);fflush(stdin);
			if(msg!=1){
				printf("��Ч�ַ��������ֹ��\n");
				break;
			}
		p->next =  p1;
		if(p==L){
			p1->prior = NULL;
		}
		else{
			p1->prior = p;
		}
		p1->next =NULL;
		p = p->next;
			n--;
		}
	}
}


void DestroyList_DuL(DuLinkedList L) {
	DuLinkedList p ;
	p = L;
	while(p){
		p = L->next;
		free(L);
		L = p;
	}
	printf("�������ٳɹ���\n");
}


Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	DuLinkedList L;
	L = p->next;
	L->prior = q;
	q->next = L;
	q->prior = NULL;
	p->next = q;
	printf("����ɹ���\n");
	return 0;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	DuLinkedList L ,p1;
	L = p->next;
	while(L!=NULL){
		p1 = L;
		L = L->next;
	}
	p1->next = q;
	q->prior = p1;
	q->next =NULL;
    printf("����ɹ���\n");	
	return 0;
}

Status DeleteList_DuL(DuLNode *p, ElemType e) {
	DuLinkedList L , q;
	L = p->next;
	while(L->data!=e&&L->next!=NULL){
		q = L;
		L = L->next;
	}
	if(L->data==e){
		if(L->next==NULL){
			p->next = NULL;
			free(L);
		}else{
		q->next = L->next;
		L->next->prior = q;
		free(L);		
		}
	printf("����ɾ���ɹ���\n");

	}
	else{
		printf("δ�ҵ������ݣ�\n");
	}
	return 0;
}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p;
	p = L->next;
	visit = Print;
	while(p!=NULL){
		(*visit)(p->data);	
		p = p->next;
	}
}
void TraverseListBack_DuL(DuLinkedList L, void(*visit)(ElemType e)){
	DuLinkedList p , q, p1;
	p = L->next;
	while(p!=NULL){
		p1 = p;
		p = p->next;
	}
	visit = Print;
	while(p1!=NULL){
		(*visit)(p1->data);	
		p1 = p1->prior;
	}
}
void Print(ElemType e ){
	printf("%d\n",e);
} 


//��ż���� 
Status ReverseEvenList(DuLinkedList L) {
	DuLinkedList p1, p2;
	p1 = L->next;//��һ�� 
	p2 = p1->next;//�ڶ��� null
	//p3 = p2->next;
	while(p2!=NULL){	
		if(p1==L->next){
			L->next = p2;
			p2->prior = NULL;
			p1->prior =p2;
			p1->next = p2->next;
			p2->next = p1;
			if(p1->next==NULL){
				return;
			}
		}
		else if(p1!=L->next) {
			p2->prior = p1->prior;
			p1->prior = p2;
			p1->next = p2->next;
			p2->next = p1;
		}
		p1 = p1->next;
		if(p1==NULL){
			return;
		}
		p1->prior = p2->next;
		p2->next->next = p1->next;
		p2 = p1->next;
	}
	
	return 0;
}


