#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

void anaMenu();
void sarkiCal();
void sarkiEkle();
void sarkiDuzenle();
void sarkiSil();
void listele();
void klasorListele();
int kayitliSarkiSayisi();

struct Sarki{
  char yol[200];
  int mod;
};
/*Dosyaya kaydedilecek veri tipi*/
typedef struct Sarki sarki;



int main() {
  srand(time(NULL));/*Rastgeleliligi sifirla*/
  while(1) anaMenu();
}

void anaMenu(){
  int secim;
  printf("SARKILAR\n------------------------\n");
  printf("\t1)Sarki Cal\n------------------------\n");
  printf("\t2)Sarki Ekle\n");
  printf("\t3)Sarki Duzenle\n");
  printf("\t4)Sarki Sil\n");
  printf("\t5)Tum sarkilari listele\n");
  printf("\t7)Cikis\n\n");
  printf("Secim:");
  scanf("%d",&secim );
  switch (secim) {
    case 1 :
      sarkiCal();
      break;
    case 2:
      sarkiEkle();
      break;
    case 3:
      sarkiDuzenle();
      break;
    case 4:
      sarkiSil();
      break;
    case 5:
      listele();
      break;
    case 6:
      klasorListele();
      break;
    case 7:
      exit(0);
      break;
    default:
      break;

  }
}

void sarkiCal(){
  int mod;
  char calistir[500],isim[100];
  sarki sarkilar[50];
  sarki secilenSarki;
  sarki gelenSarki;
  FILE *dosya;
  int i=0;
  dosya=fopen("D:\\sarkilar.bin","a+");
  printf("1)Neseli 2)Huzunlu 3)Heyecanli 4)Dertli\nModunuzu seçiniz:");
  scanf("%d",&mod );
    while(fread(&gelenSarki,sizeof(struct Sarki),1,dosya)!=0){
      if(gelenSarki.mod==mod){
        sarkilar[i]=gelenSarki;
        i++;
      }
    }
  secilenSarki=sarkilar[rand()%(i)];
  strcpy(calistir," \"C:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe\" C:\\Users\\Hp\\Documents\\Projects\\Music\\sarkilar\\");
  strcpy(isim,secilenSarki.yol);
  strcat(calistir,isim);
  printf("Secilen sarki:%s\n",calistir );
  system(calistir);
  fclose(dosya);
}

void sarkiEkle(){
  FILE *dosya;
  sarki eklenecekSarki;
  dosya=fopen("D:\\sarkilar.bin","a+");

  printf("Eklemek isiginiz sarkinin;\n");
  printf("Dosya adini giriniz:");
  fflush(stdin);
  fgets(eklenecekSarki.yol,100,stdin);
  printf("Modunu giriniz:\n1)Neseli 2)Huzunlu 3)Heyecanli 4)Dertli\n");
  scanf("%d",&eklenecekSarki.mod);
  fwrite(&eklenecekSarki,sizeof(struct Sarki),1,dosya);
  fclose(dosya);

}

void sarkiDuzenle(){
  FILE *dosya;
  FILE *temp;
  sarki gelenSarki;
  sarki duzenlenecekSarki;
  int guncellendi=0;
  char yol[100];
  dosya=fopen("D:\\sarkilar.bin","a+");
  temp=fopen("D:\\temp.bin","a+");

  printf("Duzenlemek isiginiz sarkinin;\n");
  printf("Dosya adini giriniz:");
  fflush(stdin);
  fgets(yol,100,stdin);
  printf("Yeni dosya adini giriniz:");
  fflush(stdin);
  fgets(duzenlenecekSarki.yol,100,stdin);
  printf("Sarkinin yeni modunu giriniz:\n1)Neseli 2)Huzunlu 3)Heyecanli 4)Dertli\n");
  scanf("%d",&duzenlenecekSarki.mod);
  while(fread(&gelenSarki,sizeof(struct Sarki),1,dosya)!=0){
    if(strcmp(gelenSarki.yol, yol)==0){
      fwrite(&duzenlenecekSarki,sizeof(struct Sarki),1,temp);
      guncellendi=1;
      printf("Sarki bulundu ve guncellendi.\n");
    }
    else{
      fwrite(&gelenSarki,sizeof(struct Sarki),1,temp);
    }
  }
  if(guncellendi==0) printf("Sarki bulunamadi.\n");
  fclose(temp);
  fclose(dosya);
  remove("D:\\sarkilar.bin");
  rename("D:\\temp.bin","D:\\sarkilar.bin");
  remove("D:\\temp.bin");
  getchar();
}

void sarkiSil(){
  FILE *dosya;
  FILE *temp;
  sarki gelenSarki;
  int silindi=0;
  char yol[100];
  dosya=fopen("D:\\sarkilar.bin","a+");
  temp=fopen("D:\\temp.bin","a+");

  printf("Silmek isiginiz sarkinin dosya adini giriniz:\n");
  fflush(stdin);
  fgets(yol,100,stdin);

  while(fread(&gelenSarki,sizeof(struct Sarki),1,dosya)!=0){
    if(strcmp(gelenSarki.yol, yol)==0){
      silindi=1;
      printf("Sarki bulundu ve silindi.\n");
    }
    else{
      fwrite(&gelenSarki,sizeof(struct Sarki),1,temp);
    }
  }
  if(silindi==0) printf("Sarki bulunamadi.\n");
  fclose(temp);
  fclose(dosya);
  remove("D:\\sarkilar.bin");
  rename("D:\\temp.bin","D:\\sarkilar.bin");
  getchar();
}

void listele(){
  sarki gelenSarki;
  FILE *dosya;
  dosya=fopen("D:\\sarkilar.bin","r");
  while(fread(&gelenSarki,sizeof(struct Sarki),1,dosya)!=0){
    printf("yol:%s", gelenSarki.yol);
    printf("mod:%d\n",gelenSarki.mod );
  }
  fclose(dosya);
}

void klasorListele(){
  DIR *dir;
  struct dirent *ent;
  char yol[100];
  strcpy(yol,"C:\\");
  printf("Yol:%s\n",yol );
  if( (dir=opendir(yol))!=NULL ){
    while((ent=readdir(dir))!=NULL){
      //printf("%s\n",ent->d_name );
      char *bol;
      bol=strtok(ent->d_name,".");//Bölünen yazının ilk elemanı
      bol=strtok(NULL,".");//İkinci elemanı
      printf("%s\n",bol );

    }
    closedir(dir);
  }
}
