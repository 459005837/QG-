#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
int n , c, msg; 	
LinkedList L,p;
//创建头节点 
L=(LinkedList)malloc(sizeof(LNode));
L->next=NULL;
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
						L=(LinkedList)malloc(sizeof(LNode));
						L->next=NULL;
					}
					InitList(L); break;
			case 2: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					printf("请输入要删除的数据：\n");
					msg = scanf("%d",&c);fflush(stdin);//如果为数字的话msg为1 
					if(msg!=1){
						printf("输入数据无效！");
					}else{
						DeleteList(L, c); 	
					}
					break;
			case 3: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					p=(LinkedList)malloc(sizeof(LNode));

					//先自动排序
					Sort(L); 
					//再打印链表 
					printf("系统已为您自动排序! 请输入要插入的数据：\n");
					msg = scanf("%d",&p->data);fflush(stdin);
					if(msg!=1){
						printf("输入数据无效！");
					}else{
						InsertList(L, p);
					}
						printf("插入数据成功！\n");
					break;
			case 4: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					printf("请输入要查找的数据！\n");
					msg = scanf("%d",&c);fflush(stdin);//如果为数字的话msg为1 
					if(msg!=1){
						printf("输入数据无效！");
					}else{
						SearchList(L,c); 	
					}
					break;
			case 5: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					Print(L); 
					break; 
			case 6:
				
					DestroyList(L);
					L =NULL;
					break;
			case 7:
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					ReverseList(L);
					printf("链表已反转！\n");
					break;
			case 8:	
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					IsLoopList(L);
					break; 						
			case 9: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					ReverseEvenList(L);
					printf("已完成奇偶调换！\n");
					break;
			case 10: 
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					FindMidNode(L);
					break; 
			case 11:
					if(L==NULL||L->next==NULL){
						printf("链表为空可重建一链表！\n");
						break;
					}
					Sort(L);
					printf("排序成功!\n"); 
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
