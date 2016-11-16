#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int kullanici[6],rastgele[6];
	int i,j;
	int sayi,flag;
	srand(time(NULL));
	
	for(i=0;i<6;i++){	
		do{
			flag=0;
			sayi=rand()%10;
			for(j=0;j<i;j++)if(sayi==rastgele[j])     flag=1;
		}while(flag);
		rastgele[i]=sayi;
	}
	for(i=0;i<6;i++)printf("%d\t",rastgele[i]);
	
	
	for(i=0;i<6;i++){	
		printf("\n");
		scanf("%d",&kullanici[i]); 
		}
		
	printf("\n");
	
	for(i=0;i<6;i++)printf("%d\t",kullanici[i]);		
	
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			if(rastgele[i]==kullanici[j]) printf("\n%d sayisi tuttu.",kullanici[j]);
			
		
	}