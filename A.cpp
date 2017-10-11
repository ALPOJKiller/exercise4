#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

const double EPSILON = 1E-8;
using namespace std;
template <typename T>
void print_vector(const vector<T>& v) {
	cout << v.front();
	for (auto it = v.begin()+1;it != v.end();++it) {
		cout << ", " << *it;
	}
	cout << endl;
}
std::vector<unsigned> rank_(const vector<pair<unsigned,double>>& v) {
	std::vector<unsigned> ans(v.size());
	unsigned last_index = 1;
	double last_num = v.front().second;
	for (unsigned i = 0; i < v.size(); ++i) {
		if(abs(v[i].second-last_num) > EPSILON) {
			last_index = i + 1;
			last_num = v[i].second;
		}
		ans[v[i].first] = last_index;
	}
	return ans;
}
int main() {
	string s;
	unsigned case_count = 0;
	while(getline(cin,s)) {
		if(s != "") {
			istringstream ss(s);
			double d;
			vector<pair<unsigned,double>> v;
			while(ss >> d) {
				unsigned index = v.size();
				v.push_back(make_pair(index,d));
			}
			sort(v.begin(),v.end(),[](pair<unsigned,double> a,pair<unsigned,double> b) {
				return a.second > b.second;
			});
			cout << "Case "<<++case_count<<':'<<endl;
			print_vector(rank_(v));
		}
	}
	return 0;
}
