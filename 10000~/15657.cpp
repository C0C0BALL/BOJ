#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
bool visited[9];
int arr[9];
vector<int>v;

void dfs(int idx, int start) {
	if (idx == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start;i <= n;i++) {
		visited[i] = true;
		arr[idx] = v[i - 1];
		dfs(idx + 1, i);
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	dfs(0, 1);
}
