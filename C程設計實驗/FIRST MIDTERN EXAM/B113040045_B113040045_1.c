#include<stdio.h>

int main(){
	int sum=0;
	int id=113040045; //學號 
	printf("Name：許育菖\n");
	printf("Student ID：B113040045\n");
	
	while(id>0){
		sum=sum+id%10;
		id=id/10;
	}
	
	while(sum>=10)
		sum=sum%10;
		
	printf("My secret code is %d\n",sum); 
	return 0;
}

