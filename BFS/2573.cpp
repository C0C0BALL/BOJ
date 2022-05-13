#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int field[301][301];
int newfield[301][301];
int visited[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int melt(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (field[nx][ny] == 0) cnt++;
	}
	return cnt;
}


void bfs(int x, int y) {
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
			if (visited[newx][newy] == 1 || field[newx][newy] == 0) continue;
			visited[newx][newy] = 1;
			q.push({ newx,newy });
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
	int ans = 0;
	while (1) {
		int count = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (field[i][j] != 0 && visited[i][j] == 0) {
					count++;
					bfs(i, j);
				}
			}
		}
		if (count >= 2) {
			cout << ans;
			break;
		}
		if (count == 0) {
			cout << 0;
			break;
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (field[i][j] != 0) newfield[i][j] = field[i][j] - melt(i, j) >= 0 ? field[i][j] - melt(i, j) : 0;
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				field[i][j] = newfield[i][j];
			}
		}
		ans++;
	}
}