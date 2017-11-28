#include <stdio.h>
#include <stdlib.h>

typedef struct musteri{
  int oncelik;
  char isim[20];
  struct musteri * next;
}musteri;

  musteri * ilk=NULL;


void musteriEkle(){
  //Müşterileri öncelik sırasına göre ekleyen fonksiyon
  musteri * yeni=(musteri*)malloc(sizeof(musteri));
  printf("Oncelik numaranizi giriniz:");
  scanf("%d",&yeni->oncelik);
  printf("Isminizi giriniz:");
  scanf("%s",yeni->isim );
  yeni->next=NULL;
  if(ilk==NULL){
    ilk=yeni;
  }
  else if(ilk->oncelik >= yeni->oncelik){
    yeni->next=ilk;
    ilk=yeni;
  }
  else{
    musteri * gezici=ilk;
    while(gezici->next!=NULL && gezici->next->oncelik <= yeni->oncelik)
      gezici=gezici->next;
    yeni->next=gezici->next;
    gezici->next=yeni;

  }

}

void musteriSil(){
    //Verilen sıra numarasına sahip müşteriyi silen fonksiyon.
    //İlk müşteriyi parametre olarak alır.
    if(ilk!=NULL){
      printf("%d oncelikli %s isimli musteri silindi\n",ilk->oncelik,ilk->isim);
      ilk=ilk->next;
    }
    else{
      printf("Silinecek musteri yok.\n");
    }

}

void musteriBastir(){
  musteri * gezici=ilk;
  while(gezici!=NULL){
    printf("%d oncelikli %s isimli musteri\n",gezici->oncelik,gezici->isim);
    gezici=gezici->next;
  }
}



int main(int argc, char const *argv[]) {
  musteriEkle();
  musteriEkle();
  musteriEkle();
  musteriBastir();
  musteriSil();
  musteriSil();
  musteriSil();
  musteriSil();

  return 0;
}
