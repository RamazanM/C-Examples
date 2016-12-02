// Bir sayının belli aralıktaki kuvvetlerini alan kod...
#include <stdio.h>
int main(){
	int sayi,sonuc=1;
	int min,max;
	int i,j;
	printf("Kuvvetini almak istediğiniz sayıyı girin:");	scanf("%d",&sayi);
	printf("Kuvvet aralığını girin(min,max):");	scanf("%d,%d", &min, &max);
	
	for(i=min;i<=max;i++){
		for(j=0;j<i;j++)	sonuc*=sayi;	
		printf("%dˆ%d=%d\n",sayi,i,sonuc);
		sonuc=1;
		}
	}
	
	