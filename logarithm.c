#include <stdio.h>
int main (){
	int taban,sayi,sayac=0;
	printf ("Taban:");
	scanf ("%d",&taban);
	printf ("Sayi:");
	scanf ("%d",&sayi);
	int i=0;
	while (1){
		if (sayi!=taban*i)i++;
		else break;
	}
	printf ("%d",i);
}
int pow (int a, int b){}