#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct ekmek {
	int boy;
	int en;
	char et;
	char biber;
	char domates;
	char sogan;
	char bosluk;
}ekmek;

char random_malzeme();
void setup(){
	srand(time(NULL));
	ekmek.boy=30;
	ekmek.en=10;
	ekmek.et='x';
	ekmek.biber='!';
	ekmek.domates='@';
	ekmek.sogan='0';
	ekmek.bosluk=' ';
	}

void basi (){
	int i,j;
	for(i=1;i<ekmek.en/2;i++){
		for(j=0;j<=ekmek.en;j++){
			if(j==ekmek.en/2+i || j==ekmek.en/2-i)printf("**");
			else if(j<ekmek.en/2+i && j>ekmek.en/2-i) printf(" %c",random_malzeme());
			else printf("  ");
			}
			printf("\n");
		}
	}
void ici (){
	int i,j;
	for(i=0;i<ekmek.boy;i++){
		for(j=0;j<=ekmek.en;j++){
			if(j==0||j==ekmek.en)	printf("**");
			else{
				printf(" %c",random_malzeme());
				}
			}
			printf("\n");
		}
	}
void sonu (){
		int i,j;
	for(i=ekmek.en/2;i>0;i--){
		for(j=ekmek.en;j>=0;j--){
			if(j==ekmek.en/2+i || j==ekmek.en/2-i)printf("**");
			else if(j<ekmek.en/2+i && j>ekmek.en/2-i) printf(" %c",random_malzeme());
			else printf("  ");
			}
			printf("\n");
		}

	}

char random_malzeme(){

	int sayi=rand()%4;
	switch(sayi){
		case 0:
		return ekmek.et;
		break;
		case 1:
		return ekmek.biber;
		break;
		case 2:
		return ekmek.domates;
		break;
		case 3:
		return ekmek.bosluk;
		break;
		}
	}

int main(){
	setup();
	basi();
	ici();
	sonu();
	return 0;
	}
