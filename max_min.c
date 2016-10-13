/*
Bu program kullanıcıdan aldığı maximum 100 sayı arasından
en küçüğünü ve en büyüğünü bulmak için yazılmıştır.
sayı girişini sonlandırmak için "-0" değeri verilmelidir.
*/
#include <stdio.h>
int main() {
  int sayilar[100];
  int sayac=0,devam=1;
  int tick=251;
  printf("Sayıları giriniz...\n" );
  while (devam) {
    scanf("%d",&sayilar[sayac]);
    printf("OK\n");
    if(sayilar[sayac]==-0) devam=0;
    else sayac++;
  }
  printf("Sayı girişi bitti, hesaplanıyor...\n" );

  printf("En büyüğü: %d\nEn küçüğü:%d",maximum(sayilar,sayac),minimum(sayilar,sayac) );

  return 0;
}

int maximum(int sayilar[],int sayac) {
  int i=0;
  int max=sayilar[0];
  for ( i = 1; i < sayac; i++) {
    if (max<=sayilar[i]) max=sayilar[i];
  }
  return max;
}

int minimum(int sayilar[],int sayac) {
  int i=0;
  int min=sayilar[0];
  for ( i = 1; i < sayac; i++) {
    if (min>=sayilar[i]) min=sayilar[i];
  }
  return min;
}
