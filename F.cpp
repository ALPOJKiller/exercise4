#include <iostream>
#include <map>
using namespace std;
map<unsigned,map<unsigned,unsigned> > buffer;
unsigned C(unsigned m,unsigned n) {
  if(n > m) {
    return 0;
  }
  if(m < 2 || n == 0) {
    return 1;
  }
  if(buffer.find(m) == buffer.end() || buffer[m].find(n) == buffer[m].end())
    buffer[m][n] = C(m-1,n)+C(m-1,n-1);
  return buffer[m][n];
}
int main() {
  unsigned m,n;
  unsigned case_count = 0;
  while(cin >> m >> n) {
      cout << "Case "<<++case_count<<":"<<endl
           <<C(m,n)<<endl;
  }
  return 0;
}
