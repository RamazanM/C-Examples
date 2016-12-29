#include<stdio.h>
#include<time.h>

int main() {
  srand(time(NULL));

  int dizi[100];
  int i,j;
  int max,index;

  for(i=0;i<100;i++)
    dizi[i]=rand()%1000;

    //Sıralama
    for(i=0;i<100;i++){
      max=-1;               //Maksimum değişkenini her kontrolde sıfırlıyoruz.
      for(j=0;j<100-i;j++){ //i kadar eleman sonda sıralı olduğundan 100-i'ye kadar dönüyor.
        if( dizi[j]>max ){
          max=dizi[j];
          index=j;          //sondaki elemanı geriye koymak için indexi de tutmalıyız.
        }
      }
      dizi[index]=dizi[j-1];//100-i de diyebilirdik ama j'nin değeri zaten bunun bir fazlası olduğu için j-1 dedim.
      dizi[j-1]=max;//dizinin son elemanını maximuma eşitledik.
    }

    for(i=0;i<100;i++)
      printf("%d.)%d\n",i,dizi[i] );
  return 0;
}
