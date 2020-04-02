#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
int n , c, msg; 	
DuLinkedList L,p;
void (*visit)(ElemType e);
//创建头节点 
L=(DuLinkedList)malloc(sizeof(DuLNode));
L->next=NULL;
L->prior=NULL;
Menus();
printf("请输入功能序号，或数字0退出程序：");
msg = scanf("%d",&n);fflush(stdin);
printf("\n");

while(1){
	//无效字符 
	if(msg!=1){
		printf("\n输入无效，请重新输入：");
		msg = scanf("%d",&n);fflush(stdin);
		printf("\n"); 
	}
	//数字0 
	else if(n==0&&msg==1){
		break;
	}
	//不是数字0也不是无效字符 
	else if(n!=0&&msg==1){
		switch(n){
			case 1: 
					if(L==NULL){
						L=(DuLinkedList)malloc(sizeof(DuLNode));
						L->next=NULL;
						L->prior= NULL; 
					}
					InitList_DuL(L); break;
			case 6: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					printf("请输入要删除的数据：\n");
					msg = scanf("%d",&c);fflush(stdin);//如果为数字的话msg为1 
					if(msg!=1){
						printf("输入数据无效！");
					}else{
						DeleteList_DuL(L, c); 	
					}
					break;
			case 3: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					p=(DuLinkedList)malloc(sizeof(DuLNode));
					printf("请输入要插入的数据：\n");
					msg = scanf("%d",&p->data);fflush(stdin);
					if(msg!=1){
						printf("输入数据无效！");
					}else{
						InsertBeforeList_DuL(L, p);
					}
					break;
			case 4: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					p=(DuLinkedList)malloc(sizeof(DuLNode));
					printf("请输入要插入的数据：\n");
					msg = scanf("%d",&p->data);fflush(stdin);
					if(msg!=1){
						printf("输入数据无效！");
					}else{
						InsertAfterList_DuL(L, p);
					}
					break;
			case 7: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					TraverseList_DuL(L,visit);
					break; 
			case 2:
				
					DestroyList_DuL(L);
					L =NULL;
					break;
			case 8:
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					TraverseListBack_DuL(L,visit);
					break; 
					
			case 5: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					ReverseEvenList(L);
					printf("已完成奇偶调换！\n");
					break;

			default :
					printf("未找到该功能选项！");break; 
		}
		Menus();
		printf("请输入功能序号，或数字0退出程序：");
		msg = scanf("%d",&n);fflush(stdin);
		printf("\n"); 
	}
}
return 0; 

} 
