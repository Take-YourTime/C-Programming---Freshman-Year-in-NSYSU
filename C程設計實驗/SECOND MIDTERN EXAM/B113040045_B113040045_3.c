#include<stdio.h>

int main(){
	int n1[100];
	int n2[100];
	int detect[10];
	
	int i,j,k;
	int det1=0,det2=0,count=0;
	
	FILE *file = fopen("3.txt","r");
	
	for(j=0;j<100;j++){
		n1[j]=-1;
		n2[j]=-1;
	}
	
	for(i=0;i<3;i++){
		
		for(j=0;j<10;j++)
			detect[j]=-1;
		
		for(j=0;j<100;j++){//¿é¤Jn1 
			fscanf(file,"%d",&n1[j]);
		
			if(n1[j]==-1){
				det1=j;
				break;
			}
				
		}
		
		for(j=0;j<100;j++){//¿é¤Jn2 
			fscanf(file,"%d",&n2[j]);
		
			if(n2[j]==-1){
				det2=j;
				break;
			}
				
		}
		
		for(j=0;j<=det1;j++)//§PÂ_re¼Æ¦r 
			for(k=0;k<=det2;k++)
				if(n1[j]==n2[k])
					detect[ n1[j] ]++;
		
		for(j=0;j<10;j++)
			if(detect[j]>=0)
				printf("%d ",j);
				
		printf("\n");
	}
		
	fclose(file);
	return 0;
}


