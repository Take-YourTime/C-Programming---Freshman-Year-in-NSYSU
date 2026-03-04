#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int i,j;

int validPalindrome(char s[]) {
	int len = strlen(s);
	char simp[100];	//s作簡化
	char reverse[100];	//reverse of simp
	
	int count = 0;	//計算簡化後的陣列中有幾個英文字母 
	
	for(i=0;i<len;i++){
		if(isalnum(s[i])){	//判斷是不是英文字母，不是的話不進行儲存 
			if(isupper(s[i])){	//將大寫英文字母轉成小寫 
				s[i] = s[i]+32;
			}
			
			simp[count] = s[i];
			count++;
		}
	}
	
	
	for(i=count-1,j=0; i>=0; i--,j++){	//陣列反轉 
		reverse[j] = simp[i];
	}
	
	for(i=0;i<count;i++){
		if(simp[i] != reverse[i])	//只要有一個字母不相同的話即可中斷迴圈 
			return 0;
	}
	
	return 1;
}

int main(int argc, char *argv[]) {
	FILE *file = fopen("3.txt","r");
	int result;
	char s[100];

	while(1) {
		fgets(s,100,file);
		
		if(feof(file))
			break;
		result = validPalindrome(s);
		
		printf("%s\n", result ? "true" : "false");
	}
	return 0;
}

