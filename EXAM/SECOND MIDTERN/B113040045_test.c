#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define side 112 //111+1,+1便於書寫 
void push(int,int);
void pop(int*,int*);
void sort(int*,int*);
void swap(int*,int*);
void findmax(int*,int*);
void findmin(int*,int*);


struct stack{
	int x;
	int y;
	struct stack *next;
};

struct location{
	int x;
	int y;
};

struct stack *top;

char matric[side][side];

int a[100];
int b[100];

int main(){
	int i,j,k;
	
	int A[100];
	int B[100];
	
	int x_min = 0; int x_max = 0;
	int y_min = 0; int y_max = 0;
	
	top = malloc(sizeof(top));
	top = NULL;
	
	srand(1);
	
	/*a*/
	for(i=0;i<100;i++){
		a[i] = rand()%101-50;
		b[i] = rand()%101-50;
		
		push(a[i],b[i]);
	}
	
	/*c*/
	findmax(&x_max,&y_max);
	findmin(&x_min,&y_min); 
	
	printf("Xmin = %d, Xmax = %d, Ymin = %d, Ymax = %d\n",x_min,x_max,y_min,y_max);
	printf("The area of rectangle = %d\n\n",(x_max-x_min)*(y_max-y_min) );
	system("pause");
	
	/*b*/
	for(i=0;i<100;i++){
		pop(&A[i],&B[i]);
		sort(A,B);//將陣列排序 
	}
	//此時top = NULL 
	for(i=0;i<100;i++){
		push(A[i],B[i]);//將陣列重新放入堆疊中 
	}
	
	/*d*/
	for(i=0;i<side;i++)//矩陣歸零 
		for(j=0;j<side;j++)
			matric[i][j]=' ';
			
	matric[56][56] = '0';//原點 
	//x軸 
	for(i=56,j=1;j<=55;j++){//x<0
		if((j-5)%10 == 0){
			matric[i][j] = '|';
		}
		else
			matric[i][j] = '-';
	}
	for(i=56,j=57;j<side;j++){//x>0
		if((j-6)%10 == 0){
			matric[i][j] = '|';
		}
		else
			matric[i][j] = '-';
	}
	
	//y軸 
	for(i=1,j=56;i<side;i++)
		matric[i][j] = '|';
	
	//印出矩陣
	for(i=1;i<=54;i++){//y>1
		for(j=1;j<side;j++){
			if( (j==56) && ((i-5)%10==0) )
				printf("%3d",55-i);
			else
				printf("%3c",matric[i][j]);
		}
		printf("\n");
	}
	
	i=55;
	for(j=1;j<=54;j++){//x軸上,x<0 
		if((j-5)%10 == 0)
			printf("%3d",j-55);
		else
			printf("%3d",matric[i][j]);
	}
	
	printf("%3c",'0');//原點左上 
	
	for(j=56;j<side;j++){//x軸上,x>0 
		if((j-5-1)%10 == 0)
			printf("%3d",j-55-1);
		else
			printf("%3d",matric[i][j]);
	}
	printf("\n");
	
	for(i=56,j=1;j<side;j++)//x軸 
		printf("%3c",matric[i][j]);
	printf(">\n");
	
	for(i=57,j=1;j<side;j++){//x軸下 
		if(j==106)
			printf("x軸");
		else
			printf("%3c",matric[i][j]);
	}
	printf("\n");
	
	for(i=58;i<side;i++){//y<-1
		for(j=1;j<side;j++){
			if( (j==56) && ((i-5)%10==0) )
				printf("%3d",55-i);
			else
				printf("%3c",matric[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}

/*----------------------------------------*/
/*----------------------------------------*/

void push(int x,int y){
	
	struct stack *new;
	new = malloc(sizeof(new));
	
	new->x = x;
	new->y = y;
	new->next = top;
	
	top = new;
}

void pop(int *x,int *y){
	struct stack *current;
	current = malloc(sizeof(current));
	
	current = top;
	
	*x = current->x;
	*y = current->y;
	
	top = current->next;
	
	free(current);
}

void sort(int A[100],int B[100]){
	int i,j,k;
	int det;
	
	for(i=0;i<100-1;i++)//y由大到小 
		for(j=0;j<100-1-i;j++)
			if(B[j]<B[j+1])
				swap(&B[j],&B[j+1]);
	
	for(i=0;i<100-1;i++){
		if(B[i]==B[i+1]){
			det = i+2;
			
			while(B[det]==B[i])//幾個座標y值重複 
				det++;
			
			for(j=i;j<det;j++)//x由小到大排 
				for(k=j;k<det-1;k++)
					if(B[k]>B[k+1])
						swap(&B[k],&B[k+1]);
		}
	}
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void findmax(int *x,int*y){
	int x_max = ~INT_MAX;
	int y_max = ~INT_MAX;
	
	struct stack *now;
	struct stack *current;
	
	//now = malloc(sizeof(now));
	//current = malloc(sizeof(current));
	now=top;
	
	while(now != NULL){
		current = now;
		
		if((current->x) > x_max)
			x_max = (current->x);
			
		if((current->y) > y_max)
			y_max = (current->y);
		now = current->next;
		
		free(current);
	}
	
	*x = x_max;
	*y = y_max;
	free(now);
}

void findmin(int *x,int *y){
	int x_min = INT_MAX;
	int y_min= INT_MAX;
	
	struct stack *now;
	struct stack *current ;
	
	now = malloc(sizeof(current));
	current = malloc(sizeof(current));
	now = top;
	
	while(now != NULL){
		current = now;
		
		if((current->x) < x_min)
			x_min = current->x;
		
		if((current->y) < y_min)
			y_min = current->y;
			
		current = current->next;
		now = current;
		free(current);
	}
	
	*x = x_min;
	*y = y_min;
	free(current);
}
