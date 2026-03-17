#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node *next;
	struct node *last;
};

struct node *front = NULL;
struct node *rear = NULL;


void insert_head(int n);
void insert_tail(int n);
void delete_head(void);
void delete_tail(void);

void reverse(void);
void swap(int *a,int *b);

int search(int target,struct node **locate);
void insert_target(int n,struct node **locate,int mode);
void delete_target(struct node **locate,int mode);
void list_output(int,int);

void output();

int count = 0;//計算list中有幾個數

//head  ->  tail   
/*front ->(<-last  current  next->) -> rear*/

//從頭印出

int main(){
	int n = 0;//輸入的整數
	int mode = 0;
	
	int target = 0;//目標節點的值
	int location;//目標節點的位置
	struct node *current = NULL;//指向目標節點位置 (line97 ~ line133)
	
	
	do{
		printf("Please choose what you want to do : 1.insert to tail  2. insert to head  3.delete tail  4.delete head  5.reverse  6.search  7.Exit\n");
		scanf("%d",&mode);
		
		switch(mode){
			case 1:
				printf("Please enter the value to add : ");
				scanf("%d",&n);
				
				insert_tail(n);
				output();
				break;
				
			case 2:
				printf("Please enter the value to add : ");
				scanf("%d",&n);
				
				insert_head(n);
				output();
				break;
				
			case 3:
				if(rear == NULL){
					printf("The link list is empty!\n\n");
					continue;
				}
				
				delete_tail();
				output();
				break;
				
			case 4:
				if(rear == NULL){
					printf("The link list is empty!\n\n");
					continue;
				}
				
				delete_head();
				output();
				break;
				
			case 5:
				if(rear == NULL){
					printf("The link list is empty!\n\n");
					continue;
				}
				else if(count>1)//小於1不用反轉
					reverse();
				
				output();
				break;
				
			case 6://search
				if(rear == NULL){
					printf("The link list is empty!\n\n");
					continue;
				}
				
				printf("Please enter the value to search : ");
				scanf("%d",&target);
				
				location = search(target,&current);
				
				if(location == -1){//link list中找不到目標數值
					printf("\n【Unfound the value in the link list!】\n\n");
					continue;
				}
				else
					list_output(target,location);
				
				printf("Please choose what you want to do at target node : 1.insert a value to next  2.insert a value to prev  3.delete target value  4.Exit\n");
				scanf("%d",&mode);
				
				switch(mode){
					case 1:
					case 2:
						printf("Please enter a value to insert : ");
						scanf("%d",&n);
						
						insert_target(n,&current,mode);
						output();
						break;
						
					case 3:	
						delete_target(&current,mode);
						output();
					case 4:
						break;
						
					default:
						printf("【Enter wrong mode! Please search again!!】\n\n");
						continue;//此處continue不可寫成break，輸入mode = 7時會跳出迴圈
				}
			case 7://end;
				break;
				
			default:
				printf("【Enter wrong mode!】\n\n");
				break;
		}
	}while(mode!=7);
	
	printf("【ending】\n");
	return 0;
}


void insert_tail(int n){
	struct node *current;
	current = malloc(sizeof(struct node));
	
	if(rear == NULL){	
		current->n = n;
		current->next = NULL;
		
		front = current;
		rear = current;
	}
	else{
		current->n = n;
		current->next = NULL;
		
		current->last = rear;
		rear->next = current;
		
		rear = current;
	}
	
	count++;
}


void insert_head(int n){
	struct node *current;
	current = malloc(sizeof(struct node));
	
	if(front == NULL){	
		current->n = n;
		current->last = NULL;
		
		front = current;
		rear = current;
	}
	else{
		current->n = n;
		current->last = NULL;
		
		current->next = front;
		front->last = current;
		
		front = current;
	}
	count++;
}


void delete_tail(void){
	if(count == 1){
		free(rear);
		front = rear = NULL;
	}
	else{
		struct node *current;
	
		current = rear;
		rear = rear->last;
		rear->next = NULL;
	
		free(current);
	}
	count--;
}


void delete_head(void){
	if(count == 1){
		free(front);
		front = rear = NULL;
	}
	else{
		struct node *current;
	
		current = front;
		front = front->next;
		front->last = NULL;
	
		free(current);
	}
	
	count--;
}


void reverse(void){
	struct node *run1,*run2;
	run1 = front;
	run2 = rear;
	
	if(count%2 == 0){
		do{
			swap(&(run1->n),&(run2->n));
			run1 = run1->next;
			run2 = run2->last;
		}while(run1->last != run2);
	}
	else{
		while(run1 != run2){
			swap(&(run1->n),&(run2->n));
			run1 = run1->next;
			run2 = run2->last;
		}
	}
}


void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int search(int target,struct node **locate){
	int times = 1;
	*locate = front;
	
	while(*locate != NULL){
		if((*locate)->n == target)
			break;
		
		*locate = (*locate)->next;
		times++;
	}
	
	if(times == count+1)
		return -1;
	else 
		return times;
}


void list_output(int target,int locate){
	int single = locate%10;
	
	printf("%d is at %d",target,locate);
	
	switch(single){
		case 1:
			printf("st");
			break;
		case 2:
			printf("nd");
			break;
		case 3:
			printf("rd");
			break;
		default:
			printf("th");
			break;
	}
	
	printf(" node\n\n");
}


void insert_target(int n,struct node **locate,int mode){
	/*locate = target node*/
	struct node *current = malloc(sizeof(struct node));
	
	current->n = n;
	
	if(mode == 1){//insert a value to next
		if(*locate == rear){//目標節點為list尾端時，需特別處理
			current->next = NULL;
			rear = current;
			
			(*locate)->next = current;
			current->last = *locate;
		}
		else{
			(*locate)->next->last = current;
			current->next = (*locate)->next;
		
			(*locate)->next = current;
			current->last = *locate;
		}
	}
	else{//insert a value to last
		if(*locate == front){//目標節點為list前端時，需特別處理
			current->last == NULL;
			front = current;
			
			(*locate)->last = current;
			current->next = *locate;
		}
		else{
			(*locate)->last->next = current;
			current->last = (*locate)->last;
		
			(*locate)->last = current;
			current->next = *locate;
		}
	}
	
	count++;
}


void delete_target(struct node **locate,int mode){
	if(count == 1)
		front = rear = NULL;
		
	else if(*locate == front){
		(*locate)->next->last = NULL;
		front = (*locate)->next;
	}
		
	else if(*locate == rear){
		(*locate)->last->next = NULL;
		rear = (*locate)->last;
	}
		
	else{
		(*locate)->last->next = (*locate)->next;
		(*locate)->next->last = (*locate)->last;
	}
	
	free(*locate);
	count--;
}


void output(){
	if(rear == NULL){
		printf("The link list is empty!\n\n");
		return;
	}
	
	struct node *current = front;
	
	for(int i=0; i<(1+7*count); i++)
		printf("*");
	printf("\n");
	
	
	for(int i=0; i<2; i++){
		printf("*");
		for(int j=0; j<count; j++){
			for(int k=0; k<6; k++)
				printf(" ");
			printf("*");
		}	
		printf("\n");
	}
	
	
	printf("*");
	for(int i=0; i<count; i++){
		printf("%4d  *",current->n);
		current = current->next;
	}
	printf("\n");
	
	for(int i=0; i<2; i++){
		printf("*");
		for(int j=0; j<count; j++){
			for(int k=0; k<6; k++)
				printf(" ");
			printf("*");
		}	
		printf("\n");
	}
	
	for(int i=0; i<1+7*count; i++)
		printf("*");
	printf("\n\n");
}