#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ogrenci{
	yas;
	sinif;
	};
typedef struct ogrenci OgrBlg;

int main(){
	OgrBlg dizi[3];
	int i;
	for(i=0;i<3;i++){
		dizi[i].yas=rand()%10+18;
		dizi[i].sinif=rand()%4+1;	
		}		
	for(i=0;i<3;i++){
		printf("id:%d, yas:%d, sinif:%d\n",i,dizi[i].yas,dizi[i].sinif);
		}		
	
}