#include<stdio.h>
/*write in UTF-8, not ANSI*/

int main(){
	double x=0,y=0;
	
	printf("Please enter x coordinate : ");
	scanf("%lf",&x);
	
	fflush(stdin);
	
	printf("Please enter y coordinate : ");
	scanf("%lf",&y);
	
	if(x>0){//先判斷X正負，再由Y正負辨別位於第幾象限
		if(y>0)
			printf("point (%lf,%lf) is in the first quadrant\n",x,y);
		else if(y<0)
			printf("point (%lf,%lf) is in the fourth quadrant\n",x,y);
		else
			printf("point (%lf,%lf) is not in any quadrant\n",x,y);//點在X軸上
	}
	else if(x<0){
		if(y>0)
			printf("point (%lf,%lf) is in the second quadrant\n",x,y);
		else if(y<0)
			printf("point (%lf,%lf) is in the third quadrant\n",x,y);
		else
			printf("point (%lf,%lf) is not in any quadrant\n",x,y);//點在X軸上
	}
	else if(x==0 && y!=0)
		printf("point (%lf,%lf) is not in any quadrant\n",x,y);//點在Y軸上
	else
		printf("point (0,0) is not in any quadrant\n");//點在原點
		
	return 0;
}

