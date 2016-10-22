/*
Bu uygulamada bilgisayarın rastgele ürettiği iki sayı ile
rastgele seçtiği bir operatörü kullanarak çeşitli matematiksel işlemlerin sonucunu kullanıcıdan istedim.
Kullanıcı yanlış cevap verene kadar yeni soru ürettim.
Yanlış cevap geldiğinde kaç saniyede kaç doğru cevap verdiğini gösterdim.
Ramazan Mutlu
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int devam=1,dogru=0;
  time_t start,end;
  double fark;
  time(&start);
  while (devam) {
    int sonuc,cevap;
    int sayi1=rastgele(25);
    int sayi2=rastgele(26);
    int operator=rastgele(4);
    switch (operator) {
      case 1:
      sonuc=sayi1+sayi2;
      cevap;
      printf("%d+%d=",sayi1,sayi2);
      scanf("%d", &cevap);
      if (cevap==sonuc) { printf("Tebrikler doğru cevap...\n" ); dogru++; }
      else {
        printf("Doğru cevap:%d olacaktı...\n",sonuc);
        devam=0;
    }
      break;

      case 2:
      sonuc=sayi1-sayi2;
      cevap;
      printf("%d-%d=",sayi1,sayi2);
      scanf("%d", &cevap);
      if (cevap==sonuc) { printf("Tebrikler doğru cevap...\n" ); dogru++; }
      else {
         printf("Doğru cevap:%d olacaktı...\n",sonuc);
         devam=0;
       }
      break;
      case 3:
      sonuc=sayi1*sayi2;
      cevap;
      printf("%dx%d=",sayi1,sayi2);
      scanf("%d", &cevap);
      if (cevap==sonuc) { printf("Tebrikler doğru cevap...\n" ); dogru++; }
      else {
        printf("Doğru cevap:%d olacaktı...\n",sonuc);
        devam=0;
      }
      break;
      case 4:
      sonuc=sayi1/sayi2;
      cevap;
      printf("%d/%d=",sayi1,sayi2);
      scanf("%d", &cevap);
      if (cevap==sonuc) { printf("Tebrikler doğru cevap...\n" ); dogru++; }
      else {
        printf("Doğru cevap:%d olacaktı...\n",sonuc);
        devam=0;
    }
      break;
    }
  }
  time(&end);
  fark=difftime(end,start);
  printf("%.0f saniyede %d doğru cevap. Tebrikler...\n",fark,dogru);
  return 0;
}

int rastgele(int max){
  srand(time(NULL));
  int sayi=0;
  while (sayi==0) {
    sayi=rand()%max;
  }
  srand(time(NULL));
  return sayi;
}
