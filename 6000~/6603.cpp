#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, k;
bool visited[14];
int arr[14];
vector<int>v;

void dfs(int idx, int start) {
	if (idx == 6) {
		for (int i = 0;i < 6;i++) {
			cout << v[arr[i]] << ' ';
		}
		cout << '\n';
	}
	for (int i = start;i <= k;i++) {
		if (visited[i]) continue;
		arr[idx] = i;
		visited[i] = true;
		dfs(idx + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		v.push_back(0);
		for (int i = 0;i < k;i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		dfs(0, 1);
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		v.clear();
		cout << '\n';
	}
}
