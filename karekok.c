//Bir sayının karekökü nasıl hesaplanır 
#include<stdio.h>
int main (){
	float sayi=2,kok=1;
	float katsayi=100;
	int devam=1;

	while(devam){
		
		if(kok*kok<sayi) kok+=katsayi;
		if(kok*kok>sayi){
			kok-=katsayi;
			katsayi=katsayi/10;
		}
		if(sayi==kok*kok){
			devam=0;
			printf("%f'nin karekökü: %f",sayi,kok);
			}
			else if(katsayi==1/10){
				devam=0;
				printf("kok:%f",kok);}
		}
	
	return 0;
}