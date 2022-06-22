#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	vector<char>ans;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	stack<int>s;
	int idx = 0;
	for (int i = 1;i <= n;i++) {
		s.push(i);
		ans.push_back('+');
		while (!s.empty() && idx < n && s.top() == v[idx]) {
			idx++;
			s.pop();
			ans.push_back('-');
		}
	}
	if (s.size()) {
		cout << "NO";
	}
	else {
		for (int i = 0;i < ans.size();i++) {
			cout << ans[i] << '\n';
		}
	}
}