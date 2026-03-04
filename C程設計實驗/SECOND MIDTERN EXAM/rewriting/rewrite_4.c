#include<stdio.h>
#include<string.h>

int main(){
	char s[100];
	int count = 0;
	
	int i;
	
	FILE *file = fopen("4.txt","r");
	
	while(fgets(s,100,file)){
		if(feof(file))
			break;
			
		count = 0;	
		
		for(i=0;i<strlen(s);i++){
			if(s[i] == ' ')
				count++;
		}
		
		printf("%d\n",count+1);
	}
	
	fclose(file);
	
	return 0;
}

