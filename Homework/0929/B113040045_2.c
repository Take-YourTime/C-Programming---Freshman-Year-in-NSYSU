#include<stdio.h>

int main(){
	char size; //大小 
	int sweet=0;  //甜度 
	
	printf("Please enter size : ");
	scanf("%c",&size);
	if(size!='m' && size!='l' && size!='e' && size!= 's'){//排除不正確的size 
		printf("Wrong fruit size!!!\n");
		return 0;
	} 
	
	printf("Please enter sweetness : ") ;
	scanf(" %d",&sweet);
	if(sweet>100||sweet<1){//排除不在區間內的sweetness 
		printf("Wrong fruit sweetness!!!\n");
		return 0;
	}
	
	switch(size){
		case 'm'://先把'm' 'l' 'e'三種size進行分類 
		case 'l':
		case 'e':
			if(sweet>=85 && size!='m') 
				printf("Premium class\n");
			else if(sweet>=85)
				printf("Gifted class\n");
			else if(sweet>=40)
				printf("Regular class\n");
			else
				printf("Inferior class\n");
			break;
		default:// case 's':
			if(sweet>=40)
				printf("Regular class\n");
			else
				printf("Inferior class\n");
			break;
	}
	return 0;
}

