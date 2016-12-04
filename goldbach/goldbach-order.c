#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/*
Her çift sayı iki asal sayının toplamıdır?
*/

int main(int argc, char const *argv[]){
  int arg = strtol(argv[1], NULL, 10);
  printf("Goldbach hipotezi...\n Başlangıç:%d\n",arg);
  sleep(2);
  srand(time(NULL));
  int row_sayac=0;
  int i,j;
  int bir=1,iki=1;

   for(i=arg;i<1000000;i+=2){//çift sayıları saydır.

     for(bir=2;bir<i;bir=next_asal(bir)){
       for(iki=2;iki<i;iki=next_asal(iki)){
         if(bir+iki==i){
           printf("Bulundu:%d+%d=%d",bir,iki,bir+iki );
           if(row_sayac<6){printf("\t");row_sayac++;} else {printf("\n"); row_sayac=0;}
           break;
         }
       }
       if(bir+iki==i) break;
     }
   }

}

int next_asal(int sayi){
  sayi+=1;
  while(!asal_sayi(sayi)) sayi++;
  return sayi;
}
int prev_asal(int sayi){
  sayi-=1;
  while(!asal_sayi(sayi)) sayi--;
  return sayi;
}
int asal_sayi(int sayi){
	int asal=1;
	int i;
	for(i=2;i<sayi;i++){
		if(sayi%i==0){
			asal=0;
			break;
			}
		}
	return asal;
	}
