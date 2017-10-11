#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
int binary_find(const vector<T>& v,T x) {
    int left = 0;
    int right = v.size()-1;
    while(left <= right) {
        int middle = (left+right)/2;
        if(v[middle] > x) {
            right = middle - 1;
        } else if(v[middle] < x) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
}
int main() {
  string s;
  int value_to_find;
  unsigned case_count = 0;
  while(cin >> value_to_find) {
    string s;
    getline(cin,s);
    getline(cin,s);
    vector<int> v;
    if(s != "") {
        istringstream ss(s);
        int value;
        while(ss >> value) {
             v.push_back(value);
        }
        int find_result = binary_find(v,value_to_find);
        cout << "Case "<<++case_count<<": " << value_to_find << ", " << find_result << endl;
     }
  }
  return 0;
}
