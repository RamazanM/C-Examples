#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int el_sayisi=0;
  int dizi[10];
  int sayi;
  while( el_sayisi<10){
    printf("Sayi giriniz : ");
    scanf("%d",&sayi);
    *(dizi+el_sayisi)=sayi;
    el_sayisi++;

  }

  int i,enk=99999,enb=-99999;
  for (i = 0; i < el_sayisi; i++) {
    printf("%d)%d\n",i,*(dizi+i) );
    if(*(dizi+i)<enk)enk=*(dizi+i);
    if(*(dizi+i)>enb)enb=*(dizi+i);
  }
  printf("Enk:%d\tEnb:%d\nFark:%d\n",enk,enb,enb-enk );
  return 0;
}
