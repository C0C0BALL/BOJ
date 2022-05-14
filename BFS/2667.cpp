#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[26][26];
int visited[51][51];
int movex[4] = { -1,1,0,0 };
int movey[4] = { 0,0,-1,1 };
int danji = 0;
int count_ = 0;
vector<int>v;

void dfs(int y, int x, int n) {
	visited[y][x]++;
	int mx, my;
	for (int i = 0;i < 4;i++) {
		mx = x + movex[i];
		my = y + movey[i];
		if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
		if (arr[my][mx] == 1 && visited[my][mx] == 0) dfs(my, mx, n);
	}
	count_++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string mem;
		cin >> mem;
		for (int j = 0; j < mem.size(); j++) {
			arr[i][j] = mem[j] - '0';
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			count_ = 0;
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				dfs(i, j, n);
				v.push_back(count_);
				danji++;
			}
		}
	}
	cout << danji << '\n';
	sort(v.begin(), v.end());
	for (int i = 0;i < danji;i++) {
		cout << v[i] << '\n';
	}
}