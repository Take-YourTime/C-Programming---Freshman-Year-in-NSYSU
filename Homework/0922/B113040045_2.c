#include<stdio.h>
 
int main(){
	unsigned int n=0;
	start://當輸入數值錯誤時跳回此處 
		
	printf("Please enter number : ");
	//數字介於 1－15 之間
	scanf("%d",&n);
	
	if(n>15||n<1){
		printf("Wrong number! Try again.\n\n");
		goto start; //當輸入數值不在範圍內時， 回到line 5重新輸入 
	} 
	
	printf("Output : ");
	
	int bio[4];//轉為二進制用陣列 
	
	for(int i=0;i<4;i++)//將陣列歸0 
		bio[i]=0;
	
	for(int i=0;i<4;i++){//把n重複除以2，並輸出其餘數直到n=0，再以陣列反向輸出，即轉為二進制表示法
		bio[i]=n%2;
		n=n/2;
	}
	
	for(int i=4-1;i>=0;i--)//反向輸出 
		printf("%d",bio[i]);
		
	return 0;
	//原先想法是以陣列的方式，可以將任何大小的數字轉為二進制來表示，但因題目要求要4bits，所以改成這樣 
}

