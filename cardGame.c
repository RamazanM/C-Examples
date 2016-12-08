#include<stdio.h>
#include<stdlib.h>

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

typedef struct Card{
	int sym;
	int num;
} card;

typedef struct Player{
	card cards[13];
	} player;

card deste[52];

void printDeste();
void setup();

int main(){
	player Oyuncular[4];
	setup();
	printDeste();
}

void setup(){
	int i,j,sayac=0;

	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			deste[sayac].sym=i;
			deste[sayac].num=j;
			sayac++;
		}
	}

}

void printCards(player oyuncu){

}

void shareCards(card * dizi, player oyuncu){

}
void printDeste(){
	int i=0;
	for(i;i<52;i++){
		if(i%5==0)	printf("\n");
	 	switch (deste[i].sym) {
	 		case 0:
			printf("%s %d\t",SPADE,deste[i].num );
			break;
			case 1:
			printf("%s %d\t",CLUB,deste[i].num );
			break;
			case 2:
			printf("%s %d\t",HEART,deste[i].num );
			break;
			case 3:
			printf("%s %d\t",DIAMOND,deste[i].num );
			break;
	 	}
	}
}
