#include <stdio.h>

/*
Her çift sayı iki asal sayının toplamıdır?
*/

int main(){
  int i,j;
  int bir=1,iki=1;
   for(i=4;i<35;){//çift sayıları saydır.
     j=0;
     while((bir+iki)!=i){
       if(bir+iki<i){
        if(j%2!=0) bir=next_asal(bir);
        if(j%2==0) iki=next_asal(iki);
        // printf("i:%d\n",i );
        // printf("%d+%d=%d\n",bir,iki,bir+iki);
         if(bir+iki==i){
           printf("Bulundu:%d+%d=%d\n",bir,iki,i );
           i+=2;
         }
         j++;
       }
       else{
        if(j%2!=0) bir=prev_asal(iki);
        if(j%2==0) iki=prev_asal(iki);
        if(bir+iki==i){
          printf("Bulundu:%d+%d=%d\n",bir,iki,i );
          i+=2;
        }
        j++;
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
