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
int rastgele(int);
int cevap_to_sayi(char);
int getch(void);
void game();
void gameover();

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
  int dogru_sayisi;
  int yanlis_sayisi;
  int puan;
}oyun;

int main(){
  setup();
  while (oyun.yanlis_sayisi==0) game();
  gameover();
}

void game(){              //oyunun ana mekanizmasını oluşturur.
  char cevap=-1;
  if(soru_cek()){
    printf("%d)%s\nA)%s\tB)%s\tC)%s\tD)%s\n",
    oyun.sorulan_sayisi,
    soru.soru_metni,
    soru.cevaplar[0],
    soru.cevaplar[1],
    soru.cevaplar[2],
    soru.cevaplar[3]);

    while(cevap_to_sayi(cevap)==-1){
      printf("\nCevap:");
      cevap=getch();
      printf("%c\t",cevap);
    }
      if(cevap_to_sayi(cevap)==soru.dogru){
        printf("Doğru cevap\n\n");
        oyun.dogru_sayisi++;
      }
      else oyun.yanlis_sayisi++;

  }
}

int setup(){              //oyunun çalışması için gerekli ayarlamaları yapar.
  printf("Hoşgeldiniz. Cevapların altındaki bar dolmadan doğru cevabı vermeniz gerekmekte.\n\n");
  int i=0;
  oyun.soru_dosyasi="./sorular.bin";
  oyun.sorulan_sayisi=0;
  oyun.puan=0;
  oyun.dogru_sayisi=0;
  oyun.yanlis_sayisi=0;
  oyun.sorulanlar=calloc(50,sizeof(int));
  soru.cevaplar=malloc(4*sizeof(int));
  soru.soru_metni=malloc(250*sizeof(char));
  for(i;i<4;i++)soru.cevaplar[i]=malloc(50*sizeof(char));

}

int soru_cek(){           //rastgele soru çekip, soru nesnesini doldurur. hata varsa 0 döndürür.
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
      if (sayac==secili_satir-1) {
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
    return 1;
  }
  else return 0;

}

int rastgele_soru(){      //soru_cek fonksiyonu için rastgele soru sağlar.
  int flag=1,temp,i;
  int sorulan_sayisi=oyun.sorulan_sayisi;
  while (flag){
    flag=0;
    temp=rastgele(soru_sayisi()+1);
    for(i=0;i<sorulan_sayisi;i++){
      //printf("temp=%d\toyun.sorulanlar[%d]=%d\n",temp,i,oyun.sorulanlar[i]);
      if(oyun.sorulanlar[i]==temp) {
        i=sorulan_sayisi;
        flag=1;
      }
    }
  }
  return temp;
}

int soru_sayisi(){        //soru dosyasındaki soru sayısını döndürür.
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
  sleep(1);
  srand(time(NULL));
  return sayi;
}

int getch(void){          //http://stackoverflow.com/a/23035044
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int cevap_to_sayi(char c){//harf olarak gelen cevabı sayısal değere çevirir. hata:-1
  if(c=='a'||c=='A'||c==0) return 0;
  if(c=='b'||c=='B'||c==1) return 1;
  if(c=='c'||c=='C'||c==2) return 2;
  if(c=='d'||c=='D'||c==3) return 3;
  else return -1;
}

void gameover(){          //oyun bittiğinde puanı yazdırır.
  printf("Yanlış cevap verdiniz oyun bitti.\n");
  printf("Puanınız:%d\n",oyun.dogru_sayisi);
}
