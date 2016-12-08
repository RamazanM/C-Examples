#include<stdio.h>
#include<stdlib.h>

int diziOrtalamasi(int * ilk, int * son);
int * diziCarp(int * ilk, int * iki, int size);
void printArray(int * ptr, int size);

int main(){
	int ilk[4]={4,10,5,5};	 // ilk dizimiz
	int iki[4]={2,1,4,3};	// ikinci dizi
	int * carpim = diziCarp(&ilk,&iki,4); //carpim ismindeki pointer'a diziCarp fonksiyonundan gelen adresi atıyoruz
	printArray(carpim,4);	//printArray fonksiyonuna başlangıç pointerini ve boyutunu veriyoruz.
}
	
int diziOrtalamasi(int * ilk, int * son){	//dizinin ortalamasını hesaplayıp sayı olarak döndüren fonksiyon
	int *i;
	int sum=0;
	for(i=ilk ; i < son ; i++) //ilk değerin adresi son değere eşit olana kadar->
		sum+=*i; 	//tümünü sum değişkenine ekle
	return sum/(son-ilk);
}

int * diziCarp(int * ilk, int * iki, int size){//verilen iki diziyi çarpan fonksiyon
	int * sonuc; //boş bir sonuç pointer'ı
	sonuc=calloc(size,sizeof(int));	//sonuç pointer'ına size kadar yer aç:
	int i;
	for(i=0;i<size;i++)
		*(sonuc+i)=*(ilk+i) * *(iki+i);	//sırayla değerleri çarpıp sonuc'tan i sonraki elemana ata
	return sonuc;	
	}
	
 void printArray(int * ptr, int size){
 	int i=0;
 	for(i=0;i<size;i++)
 		printf("Dizi[%d] : %d\n",i,*(ptr+i));
 	}