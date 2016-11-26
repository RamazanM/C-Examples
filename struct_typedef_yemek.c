/*
Yemek isminde bir yapı(struct) yarattık.
Bunu typedef ile tip haline getirdik.
Yemek tipinde sonuç döndüren bir fonksiyon yazdık rastgele_yemek().
10 elemanlı bir yemek dizisini rastgele doldurup ekrana bastırdık.
26/11/2016
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

struct Yemek{
	int kalori;
	int tuz;
	int yag;
	int protein;
	};
	
	typedef struct Yemek yemek;

yemek rastgele_yemek();

int main(){
	srand(time(NULL));
	yemek yemekler[10];
	int i;
	for(i=0;i<10;i++){
		yemekler[i]=rastgele_yemek();
		}
	for(i=0;i<10;i++){
		printf("%d. yemeğin;\nKalorisi:%d\nTuzu:%d\nYağı:%d\nProteini:%d\n---------------\n",
		i+1,yemekler[i].kalori,yemekler[i].tuz,yemekler[i].yag,yemekler[i].protein);
		}
	
	}
	
yemek rastgele_yemek(){
	yemek gecici;
	gecici.kalori=20+rand()%181;
	gecici.tuz=rand()%11;
	gecici.yag=rand()%21;
	gecici.protein=rand()%20;
	return gecici;
	}