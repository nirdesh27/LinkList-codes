#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data ;
	struct node *next;
}circularList;
int circularLength(circularList* head){
	circularList *current=head;
	int count=0;
	if(head==NULL) return 0;
	do{
		current =current->next;
		count++;
	}while(current!=head);
	return count;
}
printCircularList(circularList* head){
	circularList* current=head;
	if(head==NULL) return;
	do{
		printf("\t%d\n",current->data);
		current=current->next;
	}while(current!=head);
	
}
 insertAtEnd(circularList**head,int data){
	 circularList* current=*head;
	 circularList* newNode=(circularList*)malloc(sizeof(circularList));
	 newNode->data=data;
	 while(current->next!=*head) current=current->next;
	 newNode->next=newNode;
	 if(*head==NULL){*head=newNode;}else{newNode->next=*head;current->next=newNode;}
 }
 insertAtBegin(circularList**head,int data){
	 circularList* current=*head;
	 circularList* newNode=(circularList*)malloc(sizeof(circularList));
	 newNode->data=data;
	 while(current->next!=*head) current=current->next;
	 newNode->next=newNode;
	 if(*head==NULL)
		 *head=newNode;
	 else{
		 newNode->next=*head;
		 current->next=newNode;
		 *head=newNode;
	 }
	 return;
 }
 DeleteAtEnd(circularList** head){
	 circularList* current=*head;circularList* temp;
	 while((current->next)->next!=*head) current=current->next;
	// printf("\n%d",current->data);
	 temp=current->next;
	 current->next=*head;
	 free(temp);
 }
 DeleteAtBegin(circularList** head){
	 circularList *temp ,*current=*head;temp=*head;
	 while(current->next!=*head) current=current->next;
	 current->next=(*head)->next;
	 *head=(*head)->next;
	 free(temp);
 }
 int main(){
	 circularList* head=(circularList*)malloc(sizeof(circularList));
	 head->data=100;
	 head->next=head;
	 insertAtEnd(&head,200);
	 insertAtEnd(&head,300);
	 insertAtEnd(&head,400);
	 insertAtEnd(&head,400);
	 insertAtEnd(&head,500);
	 insertAtEnd(&head,600);
	 insertAtBegin(&head,50);insertAtBegin(&head,25);
	 printCircularList(head);
	// DeleteAtEnd(&head);
	DeleteAtBegin(&head);
	 printCircularList(head);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 