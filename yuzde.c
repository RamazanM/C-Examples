/*
  Farklı üye sayılarına sahip grupların yüzdelik dilimini gösteren yazılım.
  -1 değeri girildiğine hesaplamaya başlar.
*/
#include <stdio.h>
int main() {
  int uyeler[50];
  int sayac=1,devam=1;

  while (devam) {
    printf("%d.Gruptaki üye sayısı:",sayac );
    scanf("%d", &uyeler[sayac]);
    if (uyeler[sayac]!=-1) sayac++;
    else devam=0;
  }

  float carpan=100/(float) diziTopla(uyeler,sayac);
  int i=0;
  for ( i = 1; i < sayac; i++) {
    printf("%d. grubun yüzdesi:%.2f \n",i,uyeler[i]*carpan);
  }
  printf("Toplam üye sayısı:%d", diziTopla(uyeler,sayac));
  return 0;
}

int diziTopla(int *dizi,int sayac){
  int i;
  int toplam=0;
  for ( i = 1; i < sayac; i++) {
    toplam+=dizi[i];
  }
  return toplam;
}
