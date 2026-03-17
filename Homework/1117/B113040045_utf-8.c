#include<stdio.h>
#include<stdlib.h>

/*------------------------------*/
struct queue{
	int n;
	struct queue *next;
	struct queue *last;
};

struct queue *front = NULL;
struct queue *bottom = NULL;

struct queue *current = NULL;
/*------------------------------*/

struct stack{//儲存unsorted
	int integer;
	struct stack *pre;
};

struct stack *top = NULL;

/*------------------------------*/

struct sort{//儲存sorted
	int integer;
	struct sort *pre;
};

struct sort *top_sort = NULL;

/*------------------------------*/

void findwinner(void);
void enqueue(int);
void push(int);
void push_sort(int);
int pop(void);
int pop_sort(void);
void sorting(int);

/*------------------------------*/

int main(){
	FILE *file = fopen("test.txt","r");
	
	int k=0;
	int n=0;//讀檔、從stack中讀數字
	int count = 0;//計算有幾位玩家、計算次數
	
	struct stack *run = NULL;
	struct sort *run_sort = NULL;
		
	printf("Please enter a value for k : ");
	scanf("%d",&k);
	
	printf("Original : \n");
	
	while( !feof(file) ){ // enqueue
		fscanf(file,"%d",&n);
		enqueue(n);
		count++;//計算玩家數
	}
	
	
	if(k>count)//當 k>count 時，只要取 k/count 的餘數來計算即可，否則run的時候會多跑一圈以上
		k=k%count;
	
	
	const int player = count+1;//所有玩家數+1 
	
	front->next = bottom;//front此時為queue的末端，將front和first互指，形成環狀queue
	bottom->last = front;
	
	current = bottom;//current用於run玩家編號
	
	while(count>1){
		printf("\n\n %d round : \n",player-count);
		count--;
		
		for(int i=0 ; i<k-1 ; i++)//因為清除節點後，current會往前移一位，因此 k 需要 -1
			current = current->next;
			
		findwinner();
		
		for(int i=0;i<count;i++){ //印出剩餘玩家編號
			printf("%d->",bottom->n);
			bottom = bottom->next;
		}
	}
	
	printf("\n\nThe winner is No.%d\n\n\n",bottom->n);
	
	push(bottom->n);//將贏家的編號丟入stack
	
	
	/*count此時 = 1*/
	//計算while執行第幾輪
	
	/*初始的unsorted stack*/
	printf("unsorted stack : \n");
	run = top;
	while(run!=NULL){
		printf("%d->",run->integer);
		run = run->pre;
	}
	printf("NULL\n\n");
	
	/*sort*/
	while(top!=NULL){
		printf("第%d輪\n",count);
		count++;
		
		sorting( pop() );//呼叫函式sorting
			
		/*unsorted*/
		run = top;//run用於印出 stack中的值
		printf("unsorted stack :\n");
		
		while(run!=NULL){
			printf("%d->",run->integer);
			run = run->pre;
		}
		printf("NULL\n");
		/*------------------------------*/
		
		/*sorted*/
		run_sort = top_sort;
		printf("sorted stack :\n");
		
		while(run_sort!=NULL){
			printf("%d->",run_sort->integer);
			run_sort = run_sort->pre;
		}
		printf("NULL\n\n");
		/*------------------------------*/
	}
	
	
	return 0;
}


void findwinner(void){
	struct queue *start = NULL;//清除節點時，用於暫存
		
	push(current->n);//存入stack
			
	start = current->next;
		
	/*清除節點*/
	current->last->next = current->next;
	current->next->last = current->last;
		
	if(bottom == current)
		bottom = bottom->next;
			
	free(current);
	/*----------*/
	
	current = start;
}


void enqueue(int n){
	struct queue *current;
	current = malloc(sizeof(struct queue));
	
	current->n = n;
	
	if(front!=NULL)
		front->next = current;//原先首位下一個指到current
	else
		bottom = current;//以first記錄第一個節點
		
	current->last = front;//current的上一個指到原先首位
	front = current;//首位改成current
	
	printf("%d->",(front->n));//印出原始玩家編號
}


void push(int n){
	struct stack *current;
	current = malloc(sizeof(struct stack));
	
	current->integer = n;
	current->pre = top;
	top = current;
}


void push_sort(int n){
	struct sort *current;
	current = malloc(sizeof(struct stack));
	
	current->integer = n;
	current->pre = top_sort;
	top_sort = current;
}


int pop(void){//for stack
	struct stack *current;
	int n;
	
	current = top;
	top = top->pre;
	
	n=current->integer;
	
	free(current);
	
	return n;
}


int pop_sort(void){
	struct sort *current;
	int n;
	
	current = top_sort;
	top_sort = top_sort->pre;
	
	n=current->integer;
	
	free(current);
	
	return n;
}


void sorting(int n){//大到小排序
	if(top_sort!=NULL){
		while(n < (top_sort->integer) ){
			push( pop_sort() );//將「堆疊sort」取出的東西丟到stack
			
			if(top_sort==NULL)
				break;
		}
	}
	
	push_sort(n);
}