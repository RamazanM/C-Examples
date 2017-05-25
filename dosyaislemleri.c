#include<stdio.h>
#include <stdlib.h>
void veriYaz();
void veriOku();
int main(int argc, char const *argv[]) {
  veriOku();
  veriYaz();
  return 0;
}

void veriYaz(){
  FILE *dosya;  //dosya pointerı
  char isim[25],no[25]; //kullanıcıdan alınacak değerler

  dosya=fopen("dosyaadi.txt","a+"); //dosyayı append modunda aç
  printf("Isim gir:");
  fflush(stdin);  //stdin i sıfırla
  gets(isim); //girilen stringi isime ata
  printf("Numara gir:");
  gets(no); //girilen stringi noya ata

  fprintf(dosya,"%s %s \n",no,isim ); //dosyaya formatlı bir şekilde yaz
  fclose(dosya);


}

void veriOku(){
  FILE *dosya;  //dosya pointerı
  char isim[25],no[25]; //dosyadan alınacak değerler
  dosya=fopen("dosyaadi.txt","a+"); //dosyayı append modunda aç
  while (!feof(dosya)) {
    fscanf(dosya,"%s %s \n",&no,&isim);
    printf("%s %s\n",no,isim );
  }
  fclose(dosya);
}
