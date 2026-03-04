#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,k;

char * integer2Roman (int input) {
	char *ans = malloc(sizeof(char)*100);
	strcpy(ans,"");
	
	int list = 0;//陣列格子 
	int count = 0;//計算1000、100、10、1的個數 
	
	
	if(input>=1000){
		count = input/1000;
		input %= 1000;
		
		for(i=0;i<count;i++){
			ans[list]='M';
			list++;
		}
		
	}
	if(input>=900){
		input -= 900;
		
		ans[list]='C';
		list++;
		ans[list]='M';
		list++;
	}
	else if(input>=500){
		input -= 500;
		
		ans[list]='D';
		list++;
	}
	else if(input>=400){
		input -= 400;
		
		ans[list]='C';
		list++;
		ans[list]='D';
		list++;
	}
	
	
	if(input>=100){
		count = input/100;
		input%=100;
		
		for(i=0;i<count;i++){
			ans[list]='C';
			list++;
		}
	}
	if(input>=90){
		input-=90;
		
		ans[list]='X';
		list++;
		ans[list]='C';
		list++;
	}
	else if(input>=50){
		input-=50;
		
		ans[list]='L';
		list++;
	}
	else if(input>=40){
		input-=40;
		
		ans[list]='X';
		list++;
		ans[list]='L';
		list++;
	}
	
	
	if(input>=10){
		count = input/10;
		input%=10;
		
		for(i=0;i<count;i++){
			ans[list]='X';
			list++;
		}
	}
	if(input>=9){
		input-=9;
		
		ans[list]='I';
		list++;
		ans[list]='X';
		list++;
	}
	else if(input>=5){
		input-=5;
		
		ans[list]='V';
		list++;
	}
	else if(input>=4){
		input-=4;
		
		ans[list]='I';
		list++;
		ans[list]='V';
		list++;
	}
	
	
	for(i=0;i<input;i++){
		ans[list]='I';
		list++;
	}
	
	return ans;
}

int main(int argc, char *argv[]) {
	FILE *file = fopen("2.txt","r");
	int input;
	char *output;

	while(1) {
		fscanf(file,"%d",&input);
		
		if(feof(file))
			break;
		
		output = integer2Roman(input);
		printf("%s\n",output); 
	}
	return 0;
}
