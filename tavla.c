#include<stdio.h>
#include<time.h>

typedef struct{ //Taşın bilgilerini tutan yapı
  int pos;
}tas;

int zar_at(){ //1 den 6 ya kadar rastgele değer döndürür.
  return rand()%6+1;
}




int main(){
  srand(time(NULL)); //Rastgeleliği sıfırlar.
}
