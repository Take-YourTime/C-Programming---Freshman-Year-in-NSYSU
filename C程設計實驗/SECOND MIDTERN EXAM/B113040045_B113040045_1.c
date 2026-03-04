#include<stdio.h>

int min(int a,int b){
	if(a>b)
		return b;
	else
		return a;
}

int main(){
	int i,j,k;
	int arr[2][100];
	int area=0;
	int len=0;
	
	FILE *file = fopen("1.txt","r");
	
	for(i=0;i<2;i++){
		for(j=0;j<100;j++){
			fscanf(file,"%d",&arr[i][j]);
			
			if(arr[i][j]==-1)
				break;
		}
	}
	fclose(file);
	
	for(i=0;i<2;i++){
		for(k=0;k<100;k++){
			if(arr[i][k]==-1)
				break;
			
			for(j=k+1;j<100;j++){
				if(arr[i][j]==-1)
					break;
			
				len = min(arr[i][k],arr[i][j]);
			
				if( len * (j-k) > area )
					area = min(arr[i][k],arr[i][j]) * (j-k);
			}
		
		}
		
		printf("%d\n",area);
		area=0;
	}
	
	return 0;
}


