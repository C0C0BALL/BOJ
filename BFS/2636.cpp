#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, cnt;
int field[101][101];
int visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	cnt++;
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int newx = nx + dx[i];
			int newy = ny + dy[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
			if (visited[newx][newy] == 1 || field[nx][ny] == 1) continue;
			q.push({ newx,newy });
			visited[newx][newy] = 1;
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (visited[i][j] == 1) field[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> field[i][j];
		}
	}
	vector<int>result;
	int countcheeze = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (field[i][j] == 1) countcheeze++;
		}
	}
	result.push_back(countcheeze);
	while (1) {
		bool flag = false;
		countcheeze = 0;
		bfs(0, 0);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (field[i][j] == 1) {
					countcheeze++;
					flag = true;
				}
			}
		}
		result.push_back(countcheeze);
		memset(visited, 0, sizeof(visited));
		if (!flag) break;
	}
	cout << cnt << '\n' << result[result.size() - 2];
}