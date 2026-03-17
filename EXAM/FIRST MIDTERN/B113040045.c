#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define x_side 4102//4101+1
#define y_side 4102//+1便於書寫 

char square[y_side][x_side]; 

int main(){

	int i,j,k; //for迴圈變數 
	int temp=0;
	int det=0;
	int mode;
	
	int x[2000],y[2000];
	
	int x_min = INT_MAX , y_min = INT_MAX;
	int x_max = ~x_min , y_max = ~y_min;
	
	FILE *file = fopen("coordinate.txt","w");
	
	for(i=0;i<2000;i++){//歸零 
		x[i]=0;
		y[i]=0;
	}
	
	/*d*/
	/* (j,i) */
	for(i=0;i<y_side;i++) //歸零 
		for(j=0;j<x_side;j++)
			square[i][j]=' ';

	/*a*/
	fprintf(file,"排序前\n");
	fprintf(file,"%5c %5c\n",'x','y');
	fprintf(file,"=============================\n");
	
	srand(1);
	
	for(i=0;i<2000;i++){
		x[i]=rand()%4001-2000;
		y[i]=rand()%4001-2000;
		
		square[x[i]+2000][y[i]+2000] = '*';
		
		if(x[i]>x_max)
			x_max=x[i];
		if(x[i]<x_min)
			x_min=x[i];
		if(y[i]>y_max)
			y_max=y[i];
		if(y[i]<y_min)
			y_min=y[i];
		
		fprintf(file,"%5d %5d\n",x[i],y[i]);
		
	}
	fprintf(file,"\n");
	fclose(file);
	
	/*b*/
	FILE *file_sort = fopen("coordinate.txt","a+");
	
	fprintf(file_sort,"\n排序後\n");
	fprintf(file,"%5c %5c\n",'x','y');
	fprintf(file,"=============================\n");
	
	printf("使用1.泡沫排序法 2.插入排序法 3.選擇排序法:");
	scanf("%d",&mode);
	
	/* 排序 ------------------------------------------------------------------------------------------------------------------------*/
	
	if(mode==1){
		for(i=0;i<2000-1;i++){ //泡沫排序：y由大到小 
			for(j=0;j<2000-1-i;j++){
				if(y[j]<y[j+1]){
					
					temp=y[j+1];
					y[j+1]=y[j];
					y[j]=temp;
					
					temp=x[j+1];
					x[j+1]=x[j];
					x[j]=temp;
				}
			}
		}
		
		for(i=0;i<2000;i++){
			if(y[i]==y[i+1]){
				det=i+2;
				
				while(y[det] == y[i])//同樣的x值有幾個 
					det++;
					
				for(j=i;j<det-1;j++){//泡沫排序：x由小到大 
					for(k=i;k<det-1-j;k++){
						if(x[j]>x[j+1]){
							
							temp=x[j+1];
							x[j+1]=x[j];
							x[j]=temp;
							
							temp=y[j+1];
							y[j+1]=y[j];
							y[j]=temp;
						}
					}	
				}
			}
		}
	}
	
	else if(mode==2){//插入排序法 
		for(i=1;i<2000;i++){ //y由大到小 
			temp = y[i];
			
			for(j=i-1;j>=0;j--){
				
				if(temp>y[j]){
					y[j+1]=y[j];
					x[j+1]=x[j];
				}
				else{
					y[j]=temp;
					break;
				}
			}
		}
		
		for(i=0;i<2000;i++){
			if(y[i]==y[i+1]){
				det=i+2;
				
				while(y[det] == y[i])//同樣的x值有幾個 
					det++;
					
				for(j=i;j<det-1;j++){//x由小到大 
					for(k=i;k<det-1-j;k++){
						if(x[j]>x[j+1]){
							
							temp=x[j+1];
							x[j+1]=x[j];
							x[j]=temp;
							
							temp=y[j+1];
							y[j+1]=y[j];
							y[j]=temp;
						}
					}	
				}
			}
		}
	}
	
	else if(mode==3){ //選擇排序法 
		int sort_max;
		
		for(i=0;i<2000-1;i++){ //y由大到小
			
			sort_max = y[i];
			det = i;
		
			for(j=i+1;j<2000;j++)
				if(sort_max<y[j]){
					sort_max = y[j];
					det = j;
				}
			
			temp = y[i]; // 將數列最大值與數列最前方交換 
			y[i] = y[det];
			y[det] = temp;
		}
		
		for(i=0;i<2000;i++){
			if(y[i]==y[i+1]){
				det=i+2;
				
				while(y[det] == y[i])//同樣的x值有幾個 
					det++;
					
				for(j=i;j<det-1;j++){//x由小到大 
					for(k=i;k<det-1-j;k++){
						if(x[j]>x[j+1]){
							
							temp=x[j+1];
							x[j+1]=x[j];
							x[j]=temp;
							
							temp=y[j+1];
							y[j+1]=y[j];
							y[j]=temp;
						}
					}	
				}
			}
		}
	}
	
	else{
		printf("模式選擇錯誤\n");
		return 0;
	}
	/*------------------------------------------------------------------------------------------------------------------------*/
	
	for(i=0;i<2000;i++)//將排序後的x y寫入檔案 
		fprintf(file_sort,"%5d %5d\n",x[i],y[i]);
		
	fprintf(file_sort,"\n");
	fclose(file_sort);
	
	/*c*/
	printf("X之最小值為%d，X之最大值為%d，Y之最小值為%d，Y之最大值為%d\n",x_min,x_max,y_min,y_max); 
	printf("矩形面積為%d\n\n",(x_max-x_min)*(y_max-y_min));
	
	/*d*/
	square[2051][2051] = '0';//原點 
	
	//x軸 
	for(i=2051,j=1 ; j<=2050 ; j++){//x<0
		if(j%100 == 0)
			square[i][j] = '|';
		else
			square[i][j] = '-';
	}
	for(i=2051,j=2052 ; j<x_side ; j++){//x>0
		if( (j-1)%100 == 0)
			square[i][j] = '|';
		else
			square[i][j] = '-';
	}
	
	//y軸 
	for(i=1,j=2051 ; i<=2050 ; i++){//y>0
		if(i%100 == 0)
			square[i][j] = '-';
		else
			square[i][j] = '|';
	}
	for(i=2052,j=2051 ; i<=y_side ; i++){//y<0
		if( (i-1)%100 == 0)
			square[i][j] = '-';
		else
			square[i][j] = '|';
	}
	
	return 0;
}

