#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, string>u, pair<int, string>v) {
	return u.first < v.first;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>>v(n);
	for (int i = 0;i < n;i++) {
		int x;
		string str;
		cin >> x >> str;
		v[i].first = x;
		v[i].second = str;
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0;i < n;i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}