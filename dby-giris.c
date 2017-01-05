//Dinamik bellek yönetimi ile ilgili yardımcı kodları içerir.
//Calloc ve Malloc örneği...
#include <stdio.h>
#include <stdlib.h> //Dinamik bellek yönetimi kodlarını yazabilmemiz için stdlib kütüphanesi gereklidir.
#include <time.h>

int main() {
  srand(time(NULL));//Rastgeleliliği sıfırla.

  int* ptr; //ptr isimli göstergeçimizi oluşturduk.

  ptr=(int*) malloc(10 * sizeof(int));   //Bellekten içinde belirtilen byte kadar yer ayırır.
  ptr=(int*) calloc(10,sizeof(int));     //İçinde belirtilen sayı kadar, belirtilen tipte yer ayırtır.İçini boşaltır.
  //^Yukarıdakilerden sadece birisini kullanmak kafidir. Örnek olması için ikisi de yazılmıştır...^//
  //^Yukarıdakileri veri türüne cast etmeyi "(int*)" unutmamalıyız, derleyici hata vermese de hoca puan kırar.

  //Ayrılan yeri nasıl kullanırız?  -Dizi olarak
  int i;  //Sayaç değişkeni.
  for(i=0;i<10;i++)  *(ptr+i)=rand()%151;  //ptr'nin gösterdiği yerin i sonrasına tastgele değer yaz.
  for(i=0;i<10;i++)  printf("%d.Eleman:%d\n",i,*(ptr+i) );  //ptr'nin i fazlasını yazdır.

  return 0;
}
