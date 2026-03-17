#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void push(char);
void pop(void);

struct stack{
	char ch;
	struct stack *next;
};

struct stack *top;


int main(){
	char str[100];
	
	top = malloc(sizeof(top));
	top->next = NULL;
	top->ch = '\0';
	
	printf("中序運算式：");
	scanf("%s",str);
	
	for(int i=0;i<strlen(str);i++){
		
		if(isalnum(str[i])) //為英文字母或數字時，直接將其印出
			printf("%c",str[i]);
			
		else if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')' )
			push(str[i]);
		
		else{ //當輸入不為運算子的字元
			printf("\nwrong input!\n");
			return 0;
		}
	}
	
	while(top->next != NULL) //將堆疊中剩餘的元素印出
		pop();
	
	return 0;
}


void push(char opt){
	struct stack *new;
	new = malloc(sizeof(new));
	
	/*--------------------*/
	/*判斷是否要將堆疊中的元素印出*/
	
	if(top->next != NULL){		
		if(opt == '+' || opt == '-'){
			do{
				if(top->ch == '+' || top->ch == '-' || top->ch == '/' || top->ch == '*' )
					pop();
				else
					break;
					
			}while(top->next != NULL);
		}
		
		else if(opt == '/' || opt == '*'){
			do{
				if((top->ch == '/') || (top->ch == '*') )
					pop();
				
				else
					break;
					
			}while(top->next != NULL);
		}
		
		else if(opt == ')'){
			struct stack *current;
			current = malloc(sizeof(current));
			
			while(top->ch != '(')
				pop();
			
			current = top; // '('跳過不印出
			top = current->next;
			
			free(current);
			goto skip; //line 95
		}
	}
	/*--------------------*/
	
	new->ch = opt;//將當前字元存入堆疊中
	new->next = top;
	
	top = new;
/**/skip:;
}


void pop(void){
	struct stack *current;
	current = malloc(sizeof(current));
	
	printf("%c",top->ch);
	
	current = top;
	top = current->next;
	
	free(current);
}
