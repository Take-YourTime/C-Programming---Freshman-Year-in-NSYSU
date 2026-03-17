#include<stdio.h>
#include<math.h>
#define limit_y 620 //y軸長度 
#define true 1
#define false 0

int fun(double A,double B,double C,double D,int x){
	//計算方程式的值
	double y=0;
	y=A*pow(x,3)+B*pow(x,2)+C*x+D;
	if(y>0)
		return ((int)y+1);
	else if(y<0)
		return ((int)y-1);
	else
		return ((int)y-1);
}

int main(){
	int y_line=0;//方程式的值y
	double a=0,b=0,c=0,d=0;//y = ax^3+bx^2+cx^1+d
	int square[limit_y][121]; //座標 (j,i) = (x,y)
	
	printf("請輸入a :");
	scanf("%lf",&a);
	printf("請輸入b :");
	fflush(stdin);
	scanf("%lf",&b);
	printf("請輸入c :");
	fflush(stdin);
	scanf("%lf",&c);
	printf("請輸入d :");
	fflush(stdin);
	scanf("%lf",&d);
	printf("繪製 y=%lfx^3 + %lfx^2 + %ldx^1 + %lf\n",a,b,c,d);
	
	for(int i=0;i<limit_y;i++) //歸0 
		for(int j=0;j<121;j++)
			square[i][j]=false;
			
	// x:-30 ~ 30
	for(int j=-30;j<=30;j++){ //找到方程式值的座標 
		y_line=fun(a,b,c,d,j);
		square[y_line+30][2*(j+30)]=true;
	}
	printf("\n");
	/*-----------------------------*/
	for(int i=0;i<29;i++){ //y>0
		for(int j=0;j<60;j++){
			if(square[i][j]==false)
				printf(" ");
			else
				printf("*");
		}
		if(i==0)
			printf("|");
		else if(i%10==0)
			printf("%d",i-30);
		else	
			printf("|");
		
		for(int j=61;j<121;j++){
			if(square[i][j]==false)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	/*-----------------------------*/
	printf(" %20d%20d%19d|%20d%20d",-20,-10,0,10,20); //x軸上的數字
	printf("\n");
	/*-----------------------------*/
	for(int j=0;j<121;j++){ //x軸
		if(j==60)
			printf("%d",0);
		else if(j!=120 && j%20==0)
			printf("|");
		else
			printf("-");
	}	
	printf(">\n");
	/*-----------------------------*/
	for(int j=0;j<121;j++){ //文字"x軸"
		if(j==115)
			printf("x軸");
		else if(j==60)
			printf("|");
		else if(square[31][j]==false)
			printf(" ");
		else
			printf("*");
	}	
	printf("\n");
	/*-----------------------------*/
	for(int i=32;i<limit_y;i++){ //y<0
		for(int j=0;j<60;j++){
			if(square[i][j]==false)
				printf(" ");
			else
				printf("*");
		}
		
		if(i%10==0)
			printf("%d",i-30);
		else	
			printf("|");
			
		for(int j=61;j<121;j++){
			if(square[i][j]==false)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	/*-----------------------------*/
	return 0;
}
