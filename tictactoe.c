/*
Tehtid-thread: 2 tane kullanıcı işaretinin aynı desen içerisinde bulunmasıdır.
Desen-pattern: xox oyununda oyuncunun kazanması için işaretleri koyması gereken düzen topluluğu.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAME_X 1
#define GAME_O 0
#define _X 0
#define _Y 1
#define MAX_P 8
#define MAX_F 3
int player_choose=GAME_X;
int computer_choose=GAME_O;
//Prototip Tanımlamaları
int *available_patterns();
int write (int,int,int);
void print_content(int content[3][3]);
void check_empty_fields();
void check_thread();
int is_available(int,int);
void ready_write();
void write_random();
int rastgele(int max);
void setup();
//Prototip Tanımlamaları
struct game {
	int count_player;
	int count_computer;
	int player_choose;
	int computer_choose;
}game;
struct thread{
  int pattern_id;
  int x;
  int y;
} thread;

int patterns[8][3][2]={
  {{0,0},{0,1},{0,2}},
  {{1,0},{1,1},{1,2}},
  {{2,0},{2,1},{2,2}},
  {{0,0},{1,0},{2,0}},
  {{0,1},{1,1},{2,1}},
  {{0,2},{1,2},{2,2}},
  {{0,0},{1,1},{2,2}},
  {{0,2},{1,1},{2,0}} };
int content[3][3]={
  {-1,-1,-1},
  {-1,-1,-1},
  {-1,-1,-1} };

int main(){
	setup();//İlk ayarlar...
  while(!gameover()){//Oyun hala bitmediyse->
  int x,y;
  printf("Format x,y:");//Sayının girilmesi gereken format x,y şeklinde.
  scanf("%d,%d",&x,&y);//Koordinatları x ve y ye ata.
  if(write(x,y,player_choose)!=-1){//Eğer kullanıcının işaretini belirtilen koordinatlara yazabiliyorsak->
		if(gameover())break;
		print_content(content);//Oyun tablosunu ekrana yazdır.
	  check_thread();//Tehtidleri kontrol et.bkz. tehtid.
	  if(thread.pattern_id!=-1) {//Eğer iki tane player sign bir düzendeyse
			write(thread.x,thread.y,GAME_O);//tehtid struct'ına atanmış olan koordinatlara bilgisayarın işaretini yaz.
			thread.pattern_id=-1;//Tehtidi sıfırla.
			thread.x=-1;//Tehtidi sıfırla.
			thread.y=-1;//Tehtidi sıfırla.
		}
	  else {//Ortada bir tehtid yoksa->
			write_random();//Rastgele bir yere bilgisayarın işaretini yaz.
		}
	  print_content(content);//Oyun tablosunu ekrana yazdır.
	}
	else printf("Orası dolu...\n");//Eğer write() fonksiyonu -1 verirse, o koordinatların dolu olduğunu söyle.
}
  return 0;
}

void setup(){
	game.count_player=0;//Oyuncunun hamle sayısını sıfırla.
	game.count_computer=0;//Bilgisayarın hamle sayısını sıfırla.
	print_content(content);//Oyun tablosunu ekrana yazdır.
}
int * available_patterns(){//Kullanılabilir desenleri dizi olarak döndürür.
  int p_index,f_index,crdnt;
  int c_col,c_row;
  static int available_pattern_ids[8]={-1,-1,-1,-1,-1,-1,-1,-1};  //static koymayı unutma!!
  int ap_counter=0;
  int x=0,y=0;

  for(p_index=0; p_index<=MAX_P; p_index++){
    int field_counter=0;
    for(f_index=0; f_index<MAX_F; f_index++){
      x=patterns[p_index][f_index][_X];
      y=patterns[p_index][f_index][_Y];
      if(content[y][x]!=player_choose) field_counter++;
    }
    if(field_counter==3){available_pattern_ids[ap_counter]=p_index; ap_counter++;}
    //else printf("Desen Uygun Değil\n");
  }
    return available_pattern_ids;
}
void check_thread(){//Tehtidleri kontrol eder.
    int p_index,f_index;
    int thread_pattern_id=-1;
    int tp_counter=0;
    int x=-1,y=-1;
    for(p_index=0; p_index<MAX_P; p_index++){
      int field_counter=0;
      for(f_index=0; f_index<MAX_F; f_index++){
        x=patterns[p_index][f_index][_X];
        y=patterns[p_index][f_index][_Y];
				if(content[y][x]==player_choose) field_counter++;
				if(content[y][x]==computer_choose) field_counter=-1;

      }
      if(field_counter==2){thread_pattern_id=p_index; tp_counter++;}
      }
      thread.pattern_id=thread_pattern_id;
      check_empty_fields();
}
void write_random(){//Rastgele koordinatlara bilgisayarın işaretini yazar.
  int *aps=available_patterns();
  int pid=rastgele(7);
  while(aps[pid]==-1)pid=rastgele(7);
  int selected_pattern=aps[pid];
  //printf("pid%d\n",pid );
  int x,y;
  x=rastgele(4)-1;
  y=rastgele(4)-1;
  //printf("Randoma girdi\nx:%d,y:%d",x,y );
  while(content[y][x]!=-1){
    x=rastgele(4)-1;
    y=rastgele(4)-1;
  }
  if(write(x,y,computer_choose)==-1)write_random();
}
int write (int x,int y,int sign){//Verilen koordinatlara verilen işareti yazar.
  if(is_available(x,y)){
		content[x][y]=sign;
		if(sign==player_choose)game.count_player++;
		else if(sign==computer_choose)game.count_computer++;
	}
  else return -1;
}
void print_content(int content[3][3]){//Oyun tablosunu ekrana yazdırır.
  int i=0,j=0;
  for(i=0;i<3;i++){
    printf("-------------\n");
    for(j=0;j<3;j++){
      if(content[i][j]==GAME_X)printf("| %c ",'X' );
      if(content[i][j]==GAME_O)printf("| %c ",'O' );
			if(content[i][j]==-1)printf("| %c ",' ' );
    }
    printf("\n");
  }
  printf("-------------\n");
}
int is_available(int x,int y){//Verilen koordinatlar kullanılabilir ise 1 döndürür.
  if(content[x][y]==-1)return 1;
  else return 0;
}
void check_empty_fields(){//Tehtid oluşturan desendeki boş alanı kontrol eder.
  int f_index=0,x,y;
  int pattern_id=thread.pattern_id;
  for(f_index=0;f_index<MAX_F;f_index++){
    x=patterns[pattern_id][f_index][_X];
    y=patterns[pattern_id][f_index][_Y];
    if(content[y][x]==-1){
      thread.x=y;
      thread.y=x;
    }
  }
	//printf("Tehtid id:%d\tX:%d\tY:%d\n",pattern_id,thread.x,thread.y );
}
int rastgele(int max){//Verilen maximum değerde rastgele sayı üretir.
  srand(time(NULL));
  int sayi=0;
  while (sayi==0) {
    sayi=rand()%max;
  }
  sleep(1);
  srand(time(NULL));
  return sayi;
}
int gameover(){//Oyunun bitip bitmediğini, bittiyse kimin kazandığını kontrol eder.
  int p_index,f_index;
  int pattern_counter=0;
  int x=0,y=0;
	int player_counter=0;
	int computer_counter=0;
  for(p_index=0; p_index<MAX_P; p_index++){
		int player_counter=0;
		int computer_counter=0;
    for(f_index=0; f_index<MAX_F; f_index++){
      x=patterns[p_index][f_index][_X];
      y=patterns[p_index][f_index][_Y];
			if(content[y][x]==player_choose) player_counter++;
			if(content[y][x]==computer_choose) computer_counter++;
    	}
    if(player_counter==3){printf("Kazandınız\n");}
		else if(computer_counter==3){printf("Kaybettin\n");}
		else if(game.count_player==game.count_computer&&game.count_player>4)printf("Berabere\n");
    }
    if(pattern_counter==7){return 1;
		printf("Game OVER\n");}
    else return 0;
  }
