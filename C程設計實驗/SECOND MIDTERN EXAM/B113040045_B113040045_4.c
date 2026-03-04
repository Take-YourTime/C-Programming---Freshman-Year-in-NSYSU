#include<stdio.h>
#include<string.h>

int main(){
	FILE *file = fopen("4.txt","r");
	
	char s[100];
	
	int i,j;
	int count=0;

	while(fgets(s,100,file)){
		count=1;
		for(i=0;i<strlen(s);i++){
			if(s[i]==' ')
				count++;
		}
		printf("%d\n",count);
	}
	
	fclose(file);
	return 0;
}
