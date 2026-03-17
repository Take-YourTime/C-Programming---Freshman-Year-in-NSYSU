#include<stdio.h>
#include<math.h>
/*write in UTF-8, not ANSI*/

int main(){
	int n=0,sum=0; //n:正整數 sum:所有位數的總和
	printf("請輸入一個正整數:");
	scanf("%d",&n);
	
	if(n>2*pow(10,9) || n<=0){ //n < 2*10^9
		printf("錯誤的輸入值\n");
		return 0;
	}
	
	while(n>=10){ //當n < 10，此時n為個位數
		while(n>0){ //把n的每個位數相加
			sum = sum+n%10;
			n/=10;
		}
		n=sum;
		sum=0;
	}
	
	printf("%d\n",n);
}
