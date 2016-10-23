#include <stdio.h>
int main (){
	int taban,sayi,i=1;
	printf ("Taban:");
	scanf ("%d",&taban);
	printf ("Sayi:");
	scanf ("%d",&sayi);
	while (sayi!=power(taban,i)) i++;
	printf ("log%d tabanında %d = %d",taban,sayi,i);
}
int power (int a, int b){
	int i=0,sonuc=1;
	for (i;i<b;i++) sonuc*=a;
	return sonuc;
	}