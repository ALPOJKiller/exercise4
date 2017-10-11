#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<unsigned> > magic(unsigned n) {
  std::vector<std::vector<unsigned> > ans;
  for (unsigned i = 0; i < n; ++i) {
    std::vector<unsigned> v(n,0);
    ans.push_back(v);
  }
  int current_x=0,current_y=n/2;
  for (unsigned i = 1; i <= n*n; ++i) {
    ans[current_x][current_y] = i;
    if(i % n == 0) {
      ++current_x;
      current_x %= n;
    } else {
      --current_x;
      if (current_x < 0) {
        current_x += n;
      }
      ++current_y;
      current_y %= n;
    }
  }
  return ans;
}
template <typename T>
void print_matrix(vector<vector<T> > mat) {
  for (auto it_1 = mat.begin();it_1 != mat.end(); ++it_1) {
    for (auto it_2 = it_1->begin(); it_2 != it_1 -> end(); it_2++) {
        if(it_2 != it_1->begin()) {
          cout << ' ';
        }
        cout << *it_2;
    }
    cout << endl;
  }
}
int main() {
  unsigned input_val;
  unsigned case_count = 0;
  vector<unsigned> input;
  while(cin >> input_val) {
    cout << "Case "<<++case_count<<":"<<endl;
    print_matrix(magic(input_val));
  }
  return 0;
}
