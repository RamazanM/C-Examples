#include <stdio.h>
void dik_ucgen();
void bos_dik_ucgen();
void bos_ikizkenar();
void ikizkenar();

int main (){
	dik_ucgen();
	printf("\n");
	bos_dik_ucgen();
	printf("\n");
	bos_ikizkenar();
	printf("\n");
	ikizkenar();
}

void dik_ucgen(){
	int i,j;
	for(i=1;i <10;i++){
		for (j=0;j <i;j++){
			printf ("* ");
		}
		printf ("\n");
	}	
}

void bos_dik_ucgen(){
	int i,j;
	for(i=0;i <=10;i++){
		for (j=0;j <=i;j++){
			if(i==10) printf("* ");
			else if(j==0 || j==i) printf ("* ");
			else printf("  ");
		}
		printf ("\n");
	}
}

void ikizkenar(){
	int i,j;
	for(i=0;i<=7;i++){
		for(j=0;j<15;j++){
			if (i==7) printf("*");
			else if( j < 7-i || j > 7+i) printf(" ");
			else printf("*");
			}
			printf("\n");
		}
}


void bos_ikizkenar(){
	int i,j;
	for(i=0;i<=7;i++){
		for(j=0;j<15;j++){
			if (i==7) printf("*");
			else if( j == 7-i || j == 7+i) printf("*");
			else printf(" ");
			}
			printf("\n");
		}
	}

void kelebek(){
	int i,j;
	for(i=0;i<=15;i++){
		for(j=0;j<7;j++){
			if(i==0 || i== 15) printf("*");
			else if(i<7){
				
				}
			}
		}
	}