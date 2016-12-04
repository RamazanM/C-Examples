#include <stdio.h>
#include<time.h>
/*
Her çift sayı iki asal sayının toplamıdır?
*/

int main(){
  printf("Goldbach hipotezi...\n");
  sleep(2);
  srand(time(NULL));
  int row_sayac=0;
  int i,j;
  int bir=1,iki=1;
<<<<<<< HEAD
   for(i=1500;i<10000000;){//çift sayıları saydır.
=======
   for(i=2220;i<10000000;){//çift sayıları saydır.
>>>>>>> fa49fee31f20922c0e834412c138082afcfc4775

     while((bir+iki)!=i){
       if(bir+iki<i){
        if(rand()%2!=0) bir=next_asal(bir);
        else iki=next_asal(iki);
        // printf("i:%d\n",i );
         //printf("%d+%d=%d\n",bir,iki,bir+iki);
         if(bir+iki==i){
           printf("Bulundu:%d+%d=%d",bir,iki,i );

           if(row_sayac<1){printf("\t");row_sayac++;} else {printf("\n"); row_sayac=0;}
           i+=2;
         }
       }
       else{
        if(rand()%2!=0) bir=prev_asal(iki);
        else iki=prev_asal(iki);
        if(bir+iki==i){
          printf("Bulundu:%d+%d=%d",bir,iki,i );

          if(row_sayac<1){printf("\t");row_sayac++;} else {printf("\n"); row_sayac=0;}
          i+=2;
        }
       }

     }

   }
  // for(i=0;i<70;i++){
  //   if(i%2==0)bir=next_asal(bir);
  //   if(i%2!=0)iki=next_asal(iki);
  //   printf("%d+%d=%d\n",bir,iki,bir+iki);
  // }
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
