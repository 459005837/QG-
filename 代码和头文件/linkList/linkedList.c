#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>

void Menus(){
printf("\n");
printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
printf(" + 请选择以下功能：                                + \n");
printf(" + 1.创建新链表    2.删除节点          3.插入节点  + \n"); 
printf(" + 4.查找节点      5.输出链表          6.销毁链表  + \n"); 
printf(" + 7.链表逆置      8.判断是否成环      9.奇偶调换  + \n"); 
printf(" + 10.输出链表中间节点      11.链表排序            + \n"); 
printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
} 


//创建链表 
Status InitList(LinkedList L) {
	int msg,n,i = 1;
	LinkedList p,q; 
	
	if(L==NULL){
		L = (LinkedList)malloc(sizeof(LNode));
		L -> next = NULL;
	} 
	p=L;
	printf("请输入链表的长度：");
	msg = scanf("%d",&n);
	fflush(stdin);
	if(msg!=1||n==0){
		printf("请不要开玩笑！\n");
	}else{
		while(n)
		{
			q=(LinkedList)malloc(sizeof(LNode));
			printf("请输入第%d个数: ",i);
			i++; 
			msg=scanf("%d", &q->data);fflush(stdin);
			if(msg!=1){
				printf("无效字符，输入截止！\n");
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
//销毁链表 
void DestroyList(LinkedList L) {
    LinkedList p;  
    if(L==NULL||L->next==NULL){
		printf("链表为空可重建一链表！\n");
		return;
	}  
    while(p)  
    {  
        p=L->next;  
        free(L);  
        L=p;  
    }
	printf("链表销毁成功！\n");
    return ;  
}

//插入节点 
Status InsertList(LNode *L, LNode *q) {

	LinkedList s;
	s=L;
	while(s->next&&s->next->data < q->data)
	s=s->next;
	q->next=s->next;
	s->next=q;

	return 0;
}

//删除节点数据为e的节点 
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
			printf("删除成功!!\n\n");
			return 0;
		} 
		else if(p->data==e)
		{
			q->next = p->next;
			free(p);
			printf("删除成功!!\n\n");
			return 0;
		}
		else
		{
			printf("链表中没有%d\n\n",e);
			return 0;	
		}
}

//遍历链表 
void Print(LinkedList L) {

	LinkedList p ;
	p = L->next;
	int i = 1;
	
	do{
		printf("第%d个数为：%d\n",i++,p->data); 
		p = p->next;
	}while(p!=NULL);
	
}


//查找某一个数据 
Status SearchList(LinkedList L, ElemType e) {
	int i=1;

	LinkedList p = L->next;
	while(p!=NULL&&p->data!=e){
		i++;
		p = p->next; 
	}
	if(p==NULL){
		printf("链表中没有该数据！\n");
		return 0; 
	}else{
		printf("该数据在第%d个节点中!\n",i);
		return 0;
	} 	
}

//链表的反转 
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
//判断是否成环 
Status IsLoopList(LinkedList L) {
	 LinkedList p1 ,p2;
	 p1 = p2 = L;
	 p1 = p1->next->next;//null 
	 p2 = p2->next;
	 while(1){
	 	if(p1==p2){
	 		printf("链表成环！\n");
	 		return 0;
		 }
		 else if(p1==NULL||p1->next==NULL){
		 	printf("不成环\n"); 
		 	return -1;
		 }else{
			 p1 = p1->next->next;
			 p2 = p2->next;	 		
		 }
	 }
}

//奇偶调换 
Status ReverseEvenList(LinkedList L) {
	LinkedList p1, p2, temp;
	p1 = L->next;//第一个 
	p2 = p1->next;//第二个 null
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

//寻找中间节点，利用快慢指针
//当为奇数时中间那个就是中间节点，未偶数时中间两个都是中间节点 
void FindMidNode(LinkedList L) {
	LinkedList p1 , 
	p2, temp;
	p1 = p2 = L;
	
	do{
		
		p2 = p2->next->next;
		p1 = p1->next;
		 
	}while(p2!=NULL&&p2->next!=NULL); 
	
	if(p2==NULL){
		//奇数个节点
		 printf("中间节点有一个！\n");
		 printf("数值为：%d",p1->data);
	}else{
		//偶数个节点
		printf("中间节点有两个！\n");
		printf("数值为：%d 和 %d \n",p1->data,p1->next->data);	 
	} 
	return ;
}
//按递增进行排序 
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

