#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

#define stack1 0
#define stack2 1

struct node{
	int n;
	struct node *left;
	struct node *right;
};


struct node *tree_top = NULL;

struct node *level_top = NULL;//use for level order
/*---------------------*/

struct stack{
	int n;
	struct stack *next;
};

struct stack *top[2] = {NULL,NULL};

/*---------------------*/
void create_number(void);
void insert(int,struct node **);

void delete(int key);
struct node* search(int key);

void preorder(struct node **);
void inorder(struct node **);
void postorder(struct node **);


void enqueue(int n);
void dequeue(void);
void push(int n,int list);
int pop(int list);
void printqueue(void);

void levelorder(struct node **root);

int i,j,k;
int count = 0;//計算queue中有幾個元素 
int det[1001];//偵測tree中的數是否重複  (範圍：0 ~ 1001)  (如果要輸入更大的數字，可以把陣列開更大一點)


int main(){
	int n = 0;//input
	
	create_number();
	
	/*---------------------*/
	int mode = 0;
	
	
	
	while(true){
		printf("Please choose what you want to do with tree : 1.Insert  2.Delete  3.Traversal  4.Exit\n");
		scanf("%d",&mode);
		
		switch(mode){
			case 1:
				printf("Please enter the value to insert : ");
				scanf("%d",&n);
				
				if(det[n] == 1){//樹中的數字不能重複 
					printf("The value has been inside the tree.\n\n");
					continue;
				}
				det[n] = 1;
				
				insert(n,&tree_top);
				continue;
				
			case 2:
				printf("Please insert the value to delete : ");
				scanf("%d",&n);
				
				delete(n);//超麻煩 =_=
				
				continue;
				
			case 3:
				if(tree_top == NULL){
					printf("The tree has nothing!!\n\n");
					continue;
				}
				
				printf("In-order traversal:\n");
				inorder(&tree_top);
				printf("\n");
				
				printf("Pre-order traversal:\n");
				preorder(&tree_top);
				printf("\n");
				
				printf("Post-order traversal:\n");
				postorder(&tree_top);
				printf("\n");
				
				continue;
			case 4:
				printf("【ending tree】\n\n");
				break; 
			default:
				printf("【Enter Wrong mode!】\n\n");
				continue;
		}
		break;
	}
	
	/*---------------------*/
	/*Queue*/
	
	do{
		printf("Please choose what you want to do with queue : 1.Enqueue  2.Dequeue  3.Printqueue  4.ClearQueue  5.LevelOrder  6.Exit\n");
		scanf("%d",&mode);
		
		switch(mode){
			case 1:
				printf("Please enter the value to enqueue : ");
				scanf("%d",&n);
				
				enqueue(n);
				printf("\n");
				continue;
				
			case 2:
				if(top[stack1] == NULL)
					printf("Cannot delete! The queue is empty!!\n\n");
				else
					dequeue();
					
				continue;
				
			case 3:
				if(top[stack1] == NULL)
					printf("Cannot search! The queue is empty!!\n\n");
				else
					printqueue();
					
				continue;
				
			case 4://clear
				level_top = NULL;//強制歸零 
				
				while(top[stack1] != NULL)
					insert( pop(stack1),&level_top );//建立tree(level) 
					
				continue;
				
			case 5://LevelOrder
				if(level_top == NULL){
					printf("The tree has nothing!! Maybe you haven't cleared the queue.\n\n");
					continue;
				}
				printf("Level Order traversal of BST is : \n");
				printf("%d->",level_top->n);
				levelorder(&level_top);
				printf("\n\n");
				continue;
				
			case 6://end
				printf("【ending queue】\n\n");
				break;
				
			default:
				printf("【Enter Wrong mode!】\n\n");
				continue;
		}
		
		break;
		
	}while(mode != 6);
	
	
	
	return 0;
}


void create_number(void){
	int n; 
	
	srand(1);
	
	for(i=0;i<101;i++){//歸零 
		det[i] = false;
	}
	
	for(i=0;i<15;i++){
		n = rand()%100+1;
		
		while(det[n] == true){ //true代表該數已出現過 
			n = rand()%100+1;
		}
		
		det[n] = 1;
		
		insert(n,&tree_top);
	}
}


void insert(int n,struct node **temp_top){
	/* *temp_top = top of tree */
	struct node *current;
	current = malloc(sizeof(struct node));
	
	current->n = n;
	current->left = NULL;
	current->right = NULL;
	
	if(*temp_top == NULL){
		*temp_top = current;
		return;
	}
	else{
		struct node *run = *temp_top;
		
		while(true){
			if(n >= run->n){// 因為後面將queue轉成tree時，有機會輸入一樣的數字，因此使用 >=
				if(run->right == NULL){
					run->right = current;
					return;
				}
				else{
					run = run->right;
				}
			}
			else{
				if(run->left == NULL){
					run->left = current;
					return;
				}
				else{
					run = run->left;
				}
			}
		}
	}
}


void delete(int key){
	if(tree_top == NULL){
		printf("Cannot delete. The tree has nothing!!\n\n");
		return;
	}
	
	struct node *target = search(key);
	
	printf("Sorry sir! I don't have time to finish \"delete\", but I finished search() function\n\n");
	
	return;
}


struct node* search(int key){//搜尋目標節點 
	struct node *current = tree_top;
	
	if(tree_top = NULL)
		return NULL;
	
	while(current->n != key){
		
		if(key > current->n){
			if(current->right == NULL){
				return NULL;
			}
			else{
				current = current->right;
			}
		}
		else{
			if(current->left == NULL){
				return NULL;
			}
			else{
				current = current->left;
			}
		}
	}
	
	return current;
}



void preorder(struct node **current){
	if((*current) != NULL){
		printf("%d->",(*current)->n);
		preorder(&((*current)->left) );
		preorder(&((*current)->right) );
	}
	
	return;
}


void inorder(struct node **current){
	if((*current) != NULL){
		inorder(&((*current)->left) );
		printf("%d->",(*current)->n);
		inorder(&((*current)->right) );
	}
	
	return;
}


void postorder(struct node **current){
	if((*current) != NULL){
		postorder( &((*current)->left) );
		postorder( &((*current)->right) );
		printf("%d->",(*current)->n);
	}
	
	return;
}


void enqueue(int n){
	push(n,stack1);
	count++;
}


void dequeue(void){
	if(top[stack1] == NULL){
		printf("The queue is empty!!\n\n");
		return;
	}
	
	while(top[stack1]->next != NULL){
		push(pop(stack1),stack2);
	}
	
	pop(stack1);//delete queue元素 
	
	while(top[stack2] != NULL){
		push(pop(stack2),stack1);
	}
	
	count--;
}


void push(int n,int list){
	struct stack *current;
	current = malloc(sizeof(struct stack));
	
	current->n = n;
	if(top[list] == NULL){
		current->next;
		top[list] = current;
	}
	else{
		current->next = top[list];
		top[list] = current;
	}
}


int pop(int list){
	if(top[list] == NULL)
		return 0;
		
	int n;
	struct stack *current;
	
	current = top[list];
	n = top[list]->n;
	
	top[list] = current->next;
	free(current);
	return n;
}


void printqueue(void){
	if(top[stack1] == NULL)
		printf("The queue is empty!!\n\n");
	
	struct stack *current = top[stack1];
	
	for(i=0;i<count*7+1;i++)
		printf("*");
	printf("\n");
	
	for(i=0;i<2;i++){
		printf("*");
		for(j=0;j<count;j++){
			printf("      *");
		}
		printf("\n");
	}
	
	printf("*");
	for(i=0;i<count;i++){
		printf("%4d  *",current->n);
		current = current->next;
	}
	printf("\n");
	
	for(i=0;i<2;i++){
		printf("*");
		for(j=0;j<count;j++){
			printf("      *");
		}
		printf("\n");
	}
	
	for(i=0;i<count*7+1;i++)
		printf("*");
	printf("\n");
}


void levelorder(struct node **root){
	int det1=false,det2=false;
	
	if((*root)->left != NULL){
		printf("%d->",(*root)->left->n);
		det1 = true;
	}
		
		
	if((*root)->right != NULL){
		printf("%d->",(*root)->right->n);
		det2 = true;
	}
		
	if(det1 == true)
		levelorder(&((*root)->left) );
		
	if(det2 == true) 
		levelorder(&((*root)->right) );
}
