#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int ReLU(int x){ //y = max(0,x)
	if(x>=0)
		return x;
	else
		return 0;
}


int main(){
	int matrix[16][16];
	int bias[14][14];
	double kernel[9][9];
	int conv[14][14];
	double sum=0; //用於矩陣卷積運算加總 
	
	/*========================================*/
	//matrix
	FILE *file_matrix = fopen("Matrix.txt","w");
	
	srand(5);
	printf("Input:\n\n");
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			matrix[i][j] = rand()%21-10;
			fprintf(file_matrix," %4d",matrix[i][j]);
			printf(" %4d",matrix[i][j]);
		}
		fprintf(file_matrix,"\n");
		printf("\n");
	}
	printf("\n\n");	
	fclose(file_matrix);
			
	/*========================================*/		
	//bias		
	FILE *file_bias = fopen("Bias.txt","w");
	
	printf("Bias:\n\n");
	for(int i=0;i<14;i++){
		for(int j=0;j<14;j++){
			bias[i][j]=1;
			fprintf(file_bias," %-2d",bias[i][j]);
			printf(" %-2d ",bias[i][j]);
		}
		fprintf(file_bias,"\n");
		printf("\n");
	}
	printf("\n");	
	fclose(file_bias);
	
	/*========================================*/
	//kernel
	FILE *file_kernel = fopen("kernel.txt","r");
	FILE *file_conv = fopen("Conv.txt","w");
	
	printf("Kernel:\n\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			fscanf(file_kernel,"%lf",&kernel[i][j]);
			printf("%10.4lf",kernel[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
			
	/*========================================*/
	//Convolution
	printf("Convolution:\n\n");		
	for(int i=0+1 ; i<16-1 ; i++){
		for(int j=0+1 ; j<16-1 ; j++){
			
			for(int k=i-1 , q=0 ; k<=i+1 ; k++ , q++)
				for(int n=j-1 , r=0 ; n<=j+1 ; n++ , r++)
					sum += kernel[q][r]*matrix[k][n];
					
			conv[i-1][j-1] = round(sum)+1; //+1為加上Bias，round()做四捨五入 
			printf(" %4d",conv[i-1][j-1]);
			fprintf(file_conv," %4d",conv[i-1][j-1]);
			sum=0;
			
		}
		printf("\n");
		fprintf(file_conv,"\n");
	}
	printf("\n");
	fclose(file_kernel);
	fclose(file_conv);
	
	/*========================================*/
	//result
	FILE *file_result = fopen("7-1_Result.txt","w");
	
	printf("Result:\n\n");
	for(int i=0;i<14;i++){
		for(int j=0;j<14;j++){
			fprintf(file_result," %4d",ReLU(conv[i][j]));
			printf(" %4d",ReLU(conv[i][j]));
		}
		fprintf(file_result,"\n");
		printf("\n");
	}
	printf("\n");
	fclose(file_result);
	
	return 0;
}
