#include<stdio.h>
#include<time.h>

int main(){

	int dizi[100],eski[100];
	int i,j,temp;
	srand(time(NULL));
	for(i=0;i<100;i++) {
	dizi[i]=rand()%1000;
	eski[i]=dizi[i];
	}

	for(i=0;i<99;i++) {
		for(j=0;j<99-i;j++){
			if(dizi[j]>dizi[j+1]){
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
			}
		}
	}

	for(i=0;i<100;i++) { printf("%d.)Eski:%d\t Yeni:%d\n",i+1,eski[i],dizi[i]); }

}
