#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
int n , c, msg; 	
LinkedList L,p;
//����ͷ�ڵ� 
L=(LinkedList)malloc(sizeof(LNode));
L->next=NULL;
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
						L=(LinkedList)malloc(sizeof(LNode));
						L->next=NULL;
					}
					InitList(L); break;
			case 2: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					printf("������Ҫɾ�������ݣ�\n");
					msg = scanf("%d",&c);fflush(stdin);//���Ϊ���ֵĻ�msgΪ1 
					if(msg!=1){
						printf("����������Ч��");
					}else{
						DeleteList(L, c); 	
					}
					break;
			case 3: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					p=(LinkedList)malloc(sizeof(LNode));

					//���Զ�����
					Sort(L); 
					//�ٴ�ӡ���� 
					printf("ϵͳ��Ϊ���Զ�����! ������Ҫ��������ݣ�\n");
					msg = scanf("%d",&p->data);fflush(stdin);
					if(msg!=1){
						printf("����������Ч��");
					}else{
						InsertList(L, p);
					}
						printf("�������ݳɹ���\n");
					break;
			case 4: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					printf("������Ҫ���ҵ����ݣ�\n");
					msg = scanf("%d",&c);fflush(stdin);//���Ϊ���ֵĻ�msgΪ1 
					if(msg!=1){
						printf("����������Ч��");
					}else{
						SearchList(L,c); 	
					}
					break;
			case 5: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
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
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					ReverseList(L);
					printf("�����ѷ�ת��\n");
					break;
			case 8:	
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					IsLoopList(L);
					break; 						
			case 9: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					ReverseEvenList(L);
					printf("�������ż������\n");
					break;
			case 10: 
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					FindMidNode(L);
					break; 
			case 11:
					if(L==NULL||L->next==NULL){
						printf("����Ϊ�տ��ؽ�һ����\n");
						break;
					}
					Sort(L);
					printf("����ɹ�!\n"); 
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
