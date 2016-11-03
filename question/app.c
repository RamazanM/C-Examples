/*
Sorulan soru idsini sorulanlara eklemeyi unutma.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <termios.h>
#include <unistd.h>
#include <locale.h>

int setup();
int soru_cek();
int rastgele_soru();
int soru_sayisi();
int rastgele(int max);
void game();

struct soru {
  int soru_id;
  char *soru_metni;
  char **cevaplar;
  int dogru;
  time_t ilk_zaman;
  time_t son_zaman;
}soru;

struct oyun{
  char *soru_dosyasi;
  int *sorulanlar;
  int sorulan_sayisi;
  int puan;
}oyun;

int main(){
  setup();
  while (1) {
    game();
  }
}

void game(){
  int cevap;
  if(soru_cek()){
    printf("%d)%s\nA)%s\tB)%s\tC)%s\tD)%s\n",
    oyun.sorulan_sayisi,
    soru.soru_metni,
    soru.cevaplar[0],soru.cevaplar[1],soru.cevaplar[2],soru.cevaplar[3]);
    scanf("%d",&cevap);
    if(cevap==soru.dogru)printf("Doğru cevap\n");
    else printf("Yanlış cevap\n");
  }
}

int setup(){
  printf("Hoşgeldiniz. Cevapların altındaki bar dolmadan doğru cevabı vermeniz gerekmekte.\n");
  int i=0;
  oyun.soru_dosyasi="./sorular.bin";
  oyun.sorulan_sayisi=0;
  oyun.puan=0;
  oyun.sorulanlar=malloc(50*sizeof(int));
  soru.cevaplar=malloc(4*sizeof(int));
  soru.soru_metni=malloc(250*sizeof(char));
  for(i;i<4;i++)soru.cevaplar[i]=malloc(50*sizeof(char));

}

int soru_cek(){         //rastgele soru çekip, soru nesnesini doldurur. hata varsa 0 döndürür.
  FILE *dosya;
  char *line=NULL;
  char *donen_satir=NULL;
  int uzunluk=0;
  size_t len=0;
  ssize_t oku;

  int secili_satir=rastgele_soru();
  dosya=fopen(oyun.soru_dosyasi,"r");
  if (dosya!=NULL) {
    int sayac=0;
    while ((oku=getline(&line, &len,dosya))!= -1) {
      if (sayac==secili_satir) {
        donen_satir=line;
        break;
      }
      else sayac++;
    }

    char* smp=soru.soru_metni;
    char **ssmp=&smp;
    sscanf(donen_satir,"%d %s %s %s %s %s %d",
    &soru.soru_id,
    &soru.soru_metni[0],
    &soru.cevaplar[0][0],&soru.cevaplar[1][0],&soru.cevaplar[2][0],&soru.cevaplar[3][0],
    &soru.dogru);
    oyun.sorulanlar[oyun.sorulan_sayisi]=soru.soru_id;
    oyun.sorulan_sayisi++;
    printf("soru:%d\n",soru.soru_id );
    printf("soru_c:%d,%d\n",oyun.sorulanlar[0],oyun.sorulanlar[1] );
    return 1;
  }
  else return 0;

}

int rastgele_soru(){
  int temp=rastgele(soru_sayisi());
  int i=0,devam;
  //printf("Rastgele soru:%d\n",temp);

  while(1){
    devam=0;

    for(i=0;i<=oyun.sorulan_sayisi;i++){
      if(oyun.sorulanlar[i]==temp){
        temp=rastgele(soru_sayisi());
        devam=1;
      }
    }

    if(devam==0){
      return temp;
      //break;
    }
  }

}

int soru_sayisi(){
  FILE *dosya;
  char *line=NULL;
  size_t len=0;
  ssize_t oku;
  int count=0;
  dosya=fopen(oyun.soru_dosyasi,"r");
  if (dosya!=NULL)  while ((oku=getline(&line, &len,dosya))!= -1) count++;
  return count;
}

int rastgele(int max){    //rastgele sayı üretir.
  srand(time(NULL));
  int sayi=0;
  while (sayi==0) {
    sayi=rand()%max;
  }
  srand(time(NULL));
  return sayi;
}
