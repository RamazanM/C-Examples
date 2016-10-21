/*
(a + b)0 = 1
(a + b)1 = 1.a +1.b
(a + b)2 = 1.a2 + 2.a.b +1.b2
(a + b)3 = 1.a3 + 3.a2.b + 3.a.b2 +1.b3
(a + b)4 = 1.a4 + 4.a3.b + 6.a2.b2 + 4.a.b3 +1.b4
(a + b)5 = 1.a5 + 5.a4.b +10.a3.b2 +10.a2.b3 + 5.a.b4 +1.b5
*/
void binom(int n);
int fact(int a);
int combination(int a, int b);
#include <stdio.h>
int main(int argc, char const *argv[]) {
  int i=1;
  for (i; i < 10; i++) {
    printf("%d.) ",i );
    binom(i);
    printf("\n");
  }
  return 0;
}
int fact(int a){
  int sonuc=1;
  for(a;a>0;a--) sonuc=sonuc*a;
  return sonuc;
}
int combination(int a, int b){
  int fark=a-b;
  int sonuc=fact(a)/(fact(b)*fact(a-b));
  return sonuc;
}
void binom(int n){
  int k=0;
  for(k=0;k<=n;k++){
    if(combination(n,k)!=1)printf("%d",combination(n,k) );
    if((n-k)!=0 && (n-k)!=1 )printf("a^%d",n-k);
    if((n-k)==1)printf("a");
    if(k!=0&&k!=1)printf("b^%d",(k));
    if(k==1)printf("b");
    if(k!=n)printf(" + " );
} }
