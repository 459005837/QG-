#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
int n , c, msg; 	
DuLinkedList L,p;
void (*visit)(ElemType e);
//����ͷ�ڵ� 
L=(DuLinkedList)malloc(sizeof(DuLNode));
L->next=NULL;
L->prior=NULL;
Menus();
printf("�����빦����ţ�������0�˳�����");
msg = scanf("%d",&n);fflush(stdin);
printf("\n");

while(1){
	//��Ч�ַ� 
	if(msg!=1){
		printf("\n������Ч�����������룺");
		msg = scanf("%d",&n);fflush(stdin);
		printf("\n"); 
	}
	//����0 
	else if(n==0&&msg==1){
		break;
	}
	//��������0Ҳ������Ч�ַ� 
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
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					printf("������Ҫɾ�������ݣ�\n");
					msg = scanf("%d",&c);fflush(stdin);//���Ϊ���ֵĻ�msgΪ1 
					if(msg!=1){
						printf("����������Ч��");
					}else{
						DeleteList_DuL(L, c); 	
					}
					break;
			case 3: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					p=(DuLinkedList)malloc(sizeof(DuLNode));
					printf("������Ҫ��������ݣ�\n");
					msg = scanf("%d",&p->data);fflush(stdin);
					if(msg!=1){
						printf("����������Ч��");
					}else{
						InsertBeforeList_DuL(L, p);
					}
					break;
			case 4: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					p=(DuLinkedList)malloc(sizeof(DuLNode));
					printf("������Ҫ��������ݣ�\n");
					msg = scanf("%d",&p->data);fflush(stdin);
					if(msg!=1){
						printf("����������Ч��");
					}else{
						InsertAfterList_DuL(L, p);
					}
					break;
			case 7: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
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
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					TraverseListBack_DuL(L,visit);
					break; 
					
			case 5: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					ReverseEvenList(L);
					printf("�������ż������\n");
					break;

			default :
					printf("δ�ҵ��ù���ѡ�");break; 
		}
		Menus();
		printf("�����빦����ţ�������0�˳�����");
		msg = scanf("%d",&n);fflush(stdin);
		printf("\n"); 
	}
}
return 0; 

} 
