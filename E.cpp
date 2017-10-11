#include <iostream>
#include <vector>
#include <algorithm>
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
  unsigned input_val;
  unsigned case_count = 0;
  vector<unsigned> input;
  while(cin >> input_val) {
    cout << "Case "<<++case_count<<":"<<endl;
    for (size_t i = 0; i < input_val + 1; i++) {
      for (size_t j = 0; j <= i; j++) {
        cout << C(i,j);
        if(j != i)
          cout<< ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
