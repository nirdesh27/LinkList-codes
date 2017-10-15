#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next;
struct node *pre;
}Dlist;
void DlistInsertion ( Dlist **head,int data,int position){
	int k=1;
	Dlist *temp,*newNode;
	newNode=(Dlist*)malloc(sizeof(Dlist));
	//if(newNode){printf("memory error"); return;}
	newNode->data=data;
	if(position==1){
		newNode->next=*head;
		newNode->pre=NULL;
		if(*head){
			(*head)->pre=newNode;
		}
		*head=newNode;
		return;
		
	}
	temp=*head;
	while((k<position-1)&&temp->next!=NULL){
		temp=temp->next;k++;
	}
	if(k!=position-1){
		printf("desire posotion is not exist\n");
		
	}
	newNode->next=temp->next;
	newNode->pre=temp;
	if(temp->next)
		temp->next->pre=newNode;
	temp->next=newNode;
	return;
}
printDlist(Dlist * head){printf("\n"); Dlist *current=head;
	while(current!=NULL){
		printf("\t%d",current->data); current=current->next;
	}
}
freeDlist(Dlist** head){
	Dlist *p,*q;
	p=*head;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	printf("\tmemory has freed my friend..don't worry\t%c",12);
}
int DlistLength(Dlist *head){int m=0;Dlist *current=head;
while(current!=NULL){ current=current->next;
m++;}
return m;
}
deleteDlist(Dlist** head,int position){int m=DlistLength(*head);
if(*head==NULL){
	printf("list is empty\n");
	return;
}

	Dlist *temp=*head; int k=1;
	if(position==1){
		*head=(*head)->next;
		if(*head!=NULL)
			(*head)->pre=NULL;
		free(temp);
		return;
	}
	
	while(k<position){  temp=temp->next;k++;}
				if(position<m){		 (temp->pre)->next=temp->next;
	                     (temp->next)->pre=temp->pre;
				free(temp);}
				if(position==m){(temp->pre)->next=NULL;temp->pre=NULL;
				free(temp);}
				
			
}
int main(){
	Dlist * head=(Dlist*)malloc(sizeof(Dlist));
	head->data=15;
	head->next=NULL;
	head->pre=NULL;
	DlistInsertion(&head,7,2);
	DlistInsertion(&head,40,3);
	DlistInsertion(&head,4,1);
	DlistInsertion(&head,299,3);
	DlistInsertion(&head,399,0);
	DlistInsertion(&head,499,0);
	DlistInsertion(&head,599,1);
	printDlist(head);printf("\n%d",DlistLength(head));
    deleteDlist(&head,7);
	printf("\n%d",DlistLength(head));
	deleteDlist(&head,7);
	deleteDlist(&head,1);
	printf("\n%d",DlistLength(head));
	printDlist(head);
	freeDlist(&head); return 0;
}