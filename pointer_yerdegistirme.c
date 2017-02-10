#include<stdio.h>
//#################################
int yerdegistir(int *a, int *b){
   int gecici=*a;
   *a=*b;
   *b=gecici;
}
//#################################
//Yukarıdaki fonksiyon sınavda soru olarak çıkmıştı.
int main(){
  int ilk,ikinci;
  printf("ilk sayi:");
  scanf("%d",&ilk);
  printf("ikinci sayi:");
  scanf("%d",&ikinci);

  printf("ilk:%d\tikinci:%d\n",ilk,ikinci);

  printf("Yer Degistiriliyor...\n");
  yerdegistir(&ilk,&ikinci);

  printf("ilk:%d\tikinci:%d\n",ilk,ikinci);
}
