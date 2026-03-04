#include<stdio.h>

int main(){
	int i,j,k;
	int n1[100],n2[100];
	int det[10];
	
	FILE *file = fopen("3.txt","r");
	
	
	do{
		
		for(i=0;i<10;i++){//Âk0 
			det[i] = 0;
		}
		
		for(i=0;i<100;i++){//¿é¤Jn1 
			fscanf(file,"%d",&n1[i]);
			if(n1[i] == -1)
				break;
			else if(feof(file))
				goto end;
				
			det[ n1[i] ] = 1;
		}
		
		for(i=0;i<100;i++){//¿é¤Jn2
			fscanf(file,"%d",&n2[i]);
			if(n2[i] == -1)
				break;
			det[ n2[i] ]++;
		}
		
		for(i=1;i<10;i++){
			if(det[i]>1)
				printf("%d ",i);
		}
		printf("\n");
		
	}while(1);
	
	end:
	fclose(file);
	
	return 0;
}

