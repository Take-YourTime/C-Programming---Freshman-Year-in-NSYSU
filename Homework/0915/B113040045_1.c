#include<stdio.h>
#pragma warning(disable:4996)

int main() {

	float s = 0, h = 0;
	//s：底邊 h：高

	printf("請輸入三角形的底邊長度：");
	scanf("%f", &s);
	printf("請輸入三角形的高：");
	scanf("%f", &h);
	printf("三角形的面積為：%f\n", s*h/2);
	return 0;
}
