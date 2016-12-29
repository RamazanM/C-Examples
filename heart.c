#include <stdio.h>
int main() {
  int i,j;
  for(i=0;i<51;i++){
    for(j=0;j<25;j++){
      //if(i==0 || i==7)printf("*");
      if(i<=3 && (j==6-i*2 || j==6+i*2 )  ) printf("*");
      if(i<=3 && (j==17-i*2 || j==17+i*2 )  ) printf("*");
      if(i>3 && j<12 && j==i-3 ) printf("*");
      if(i>3  && i<16 && j>6 && j==27-i ) printf("*");
      else printf("  ");
    }
    printf("\n\n");
  }
  getchar();
  return 0;
}
