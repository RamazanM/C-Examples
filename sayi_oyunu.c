#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int is_valid(int sayi){ //Rastgele üretilen numaranın istenilen şartlara uyup uymadığını kontrol eden fonksiyon.
  char sayi_c[4];
  sprintf(sayi_c,"%d",sayi);
  return(
    (sayi_c[0]!=sayi_c[1])&&
    (sayi_c[0]!=sayi_c[2])&&
    (sayi_c[0]!=sayi_c[3])&&
    (sayi_c[1]!=sayi_c[2])&&
    (sayi_c[1]!=sayi_c[3])&&
    (sayi_c[2]!=sayi_c[3])
  );
}

void check_match(int sayi,int tahmin){//Bilgisayarın belirlediği rakamlarla kullanıcının girdiğini kontrol eder sonucu sözel olarak döndürür.
  char sayi_c[4];
  char tahmin_c[4];
  sprintf(sayi_c,"%d",sayi);
  sprintf(tahmin_c,"%d",tahmin);
  int dogru_sayac=0,yanlis_sayac=0,i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      if(sayi_c[i]==tahmin_c[j]){
        if(i==j)dogru_sayac++;
        else yanlis_sayac++;
      }
    }
  }
  printf("Girilen rakamların %d tanesi var, %d tanesi dogru yerde, %d tanesi yanlis yerde.\n",dogru_sayac+yanlis_sayac,dogru_sayac,yanlis_sayac );
}



int main() {
  srand(time(NULL));
  int sayi=-1,tahmin=-1;
  while(!is_valid(sayi))sayi=rand()%10000;
  printf("4 haneli sayı belirlenmiştir.\n");
  while(sayi!=tahmin){
    printf("Tahmininizi Yazınız:");
    scanf("%d",&tahmin);
    check_match(sayi,tahmin);
  }
  printf("Tebrikler...\n");
  return 0;
}
