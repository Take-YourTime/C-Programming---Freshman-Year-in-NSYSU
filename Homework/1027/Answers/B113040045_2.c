#include<stdio.h>
#include<string.h>

int main(){
	char path[21][100];//字串 
	int length=0;//字串長度 
	int x=0,y=0;//x：x軸位移 、 y：y軸位移 
	
	FILE *file_r = fopen("Test.txt","r");
	
	for(int i=0;i<21;i++){//讀檔 
		fscanf(file_r,"%s",path[i]);
	}
	fclose(file_r);
	
	FILE *file_w = fopen("7-2_Result.txt","w");
	
	for(int i=0;i<21;i++){
		length = strlen(path[i]);
		printf("第%d個字串 : ",i+1);
		fprintf(file_w,"第%d個字串 : ",i+1);
		
		for(int j=0;j<length;j++){//計算位移量 
			if(path[i][j]=='U')
				y++;
			else if(path[i][j]=='D')
				y--;
			else if(path[i][j]=='R')
				x++;
			else
				x--;
		}
		
		if(x==0 && y==0){
			printf("True\n");
			fprintf(file_w,"True\n");
		}
		else{
			printf("False\n");
			fprintf(file_w,"False\n");
		}	
		
		x=0; y=0;
	}
	
	fclose(file_w);
	
	return 0;
}
