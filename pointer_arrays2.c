#include<stdio.h>
#include<time.h>

void randomDoldur (int * dizi , int length);
void diziYazdir (int * dizi, int length);

int main (){
 srand (time (NULL));	//Rastgeleliliği sıfırla.
 int sayilar[10];					//10 elemanlı bir sayı dizisi tanımla
 randomDoldur(sayilar,10);//Sayılar dizisini rastgele doldur
 diziYazdir(sayilar,10);//Diziyi ekrana yazdır
 
}

void randomDoldur (int * dizi , int length){
 int i;
 for (i=0;i <length;i++)
  *(dizi+i)=rand()%51;  
}

void diziYazdir (int * dizi, int length){
 int i;
 for (i=0;i <length;i++)
  printf ("%d\n",*(dizi+i));
}