#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void save_score(float,int); //Prototip

typedef struct Score{ //Kullanıcı ismini ve skorunu tutan struct.
  char isim[20];
  float puan;
}score;

int is_valid(int sayi){ //Rastgele üretilen numaranin istenilen sartlara uyup uymadiğini kontrol eden fonksiyon.
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

void check_match(int sayi,int tahmin,int* arti,int* eksi){//Bilgisayarin belirlediği rakamlarla kullanicinin girdiğini kontrol eder sonucu sözel olarak döndürür.
  char sayi_c[4];
  char tahmin_c[4];
  sprintf(sayi_c,"%d",sayi);
  sprintf(tahmin_c,"%d",tahmin);
  int dogru_sayac=0,yanlis_sayac=0,i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      if(sayi_c[i]==tahmin_c[j]){
        if(i==j){
          dogru_sayac++;
          (*arti)=(*arti)+1;
        }
        else{
          yanlis_sayac++;
          (*eksi)=(*eksi)-1;
        }
      }
    }
  }
  printf("Girilen rakamlarin %d tanesi var, %d tanesi dogru yerde, %d tanesi yanlis yerde.\n",dogru_sayac+yanlis_sayac,dogru_sayac,yanlis_sayac );
}

float puan(float arti,float eksi,float hak){//Artı eksi ve kullanılan hakka göre puanı hesaplayıp döndürür.
  return 10*arti+5*eksi+(1000/hak)-( (arti*eksi)/(arti+eksi) );
}

score* top10(){ //ilk 10 kişiyi skor dizisi olarak döndürür.
  FILE *dosya;
  dosya=fopen("high_score.txt","rb");
  score *puan=(score*)malloc(10*sizeof(score));

  for(int i=0;i<10;i++){
    fread((puan+i),sizeof(score),1,dosya);
}
  fclose(dosya);
  return puan;
}

void check_high_score(float puan){ //Oyuncunun top10'a girip giremediği kontrol edilir.
  score *top=top10();
  for(int i=0;i<10;i++){
    if( puan > (top+i)->puan ){
      printf("Tebrikler ilk 10'a girdiniz.\n");
        save_score(puan,i);
        break;
    }
  }
}

void save_score(float puan,int position){//check_high_score'dan gelen sıra bilgisine göre oyuncuyu gerekli sıraya yerleştirir.
  score *enIyiler=top10();
  score *temp=top10();
  FILE *dosya;
  dosya=fopen("high_score.txt","w+");
  printf("Isminizi giriniz:");
  char isim[20];
  scanf("%s",isim);
  score player_puan;
  strcpy(player_puan.isim,isim);
  player_puan.puan=puan;
  *(enIyiler+position)=player_puan;

  for(int i=position+1;i<10;i++){
    *(enIyiler+i)=*(temp+i-1);
  }

  for(int i=0;i<10;i++){
    fwrite((enIyiler+i),sizeof(player_puan),1,dosya);
  }

  fclose(dosya);
}

void print_top10(){//Zirvedekiler listesini ekrana bastırır.
  printf("Lider Tablosu\n");
  score *top=top10();
  for(int i=0;i<10;i++)
    if((top+i)->puan > 0)
      printf("%d) %s\t%f\n",i+1,(top+i)->isim,(top+i)->puan );
  printf("\n");
}


int main(int argc, char const *argv[]) {
  srand(time(NULL));

  print_top10(); //İlk 10 a girenler listeleniyor.

  int sayi=-1,tahmin=-1;
  int arti=0,eksi=0,hak=0;

  while(!is_valid(sayi))  sayi=1000+rand()%9000; //Geçerli bir random sayı belirleniyor.

  if(argc>1&& strcmp(argv[1],"-d") ) printf("4 haneli sayi belirlenmistir.\n%d\n",sayi); //Debug satırı.

  while(sayi!=tahmin && hak<10){
    printf("\nKalan Hakkınız:%d\nTahmininizi Yaziniz:",10-hak);
    scanf("%d",&tahmin);
    hak++;
    check_match(sayi,tahmin,&arti,&eksi);
  }
  float anlik_puan=puan( (float) arti,(float) eksi,(float) hak);
  printf("\nPuaniniz:%f\n",anlik_puan );
  check_high_score(anlik_puan); //Top 10'a girip girmediği kontrol edilir girdiyse isim istenip listeye eklenir.
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  print_top10();
  return 0;
}
