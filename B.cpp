#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

template<typename T>
void print_first_n(priority_queue<T> q,unsigned n) {
    for (unsigned i = 0; i < n; i++) {
      if(i != 0)
        cout << ", ";
      cout << q.top();
      q.pop();
    }
    cout << endl;
}
int main() {
  vector<int> v{0,0,0,0,0,0,0,0,0,0};
  priority_queue<int> q(less<int>(),v);
  string s;
  unsigned case_count = 0;
  while(getline(cin,s)) {
	   if(s != "") {
		     istringstream ss(s);
		     int value;
		     while(ss >> value) {
			        q.push(value);
		     }
	    }
      cout << "Case "<<++case_count<<": ";
      print_first_n(q,10);
  }
  return 0;
}
