#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	float a = 0, b = 0;

	printf("請輸入a的值：");
	scanf("%f", &a);
	printf("請輸入b的值：");
	scanf("%f", &b);

	printf("a-b = %f", a - b);
	printf("\nb*(a-b) = %f", b * (a - b));
	printf("\na+b*(a-b) = %f", a + b * (a - b));//先乘除後加減
	printf("\n[a+b*(a-b)/b] = %f\n", (a + b * (a - b)) / b);

	return 0;
}
