#include <iostream>
#include <queue>
using namespace std;

int n, m, h;
int field[101][101][101];
int visited[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int>>q;

void bfs() {
	while (!q.empty()) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int nz = q.front().second;
		q.pop();
		for (int i = 0;i < 6;i++) {
			for (int j = 0;j < 6;j++) {
				for (int k = 0;k < 6;k++) {
					int newx = nx + dx[i];
					int newy = ny + dy[i];
					int newz = nz + dz[i];
					if (newx < 0 || newy < 0 || newz < 0 || newx >= h || newy >= n || newz >= m) continue;
					if (visited[newx][newy][newz] == 1) continue;
					if (field[newx][newy][newz] == 0) {
						q.push({ {newx,newy},newz });
						visited[newx][newy][newz] = 1;
						field[newx][newy][newz] = field[nx][ny][nz] + 1;
					}
				}
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < m;k++) {
				cin >> field[i][j][k];
			}
		}
	}
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < m;k++) {
				if (field[i][j][k] == 1) q.push({ {i,j}, k });
			}
		}
	}
	bfs();
	int answer = 0;
	bool flag = false;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < m;k++) {
				if (field[i][j][k] == 0) flag = true;
				if (field[i][j][k] > answer) answer=field[i][j][k];
			}
		}
	}
	if (flag) cout << -1;
	else cout << answer - 1;
}
