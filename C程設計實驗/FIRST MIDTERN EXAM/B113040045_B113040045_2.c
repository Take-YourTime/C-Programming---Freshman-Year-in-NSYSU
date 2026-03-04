#include<stdio.h>

int main(){
	int i;//癹伴跑计 
	int nums[100]; //计 
	int det[100]; //计计秖 
	int input=0;
	
	for(i=0;i<100;i++){
		nums[i]=0;
		det[i]=0;
	}
		
	i=0;	
	while(scanf("%d",&input)){
		nums[i]=input; //肈ヘ璶―块计皚 
		i++;
		 
		if(input==-1)
			break;
	
		det[input]++; 
	}
	
	for(i=0;i<100;i++){
		if(det[i]==1){
			printf("%d",i);
			break;
		}	
	}
	
	return 0;
}

