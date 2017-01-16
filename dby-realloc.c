/*
Dinamik bellek yönetimi ile ilgili yardımcı kodları içerir.
Realloc örneği.
Amaç:Veri girildikçe büyüyen bir bellek alanı ayırmak.
Ramazan Mutlu
*/

#include <stdio.h>
#include <stdlib.h> //Dinamik bellek yönetimi kodlarını yazabilmemiz için stdlib kütüphanesi gereklidir.

int main(){
    int *notlar,i=1,toplam=0,ort=0; //notları gösterecek pointer'ı ve gerekli değişkenleri tanımladık.
    notlar=(int*)malloc(i*sizeof(int));  //1 integerlık yer ayırdık.

    while (1) { // Programı sonsuz döngüye soktuk, ileride break ile çıkacağız.
      printf("Not giriniz:");
      scanf("%d",(notlar+i-1)); //notlar'ın i sonrasına gelen değeri atadık. notlar zaten bir pointer olduğu için & işareti kullanmadık.

      if( *(notlar+i-1) != -1 ){  //Girilen sayının -1 olup olmadığını kontrol ettik.
        i++;  //i sayacımızı 1 arttırdık.
        notlar =(int*) realloc(notlar,i*sizeof(int)); //Diziyi i eleman alacak şekilde genişlettik.
        printf("%d\n",*(notlar+i-2) );
        toplam+=*(notlar+i-2);  //toplam değişkenine girilen sayıyı ekledik.
        
      }
      else{  
      	break;
      }  //girilen sayı -1 ise döngüden çık.
    }
    ort=toplam/(i-1);
    printf("Notlarin toplami:%d\nOrtalamasi:%d\n",toplam,ort );
}
