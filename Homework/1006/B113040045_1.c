#include<stdio.h>
#include<math.h>
#define true 1
#define false 0
#define Maximum 1000000 //質數表的上限值
/*write in UTF-8, not ANSI*/

int prime[Maximum]; //自然數陣列。 true:質數 ; false:合數
 
void eratosthenes() //質數表
{
	/*
	先將陣列所有格子變成true
	0、1不是質數，將prime[0]、prime[1]改成false

	從最小質數2開始
	1、將範圍內所有2的倍數改成false
	2、找到下一個值為true的格子，即為下一個質數
	3、重複上述步驟，直到找到範圍內所有質數
	*/
    for (int i=0; i<Maximum; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
	
	int sqrt_max = sqrt(Maximum);
    
    /*
    當要刪除一個質數i的倍數時，此時已經把(小於i的質數其倍數)倍刪除了
    因此只須刪除「大於等於i的(質數其倍數)」倍
    
    k:倍率
	j:質數i的倍數

    由大到小，當prime[k]=true時
    k才能涵蓋所有「大於等於i的(質數其倍數)」倍
	*/
    for (int i=2; i<=sqrt_max; i++)
        if (prime[i])
            for (int k=(Maximum-1)/i,j=i*k ; k>=i ; k--,j=j-i)
                if (prime[k])
                    prime[j] = false;;
}

int main(){
	eratosthenes(); //呼叫函式 → 建立質數表
	int n=0;
	
	printf("請輸入大於2的偶數 :");
	scanf("%d",&n);
	
	if(n>Maximum||n<4){
		printf("錯誤的輸入值\n");
		return 0;
	}
	
	for(int i=2;i<=Maximum;i++){
		if(prime[i]==true)
			if(prime[n-i]==true){
				printf("%d = %d + %d\n",n,i,n-i);
				return 0;
			}
				
	}
	
}
