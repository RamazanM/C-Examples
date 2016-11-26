#include<stdio.h>
#include<stdbool.h>

int asal_sayi(int);
	
int main(){
	int sayi;
	while(1){
		printf("Asallığını kontrol etmek için bir sayı giriniz:");
		scanf("%d",&sayi);
		if(asal_sayi(sayi)) printf("%d bir asal sayıdır\n",sayi);
		else printf("%d asal değildir.\n",sayi);
		}		
	return 0;
	}

int asal_sayi(int sayi){
	int asal=1;
	int i;
	for(i=2;i<sayi;i++){
		if(sayi%i==0){
			asal=0;
			break;
			}
		}
	return asal;
	}