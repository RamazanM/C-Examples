//Bir sayının karekökü nasıl hesaplanır 
#include<stdio.h>
int main (){
	float sayi=12,kok=1;
	int sayac=0;
	float katsayi=100;
	int devam=1;

	while(devam){
  	 if(katsayi==1/100){
				devam=0;
				printf("kok:%f",kok);
				}
		
		if(kok*kok<sayi) {
			kok+=katsayi;
			}
		if(kok*kok>sayi){
			kok-=katsayi;
			katsayi=katsayi/10;
		
		}
		if(sayi==kok*kok){
			devam=0;
			printf("%f'nin karekökü: %f",sayi,kok);
			}

		}
	
	return 0;
}