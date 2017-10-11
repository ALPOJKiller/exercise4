#include <stdio.h>
unsigned Josephus(unsigned n,unsigned m) {
  if(n == 1)
    return 0;
  return (Josephus(n-1,m)+m)%n;
}
int main() {
  unsigned n,m;
  unsigned case_count = 0;
  while(scanf("%u %u",&n,&m) != EOF) {
    printf("Case %u: %u, %u, %u\n",++case_count,n,m,Josephus(n,m)+1);
  }
  return 0;
}
