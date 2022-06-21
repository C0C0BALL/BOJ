#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l;
int destx, desty;
int field[301][301];
int visit[301][301];
int dx[8] = { -1,1,2,2,1,-1,-2,-2 };
int dy[8] = { 2,2,1,-1,-2,-2,-1,1 };

bool bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0;i < 8;i++) {
			int newx = nx + dx[i];
			int newy = ny + dy[i];
			if (newx < 0 || newy < 0 || newx >= l || newy >= l) continue;
			if (visit[newx][newy] == 1 || field[newx][newy] != 0) continue;
			field[newx][newy] = field[nx][ny] + 1;
			q.push({ newx,newy });
			visit[newx][newy] = 1;
			if (newx == destx && newy == desty) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> l;
		int x, y;
		cin >> x >> y >> destx >> desty;
		field[x][y] = 1;
		if (bfs(x, y)) cout << field[destx][desty] - 1 << '\n';
		else cout << 0 << '\n';
		memset(visit, 0, sizeof(visit));
		memset(field, 0, sizeof(field));
	}
}
