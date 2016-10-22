#include <stdio.h>
int main (){
	int taban,sayi,sayac=0;
	printf ("Taban:");
	scanf ("%d",&taban);
	printf ("Sayi:");
	scanf ("%d",&sayi);
	int i=1;
	while (1){
		if (sayi!=pow (taban,i))i++;
		else break;
	}
	printf ("log%d tabanında %d = %d",taban,sayi,i);
}
int pow (int a, int b){
	int i=0,sonuc=1;
	for (i;i<b;i++) sonuc*=a;
	return sonuc;
	}