#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>

void Menus(){
printf("\n");
printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
printf(" + ��ѡ�����¹��ܣ�                                + \n");
printf(" + 1.����������    2.ɾ���ڵ�          3.����ڵ�  + \n"); 
printf(" + 4.���ҽڵ�      5.�������          6.��������  + \n"); 
printf(" + 7.��������      8.�ж��Ƿ�ɻ�      9.��ż����  + \n"); 
printf(" + 10.��������м�ڵ�      11.��������            + \n"); 
printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
} 


//�������� 
Status InitList(LinkedList L) {
	int msg,n,i = 1;
	LinkedList p,q; 
	
	if(L==NULL){
		L = (LinkedList)malloc(sizeof(LNode));
		L -> next = NULL;
	} 
	p=L;
	printf("����������ĳ��ȣ�");
	msg = scanf("%d",&n);
	fflush(stdin);
	if(msg!=1||n==0){
		printf("�벻Ҫ����Ц��\n");
	}else{
		while(n)
		{
			q=(LinkedList)malloc(sizeof(LNode));
			printf("�������%d����: ",i);
			i++; 
			msg=scanf("%d", &q->data);fflush(stdin);
			if(msg!=1){
				printf("��Ч�ַ��������ֹ��\n");
				break;
			}
			q->next=NULL;
			p->next=q;
			p=q;
			n--;
		}
	}
	return 0;
}
//�������� 
void DestroyList(LinkedList L) {
    LinkedList p;  
    if(L==NULL||L->next==NULL){
		printf("����Ϊ�տ��ؽ�һ����\n");
		return;
	}  
    while(p)  
    {  
        p=L->next;  
        free(L);  
        L=p;  
    }
	printf("�������ٳɹ���\n");
    return ;  
}

//����ڵ� 
Status InsertList(LNode *L, LNode *q) {

	LinkedList s;
	s=L;
	while(s->next&&s->next->data < q->data)
	s=s->next;
	q->next=s->next;
	s->next=q;

	return 0;
}

//ɾ���ڵ�����Ϊe�Ľڵ� 
Status DeleteList(LNode *L, ElemType e) {
	int i=1;
	LinkedList p,q;
	p=L->next;
	while(p->next!=NULL&&p->data!=e)
	{	
		q=p;
		p=p->next;
	}
		if(p==L->next&&p->data==e){
			q=L->next;
			L->next=L->next->next;
			free(q);
			printf("ɾ���ɹ�!!\n\n");
			return 0;
		} 
		else if(p->data==e)
		{
			q->next = p->next;
			free(p);
			printf("ɾ���ɹ�!!\n\n");
			return 0;
		}
		else
		{
			printf("������û��%d\n\n",e);
			return 0;	
		}
}

//�������� 
void Print(LinkedList L) {

	LinkedList p ;
	p = L->next;
	int i = 1;
	
	do{
		printf("��%d����Ϊ��%d\n",i++,p->data); 
		p = p->next;
	}while(p!=NULL);
	
}


//����ĳһ������ 
Status SearchList(LinkedList L, ElemType e) {
	int i=1;

	LinkedList p = L->next;
	while(p!=NULL&&p->data!=e){
		i++;
		p = p->next; 
	}
	if(p==NULL){
		printf("������û�и����ݣ�\n");
		return 0; 
	}else{
		printf("�������ڵ�%d���ڵ���!\n",i);
		return 0;
	} 	
}

//����ķ�ת 
Status ReverseList(LinkedList L) {

	LinkedList  p1, p2 ,temp;	
	p1 = L->next;
	p2 = temp = NULL;
	while(p1!=NULL){
		temp = p1->next;
		p1->next = p2;
		p2 = p1;
		p1 = temp;	
	}
	p1 = p2;
	L->next = p1;	
	return 0;
}
//�ж��Ƿ�ɻ� 
Status IsLoopList(LinkedList L) {
	 LinkedList p1 ,p2;
	 p1 = p2 = L;
	 p1 = p1->next->next;//null 
	 p2 = p2->next;
	 while(1){
	 	if(p1==p2){
	 		printf("����ɻ���\n");
	 		return 0;
		 }
		 else if(p1==NULL||p1->next==NULL){
		 	printf("���ɻ�\n"); 
		 	return -1;
		 }else{
			 p1 = p1->next->next;
			 p2 = p2->next;	 		
		 }
	 }
}

//��ż���� 
Status ReverseEvenList(LinkedList L) {
	LinkedList p1, p2, temp;
	p1 = L->next;//��һ�� 
	p2 = p1->next;//�ڶ��� null
	//p3 = p2->next;
	if(p2!=NULL){
		L->next = p2;
		while(1){
			temp = p2->next;
			p1->next = temp;
			p2->next = p1;
			if(temp!=NULL&&temp->next!=NULL){
				p1->next = temp->next;//null
			}
			p1 = temp;
			if(p1==NULL||p1->next==NULL){
				return 0;
			}
			p2 = p1->next;
		}
	}
	return 0;
}

//Ѱ���м�ڵ㣬���ÿ���ָ��
//��Ϊ����ʱ�м��Ǹ������м�ڵ㣬δż��ʱ�м����������м�ڵ� 
void FindMidNode(LinkedList L) {
	LinkedList p1 , 
	p2, temp;
	p1 = p2 = L;
	
	do{
		
		p2 = p2->next->next;
		p1 = p1->next;
		 
	}while(p2!=NULL&&p2->next!=NULL); 
	
	if(p2==NULL){
		//�������ڵ�
		 printf("�м�ڵ���һ����\n");
		 printf("��ֵΪ��%d",p1->data);
	}else{
		//ż�����ڵ�
		printf("�м�ڵ���������\n");
		printf("��ֵΪ��%d �� %d \n",p1->data,p1->next->data);	 
	} 
	return ;
}
//�������������� 
Status Sort(LinkedList L)
{
	
	LinkedList s,r;
	s=L->next;
	L->next=NULL;
		while(s)
		{
		r=s;
		s=s->next;
		r->next=NULL;
		InsertList(L,r);
		}
	return 0;
}

