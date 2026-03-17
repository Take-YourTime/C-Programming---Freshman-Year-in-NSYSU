#include<stdio.h>
#define true 1

int n[100]; // 數字 

void swap(int *n1,int *n2){
	int temp = *n1;
	*n1=*n2;
	*n2=temp;
}

void sort(){
	for(int i=0;i<100;i++)
		for(int j=0;j<100-1-i;j++)
			if(n[j]>n[j+1])
				swap(&n[j],&n[j+1]);
}

void BinarySearch(int key){
	int min=1 , max=100;
	int det = (min+max)/2;
	
	while(true){
		
		if(n[det-1]==key){
			printf("key:%d在第%d個位置\n",key,det);
			break;
		}
		
		if(n[det-1]<key)
			min=det+1;
		else
			max=det-1;
			
		if(min>max){ // 搜尋完畢 
			printf("找不到key:%d\n",key);
			break;
		}
		
		det = (min+max)/2;
	}
}

int main(){
	FILE *file_test = fopen("test.txt","r");
	int key = 0;//搜尋的目標數字 
	
	for(int i=0;i<100;i++)
		fscanf(file_test,"%d",&n[i]);
		
	fclose(file_test);
	
	sort();//泡沫排序法 
	/*--------------------*/
	FILE *file_sorted = fopen("sorted.txt","w");
	
	for(int i=0;i<100;i++){
		fprintf(file_sorted,"%d\n",n[i]);
		printf("%d\n",n[i]);
	}
	
	fclose(file_sorted);
	/*--------------------*/
	printf("請輸入要搜尋的key:\n");
	scanf("%d",&key);
	
	BinarySearch(key);
	
	return 0;
}
