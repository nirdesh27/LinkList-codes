#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int capacity;
	int front;
	int rear;
	int *array;
}queue;
queue* createQueue(int capacity){
	queue *q=(queue*)malloc(sizeof(queue));
	q->capacity=capacity;
	q->front=-1;
	q->rear=-1;
	q->array=(int*)malloc(sizeof(int)*q->capacity);
	return q;
}
int isEmpty(queue* q){
	return (q->front==-1);
}
int isFull(queue* q){
	return((q->rear+1)%q->capacity==q->front);
}
 void enqueue(queue* q, int data){
	 if(isFull(q)) {printf("full hai");return;}
	 else{
		 q->rear=(q->rear+1)%q->capacity;
		 q->array[q->rear]=data;
	 }
	 if(q->front==-1){q->front=q->rear;}
	 printf("inserted\n");
 }
 int dequeue(queue* q){
	int data=0;
	if(isEmpty(q)){printf("queue is empty bro..");return 0;}
	else{
		data=q->array[q->front];
		if(q->front==q->rear) q->front=q->rear=-1;else q->front=(q->front+1)%q->capacity;
	}
	 return data;
	 
 }
 int main(){
	  queue* q1=createQueue(5);
	  enqueue(q1,10);
	  enqueue(q1,20);
	 //  enqueue(q1,30);
	   // enqueue(q1,40);
		// enqueue(q1,50);
		// enqueue(q1,60);
		printf("%d\n",dequeue(q1));
		printf("%d\n",dequeue(q1));
		printf("%d\n",dequeue(q1));
		
		 
	 return 0;
	}
 
