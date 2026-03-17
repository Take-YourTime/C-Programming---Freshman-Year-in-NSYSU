#include<stdio.h>
#include<limits.h>//使用宏 : INT_MAX 

void Read(int matrix[32][32]){
	FILE *file_binaryimage = fopen("BinaryImage.txt","r");
	
	printf("Binary Image\n");
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			fscanf(file_binaryimage,"%d",&matrix[i][j]);
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	fclose(file_binaryimage);
}



void ForwardPass(int matrix[32][32]){
	int min=INT_MAX;
	
	/* forward pass */
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			if(matrix[i][j]==1){
				for(int k=i-1,n=j-1;n<=j+1;n++)//找尋window中的最小值 
					if(matrix[k][n]<min)
						min=matrix[k][n];
				if(matrix[i][j-1]<min)
						min=matrix[i][j-1];
				/*--------------------*/
				matrix[i][j]+=min;
				min=INT_MAX;
			}
		}
	}
	
	printf("Forward Pass\n");//印出矩陣
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");		
}


void BackwardPass(int matrix[32][32]){
	int min=INT_MAX;
	FILE *file = fopen("Result.txt","w");
	
	/* backward pass */
	for(int i=32-1;i>=0;i--){
		for(int j=32-1;j>=0;j--){
			if(matrix[i][j]!=0){
				for(int k=i+1,n=j+1;n>=j-1;n--)//找尋window中的最小值 
					if(matrix[k][n]<min)
						min=matrix[k][n];
				if(matrix[i][j+1]<min)
						min=matrix[i][j+1];
				/*--------------------*/
				if(matrix[i][j] > min+1)
					matrix[i][j] = min+1;
				min=INT_MAX;
			}
		}
	}
	
	printf("Backward Pass\n");//印出矩陣 
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			printf("%3d",matrix[i][j]);
			fprintf(file,"%3d",matrix[i][j]);
		}
		printf("\n");
		fprintf(file,"\n");
	}
	printf("\n");
	fprintf(file,"\n");
	
	fclose(file);
}


void Location(int matrix[32][32]){
	char answer;//輸入 Yes or No
	
	printf("請問是否要查詢pixel值?(Y/N)\n");
	
	while( scanf("%c",&answer) ){
		if(answer=='Y'){
			int x=0,y=0;//座標 
			
			printf("請輸入要查詢的座標：\n");
			printf("x = ");
			scanf("%d",&x);
			if( x>31 || x<0 ){
				printf("x座標超出範圍！\n\n");
				goto Rerun;//line 121
			}
			
			printf("\ny = ");
			scanf("%d",&y);
			if( y>31 || y<0 ){
				printf("y座標超出範圍！\n\n");
				goto Rerun;//line 121
			}
			
			printf("\npixel value : %d\n",matrix[x][y]);
		}
		else if(answer=='N')
			break;
			
		else
			printf("輸入錯誤！\n\n");
				
/**/	Rerun:
	
		printf("請問是否要查詢pixel值?(Y/N)\n");
		fflush(stdin);
	}
}



int main(){
	int matrix[32][32];
	
	Read(matrix);
	
	ForwardPass(matrix);
	
	BackwardPass(matrix);
	
	Location(matrix);
	
	return 0;	
}
