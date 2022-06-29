#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	int ans = 0;
	cin >> n >> k;
	vector<int>u(n);
	vector<int>state(n);
	vector<int>v(k);
	for (int i = 0;i < k;i++) {
		cin >> v[i];
	}
	int idx = 0;
	int countElement = 0;
	for (int i = 0;i < n;i++) {
		if (i == 0) {
			u[i] = v[idx];
			countElement++;
			idx++;
		}
		else {
			bool flag = false;
			for (int j = 0;j < countElement;j++) {
				if (v[idx] == u[j]) {
					flag = true;
					break;
				}
			}
			if (flag) i--;
			else {
				u[i] = v[idx];
				countElement++;
			}
			idx++;
		}
	}
	for (int i = idx;i < k;i++) {
		bool flag = false; //true:존재 false: 존재X
		for (int j = 0;j < n;j++) {
			if (v[i] == u[j]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			fill(state.begin(), state.end(), 999);
			for (int j = 0;j < n;j++) {
				for (int l = i;l < k;l++) {
					if (u[j] == v[l]) {
						state[j] = l;
						break;
					}
				}
			}
			int maxIdx = max_element(state.begin(), state.end()) - state.begin();
			u[maxIdx] = v[i];
			ans++;
		}
	}
	cout << ans;
}
