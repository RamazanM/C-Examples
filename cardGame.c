//0:SPADE --- 1:CLUB --- 2:HEART --- 3:DIAMOND
/*
Amaç: Batak gibi oyunlar için gerekli ortamı hazırlayıp,
bilgisayara natak oynatmak...
Ne aşamadayım:
+52 Kartlık deste oluşturuldu
+13'er şekilde 4 oyuncuya rastgele dağıtıldı
+Koz seçme diyaloğu yapıldı(Henüz seçim aktarılmıyor)
+Masa görünümü çizildi (drawTable)
+Atılacak kartı seçme diyaloğu yapıldı (Henüz seçim aktarılmıyor)

-Kart atma sistemi yazılacak
-Puan sistemi yazılacak
-Botların oynama sistemi
-Botların koz seçme sistemi

--Ramazan M	/	8.12.16
*/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

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
player Oyuncular[4];
int destede_kalan=52;

void printDeste();
void printCards(player oyuncu,int selected);
void setup();
void shareCards();
void desteDuzenle();
void chooseCard();
void chooseKoz();
int getch(void);

int main(){
	setup();//Gerekli ayarlamalar
	shareCards();//Kartları Dağıt
	chooseCard();//Atılacak kartı seçme diyaloğu
	//chooseKoz(); //Eğer koz seçme sırası sendeyse
	getchar();
}

void setup(){
	srand(time(NULL));
	int i,j,sayac=0;
	for(i=0;i<4;i++){
		for(j=1;j<=13;j++){
			deste[sayac].sym=i;
			deste[sayac].num=j;
			sayac++;
		}
	}
}
void choose_koz(){
	int selected=0;
	while(1){
		system("clear");
		switch(selected){
			case 0:
			printf("Kozu Seç: ->%s\t%s\t%s\t%s", SPADE,CLUB,HEART,DIAMOND );
			break;
			case 1:
			printf("Kozu Seç: %s\t->%s\t%s\t%s", SPADE,CLUB,HEART,DIAMOND );
			break;
			case 2:
			printf("Kozu Seç: %s\t%s\t->%s\t%s", SPADE,CLUB,HEART,DIAMOND );
			break;
			case 3:
			printf("Kozu Seç: %s\t%s\t%s\t->%s", SPADE,CLUB,HEART,DIAMOND );
			break;
		}
		printf("\n");
		switch(getch()) {
    case 67:    // key right
		if(selected<3){
			selected++;
    	break;}
			else break;
    case 68:    // key left
		if(selected>0){
			selected--;
			break;}
			else break;
			}


	}
}
void drawTable(){
	printf("\t\t\t\tPlayer2\n\t------------------------------------------------\n\n");
	printf("Player1|\tBuraya ortadaki kartlar yazılacak...\t|Player3");
	printf("\n\n\t------------------------------------------------\n");
}
void chooseCard() {
	int selected=0;
	drawTable();
	printf("Kartlarım:\n");
	printCards(Oyuncular[0],selected);
	printf("\n\n\n\n");
	while(1){
		switch(getch()) {
    case 67:    // key right
		if(selected<=11){
			selected++;
    	break;}
			else break;
    case 68:    // key left
		if(selected>0){
			selected--;
			break;}
			else break;
			}

			system("clear");
			drawTable();
			printf("\n\nKartlarım:\n");
		printCards(Oyuncular[0],selected);
			printf("\n\n\n\n");
	}
}
void printCards(player oyuncu,int selected){
	int i;

	for(i=0;i<13;i++){
		if(i%2==0)	printf("\n");
	 	switch (oyuncu.cards[i].sym) {
	 		case 0:
			if(i==selected)printf("->");
			printf("%s %d\t",SPADE,oyuncu.cards[i].num );
			break;
			case 1:
			if(i==selected)printf("->");
			printf("%s %d\t",CLUB,oyuncu.cards[i].num );
			break;
			case 2:
			if(i==selected)printf("->");
			printf("%s %d\t",HEART,oyuncu.cards[i].num );
			break;
			case 3:
			if(i==selected)printf("->");
			printf("%s %d\t",DIAMOND,oyuncu.cards[i].num );
			break;
	 	}

	}
}
void shareCards(){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			int choose = rand()%destede_kalan;
			Oyuncular[i].cards[j]=deste[choose];
			deste[choose].sym=-1;	deste[choose].num=-1; //Kartı sıfırla
			destede_kalan--;
			desteDuzenle();
			//------DEBUG-------printf("Oyuncu:%d - Kart:%d->sym:%d , num:%d\n",i,j,Oyuncular[i].cards[j].sym,Oyuncular[i].cards[j].num );
		}
	}
}
void printDeste(){
	int i=0;
	for(i;i<52;i++){
		if(i%7==0)	printf("\n");
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
void desteDuzenle(){
	int i;
	int kalan=destede_kalan;
	for(i=0;i<kalan;i++){
		if(deste[i].num==-1){
			deste[i].sym=deste[kalan].sym;
			deste[i].num=deste[kalan].num;
			deste[kalan].sym=-1;
			deste[kalan].num=-1;
			break;
		}
	}
}
int getch(void){  //http://stackoverflow.com/a/23035044
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
