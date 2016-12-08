/*
Klasik adam asmaca oyununun konsol versiyonu.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <locale.h>
char *randomSatir(char *dosyaAdi);
//Prototip tanımlama gerekli!!!
int main(int argc, char const *argv[]) {
  srand(time(NULL));
  char *locale;
  locale = setlocale(LC_ALL, "");

  int tryAgain=1;
  char answer;
  while(tryAgain){
    game();//Oyunu başlatır...
    printf("\nYeniden Oynamak İster misiniz?(E/H)\n\n");
    answer=getch();
    if(answer=='E'||answer=='e') tryAgain=1;
    else {
      tryAgain=0;
      printf("İyi günler...\n"); }
    }
    return 0;
}

int game(){
  int i,j,harfSayaci=0;
  char *filename="./kelime";  //Dosya uygulamanın yanında...
  char *kelime=randomSatir(filename);
  char bulunan[40]="                    ";
  int uzunluk=strlen(kelime);
  char harfler[10]="         ";
  int gameContinue=1;

  printf("10 hamle hakkınız var.\nAranan kelimeyi bulmalısınız.\n");
  printf("Bir harf deneyiniz:\n" );

  while(gameContinue){

    harfler[harfSayaci]=getch();
    harfSayaci++;

    for(i=0;i<strlen(kelime)-1;i++){
      for(j=0;j<harfSayaci;j++){ if(kelime[i]==harfler[j]) bulunan[i]=kelime[i];  }
    }

    printf("\nKelime:");kelimeYazdir(bulunan,uzunluk);
    printf("Denenen Harfler:");denenen(harfler);
    printf("%d Hamleniz kaldı.\n",10-harfSayaci );

    if(compareStr(kelime,bulunan,uzunluk)) {printf("Tebrikler kazandınız...\n" ); gameContinue=0;}
    if(harfSayaci>=10){printf("Maalesef Hakkınız doldu...\nDoğru Cevap:%s",kelime );gameContinue=0;}
  }
  return 0;
}

char *randomSatir(char *dosyaAdi){
  FILE *dosya;
  char *line=NULL;
  char *donen_satir=NULL;
  int uzunluk=0;
  size_t len=0;
  ssize_t oku;
  int secili_satir=rastgele(kacSatirVar(dosyaAdi));
  dosya=fopen(dosyaAdi,"r");
  if (dosya!=NULL) {
    int sayac=0;
    while ((oku=getline(&line, &len,dosya))!= -1) {
      if (sayac==secili_satir) {
        donen_satir=line;
        break;
      }
      else sayac++;
    }
    return donen_satir;
  }
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
int kacSatirVar(char *dosyaAdi){
  FILE *dosya;
  char *line=NULL;
  size_t len=0;
  ssize_t oku;
  int count=0;
  dosya=fopen(dosyaAdi,"r");
  if (dosya!=NULL)  while ((oku=getline(&line, &len,dosya))!= -1) count++;
  return count;
}
int getch(void){  //http://stackoverflow.com/a/23035044
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
int compareStr(char *ilk, char *ikinci,int length){
  int i,check=1;
  for(i=0;i<length;i++){
    if(ilk[i]==ikinci[i]) check++;
  }
  if (check==length) return 1;
  else return 0;
}
int kelimeYazdir(char *kelime,int length){
  length--;
  char sonuc[10];
  int i;
  for(i=length;i<10;i++){sonuc[i]=' ';}
  for(i=0;i<length;i++){
    if(kelime[i]!=' ')sonuc[i]=kelime[i];
    else sonuc[i]='_';
  }
  printf("%s",sonuc );
  return 0;

}
int denenen(char *dizi){
  char sonuc[10];
  int i;
  for(i=0;i<10;i++){
    sonuc[i]=dizi[i];
  }
  printf("%s",sonuc);
  return 0;
}
