#include<stdio.h>

int main(){
	int i;//迴圈變數
	int nums[100];
	int det[100];
	int t; // t = the number of nums
	
	for(i=0;i<100;i++){
		nums[i]=0;
		det[i]=0;
	}
	
	for(i=0;i<100;i++){
		scanf("%d",&nums[i]);
		
		if(nums[i]==-1) // 輸入-1 →停止輸入 
			break;
			
		det[ nums[i] ]++;
		t++;
	}
	
	for(i=0;i<t;i++){
		if(det[i] >= t/2)
			printf("%d ",i);	
	}
	printf("\n");

	return 0;
}

