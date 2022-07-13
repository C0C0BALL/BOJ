#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX 1001
#define INF 123456789
using namespace std;

int n, m, dist[MAX], route[MAX];
vector<pair<int, int>>v[MAX];
vector<int>vv;

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int newcost = v[cur][i].second + cost;
			if (dist[next] > newcost) {
				dist[next] = newcost;
				route[next] = cur;
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	int x, y;
	cin >> x >> y;
	dijkstra(x);
	int now = y;
	vv.push_back(now);
	while (1) {
		int prev = route[now];
		vv.push_back(prev);
		if (prev == x) break;
		now = prev;
	}
	cout << dist[y] << '\n' << vv.size() << '\n';
	for (int i = vv.size() - 1; i >= 0; i--) {
		cout << vv[i] << ' ';
	}
}
