#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void print_Listnode(struct ListNode* head) {
	if(head == NULL)
		printf(" ");
	while(head != NULL) {
		printf("%d ",head -> val);
		head = head -> next;
	}
	printf("\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
 	struct ListNode *current;	//被刪除的節點 
 	struct ListNode *run;	//用來判斷current後的第n個節點是不是空的，是的話代表當前的current為要刪除的節點 
 	
 	current = head;
 	
 	int i;
 	while(1){
 		run = current;
 		
 		for(i=0;i<n;i++){
 			run = run->next;
		}
		
		if(run == NULL){
			if(current == head){	//刪除首個節點時 
				head = current->next;
				free(current);
			}
			else{
				struct ListNode *temp = head;	//找到current的上一個節點，以進行current的刪除 
			
				while(temp->next != current)
					temp = temp->next;
				
				temp->next = current->next;
				free(current);
			} 
			break;
		}
		
		current = current->next;
	}
	
	return head;
}


int main(int argc, char *argv[]) {
	struct ListNode *head = malloc(sizeof(struct ListNode));
	struct ListNode *orign_head = head;
	
	srand(time(NULL));
	
	int i;
	int num = rand()%30 + 1;
	int n = rand()%num + 1;
	
	for(i=1; i <= num; i++) {
		head -> val = i;
		head -> next = malloc(sizeof(struct ListNode));
		if(i == num)
			head -> next = NULL;
		else
			head = head -> next;
	}
	head = orign_head;
	
	printf("orign List\n");
	print_Listnode(head);
	
	printf("Remove %dth Node From End of List\n",n);
	head = removeNthFromEnd(head,n);
	
	printf("result\n");
	print_Listnode(head);
	return 0;
}

