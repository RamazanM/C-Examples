#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int sayi;
	struct node * next;
}node;

node *dugum=NULL;
int enKucuk;

void push(){
	node *yeni=(node*)malloc(sizeof(node));
	printf("Sayiyi giriniz:");
	scanf("%d",&yeni->sayi);
	yeni->next=NULL;
	
	
	if(dugum==NULL){
		dugum=yeni;
		enKucuk=dugum->sayi;
	}
	else{
		if(yeni->sayi < enKucuk) enKucuk = yeni->sayi;

		node *gezici=dugum;
		while(gezici->next!=NULL)
			gezici=gezici->next;
		gezici->next=yeni;
	}
}

void pop(){
	if(dugum==NULL)
		printf("Stackte eleman bulunmamaktadýr lutfen eleman ekleyin.\n");
		
	else{
		node *gezici=dugum;
		int nextMin=999999;
		if(dugum->next==NULL){
			printf("%d popped.\n",gezici->sayi);
			dugum=NULL;
			enKucuk=0;
		}
		else{
			while(gezici->next->next!=NULL){
			 	gezici=gezici->next;
				if(gezici->sayi > enKucuk && gezici->sayi < nextMin) nextMin=gezici->sayi;
				 }
			if(gezici->next->sayi==enKucuk) enKucuk=nextMin;
			printf("%d popped.\n",gezici->next->sayi);
			gezici->next=NULL;
		}
	}
}

void print_stack(){
	if(dugum==NULL)
		printf("Stack'te eleman bulunmamaktadýr lutfen eleman ekleyin.\n");

	else{
		node *gezici=dugum;
		while(gezici!=NULL){
			printf("%d \n",gezici->sayi);
			gezici=gezici->next;
		} 
	}
}


int main(){
	while(1){
		printf("1)push\t2)pop\t3)print\t4)En Kucugu yazdir \nIslem seciniz:");
		int secim;
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				print_stack();
				break;
			case 4:
				printf("En kucuk eleman:%d\n",enKucuk);
				break;
		}
		
	}
}
