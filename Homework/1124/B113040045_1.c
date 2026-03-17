#include<stdio.h>
#include<stdlib.h>

#define stack1 0
#define stack2 1
#define true 1

struct stack{
	int n;
	struct stack *next;
};

struct stack *top[2] = {NULL,NULL};


void enqueue(int);
void dequeue(void);
void push(int,int);
int pop(int);


int main(){
	int mode = 0;
	int n;
	int count = 0;//計算堆疊中有幾個數
	
	struct stack *current;
	
	/*
	將固定數列放置於stack2,stack1只用於enqueue和dequeue，

	如此一來可方便走訪並輸出整個數列堆疊
	*/
	
	do{
		printf("Please choose what you want to do : 1.Enqueue 2.Dequeue 3.Exit\n");
		scanf("%d",&mode);
		
		switch(mode){
			case 1:
				printf("Please enter the value to enqueue :　");
				scanf("%d",&n);
				
				enqueue(n);
				count++;
				break;
				
			case 2:
				if(top[stack1] == NULL){
					printf("The queue is empty!\n\n");
					continue;
				}
					
				dequeue();
				count--;
				break;
				
			case 3:
				goto end;//結束迴圈
				
			default:
				printf("Enter wrong mode!\n\n");
				continue;
		}
		
		/*---------------------------------------------------*/
		/*列印*/
		
		if(top[stack1] == NULL){
			printf("The queue is empty!\n\n");
			continue;
		}
			
		current = top[stack1];
		
		for(int i=0;i<1+7*count;i++)
			printf("*");
		printf("\n");
		
		for(int i=0;i<2;i++){
			for(int j=0;j<count;j++){
				printf("*");
				
				for(int k=0;k<6;k++)
					printf(" ");
			}
			printf("*\n");
		}
		
		for(int i=0;i<count;i++){
			printf("*");
				
			printf("%4d",current->n);
			current = current->next;
			
			for(int j=0;j<2;j++)
				printf(" ");
		}
		printf("*\n");
		
		for(int i=0;i<2;i++){
			for(int j=0;j<count;j++){
				printf("*");
				
				for(int k=0;k<6;k++)
					printf(" ");
			}
			printf("*\n");
		}
		
		for(int i=0;i<1+7*count;i++)
			printf("*");
		printf("\n\n");
		/*---------------------------------------------------*/
			
	}while(true);
	
	end:
	
	return 0;
}


void enqueue(int n){
	while(top[stack1] != NULL)//將數列放入stack2
		push( pop(stack1),stack2 );
		
	push(n,stack2);//存入stack1
	
	while(top[stack2] != NULL)//將數列放回stack1，stack2固定是空的
		push( pop(stack2),stack1 );
}


void dequeue(){
	pop(stack1);
}


void push(int n,int list){
	struct stack *current;
	current = malloc(sizeof(struct stack));
	
	current->n = n;
	current->next = top[list];
	
	top[list] = current;
}


int pop(int list){
	struct stack *current;
	int n;
	
	current = top[list];
	n = current->n;
	
	top[list] = top[list]->next;
	
	free(current);
	return n;
}
