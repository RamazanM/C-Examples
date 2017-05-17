ddd#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ana_menu();
int hasta_ara();
int hasta_ekle();
int hasta_guncelle();
int hasta_listele();
int hasta_sil();
int k_index_hesapla(int boy,int kilo);

struct Hasta{
  char k_no[11];
  char isim[50];
  int boy,kilo;
};
typedef struct Hasta hasta;

void main() {
  while(1) {ana_menu();}
}

int ana_menu(){
  /*islemlerin seciminin yapılacagi menu*/
  int secim;
  system("cls");
  printf("ANA MENU\n");
  printf("1)Hasta Ara\n");
  printf("2)Hasta Ekle\n");
  printf("3)Hasta Guncelle\n");
  printf("4)Hasta Sil\n");
  printf("5)Tum hastalari listele\n");
  printf("6)Cikis\n");

  printf("Seciminizi yapiniz:");
  scanf("%d", &secim );

  switch (secim) {
    case 1:
      hasta_ara();
      break;
    case 2:
      hasta_ekle();
      break;
    case 3:
      hasta_guncelle();
      break;
    case 4:
      hasta_sil();
      break;
    case 5:
      hasta_listele();
      break;
    case 6:
      exit(0);

  }
}
int hasta_ara(){
  /*isme veya kimlik numarasina gore arama yapan fonksiyon*/
  char isim[50];
  FILE *dosya;
  hasta gelenHasta;
  system("cls");
  dosya=fopen("D:\\hastalar.bin","a+");
  printf("Aramak istediginiz hastanin adini/kimlik no'sunu giriniz:" );
  fflush(stdin);
  fgets(isim,50,stdin);
  while(fread(&gelenHasta,1,sizeof(struct Hasta),dosya)){
    if(strcmp(gelenHasta.isim,isim)==0 || strcmp(gelenHasta.k_no,isim)==0 ){
      printf("Kimlik Numarasi:%s",gelenHasta.k_no );
      printf("Ismi:%s",gelenHasta.isim );
      printf("Boyu:%d\n",gelenHasta.boy );
      printf("Kilosu:%d\n",gelenHasta.kilo );
      k_index_hesapla(gelenHasta.boy,gelenHasta.kilo);
    }
  }
  fclose(dosya);
  getchar();
}
int hasta_ekle(){
  char isim[30],k_no[11];
  int boy,kilo,k_index;
  hasta eklenecek_hasta;
  FILE *dosya;
  dosya=fopen("D:\\hastalar.bin","a+");
  system("cls");
  printf("Kimlik numarasi giriniz:");
  fflush(stdin);
  fgets(k_no,11,stdin);
  printf("Isminizi giriniz:");
  fflush(stdin);
  fgets(isim,30,stdin);
  printf("Boyunuzu giriniz:");
  scanf("%d",&boy);
  printf("Kilonuzu giriniz:");
  scanf("%d",&kilo);
  k_index=kilo/(boy*boy);

  strcpy(eklenecek_hasta.k_no, k_no);
  strcpy(eklenecek_hasta.isim,isim);
  eklenecek_hasta.boy=boy;
  eklenecek_hasta.kilo=kilo;

  fwrite(&eklenecek_hasta,sizeof(struct Hasta),1,dosya);
  fclose(dosya);
  getchar();
  return 0;
}
int hasta_listele(){
  hasta gelenHasta;
  FILE *dosya;
  dosya=fopen("D:\\hastalar.bin","rb");
  //system("cls");
  while(fread(&gelenHasta,1,sizeof(struct Hasta),dosya)!=0){
      printf("\nKimlik Numarasi:%s",gelenHasta.k_no );
      printf("Ismi:%s",gelenHasta.isim );
      printf("Boyu:%d\n",gelenHasta.boy );
      printf("Kilosu:%d\n",gelenHasta.kilo );
      k_index_hesapla(gelenHasta.boy,gelenHasta.kilo);
  }
  fclose(dosya);
  getch();
  return 0;
}
int hasta_guncelle(){
  FILE *dosya;
  FILE *temp;
  int guncellendi=0;
  hasta gelenHasta;
  hasta guncelHasta;
  char k_no[11];
  system("cls");
  dosya=fopen("D:\\hastalar.bin","a+");
  temp=fopen("D:\\temp.bin","a+");

  printf("Guncellemek istediginiz hastanin kimlik numarasini giriniz:\n" );
  fflush(stdin);
  fgets(k_no,11,stdin);

  while(fread(&gelenHasta,1,sizeof(struct Hasta),dosya)!=0){
    if(strcmp(gelenHasta.k_no,k_no)==0){
        printf("Guncellemek istediginiz hasta: %s",gelenHasta.isim );
        printf("Hastanin yeni kilosunu giriniz:\n");
        scanf("%d",&guncelHasta.kilo );
        printf("Hastanin yeni boyunu giriniz:\n");
        scanf("%d",&guncelHasta.boy );
        strcpy(guncelHasta.isim,gelenHasta.isim);
        strcpy(guncelHasta.k_no,gelenHasta.k_no);
        printf("Hasta bulundu ve guncellendi.\n");
        fwrite(&guncelHasta,sizeof(struct Hasta),1,temp);
        guncellendi=1;
    }
    else{
      fwrite(&gelenHasta,sizeof(struct Hasta),1,temp);
    }
  }
  if(guncellendi==0) printf("Hasta bulunamadi.\n");
  fclose(temp);
  fclose(dosya);
  remove("D:\\hastalar.bin");
  rename("D:\\temp.bin","D:\\hastalar.bin");
  remove("D:\\temp.bin");
  getchar();
  return 0;
}
int hasta_sil(){
  FILE *dosya;
  FILE *temp;
  hasta gelenHasta;
  char k_no[11];
  int silindi=0;
  dosya=fopen("D:\\hastalar.bin","a+");
  temp=fopen("D:\\temp.bin","a+");

  system("cls");
  printf("Silmek istediginiz hastanin kimlik numarasini giriniz:\n" );
  fflush(stdin);
  fgets(k_no,11,stdin);

  while(fread(&gelenHasta,1,sizeof(struct Hasta),dosya)!=0){
    if(strcmp(gelenHasta.k_no,k_no)==0){
      printf("%s Hasta bulundu ve silindi\n",gelenHasta.k_no);
      silindi=1;
    }
    else{
      fwrite(&gelenHasta,sizeof(struct Hasta),1,temp);
    }
  }
  if(silindi==0) printf("Hasta bulunamadi.\n");
  fclose(temp);
  fclose(dosya);
  remove("D:\\hastalar.bin");
  rename("D:\\temp.bin","D:\\hastalar.bin");
  remove("D:\\temp.bin");
  getchar();
  return 0;
}
int k_index_hesapla(int boy,int kilo){
  float k_index=(float)kilo/((float)boy/100*(float)boy/100);
  printf("Vucut kitle endeksiniz:%f\n",k_index);
  if(k_index<18.5){
    printf("Zayif\n");
  }
  else if(k_index<25){
    printf("Normal\n");
  }
  else if(k_index<30){
    printf("Fazla Kilolu\n");
  }
  else if(k_index<35){
        printf("I.Seviye Obez\n");
  }
  else if(k_index<45){
    printf("II.Seviye Obez\n");
  }
  else if(k_index>=45){
    printf("III.Seviye Obez\n");
  }
  return 0;
}
