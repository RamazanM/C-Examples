#include<stdio.h>
#include<time.h>

int bul(int sat,int sut)
{
	if(sut<=1)return 1;
	if(sat<=1)return 1;
	if(sat==sut)return 1;
	return ( bul(sat-1,sut-1) + bul(sat-1,sut));
}

int main (){
	int sat,sut;
	while(1){
		time_t start= clock();
		scanf("%d %d",&sat,&sut);
		int sayi=bul(sat,sut);
		printf("%d\n",sayi);
		time_t end=clock();
		printf("Zaman:%f",(double)(end-start)/CLOCKS_PER_SEC);
		
	}
	}
