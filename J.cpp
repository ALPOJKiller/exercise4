#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;
template <typename T>
T matrix_sum(std::vector<std::vector<T> > mat) {
  T ans = 0;
  for(auto& v:mat) {
    ans += accumulate(v.begin(),v.end(),static_cast<T>(0));
  }
  return ans;
}
int main() {
    string s;
    vector<vector<double> > mat;
    unsigned case_count = 0;
    while (getline(cin,s)) {
      if(s == "") {
        cout << "Case "<<++case_count<<": "<< mat.size() << ", " <<mat.front().size() << ", " << matrix_sum(mat) << endl;
        mat.clear();
      } else {
        istringstream ss(s);
        double d;
        std::vector<double> v;
        while (ss >> d) {
          v.push_back(d);
        }
        mat.push_back(v);
      }
    }
    cout << "Case "<<++case_count<<": "<< mat.size() << ", " <<mat.front().size() << ", " << matrix_sum(mat) << endl;
    return 0;
}
