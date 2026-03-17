#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define limit_y 620 //y軸長度 : 0 ~ 620

int fun(double A,double B,double C,double D,int x){
	/* 計算方程式的值 */
	double y=0;
	y = A*pow(x,3)+B*pow(x,2)+C*x+D;
	
	return ((int)y);
}

int dfun(double A,double B,double C,int x){
	/* 方程式的微分，計算初始座標斜率 */
	double y=0; 
	A=A*3;
	B=B*2;
	
	y = A*pow(x,2)+B*x+C;
	
	return ((int)y);
}

void create_line(int x1,int y1,int x2,int y2,double *q,double *r){
	//y=q*x+r , 以指標h回傳q、r的值 
	*q = ( (double)y1-(double)y2 ) / ( (double)x1-(double)x2 );
	
	*r = (double)y1 - (*q) * (double)x1;
}

int calculate_line(double q,double r,int x){
	double y = q*x+r;
	
	if((int)y>=-30 && (int)y<=590)
		return ((int)y);
	else
		return -31; //out of range
} 



int main(){
	int y_line=0;// 方程式的值 : y
	int x_1=0,x_2=0;
	int count=0;// y軸尺碼位數 
	double a=0,b=0,c=0,d=0;// y = ax^3+bx^2+cx^1+d
	double q=0,r=0;// 兩點連成直線 : y = q*x+r 
	int square[limit_y+1][121];// 座標 (j,i) = (x,y)
	
	printf("請輸入a值 :");
	scanf("%lf",&a); fflush(stdin);
	
	printf("請輸入b值 :");
	scanf("%lf",&b); fflush(stdin);
	
	printf("請輸入c值 :");
	scanf("%lf",&c); fflush(stdin);
	
	printf("請輸入d值 :");
	scanf("%lf",&d); fflush(stdin); 
	
	printf("方程式 y=%lfx^3 + %lfx^2 + %ldx^1 + %lf\n\n",a,b,c,d);
	 
	printf("請輸入x1 : ");
	scanf("%d",&x_1); fflush(stdin);
	 
	printf("請輸入x2 : ");
	scanf("%d",&x_2); 
	printf("\n");
	
	/* 陣列歸0 */ 
	for(int i=0 ; i<=limit_y ; i++) 
		for(int j=0;j<121;j++)
			square[i][j]=0;
			
	/*
	座標數字代號 
	0:' ' (space)
	1:'/'
	2:'\'
	3:'-'
	4:'+'
	5:'|'
	*/
			
	/* x軸 : (i=580) */ 
	for(int i=limit_y-30,j=-30 ; j<=30 ; j++){
		if(j%5==0){
			square[i][2*(j+30)]=5;//'|'
			
			if(j>0){
				if(j>=10){
					square[i-1][2*(j+30)] = j/10;
					square[i-1][2*(j+30) +1 ] = j%10;
				}
				
				else
					square[i-1][2*(j+30)] = j%10;
			}
			else if(j<0){
				if(j<=-10){
					square[i-1][2*( j+30) +1 ] = abs( j/10 );
					square[i-1][2*( j+30) +2 ] = abs( j%10 );
				}
				
				else
					square[i-1][2*( j+30 ) +1 ] = abs( j%10 );
			}
		}	
		else
			square[i][2*(j+30)]=3;//'-' 
	}
	square[limit_y-30][0]=5;
	
	/* y軸 */
	for(int i=0,j=60 ; i<=limit_y ; i++){
		if(i%5==0){
			if( limit_y-(i+30) >= 0 ){
				if( limit_y-(i+30) >= 100 ){
					square[i][j] = (limit_y - (i+30) ) / 100;
					square[i][j+1] = ( (limit_y - (i+30) ) % 100 ) / 10;
					square[i][j+2] = (limit_y - (i+30)) % 10;
				}
				
				else if( limit_y-(i+30) >= 10 ){
					square[i][j] = ( limit_y - (i+30) ) / 10;
					square[i][j+1] = ( limit_y - (i+30) ) % 10;
				}
				
				else // 10 > limit_y-(i+29) >= 0 
					square[i][j] = limit_y - (i+30);
			}
			else{ // limit_y-(i+29) < 0 
				if( limit_y-(i+30) <= -10 ){
					square[i][j+1] = abs( ( limit_y - (i+30) ) / 10 ); //abs() : 取絕對值 
					square[i][j+2] = abs( ( limit_y - (i+30) ) % 10 );
				}
				
				else{ // -10 < limit_y-(i+29) < 0 
					square[i][j+1] = abs( ( limit_y - (i+30) ) % 10 );
				}
			}	
		}
		else
			square[i][j]=5;
	}
	
	/* 找到方程式的座標 */ 
	//x=-30
	if(dfun(a,b,c,-30)>0)
		square[ limit_y - (fun(a,b,c,d,-30)+30) ][0]=1; //+29 : 為+30-1 
	else if(dfun(a,b,c,-30)<0)
		square[ limit_y - (fun(a,b,c,d,-30)+30) ][0]=2;
	else
		square[ limit_y - (fun(a,b,c,d,-30)+30) ][0]=3;
		
	// x:-29 ~ 30	
	for(int j=-29 ; j<=30 ; j++){
		y_line=fun(a,b,c,d,j);
		
		if(y_line-fun(a,b,c,d,j-1)>0)
			square[ limit_y - (y_line+30) ][2*(j+30)]=1;
			
		else if(y_line-fun(a,b,c,d,j-1)<0)
			square[ limit_y - (y_line+30) ][2*(j+30)]=2;
			
		else
			square[ limit_y - (y_line+30) ][2*(j+30)]=3;
	}
	
	/* 方程式：y=x1 y=x2 */
	for(int i=0,j=x_1 ; i<=limit_y ; i++)
		square[i][2*(j+30)]=5;
		
	for(int i=0,j=x_2 ; i<=limit_y ; i++)
		square[i][2*(j+30)]=5;
		
	
	/* 方程式與兩豎線交叉處 */
	square[ limit_y - ( fun(a,b,c,d,x_1)+30 ) ][ 2*(x_1+30) ]=4; 
	square[ limit_y - ( fun(a,b,c,d,x_2)+30 ) ][ 2*(x_2+30) ]=4;
	
	/* 兩點連成直線 */
	//找到直線方程式「y=q*x+r」中 q,r 的值
	create_line( x_1 , fun(a,b,c,d,x_1) , x_2 , fun(a,b,c,d,x_2) , &q , &r ); 
	
	for(int j=-30;j<=30;j++){
		y_line = calculate_line(q,r,j);
		if(y_line!=-31)
			square[ limit_y - (y_line+30) ][ 2*(j+30) ]=4;
	}
	
	
	/*--------------------===== 列印座標 =====--------------------*/
	
	
	//y>0
	for(int i=0 ; i<=limit_y-32 ; i++){
		//x<0		
		for(int j=0 ; j<60 ; j++){
			if(square[i][j]==0) 
				printf("%c",' ');
			else if(square[i][j]==1)
				printf("%c",'/');
			else if(square[i][j]==2)
				printf("%c",'\\');
			else if(square[i][j]==3)
				printf("%c",'-');
			else if(square[i][j]==5)
				printf("%c",'|');
			else
				printf("%c",'+');
		} 
		
		//x=0
		if(i%5==0){
			if( limit_y-(i+30) >= 100 ){
				for(int j=60;j<=62;j++)
					printf("%d",square[i][j]);
				count=2;
			}
				
			else if( limit_y-(i+30) >= 10 ){
				for(int j=60;j<=61;j++)
					printf("%d",square[i][j]);
				count=1;
			}
			
			else{
				printf("%d",square[i][60]);
				count=0;
			}	
		}
		else{
			printf("|");
			count=0;
		}
		
		//x>0
		for(int j = (61+count) ; j<121 ; j++){
			if(square[i][j]==0) 
				printf("%c",' ');
			else if(square[i][j]==1)
				printf("%c",'/');
			else if(square[i][j]==2)
				printf("%c",'\\');
			else if(square[i][j]==3)
				printf("%c",'-');
			else if(square[i][j]==5)
				printf("%c",'|');
			else
				printf("%c",'+');
		}
		printf("\n");
	}
	/*-----------------------------*/
	//x軸尺碼 
	for(int i=limit_y-31,j=-30 ; j<=30 ; j++){
		if(j%5==0){
			if(j>0){
				if(j*2 > 10){
					count=2;
					for(int k = 2*(j+30) ; k <= 2*( j+30 ) +1 ; k++)
						printf("%d",square[i][k]);
				}
				else{
					printf("%d",square[i][ 2*( j+30 ) ]);
					count=1;
				}
			}
			
			else if(j<0){
				if(j*2 < -10){
					count=3;
					printf("%c",'-');
					for(int k=2*( j+30 ) +1 ; k <= 2*( j+30 ) +2 ; k++)
						printf("%d",square[i][k]);
				}
				else{
					count=2;
					printf("%c",'-');
					printf("%d",square[i][ 2*( j+30 ) +1 ]);
				}
					
			}
			
			else
				count=0;
				
			if(j==30)
				break;
				
			for(int k = 2*(j+30) + count ; k < 2*(j+30) + 10 ; k++){
				if(square[i][k]==0) 
					printf("%c",' ');
				else if(square[i][k]==1)
					printf("%c",'/');
				else if(square[i][k]==2)
					printf("%c",'\\');
				else if(square[i][k]==3)
					printf("%c",'-');
				else if(square[i][k]==5)
					printf("%c",'|');
				else
					printf("%c",'+');
			}
		}
	}
	printf("\n");
	/*-----------------------------*/
	//y=0(x軸)
	for(int i=limit_y-30,j=0 ; j<121 ; j++){
		if(j==60)
			printf("0");
		else if(square[i][j]==0) 
			printf("%c",' ');
		else if(square[i][j]==1)
			printf("%c",'/');
		else if(square[i][j]==2)
			printf("%c",'\\');
		else if(square[i][j]==3)
			printf("%c",'-');
		else if(square[i][j]==5){
			printf("%c",'|');
		}
		else
			printf("%c",'+');
	}	
	printf(">\n");
	/*-----------------------------*/
	//文字"x軸"
	for(int i=limit_y-29,j=0 ; j<121 ; j++){
		if(j==115)
			printf("x軸");
		else if(j==60)
			printf("|");
		else{
			if(square[i][j]==0) 
				printf("%c",' ');
			else if(square[i][j]==1)
				printf("%c",'/');
			else if(square[i][j]==2)
				printf("%c",'\\');
			else if(square[i][j]==3)
				printf("%c",'-');
			else if(square[i][j]==5)
				printf("%c",'|');
			else
				printf("%c",'+');
		}	
	}	
	printf("\n");
	/*-----------------------------*/
	//y<0
	for(int i=limit_y-28 ; i<=limit_y ; i++){
		//x<0
		for(int j=0;j<60;j++){
			if(square[i][j]==0) 
				printf("%c",' ');
			else if(square[i][j]==1)
				printf("%c",'/');
			else if(square[i][j]==2)
				printf("%c",'\\');
			else if(square[i][j]==3)
				printf("%c",'-');
			else if(square[i][j]==5)
				printf("%c",'|');
			else
				printf("%c",'+');
		}
		
		//x=0
		if(i%5==0){
			if( limit_y-(i+30) <= -10 ){
				printf("-");
				for(int j=61;j<=62;j++)
					printf("%d",square[i][j]);
				count=2;
			}
			else{
				printf("-");
				printf("%d",square[i][61]);
				count=1;
			}	
		}
		else{
			printf("|");
			count=0;
		}
		
		//x>0	
		for(int j = (61+count) ; j<121 ; j++){
			if(square[i][j]==0)
				printf("%c",' ');
			else if(square[i][j]==1)
				printf("%c",'/');
			else if(square[i][j]==2)
				printf("%c",'\\');
			else if(square[i][j]==3)
				printf("%c",'-');
			else if(square[i][j]==5)
				printf("%c",'|');
			else
				printf("%c",'+');
		}
		printf("\n");
	}
	/*-----------------------------*/
	
	return 0;
}
