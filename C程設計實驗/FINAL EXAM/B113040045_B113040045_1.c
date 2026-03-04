#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j;

int rotateString(char s[],char goal[]){
	int len = strlen(s);
	
	for(i=0;i<len;i++){
		if(strcmp(s,goal) == 0){
			return 1;
		}
		else if(len == 1)	//字串只有一個字元時 
			break;
			
		else{	//shift
			int ch = s[0];
			for(j=0; j<len-1; j++){
				s[j] = s[j+1];
			}
			s[len-1] = ch;
		} 
	}
	
	return 0;
}

int main(int argc, char *argv[]) {
	FILE *file = fopen("1.txt","r");
	int result;
	char s[100],goal[100];
	
	while(1){
		fscanf(file,"%s",s);
		fscanf(file,"%s",goal);
		
		if(feof(file))
			break;
			
		result = rotateString(s,goal);
		printf("%s\n", result ? "true" : "false");
	} 
	return 0;
}

