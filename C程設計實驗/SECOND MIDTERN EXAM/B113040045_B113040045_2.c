#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *file = fopen("2.txt","r");
	
	char ch[100];
	int i;
	int det=0;
	int sum=0;
	
	while(!feof(file)){
		
		fscanf(file,"%s",ch);
		
		for(i=0;i<100;i++){
			if(ch[i]=='\0')
				break;
			
			if(ch[i]=='I')
				sum+=1;
				
			else if(ch[i]=='V'){
				if(i!=0){
					if(ch[i-1]=='I')
						sum+=(4-1);
					else
						sum+=5;
				}
				else
					sum+=5;
			}
			
			else if(ch[i]=='X'){
				if(i!=0){
					if(ch[i-1]== 'I')
						sum+=(9-1);
					else
						sum+=10;
				}
				else
					sum+=10;
			}
			
			else if(ch[i]=='L'){
				if(i!=0){
					if(ch[i-1]== 'X')
						sum+=(40-10);
					else
						sum+=50;
				}
				else
					sum+=50;
				
			}
			
			else if(ch[i]=='C'){
				if(i!=0){
					if(ch[i-1]== 'X')
						sum+=(90-10);
					else
						sum+=100;
				}
				else
					sum+=100;
			}
			
			else if(ch[i]=='D'){
				if(i!=0){
					if(ch[i-1]== 'C')
						sum+=(400-100);
					else
						sum+=500;
				}
				else
					sum+=500;
			}
			
			else if(ch[i]=='M'){
				if(i!=0){
					if(ch[i-1]== 'C')
						sum+=(900-100);
					else
						sum+=1000;
				}
				else
					sum+=1000;
			} 
		}
		
		printf("%d\n",sum);
		sum=0;
		
		if(det==2)
			break;
		else
			det++;
	}
	
	fclose(file);
	return 0;
}
