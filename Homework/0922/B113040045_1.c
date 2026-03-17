#include<stdio.h>

int main(){
	int n=0;
	
	printf("How much is it : ");
	scanf("%d",&n);
	
	printf("NT 100 : %d",n/100);
	n=n%100;
	//除以100後剩下多少，以下類推 
	printf("\nNT 50 : %d",n/50);
	n=n%50;
	printf("\nNT 10 : %d",n/10);
	n=n%10;
	printf("\nNT 5 : %d",n/5);
	n=n%5;
	
	//最後剩下的即為1元數量 
	printf("\nNT 1 : %d\n",n); 
	
	return 0;
}

