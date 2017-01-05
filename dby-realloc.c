/*
Dinamik bellek yönetimi ile ilgili yardımcı kodları içerir.
Realloc örneği.
Amaç:Veri girildikçe büyüyen bir bellek alanı ayırmak.
*/

#include <stdio.h>
#include <stdlib.h> //Dinamik bellek yönetimi kodlarını yazabilmemiz için stdlib kütüphanesi gereklidir.

int main(){
    int *notlar,i=0,toplam=0,ort=0; //notları gösterecek pointer'ı ve gerekli değişkenleri tanımladık.
    malloc(1*sizeof(int));  //1 integerlık yer ayırdık.

    while (1) { // Programı sonsuz döngüye soktuk, ileride break ile çıkacağız.
      printf("Not giriniz:");
      scanf("%d",notlar+i); //notlar'ın i sonrasına gelen değeri atadık. notlar zaten bir pointer olduğu için & işareti kullanmadık.

      if( *(notlar+i) != -1 ){  //Girilen sayının -1 olup olmadığını kontrol ettik.
        toplam+=*(notlar+i);  //toplam değişkenine girilen sayıyı ekledik.
        i++;  //i sayacımızı 1 arttırdık.
      }
      else  break;  //girilen sayı -1 ise döngüden çık.
    }
    ort=toplam/i;
    printf("Notlarin toplami:%d\nOrtalamasi:%d\n",toplam,ort );
}
