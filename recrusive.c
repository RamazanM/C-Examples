#include <stdio.h>
// Recrusive fonksiyon örneği

int faktoriyel(int sayi){		//Faktöriyel isimli bir fonksiyon tanımladık.
	if(sayi>1){			//Fonksiyona parametre olarak gelen sayı 1den büyük ise
		sayi*=faktoriyel(sayi-1);	//Aynı fonksiyonu bir daha çağırıp gelen değeri sayı ile çarpıyoruz.
		return sayi;		//her seferinde sayıyı geri döndürüyoruz.
	}		//sürekli içiçe çağırıldığından en içtekı fonksiyondan 1, bir sonrakinden 1*2, 1*2*3 diye gider...
}

int main(){
	int sayi;
	printf("Faktöriyelini almak istediğiniz sayıyı giriniz:");
	scanf("%d",&sayi);
	printf("%d'nin faktöriyeli:%d",sayi,faktoriyel(sayi));
}