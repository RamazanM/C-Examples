#include<stdio.h>

int main(){
	int a=12; 	//a isimli değişken.
	int * p;		   //p isimli pointer
	p=&a; 		//p pointer'ı a'nın adresini gösterir artık;

	printf("a:%d\n",a);	//a'nın içeriği
	printf("p:%x\n",p);	//p'nin içeriği(gösterdiği adres)
	printf("&p:%x\n",&p);	//p'nin adresi
	printf("*p:%d\n",*p);	//p'nin gösterdiği adresteki değer.
	}
