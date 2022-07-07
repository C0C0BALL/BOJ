#include <iostream>
#include <vector>
#include <queue>
#define MAX 801
#define INF 123456789
using namespace std;

int n, e, x, y;
vector<pair<int, int>>v[MAX + 1];
int dist[MAX + 1];

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
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> x >> y;
	// 1. 1->x->y->n
	// 2. 1->y->x->n
	int route_1, route_2 = 0;
	bool flag = false;
	dijkstra(1);
	route_1 = dist[x];
	route_2 = dist[y];
	dijkstra(x);
	route_1 += dist[y];
	route_2 += dist[y] + dist[n];
	dijkstra(y);
	route_1 += dist[n];
	int answer;
	if (route_1 >= INF && route_2 >= INF) flag = true;
	else {
		answer = min(route_1, route_2);
	}
	if (flag) cout << -1;
	else cout << answer;
}
