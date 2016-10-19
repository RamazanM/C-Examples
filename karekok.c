//Girilen sayının karekökünü hesaplayan program/fonksiyon
#include<stdio.h>
float karekok(float sayi);

int main (){
	int sayi=0;
	while(1){
	printf("Karekökünü almak istediğiniz sayıyı giriniz:");
	scanf("%d",&sayi);
	printf("%d'nin karekökü: %f\n",sayi, karekok(sayi));
}
	return 0;
}

float karekok(float sayi){

	float kok=1,katsayi=100;
	int devam=1,sigorta=0;

	while(devam){

		if(sigorta==250) devam=0;
		if(kok*kok<sayi) kok+=katsayi;

		if(kok*kok>sayi){
			kok-=katsayi;
			katsayi=katsayi/10;
		}

		if(sayi==kok*kok) devam=0;

		sigorta++;
	}
	return kok;
}
