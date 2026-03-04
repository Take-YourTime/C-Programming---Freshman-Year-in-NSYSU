#include<stdio.h>
#include<math.h>

/* 0~9 48~57 */
int main(){
	int i=0,j;
	int t=0; //times
	int up=0,number=0,number_trans=0;//up ¦¸¤è 
	char input;
	int temp=0;
	int nums[100];
	
	while(input=getchar()){
		if(input=='\n')
			continue;
		else if(input=='-')
			break;
		else if(input==' '){
			while(up>0){
				number_trans += (number%10)*pow(10,up-1);
				up--;
				number/=10;
			}
			
			nums[i]=number_trans;
			i++;
			number_trans=0;
		}
		else{
			number+=( (int)input-48 )*pow(10,up);
			up++;
		}	
	}
	
	t=i;
	
	for(i=0;i<t;i++){
		if(nums[i]==0){
			for(j=i+1;j<t;j++){
				if(nums[j]!=0){
					temp = nums[j];
					nums[j] = nums[i];
					nums[i] = temp;
					break;
				}
			}
		}
	}
	
	printf("[");
	for(i=0;i<t-1;i++){
		printf("%d,",nums[i]);
	}
	printf("%d]",nums[t-1]);
	printf("\n");
	
	return 0;
}
