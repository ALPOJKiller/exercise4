#include <iostream>
#include <algorithm>
using namespace std;

void matrix(unsigned n) {
  for (size_t i = 1; i < n+1; i++) {
    for (size_t j = 1; j < n+1; j++) {
      if(j != 1)
        cout << ' ';
      cout << min({i,j,n-i+1,n-j+1});
    }
    cout << endl;
  }
}
int main() {
    unsigned input_val;
    unsigned case_count = 0;
    while(cin >> input_val) {
      cout << "Case "<<++case_count<<":"<<endl;
      matrix(input_val);
    }
    return 0;
}
