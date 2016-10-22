//Girilen sayının girilen tabanda kökünü hesaplayan program/fonksiyon
#include<stdio.h>

float kok(float,int);
float power(float sayi,int kuvvet);

int main (){
	while(1){
		int sayi,kuvvet;
		printf("Girilen sayinin girilen kuvvette kokunu hesaplar. \nFormat: sayi,kuvvet: ");
		scanf("%d,%d",&sayi,&kuvvet);
		printf("%d'nin %d.dereceden kökü: %f\n",sayi,kuvvet, kok(sayi,kuvvet));
}
	return 0;
}

float kok(float sayi,int kuvvet){

	float kok=1,katsayi=100;
	int devam=1,sigorta=0;

	while(devam){
		if(sigorta==25000) devam=0;
		if(power(kok,kuvvet)<sayi) kok+=katsayi;
		if(power(kok,kuvvet)>sayi){
			kok-=katsayi;
			katsayi=katsayi/10;
		}
		if(sayi==power(kok,kuvvet)) devam=0;
		sigorta++;
	}
	return kok;
}

float power(float sayi,int kuvvet){
	int i;
	float sonuc=1;
	for(i=0;i<kuvvet;i++) sonuc*=sayi;
	return sonuc;
}
