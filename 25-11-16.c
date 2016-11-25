#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Uye{
	int num;
	char isim[10];
	int yas;
	};

typedef struct Uye uye;

int main(){
	uye ilk;
	ilk.num=1;
	ilk.isim="asdfghjkle";
	ilk.yas=20;
		
	printf("%d - %s - %d",ilk.num,ilk.isim,ilk.yas);
	}