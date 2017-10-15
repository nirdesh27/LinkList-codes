#include "list.h"
#include<stdio.h>
#include<stdlib.h>

int size(node* head)
{
 int i=0;
 if(head==NULL) return 0;
 while(head!=NULL) { 
                     head=head->next; i++;
                    }
 return i;
}

int isEmpty(node * head)
{
if(head==NULL) return 1;
return 0;
}

int isFirst(node* list,node* position)
{
if(list==position) return 1;
return 0;
}

int isLast(node* list,node* position)
{
if(position->next==NULL) return 1;
return 0;
}

node* first(node* list)
{
return list;
}

node* last(node* list)
{
if(list==NULL) return list;
while(list->next!=NULL) list=list->next;
return list; 
}

node* before(node* list,node* position)
{
if(list==NULL||isFirst(list,position)) return NULL;
while(list->next!=position) list=list->next;
return list;
}

node* after(node* list,node* position)
{
	if(list==NULL||isLast(list,position)) return NULL;
	return position->next;
}

void replaceElement(node* position,int a)
{
	if(position!=NULL) position->value=a;
	return;
	
}

void swapElement(node* position1,node* position2)
{
	
	int temp;
	if(position1==NULL||position2==NULL) return ;
    temp=position1->value;
	position1->value=position2->value;
	position2->value=temp;
	return;
}

void insertBefore(node* list,node* position,int a)      //if list is empty or position is null returns NULL
{                                                         //if list is empty returns
	node *prev;
	node *new;
	new=(node*)malloc(sizeof(node));
	new->value=a;
	if ((list==NULL)||(position==NULL)) return  ;
	prev=before(list,position);
	if(prev==NULL)
		if(!isFirst(list,position)) return ;
	prev->next=new;
	new->next=position;
	return ;
}
 
void insertAfter(node* list,node* position,int a)    //if list is empty or position is null returns NULL
{                                                    //if list is empty returns
	
	node *new;
	node* following;
	new=(node*)malloc(sizeof(node));
	new->value=a;
	if((list==NULL)||(position==NULL)) {return ;}
	following=after(list,position);
	if(following==NULL){if(!isLast(list,position)) return; position->next=new; new->next=NULL; return ;}
	new->next=following;
	position->next=new;
	return ;
	
}

node* insertFirst(node* list,int a)         //inserts node at start, and returns pointer to list//
{                                              //if list is empty creates it.
	
	node* new;
	new=(node*)malloc(sizeof(node));
	new->value=a;
	if(list==NULL) {new->next=NULL; list=new; return list;}
	new->next=list;
	list=new;
	return list;
}

node* insertLast(node* list, int a)           //inserts node at last of list & returns pointer to the last element of list.
                                                   //if list is empty it creates the list
{
	
	node* new;
	node* end;
	new=(node*)malloc(sizeof(node));
	new->value=a;
	if(list==NULL){new->next=NULL; return new; }
	end=last(list);
	end->next=new;
	new->next=NULL;
	end=new;
	return end;
}

void clean(node* list,node* position)            //removes the position and returns pointer to the list//
{
	
	node* temp;
	if(list==NULL||position==NULL) return;
	if(list==position){
		                if(position->next==NULL){list=NULL; free(position); return;}
						list=list->next; free(position); return  ; 
	                   }
	if(position->next=NULL){
		                    temp=before(list,position);
							temp->next=NULL;
		                    free(position);
							return;
	                       }
    temp=before(list,position);
    temp->next=position->next;
    free(position);	
    return;
}