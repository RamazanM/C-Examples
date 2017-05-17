#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//beyaz 1 siyah 0
//#define clear() printf("\033[H\033[J")
// #define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

typedef struct Hane{
  int id;
  int renk;
  int sayi;
  struct Hane * next;
} hane;
hane * first=NULL;
int oyunSirasi=0;
int imlec=0;
char ntc(int sayi){
  switch (sayi) {
    case 1:return 'B';
    case 0:return 'S';
    default: return ' ';
  }
}
int countHane(int haneS,int renk){
  int i;
  hane *hptr=first;
  for(i=2;i<=haneS;i++){
    hptr=hptr->next;
  }
  if(hptr->renk==renk) return hptr->sayi;
  else return -1;
}
int checkHane(int haneS,int yukseklik){
  int i;
  hane *hptr=first;
  for(i=2;i<=haneS;i++){
    hptr=hptr->next;
  }
  if(hptr->sayi>=yukseklik) return hptr->renk;
  else return 9;
  printf("%d.bolmede %d tane %d tasi var\n",haneS,hptr->sayi,hptr->renk);

}
void setup(){  //Tavla tahtasının kurulumunu yapar.

  first = malloc(sizeof(hane));
  hane *hptr=first;
  FILE *setupFile=fopen("tavlasetup.bin","rb");
  char satir[20];
  size_t uzunluk=0;
  ssize_t oku;

  if(setupFile==NULL) printf("okuma hatasi");
  while ( fgets(satir,sizeof(satir),setupFile) ) {
    int dolu=sscanf(satir,"%d %d %d",&hptr->id,&hptr->renk,&hptr->sayi);
    if(dolu<2){
      sscanf(satir,"%d",&hptr->id);
      hptr->renk=-1;
      hptr->sayi=-1;
    }
    hptr->next=malloc(sizeof(hane));
    hptr=hptr->next;
  }
  fclose(setupFile);
}
void tahtayiCiz(){ //Tavla tahtasını konsola çizer.
  printf("***************************************************************\n");
  int i,j;
  for(i=1;i<7;i++){
    for(j=1;j<=12;j++){
      if(imlec==j)printf("x");
      if(j==1||j==7) printf("*");
      if(j==12) {
        printf("| %c |",ntc(checkHane(j,i)) );
        printf("*\n" );
      }
      else printf("| %c |",ntc(checkHane(j,i)) );
    }
  }

  printf("\n\n\n\n" );

  for(i=7;i>=1;i--){
    for(j=24;j>=13;j--){
      if(j==24||j==18) printf("*");
      if(j==13) {
        printf("| %c |",ntc(checkHane(j,i)) );
        printf("*\n" );
      }
      else printf("| %c |",ntc(checkHane(j,i)) );
    }
  }
  printf("***************************************************************\n");

}
void imlecYerlestir(int yon){
  if (imlec<1 || imlec>24) imlec=1;
  if(yon==1){
    while(countHane(imlec,1)==-1) imlec++;
  }
  else{
    while(countHane(imlec,1)==-1) imlec--;
  }
}
int zar_at(){ //1 den 6 ya kadar rastgele değer döndürür.
  return rand()%6+1;
}

int main(){
  srand(time(NULL)); //Rastgeleliği sıfırlar.
  setup();
  tahtayiCiz();
}
