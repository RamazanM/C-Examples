#include<stdio.h>
#include <time.h>

void randomDoldur (int * dizi , int length);
void diziYazdir (int * dizi, int length);
 


int main (){

 srand (time (NULL));

 int sayilar[10];
 randomDoldur(sayilar,10);
 diziYazdir(sayilar,10);
 
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