#include<stdio.h>

int min(int a,int b){
	if(a>b)
		return b;
	else
		return a;
}

int main(){
	FILE *file = fopen("1.txt","r");
	
	int i,j;
	
	int n[100];
	int area,len;
	
	while(1){
		int temp = 0;//¼È¦s­±¿n 
		area = 0;
		len = 0;
		
		for(i=0;i<100;i++){
			n[i] = -1;
		}
		
		for(i=0;i<100;i++){
			fscanf(file,"%d",&n[i]);
			
			if(feof(file))
				goto end;
			else if(n[i] == -1)
				break;
			
			len++;
		}
		
		for(i=0;i<len-1;i++){
			for(j=i+1;j<len;j++){
				temp = (j-i)*min(n[i],n[j]);
				
				if(temp>area)
					area = temp;
			}
		}
		
		printf("%d\n",area);
	}
	
	end:
	fclose(file);
	
	return 0;
}

