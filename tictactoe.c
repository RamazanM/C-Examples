#include <stdio.h>
#define GAME_X 1
#define GAME_O 0
#define _X 0
#define _Y 1
#define MAX_P 8
#define MAX_F 3
int content[4][3];
int player_choose=GAME_X;
int *available_patterns();
int patterns[8][3][2]={
  {{0,0},{0,1},{0,2}},
  {{1,0},{1,1},{1,2}},
  {{2,0},{2,1},{2,2}},
  {{0,0},{1,0},{2,0}},
  {{0,1},{1,1},{2,1}},
  {{0,2},{1,2},{2,2}},
  {{0,0},{1,1},{2,2}},
  {{0,2},{1,1},{2,0}},
};
int content[4][3]={
  {1,-1,-1},
  {-1,-1,-1},
  {-1,-1,-1},

};



int main(){

int* deneme=available_patterns();

int i=0;
for(i;i<7;i++)printf("%d\n",deneme[i] );
// 8: pattern indexi -> p_index
// 3: alan indexi -> f_index
// 2: koordinatlar -> crdnt



// 4: content col -> c_col
// 3: content row -> c_row


  return 0;
}


int * available_patterns(){
  int p_index,f_index,crdnt;
  int c_col,c_row;
  static int available_pattern_ids[8]={-1,-1,-1,-1,-1,-1,-1};  //static koymayı unutma!!
  int ap_counter=0;
  int x=0,y=0;

  for(p_index=0; p_index<MAX_P; p_index++){
    int field_counter=0;
    for(f_index=0; f_index<MAX_F; f_index++){
      x=patterns[p_index][f_index][_X];
      y=patterns[p_index][f_index][_Y];
      if(content[y][x]!=player_choose) field_counter++;
      //printf("%d\n",field_counter);
    }
    if(field_counter==3){available_pattern_ids[ap_counter]=p_index; ap_counter++;}
    else printf("Desen Uygun Değil\n");
    }
return available_pattern_ids;
}
int *check_empty_fields(int pattern_id){
  //koordinatları döndür
}
int random  (int *patternOrField){}
void write (int *coordinate, int sign){}