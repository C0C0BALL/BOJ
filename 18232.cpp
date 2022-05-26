#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, s, e;
bool flag;
vector<int>tel[300001];
int visited[300001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> s >> e;
	for (int i = 0;i < m;i++) {
		int tx, ty;
		cin >> tx >> ty;
		tel[tx].push_back(ty);
		tel[ty].push_back(tx);
	}
	queue<pair<int, int>>q;
	q.push({ s,0 });
	visited[s] = 1;
	while (!q.empty()) {
		int nx = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (nx == e) {
			flag = true;
			cout << cnt << '\n';
			return 0;
		}
		if (nx - 1 > 0 && visited[nx - 1] == 0) {
			visited[nx - 1] = 1;
			q.push({ nx - 1,cnt + 1 });
		}
		if (nx + 1 <= n && visited[nx + 1]==0) {
			visited[nx + 1] = 1;
			q.push({ nx + 1,cnt + 1 });
		}
		for (int i = 0;i < tel[nx].size();i++) {
			if (visited[tel[nx][i]] == 0) {
				visited[tel[nx][i]]= 1;
				q.push({ tel[nx][i],cnt + 1 });
			}
		}
	}
	if (!flag) cout << -1;
}