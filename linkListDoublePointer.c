#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
	int data;
	struct ListNode * next;
}stack;
stack * createStack(){
	return NULL;
}
void Push(stack **top,int data){
	stack* temp;
	temp = (stack*)malloc(sizeof(stack));
	temp->data = data;
	temp->next = *top;
	*top = temp;
}
int isEmptyStack(stack * top){
	return top ==NULL;
}
int pop(stack** top){
	int data;
	stack* temp;
	temp = *top;
	*top = (*top)->next;
	data = temp->data;
	free(temp);return data;
}
int top( stack* top){
	if(isEmptyStack(top)){
		printf("empty");
		return 0;
	}
		return top->next->data;
	
}
void print(stack** s){
	stack* temp = *s;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp= temp->next;
	}
}
void delete(stack** top){
	stack * temp,*p;
	p=*top;
	while(p->next){
		temp=p->next;
		p->next = temp->next;
		free(temp);
	}
	free(p);
}
int main(){
	stack* s = createStack();
	Push(&s,1);
	Push(&s,2);
	Push(&s,3);
	Push(&s,4);
	Push(&s,5);
	Push(&s,6);
	print(&s);
	int value =pop(&s);
	print(&s);
}
