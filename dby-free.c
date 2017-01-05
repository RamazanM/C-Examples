/*
Dinamik bellek yönetimi ile ilgili yardımcı kodları içerir.
Free örneği.
Amaç:Free komutu verildiğinde pointer'ın boşa çıktığını göstermek.
*/
#include <stdio.h>
#include <stdlib.h> //Dinamik bellek yönetimi kodlarını yazabilmemiz için stdlib kütüphanesi gereklidir.

int main(){
  char *harfler;
  harfler=malloc(15*sizeof(char));  //15 char'lık bir alan ayırdık.
  int i;
  for(i=0;i<15;i++) *(harfler+i)='R'; //15'ini de R harfi ile doldurduk.
  printf("Dolduruldu...\n");
  for(i=0;i<15;i++) printf("%d.)%c\n", i , *(harfler+i) );
  free(harfler);
  printf("Boşaltıldı...\n");
  for(i=0;i<15;i++) printf("%d.)%c\n", i , *(harfler+i) );

}
