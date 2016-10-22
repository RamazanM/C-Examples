/*
Bu uygulamada fibonacci adında bir fonksiyon tanımladım.
Bu fonksiyon, parametre olarak verilen sayıya kadar olan fibonacci sayılarını ekrana yazdırıyor.
Ramazan Mutlu
*/
void fibonacci(int max);

#include <stdio.h>
int main() {
  fibonacci(1000);
  return 0;
}

void fibonacci(int max) {
  int ilk=1,ikinci=2,toplam=0;
  printf("%d,",ilk );
  while (ikinci<max) {
    printf("%d,",ikinci );
    toplam=ilk+ikinci;
    ilk=ikinci;
    ikinci=toplam;
  }
}
