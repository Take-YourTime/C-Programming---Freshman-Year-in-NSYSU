#include<stdio.h>
#include<stdlib.h>

#define queue1 0
#define queue2 1
#define true 1

struct node{
	int n;
	struct node *next;
};

struct node *front[2] = {NULL,NULL};
struct node *rear[2] = {NULL,NULL};


void swap(struct node**,struct node**);
void push(int);
void pop(void);
void enqueue(int,int);
int dequeue(int);


int main(){
	int mode = 0;
	int n;
	int count = 0;
	
	struct node *current;
	
	
	do{
		printf("Please choose what you want to do : 1.push 2.pop 3.Exit\n");
		scanf("%d",&mode);
		
		switch(mode){
			case 1:
				printf("Please enter the value to push : ");
				scanf("%d",&n);
				
				count++;
				push(n);
				break;
				
			case 2:
				if(rear[queue1] == NULL){
					printf("The stack is empty!\n\n");
					continue;
				}
				
				count--;
				pop();
				break;
				
			case 3:
				goto end;
				
			default:
				printf("Enter wrong mode!\n\n");
				continue;
		}
		
		/*---------------------------------------------------*/
		
		
		if(rear[queue1] == NULL){
			printf("The stack is empty!\n\n");
			continue;
		}
			
		current = front[queue1];
		
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


void swap(struct node **a,struct node **b){
	struct node *temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/*logic : a -> rear[queue1] ->struct node*/

void push(int n){
	enqueue(n,queue2);
	
	while(rear[queue1] != NULL)
		enqueue( dequeue(queue1),queue2 );
	
	swap(&rear[queue1],&rear[queue2]);
	swap(&front[queue1],&front[queue2]);
}


void pop(void){
	dequeue(queue1);
}


/* ->rear <- <- front-> */
void enqueue(int n,int list){
	struct node *current;
	current = malloc(sizeof(struct node));
	
	current->n = n;
	
	if(front[list] == NULL){
		front[list] = current;
		rear[list] = current;
	}
	else{
		rear[list]->next = current;
		rear[list] = current;
	}	
}


int dequeue(int list){
	int n;
	
	if(rear[list] == front[list]){
		n = rear[list]->n;
		
		free(rear[list]);
		
		front[list] = NULL;
		rear[list] = NULL;
	}
	else{
		struct node *current;
		current = front[list];
		n = current->n;
		
		front[list] = current->next;
	
		free(current);
	}
	
	return n;
}