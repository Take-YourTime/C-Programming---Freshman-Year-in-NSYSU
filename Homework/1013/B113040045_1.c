#include<stdio.h>

int main(){
	int food=0,snack=0,ice=0,salt=0;//food:主食  snack:附食  ice:紅茶冰塊  salt:薯條鹽份 
	int sum=0;//總金額 
	char code,confirmation;//code:折扣碼  confirmation:餐點確認 
	
	printf("請輸入您想點的主食：1.漢堡 2.潛艇堡 3.沙拉 4.義大利麵\n");
	scanf("%d",&food);
	
	fflush(stdin);
	
	printf("請輸入您想點的附食：1.紅茶 2.薯條 3.濃湯\n");
	scanf("%d",&snack);
	if(snack==1){
		printf("紅茶的冰塊：1.正常 2.微冰 3.去冰\n");
		fflush(stdin);
		scanf("%d",&ice);
	} 
	else if(snack==2){
		printf("薯條的鹽分：1.正常鹽  2.去鹽\n");
		fflush(stdin);
		scanf("%d",&salt);
	}
	
	
	printf("請問是否有折扣碼？若有請輸入折扣碼，無請輸入(N)！！！\n");
	fflush(stdin);
	scanf("%c",&code);
	
	printf("您所點的為以下：\n\n");
	switch(food){//主食 
		case 1:
			printf("漢堡x1\n");
			sum+=60;
			break;
		case 2:
			printf("潛艇堡x1\n");
			sum+=80;
			break;
		case 3:
			printf("沙拉x1\n");
			sum+=70;
			break;
		case 4:
			printf("義大利麵x1\n");
			sum+=90;
			break; 
		default:
			printf("主食輸入錯誤\n");
			break; 	
	}
	
	switch(snack){//附食 
		case 1:
			printf("紅茶");
			sum+=30;
			switch(ice){//紅茶冰塊量 
				case 1:
					printf("正常冰x1\n");
					break;
				case 2:
					printf("微冰x1\n");
					break; 
				case 3:
					printf("去冰x1\n");
					break; 
				default:
					printf(" 冰塊量輸入錯誤\n");
					break;
			}
			break;
			
		case 2:
			printf("薯條");
			sum+=40;
			switch(salt){//薯條鹽份 
				case 1:
					printf("正常鹽x1\n");
					break;
				case 2:
					printf("無鹽x1\n");
					break;
				default:
					printf(" 鹽分輸入錯誤\n");
					break;
			}
			break;
		
		case 3:
			printf("濃湯x1\n");
			sum+=40;
			break;
		default:
			printf("附食輸入錯誤\n");
			break;
	}
	
	if(code=='e'){//折扣碼 
		if(sum>=100)
			sum=sum*0.8;
	}
	else if(code!='N')
		printf("\n折扣碼輸入錯誤\n");
	
		
	printf("\n總金額為：%d\n",sum);
	
	
	printf("\n是否正確？(Y/N)\n");//餐點確認 
	fflush(stdin);
	scanf("%c",&confirmation);
	if(confirmation=='Y')
		printf("成功\\n");
	else if(confirmation=='N')
		printf("錯誤\n");
	else
		printf("Wrong answer！！\n");
	
	return 0;
}

