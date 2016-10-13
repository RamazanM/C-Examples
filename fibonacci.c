/*
Bu uygulamada fibonacci adında bir fonksiyon tanımladım.
Bu fonksiyon, parametre olarak verilen sayıya kadar olan fibonacci sayılarını ekrana yazdırıyor.
Ramazan Mutlu
*/
#include <stdio.h>
int main() {
  fibonacci(1000);
  return 0;
}

int fibonacci(int max) {
  int ilk=1,ikinci=2,toplam=0;
  printf("%d,",ilk );
  while (ilk<max) {
    printf("%d,",ikinci );
    toplam=ilk+ikinci;
    ilk=ikinci;
    ikinci=toplam;
  }
  return 0;
}


/*
/home/ramazan/Desktop/C-Cpp/C/fibonacci.c:12:6: warning: conflicting types for ‘fibonacci’ [enabled by default]
void fibonacci(int max) {
^
/home/ramazan/Desktop/C-Cpp/C/fibonacci.c:8:3: note: previous implicit declaration of ‘fibonacci’ was here
fibonacci(1000);
^*/
